Route2_House_MapScripts:: @ 816F5F8
	.byte 0

Route2_House_EventScript_16F5F9:: @ 816F5F9
	loadword 0, gUnknown_819D5E7
	callstd 2
	end

Route2_House_EventScript_16F602:: @ 816F602
	lock
	faceplayer
	setvar VAR_0x8008, 0
	call EventScript_1A8CAD
	checkflag FLAG_0x248
	goto_if 1, EventScript_16F674
	loadword 0, gUnknown_81A597B
	callstd 5
	compare_var_to_value VAR_RESULT, 0
	goto_if 1, EventScript_16F65C
	call EventScript_1A8CBD
	compare_var_to_value VAR_0x8004, 6
	goto_if 4, EventScript_16F65C
	call EventScript_1A8CC9
	compare_var_to_var VAR_RESULT, VAR_0x8009
	goto_if 5, EventScript_16F666
	call EventScript_1A8CD9
	loadword 0, gUnknown_81A59DA
	callstd 4
	setflag FLAG_0x248
	release
	end

EventScript_16F65C:: @ 816F65C
	loadword 0, gUnknown_81A59B6
	callstd 4
	release
	end

EventScript_16F666:: @ 816F666
	getspeciesname 0, 32777
	loadword 0, gUnknown_81A59C6
	callstd 4
	release
	end

EventScript_16F674:: @ 816F674
	loadword 0, gUnknown_81A59E7
	callstd 4
	release
	end