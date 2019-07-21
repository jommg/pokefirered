	.section .rodata

	.align 2
gDoorOpenAnimFrames:: @ 835B488
	.incbin "baserom.gba", 0x35B488, 0x14

gBigDoorOpenAnimFrames:: @ 835B49C
	.incbin "baserom.gba", 0x35B49C, 0x14

gDoorCloseAnimFrames:: @ 835B4B0
	.incbin "baserom.gba", 0x35B4B0, 0x14

gBigDoorCloseAnimFrames:: @ 835B4C4
	.incbin "baserom.gba", 0x35B4C4, 0x114

gDoorAnimGraphicsTable:: @ 835B5D8
	.incbin "baserom.gba", 0x35B5D8, 0x18C
