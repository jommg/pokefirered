#include "global.h"
#include "field_door.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "task.h"
#include "metatile_behavior.h"
#include "constants/songs.h"


static const u8 sDoorAnimTiles_00[][0x80] =
{
    INCBIN_U8("graphics/door_anims/00/0.4bpp"),
    INCBIN_U8("graphics/door_anims/00/1.4bpp"),
    INCBIN_U8("graphics/door_anims/00/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_01[][0x80] =
{
    INCBIN_U8("graphics/door_anims/01/0.4bpp"),
    INCBIN_U8("graphics/door_anims/01/1.4bpp"),
    INCBIN_U8("graphics/door_anims/01/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_02[][0x80] =
{
    INCBIN_U8("graphics/door_anims/02/0.4bpp"),
    INCBIN_U8("graphics/door_anims/02/1.4bpp"),
    INCBIN_U8("graphics/door_anims/02/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_03[][0x80] =
{
    INCBIN_U8("graphics/door_anims/03/0.4bpp"),
    INCBIN_U8("graphics/door_anims/03/1.4bpp"),
    INCBIN_U8("graphics/door_anims/03/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_04[][0x80] =
{
    INCBIN_U8("graphics/door_anims/04/0.4bpp"),
    INCBIN_U8("graphics/door_anims/04/1.4bpp"),
    INCBIN_U8("graphics/door_anims/04/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_05[][0x80] =
{
    INCBIN_U8("graphics/door_anims/05/0.4bpp"),
    INCBIN_U8("graphics/door_anims/05/1.4bpp"),
    INCBIN_U8("graphics/door_anims/05/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_06[][0x80] =
{
    INCBIN_U8("graphics/door_anims/06/0.4bpp"),
    INCBIN_U8("graphics/door_anims/06/1.4bpp"),
    INCBIN_U8("graphics/door_anims/06/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_07[][0x80] =
{
    INCBIN_U8("graphics/door_anims/07/0.4bpp"),
    INCBIN_U8("graphics/door_anims/07/1.4bpp"),
    INCBIN_U8("graphics/door_anims/07/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_08[][0x80] =
{
    INCBIN_U8("graphics/door_anims/08/0.4bpp"),
    INCBIN_U8("graphics/door_anims/08/1.4bpp"),
    INCBIN_U8("graphics/door_anims/08/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_09[][0x80] =
{
    INCBIN_U8("graphics/door_anims/09/0.4bpp"),
    INCBIN_U8("graphics/door_anims/09/1.4bpp"),
    INCBIN_U8("graphics/door_anims/09/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_10[][0x80] =
{
    INCBIN_U8("graphics/door_anims/10/0.4bpp"),
    INCBIN_U8("graphics/door_anims/10/1.4bpp"),
    INCBIN_U8("graphics/door_anims/10/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_11[][0x80] =
{
    INCBIN_U8("graphics/door_anims/11/0.4bpp"),
    INCBIN_U8("graphics/door_anims/11/1.4bpp"),
    INCBIN_U8("graphics/door_anims/11/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_12[][0x80] =
{
    INCBIN_U8("graphics/door_anims/12/0.4bpp"),
    INCBIN_U8("graphics/door_anims/12/1.4bpp"),
    INCBIN_U8("graphics/door_anims/12/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_13[][0x80] =
{
    INCBIN_U8("graphics/door_anims/13/0.4bpp"),
    INCBIN_U8("graphics/door_anims/13/1.4bpp"),
    INCBIN_U8("graphics/door_anims/13/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_14[][0x80] =
{
    INCBIN_U8("graphics/door_anims/14/0.4bpp"),
    INCBIN_U8("graphics/door_anims/14/1.4bpp"),
    INCBIN_U8("graphics/door_anims/14/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_15[][0x80] =
{
    INCBIN_U8("graphics/door_anims/15/0.4bpp"),
    INCBIN_U8("graphics/door_anims/15/1.4bpp"),
    INCBIN_U8("graphics/door_anims/15/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_16[][0x80] =
{
    INCBIN_U8("graphics/door_anims/16/0.4bpp"),
    INCBIN_U8("graphics/door_anims/16/1.4bpp"),
    INCBIN_U8("graphics/door_anims/16/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_24[][0x100] =
{
    INCBIN_U8("graphics/door_anims/24/0.4bpp"),
    INCBIN_U8("graphics/door_anims/24/1.4bpp"),
    INCBIN_U8("graphics/door_anims/24/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_25[][0x100] =
{
    INCBIN_U8("graphics/door_anims/25/0.4bpp"),
    INCBIN_U8("graphics/door_anims/25/1.4bpp"),
    INCBIN_U8("graphics/door_anims/25/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_26[][0x100] =
{
    INCBIN_U8("graphics/door_anims/26/0.4bpp"),
    INCBIN_U8("graphics/door_anims/26/1.4bpp"),
    INCBIN_U8("graphics/door_anims/26/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_27[][0x100] =
{
    INCBIN_U8("graphics/door_anims/27/0.4bpp"),
    INCBIN_U8("graphics/door_anims/27/1.4bpp"),
    INCBIN_U8("graphics/door_anims/27/2.4bpp"),
};

asm(".space 0x3D00");

static const u8 sDoorAnimTiles_UnusedTops[][0x40] =
{
    INCBIN_U8("graphics/door_anims/unused_8359588/0_top.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359588/1_top.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359588/2_top.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359588/3_top.4bpp"),
};

asm(".space 256");

static const u8 sDoorAnimTiles_UnusedUpperCenters[][0x40] =
{
    INCBIN_U8("graphics/door_anims/unused_8359788/0_upper_center.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359788/1_upper_center.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359788/2_upper_center.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359788/3_upper_center.4bpp"),
};

asm(".space 256");

static const u8 sDoorAnimTiles_UnusedLowerCenters[][0x40] =
{
    INCBIN_U8("graphics/door_anims/unused_8359988/0_lower_center.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359988/1_lower_center.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359988/2_lower_center.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359988/3_lower_center.4bpp"),
};

asm(".space 256");

static const u8 sDoorAnimTiles_UnusedBottoms[][0x40] =
{
    INCBIN_U8("graphics/door_anims/unused_8359B88/0_bottom.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359B88/1_bottom.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359B88/2_bottom.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_8359B88/3_bottom.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_28[][0x100] =
{
    INCBIN_U8("graphics/door_anims/28/0.4bpp"),
    INCBIN_U8("graphics/door_anims/28/1.4bpp"),
    INCBIN_U8("graphics/door_anims/28/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_17[][0x80] =
{
    INCBIN_U8("graphics/door_anims/17/0.4bpp"),
    INCBIN_U8("graphics/door_anims/17/1.4bpp"),
    INCBIN_U8("graphics/door_anims/17/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_18[][0x80] =
{
    INCBIN_U8("graphics/door_anims/18/0.4bpp"),
    INCBIN_U8("graphics/door_anims/18/1.4bpp"),
    INCBIN_U8("graphics/door_anims/18/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_19[][0x80] =
{
    INCBIN_U8("graphics/door_anims/19/0.4bpp"),
    INCBIN_U8("graphics/door_anims/19/1.4bpp"),
    INCBIN_U8("graphics/door_anims/19/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_20[][0x80] =
{
    INCBIN_U8("graphics/door_anims/20/0.4bpp"),
    INCBIN_U8("graphics/door_anims/20/1.4bpp"),
    INCBIN_U8("graphics/door_anims/20/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_21[][0x80] =
{
    INCBIN_U8("graphics/door_anims/21/0.4bpp"),
    INCBIN_U8("graphics/door_anims/21/1.4bpp"),
    INCBIN_U8("graphics/door_anims/21/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_22[][0x80] =
{
    INCBIN_U8("graphics/door_anims/22/0.4bpp"),
    INCBIN_U8("graphics/door_anims/22/1.4bpp"),
    INCBIN_U8("graphics/door_anims/22/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_23[][0x80] =
{
    INCBIN_U8("graphics/door_anims/23/0.4bpp"),
    INCBIN_U8("graphics/door_anims/23/1.4bpp"),
    INCBIN_U8("graphics/door_anims/23/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_29[][0x100] =
{
    INCBIN_U8("graphics/door_anims/29/0.4bpp"),
    INCBIN_U8("graphics/door_anims/29/1.4bpp"),
    INCBIN_U8("graphics/door_anims/29/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_30[][0x100] =
{
    INCBIN_U8("graphics/door_anims/30/0.4bpp"),
    INCBIN_U8("graphics/door_anims/30/1.4bpp"),
    INCBIN_U8("graphics/door_anims/30/2.4bpp"),
};

asm(".space 32");

static const u8 sDoorAnimTiles_31[][0x100] =
{
    INCBIN_U8("graphics/door_anims/31/0.4bpp"),
    INCBIN_U8("graphics/door_anims/31/1.4bpp"),
    INCBIN_U8("graphics/door_anims/31/2.4bpp"),
};

asm(".space 32");

static const struct DoorAnimFrame sDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x80},
    {4, 0x100},
    {0, 0},
};

static const struct DoorAnimFrame sBigDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x100},
    {4, 0x200},
    {0, 0},
};

static const struct DoorAnimFrame sDoorCloseAnimFrames[] =
{
    {4, 0x100},
    {4, 0x80},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const struct DoorAnimFrame sBigDoorCloseAnimFrames[]={
    {4, 0X200},
    {4, 0X100},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const u8 sDoorAnimPalettes_835B4D8[] = {2, 2, 2, 2, 2, 2, 2, 2}; // door 00
static const u8 sDoorAnimPalettes_835B4E0[] = {3, 3, 3, 3, 3, 3, 3, 3}; // door 01
static const u8 sDoorAnimPalettes_835B4E8[] = {3, 3, 3, 3, 3, 3, 3, 3}; // door 02
static const u8 sDoorAnimPalettes_835B4F0[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 03
static const u8 sDoorAnimPalettes_835B4F8[] = {10, 10, 10, 10, 10, 10, 10, 10}; // door 04
static const u8 sDoorAnimPalettes_835B500[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 05
static const u8 sDoorAnimPalettes_835B508[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 06
static const u8 sDoorAnimPalettes_835B510[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 07
static const u8 sDoorAnimPalettes_835B518[] = {3, 3, 3, 3, 3, 3, 3, 3}; // door 08
static const u8 sDoorAnimPalettes_835B520[] = {12, 12, 12, 12, 12, 12, 12, 12}; // door 09
static const u8 sDoorAnimPalettes_835B528[] = {9, 9, 9, 9, 9, 9, 9, 9}; // door 10
static const u8 sDoorAnimPalettes_835B530[] = {9, 9, 9, 9, 9, 9, 9, 9}; // door 11
static const u8 sDoorAnimPalettes_835B538[] = {9, 9, 9, 9, 9, 9, 9, 9}; // door 12
static const u8 sDoorAnimPalettes_835B540[] = {3, 3, 3, 3, 3, 3, 3, 3}; // door 13
static const u8 sDoorAnimPalettes_835B548[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 14
static const u8 sDoorAnimPalettes_835B550[] = {9, 9, 9, 9, 9, 9, 9, 9}; // door 15
static const u8 sDoorAnimPalettes_835B558[] = {3, 3, 3, 3, 3, 3, 3, 3}; // door 16
static const u8 sDoorAnimPalettes_835B560[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 24
static const u8 sDoorAnimPalettes_835B568[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 25
static const u8 sDoorAnimPalettes_835B570[] = {12, 12, 2, 2, 2, 2, 2, 2}; // door 26
static const u8 sDoorAnimPalettes_835B578[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 27
static const u8 sDoorAnimPalettes_835B580[] = {8, 8, 2, 2, 2, 2, 2, 2}; // door 28
static const u8 sDoorAnimPalettes_835B588[] = {5, 5, 5, 5, 5, 5, 5, 5}; // door 17
static const u8 sDoorAnimPalettes_835B590[] = {3, 3, 3, 3, 3, 3, 3, 3}; // door 18
static const u8 sDoorAnimPalettes_835B598[] = {3, 3, 3, 3, 3, 3, 3, 3}; // door 19
static const u8 sDoorAnimPalettes_835B5A0[] = {5, 5, 5, 5, 5, 5, 5, 5}; // door 20
static const u8 sDoorAnimPalettes_835B5A8[] = {3, 3, 3, 3, 3, 3, 3, 3}; // door 21
static const u8 sDoorAnimPalettes_835B5B0[] = {10, 10, 10, 10, 10, 10, 10, 10}; // door 22
static const u8 sDoorAnimPalettes_835B5B8[] = {5, 5, 5, 5, 5, 5, 5, 5}; // door 23
static const u8 sDoorAnimPalettes_835B5C0[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 29
static const u8 sDoorAnimPalettes_835B5C8[] = {8, 8, 2, 2, 2, 2, 2, 2}; // door 30
static const u8 sDoorAnimPalettes_835B5D0[] = {11, 11, 2, 2, 2, 2, 2, 2}; // door 31

static const struct DoorGraphics gDoorAnimGraphicsTable[]={
    {0X03d, 0, 0, sDoorAnimTiles_00, sDoorAnimPalettes_835B4D8}, // door 00
    {0X062, 1, 0, sDoorAnimTiles_01, sDoorAnimPalettes_835B4E0}, // door 01
    {0X15b, 1, 0, sDoorAnimTiles_02, sDoorAnimPalettes_835B4E8}, // door 02
    {0X2a3, 0, 0, sDoorAnimTiles_03, sDoorAnimPalettes_835B4F0}, // door 03
    {0X2ac, 0, 0, sDoorAnimTiles_04, sDoorAnimPalettes_835B4F8}, // door 04
    {0X299, 0, 0, sDoorAnimTiles_05, sDoorAnimPalettes_835B500}, // door 05
    {0X2ce, 0, 0, sDoorAnimTiles_06, sDoorAnimPalettes_835B508}, // door 06
    {0X284, 0, 0, sDoorAnimTiles_07, sDoorAnimPalettes_835B510}, // door 07
    {0X2bc, 1, 0, sDoorAnimTiles_08, sDoorAnimPalettes_835B518}, // door 08
    {0X298, 0, 0, sDoorAnimTiles_09, sDoorAnimPalettes_835B520}, // door 09
    {0X2a2, 0, 0, sDoorAnimTiles_10, sDoorAnimPalettes_835B528}, // door 10
    {0X29e, 0, 0, sDoorAnimTiles_11, sDoorAnimPalettes_835B530}, // door 11
    {0X2e1, 0, 0, sDoorAnimTiles_12, sDoorAnimPalettes_835B538}, // door 12
    {0X294, 1, 0, sDoorAnimTiles_13, sDoorAnimPalettes_835B540}, // door 13
    {0X2bf, 0, 0, sDoorAnimTiles_14, sDoorAnimPalettes_835B548}, // door 14
    {0X2d2, 1, 0, sDoorAnimTiles_15, sDoorAnimPalettes_835B550}, // door 15
    {0X2ad, 0, 0, sDoorAnimTiles_16, sDoorAnimPalettes_835B558}, // door 16
    {0X297, 0, 0, sDoorAnimTiles_17, sDoorAnimPalettes_835B588}, // door 17
    {0X29b, 1, 0, sDoorAnimTiles_18, sDoorAnimPalettes_835B590}, // door 18
    {0X2eb, 0, 0, sDoorAnimTiles_19, sDoorAnimPalettes_835B598}, // door 19
    {0X29a, 0, 0, sDoorAnimTiles_20, sDoorAnimPalettes_835B5A0}, // door 20
    {0X2b9, 0, 0, sDoorAnimTiles_21, sDoorAnimPalettes_835B5A8}, // door 21
    {0X2af, 0, 0, sDoorAnimTiles_22, sDoorAnimPalettes_835B5B0}, // door 22
    {0X30c, 0, 0, sDoorAnimTiles_23, sDoorAnimPalettes_835B5B8}, // door 23
    {0X28d, 1, 1, sDoorAnimTiles_24, sDoorAnimPalettes_835B560}, // door 24
    {0X2de, 1, 1, sDoorAnimTiles_25, sDoorAnimPalettes_835B568}, // door 25
    {0X2ab, 1, 1, sDoorAnimTiles_26, sDoorAnimPalettes_835B570}, // door 26
    {0X281, 0, 1, sDoorAnimTiles_27, sDoorAnimPalettes_835B578}, // door 27
    {0X2e2, 1, 1, sDoorAnimTiles_28, sDoorAnimPalettes_835B580}, // door 28
    {0X296, 1, 1, sDoorAnimTiles_29, sDoorAnimPalettes_835B5C0}, // door 29
    {0X2c3, 1, 1, sDoorAnimTiles_30, sDoorAnimPalettes_835B5C8}, // door 30
    {0X356, 1, 1, sDoorAnimTiles_31, sDoorAnimPalettes_835B5D0}, // door 31
    {0, 0, 0, NULL, NULL},
};

static void DrawDoor(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame, int x, int y);
static void DrawClosedDoorTiles(const struct DoorGraphics *gfx, int x, int y);
static void CopyDoorTilesToVram(const void *src);
static void DrawCurrentDoorAnimFrame(const struct DoorGraphics *gfx, int x, int y, const u8 *pal);
static void DoorBuildBlockdef(u16 *a, u16 b, const u8 *c);
static void Task_AnimateDoor(u8 taskId);
static bool32 DrawNextFrame(const struct DoorGraphics *gfx, struct DoorAnimFrame *frames, s16 *taskData);
static const struct DoorGraphics *GetDoorGraphics(const struct DoorGraphics *gfx, u16 metatileNum);
static s8 StartDoorAnimationTask(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frames, u32 x, u32 y);
static void DrawClosedDoor(const struct DoorGraphics *gfx, int x, int y);
static void DrawOpenedDoor(const struct DoorGraphics *gfx, u32 x, u32 y);
static const struct DoorAnimFrame *GetLastDoorFrame(const struct DoorAnimFrame *frame, const void *unused);
static s8 StartDoorOpenAnimation(const struct DoorGraphics *gfx, u32 x, u32 y);
static s8 StartDoorCloseAnimation(const struct DoorGraphics *gfx, u32 x, u32 y);
static s8 CurMapdataGetDoorX2At(const struct DoorGraphics *gfx, u32 x, u32 y);


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
        DoorBuildBlockdef(arr, 0x3F8, pal);
    else{
        DoorBuildBlockdef(arr, 0x3F8, pal);
        sub_805A91C(x, y - 1, arr);
        DoorBuildBlockdef(arr, 0x3FC, pal + 4);
    }
    sub_805A91C(x, y, arr);
}

static void DoorBuildBlockdef(u16 *a, u16 b, const u8 *c)
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

    if (DrawNextFrame(gfx, frames, taskData) == FALSE)
        DestroyTask(taskId);
}

static bool32 DrawNextFrame(const struct DoorGraphics *gfx, struct DoorAnimFrame *frames, s16 *taskData)
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
        frame = gfx->size == 0 ? sDoorOpenAnimFrames : sBigDoorOpenAnimFrames;
        DrawDoor(gfx, GetLastDoorFrame(frame, frame), x, y);
    }
}


static const struct DoorAnimFrame *GetLastDoorFrame(const struct DoorAnimFrame *frame, const void *unused)
{
    while (frame->time != 0)
        frame++;
    return frame - 1;
}
 

static s8 StartDoorOpenAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else{
        if(gfx->size == 0)
            return StartDoorAnimationTask(gfx, sDoorOpenAnimFrames, x, y);
        else 
            return StartDoorAnimationTask(gfx, sBigDoorOpenAnimFrames, x, y);
    }
}
 

static s8 StartDoorCloseAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else{
        if(gfx->size == 0)
            return StartDoorAnimationTask(gfx, sDoorCloseAnimFrames, x, y);
        else 
            return StartDoorAnimationTask(gfx, sBigDoorCloseAnimFrames, x, y);
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
        return StartDoorCloseAnimation(gDoorAnimGraphicsTable, x, y);
}


s8 FieldAnimateDoorOpen(u32 x, u32 y)
{
    if (!MetatileBehavior_IsWarpDoor_2(MapGridGetMetatileBehaviorAt((s16)x, (s16)y)))
        return -1;
    else
        return StartDoorOpenAnimation(gDoorAnimGraphicsTable, x, y);
}

bool8 FieldIsDoorAnimationRunning(void)
{
    return FuncIsActiveTask(Task_AnimateDoor);
}
    
u32 GetDoorSoundEffect(u32 x, u32 y)
{
    int sound = CurMapdataGetDoorX2At(gDoorAnimGraphicsTable, x, y);
    if (sound == 0)
        return SE_W253;
    else
        return SE_JIDO_DOA;
}

static s8 CurMapdataGetDoorX2At(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else
        return gfx->sound;
}
