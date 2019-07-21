#ifndef GUARD_FIELDDOOR_H
#define GUARD_FIELDDOOR_H

struct DoorGraphics
{
   /*0x00*/ u16 metatileNum;
   /*0x02*/ u8 sound;
   /*0x03*/ u8 size;
   /*0x04*/ const void *tiles;
   /*0x08*/ const void *palette;
};

struct DoorAnimFrame
{
    u8 time;
    u16 offset;
};

void FieldSetDoorOpened(u32, u32);
void FieldSetDoorClosed(u32, u32);
s8 FieldAnimateDoorClose(u32, u32);
s8 FieldAnimateDoorOpen(u32, u32);
bool8 FieldIsDoorAnimationRunning(void);
u32 GetDoorSoundEffect(u32 x, u32 y);

#endif
