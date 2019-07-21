#include "global.h"
#include "field_door.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "task.h"
#include "metatile_behavior.h"
#include "constants/songs.h"


extern const struct DoorAnimFrame gDoorOpenAnimFrames[];
extern const struct DoorAnimFrame gBigDoorOpenAnimFrames[];
extern const struct DoorAnimFrame gDoorCloseAnimFrames[];
extern const struct DoorAnimFrame gBigDoorCloseAnimFrames[];
extern const struct DoorGraphics gDoorAnimGraphicsTable[];

static void DrawDoor(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame, int x, int y);
static void DrawClosedDoorTiles(const struct DoorGraphics *gfx, int x, int y);
static void CopyDoorTilesToVram(const void *src);
static void DrawCurrentDoorAnimFrame(const struct DoorGraphics *gfx, int x, int y, const u8 *pal);
static void door_build_blockdef(u16 *a, u16 b, const u8 *c);
static void Task_AnimateDoor(u8 taskId);
static bool32 sub_805B060(const struct DoorGraphics *gfx, struct DoorAnimFrame *frames, s16 *taskData);
static const struct DoorGraphics *GetDoorGraphics(const struct DoorGraphics *gfx, u16 metatileNum);
static s8 StartDoorAnimationTask(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frames, u32 x, u32 y);
static void DrawClosedDoor(const struct DoorGraphics *gfx, int x, int y);
static void DrawOpenedDoor(const struct DoorGraphics *gfx, u32 x, u32 y);
static const struct DoorAnimFrame *GetLastDoorFrame(const struct DoorAnimFrame *frame, const void *unused);
static s8 StartDoorCloseAnimation(const struct DoorGraphics *gfx, u32 x, u32 y);
static s8 sub_805B210(const struct DoorGraphics *gfx, u32 x, u32 y);
static s8 cur_mapdata_get_door_x2_at(const struct DoorGraphics *gfx, u32 x, u32 y);


static void DrawDoor(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame, int x, int y)
{
    if(frame->offset == 0xffff)
        DrawClosedDoorTiles(gfx, x, y);
    else{
        CopyDoorTilesToVram(gfx->tiles + frame->offset);
        DrawCurrentDoorAnimFrame(gfx, x, y, gfx->palette);
    }
}

static void DrawClosedDoorTiles(const struct DoorGraphics *gfx, int x, int y)
{
    if(gfx->size == 0)
        CurrentMapDrawMetatileAt(x,y);
    else{
        CurrentMapDrawMetatileAt(x,y);
        CurrentMapDrawMetatileAt(x, y-1);
    }
}

static void CopyDoorTilesToVram(const void *src)
{
    CpuFastSet(src, (void *)(VRAM + 0x7F00), 0x40);
}

static void DrawCurrentDoorAnimFrame(const struct DoorGraphics *gfx, int x, int y, const u8 *pal)
{
    u16 arr[8];
    if(gfx->size == 0)
        door_build_blockdef(arr, 0x3F8, pal);
    else{
        door_build_blockdef(arr, 0x3F8, pal);
        sub_805A91C(x, y - 1, arr);
        door_build_blockdef(arr, 0x3FC, pal + 4);
    }
    sub_805A91C(x, y, arr);
}

static void door_build_blockdef(u16 *a, u16 b, const u8 *c)
{
    int i;
    u16 unk;
    for (i = 0; i < 4; i++)
    {
        unk = *(c++) << 12;
        a[i] = unk | (b + i);
    }
    for (; i < 8; i++)
    {
        unk = *(c++) << 12;
        a[i] = unk;
    }
}

enum
{
    TD_FRAMELIST = 0,
    TD_GFX = 2,
    TD_FRAME = 4,
    TD_COUNTER,
    TD_X,
    TD_Y
};

static void Task_AnimateDoor(u8 taskId)
{
    u16 *taskData = gTasks[taskId].data;
    struct DoorAnimFrame *frames = (struct DoorAnimFrame *)(taskData[TD_FRAMELIST] << 16 | taskData[TD_FRAMELIST + 1]);
    struct DoorGraphics *gfx = (struct DoorGraphics *)(taskData[TD_GFX] << 16 | taskData[TD_GFX + 1]);

    if (sub_805B060(gfx, frames, taskData) == FALSE)
        DestroyTask(taskId);
}

