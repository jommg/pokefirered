LavenderTown_House2_MapScripts:: @ 816B265
	.byte 0

LavenderTown_House2_EventScript_16B266:: @ 816B266
	lock
	faceplayer
	loadword 0, gUnknown_8193A4B
	callstd 5
	compare_var_to_value VAR_RESULT, 1
	goto_if 1, EventScript_16B287
	compare_var_to_value VAR_RESULT, 0
	goto_if 1, EventScript_16B2AA
	end

EventScript_16B287:: @ 816B287
	loadword 0, gUnknown_8193AA6
	callstd 4
	special sub_80BF8FC
	waitstate
	compare_var_to_value VAR_0x8004, 6
	goto_if 0, EventScript_16B2B4
	compare_var_to_value VAR_0x8004, 6
	goto_if 4, EventScript_16B2AA
	end

EventScript_16B2AA:: @ 816B2AA
	loadword 0, gUnknown_8193BD4
	callstd 4
	release
	end

EventScript_16B2B4:: @ 816B2B4
	specialvar VAR_RESULT, sub_80CAD54
	compare_var_to_value VAR_RESULT, 412
	goto_if 1, EventScript_16B307
	special TV_CopyNicknameToStringVar1AndEnsureTerminated
	special TV_CheckMonOTIDEqualsPlayerID
	compare_var_to_value VAR_RESULT, 1
	goto_if 1, EventScript_16B311
	specialvar VAR_RESULT, sub_80CAD7C
	special TV_CopyNicknameToStringVar1AndEnsureTerminated
	compare_var_to_value VAR_RESULT, 1
	goto_if 1, EventScript_16B311
	loadword 0, gUnknown_8193AD2
	callstd 5
	compare_var_to_value VAR_RESULT, 1
	goto_if 1, EventScript_16B31B
	compare_var_to_value VAR_RESULT, 0
	goto_if 1, EventScript_16B2AA
	end

EventScript_16B307:: @ 816B307
	loadword 0, gUnknown_8193CC4
	callstd 4
	release
	end

EventScript_16B311:: @ 816B311
	loadword 0, gUnknown_8193C82
	callstd 4
	release
	end

EventScript_16B31B:: @ 816B31B
	loadword 0, gUnknown_8193B36
	callstd 4
	call EventScript_1A74EB
	specialvar VAR_RESULT, sub_80CBFA0
	special TV_CopyNicknameToStringVar1AndEnsureTerminated
	compare_var_to_value VAR_RESULT, 1
	goto_if 1, EventScript_16B345
	loadword 0, gUnknown_8193BF0
	callstd 4
	release
	end

EventScript_16B345:: @ 816B345
	loadword 0, gUnknown_8193B66
	callstd 4
	release
	end