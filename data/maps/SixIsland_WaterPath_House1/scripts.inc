SixIsland_WaterPath_House1_MapScripts:: @ 817206C
	.byte 0

SixIsland_WaterPath_House1_EventScript_17206D:: @ 817206D
	lock
	faceplayer
	special sub_8110AB4
	compare_var_to_value VAR_RESULT, 2
	goto_if 1, EventScript_1A7AE0
	special sub_8112364
	setvar VAR_0x8004, 214
	specialvar VAR_RESULT, sub_80CC48C
	compare_var_to_value VAR_RESULT, 0
	goto_if 1, EventScript_1720E5
	special sub_80A0918
	loadword 0, gUnknown_81A4A3F
	callstd 4
	special sub_80BF8FC
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	compare_var_to_value VAR_RESULT, 6
	goto_if 4, EventScript_1720EF
	special sub_80A0930
	compare_var_to_value VAR_RESULT, 1
	goto_if 1, EventScript_1720F1
	compare_var_to_value VAR_RESULT, 2
	goto_if 1, EventScript_1720FB
	compare_var_to_value VAR_RESULT, 3
	goto_if 1, EventScript_172121
	compare_var_to_value VAR_RESULT, 4
	goto_if 1, EventScript_17210E
	release
	end

EventScript_1720E5:: @ 81720E5
	loadword 0, gUnknown_81A49E9
	callstd 4
	release
	end

EventScript_1720EF:: @ 81720EF
	release
	end

EventScript_1720F1:: @ 81720F1
	loadword 0, gUnknown_81A4BEF
	callstd 4
	release
	end

EventScript_1720FB:: @ 81720FB
	checkflag FLAG_0x2D9
	goto_if 0, EventScript_172121
	loadword 0, gUnknown_81A4B7A
	callstd 4
	release
	end

EventScript_17210E:: @ 817210E
	checkflag FLAG_0x2D9
	goto_if 0, EventScript_172121
	loadword 0, gUnknown_81A4B39
	callstd 4
	release
	end

EventScript_172121:: @ 8172121
	setflag FLAG_0x2D9
	loadword 0, gUnknown_81A4A88
	callstd 4
	setorcopyvar VAR_0x8000, 8
	setorcopyvar VAR_0x8001, 1
	callstd 0
	compare_var_to_value VAR_RESULT, 0
	goto_if 1, EventScript_17214D
	loadword 0, gUnknown_81A4AD9
	callstd 4
	release
	end

EventScript_17214D:: @ 817214D
	loadword 0, gUnknown_81A4C47
	callstd 4
	release
	end

SixIsland_WaterPath_House1_EventScript_172157:: @ 8172157
	lockall
	checkflag FLAG_0x2D9
	goto_if 1, EventScript_17216B
	loadword 0, gUnknown_81A4CB9
	callstd 4
	releaseall
	end

EventScript_17216B:: @ 817216B
	special sub_80A0918
	loadword 0, gUnknown_81A4C6E
	callstd 4
	releaseall
	end