static bool32 sub_805B060(const struct DoorGraphics *gfx, struct DoorAnimFrame *frames, s16 *taskData)
{
    if (taskData[TD_COUNTER] == 0)
        DrawDoor(gfx, &frames[taskData[TD_FRAME]], taskData[TD_X], taskData[TD_Y]);
    if (taskData[TD_COUNTER] == frames[taskData[TD_FRAME]].time)
    {
        taskData[TD_COUNTER] = 0;
        taskData[TD_FRAME]++;
        if (frames[taskData[TD_FRAME]].time == 0)
            return FALSE;
        else
            return TRUE;
    }
    taskData[TD_COUNTER]++;
    return TRUE;
}


static const struct DoorGraphics *GetDoorGraphics(const struct DoorGraphics *gfx, u16 metatileNum)
{
    while (gfx->tiles != NULL)
    {
        if (gfx->metatileNum == metatileNum)
            return gfx;
        gfx++;
    }
    return NULL;
}

static s8 StartDoorAnimationTask(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frames, u32 x, u32 y)
{
    if (FuncIsActiveTask(Task_AnimateDoor) == TRUE)
        return -1;
    else
    {
        u8 taskId = CreateTask(Task_AnimateDoor, 0x50);
        s16 *taskData = gTasks[taskId].data;

        taskData[TD_X] = x;
        taskData[TD_Y] = y;

        taskData[TD_FRAMELIST + 1] = (u32)frames;
        taskData[TD_FRAMELIST] = (u32)frames >> 16;

        taskData[TD_GFX + 1] = (u32)gfx;
        taskData[TD_GFX] = (u32)gfx >> 16;

        return taskId;
    }
}


static void DrawClosedDoor(const struct DoorGraphics *gfx, int x, int y)
{
    DrawClosedDoorTiles(gfx, x, y);
}


static void DrawOpenedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    const struct DoorAnimFrame *frame;
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx != NULL){
        frame = gfx->size == 0? gDoorOpenAnimFrames : gBigDoorOpenAnimFrames;
        DrawDoor(gfx, GetLastDoorFrame(frame, frame), x, y);
    }
}


static const struct DoorAnimFrame *GetLastDoorFrame(const struct DoorAnimFrame *frame, const void *unused)
{
    while (frame->time != 0)
        frame++;
    return frame - 1;
}
 

static s8 StartDoorCloseAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else{
        if(gfx->size ==0)
            return StartDoorAnimationTask(gfx, gDoorOpenAnimFrames, x, y);
        else 
            return StartDoorAnimationTask(gfx, gBigDoorOpenAnimFrames, x, y);
    }
}
 

static s8 sub_805B210(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else{
        if(gfx->size ==0)
            return StartDoorAnimationTask(gfx, gDoorCloseAnimFrames, x, y);
        else 
            return StartDoorAnimationTask(gfx, gBigDoorCloseAnimFrames, x, y);
    }
}

void FieldSetDoorOpened(u32 x, u32 y)
{
    if (MetatileBehavior_IsWarpDoor_2(MapGridGetMetatileBehaviorAt((s16)x, (s16)y)))
        DrawOpenedDoor(gDoorAnimGraphicsTable, x, y);
}

void FieldSetDoorClosed(u32 x, u32 y)
{
    if (MetatileBehavior_IsWarpDoor_2(MapGridGetMetatileBehaviorAt((s16)x, (s16)y)))
        DrawClosedDoor(gDoorAnimGraphicsTable, x, y);
}

s8 FieldAnimateDoorClose(u32 x, u32 y)
{
    if (!MetatileBehavior_IsWarpDoor_2(MapGridGetMetatileBehaviorAt((s16)x, (s16)y)))
        return -1;
    else
        return sub_805B210(gDoorAnimGraphicsTable, x, y);
}


s8 FieldAnimateDoorOpen(u32 x, u32 y)
{
    if (!MetatileBehavior_IsWarpDoor_2(MapGridGetMetatileBehaviorAt((s16)x, (s16)y)))
        return -1;
    else
        return StartDoorCloseAnimation(gDoorAnimGraphicsTable, x, y);
}

bool8 FieldIsDoorAnimationRunning(void)
{
    return FuncIsActiveTask(Task_AnimateDoor);
}
    
u32 GetDoorSoundEffect(u32 x, u32 y)
{
    int sound = cur_mapdata_get_door_x2_at(gDoorAnimGraphicsTable, x, y);
    if (sound == 0)
        return SE_W253;
    else
        return SE_JIDO_DOA;
}

static s8 cur_mapdata_get_door_x2_at(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else
        return gfx->sound;
}
