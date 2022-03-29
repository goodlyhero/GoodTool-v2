--Geterates code to register natives and bind them (now register only)

ntable ={{0x6F3B29D0, "Deg2Rad", "(R)R"},
{0x6F3B29F0, "Rad2Deg", "(R)R"},
{0x6F3B2A10, "Sin", "(R)R"},
{0x6F3B2A30, "Cos", "(R)R"},
{0x6F3B2A50, "Tan", "(R)R"},
{0x6F3B2A70, "Asin", "(R)R"},
{0x6F3B2AB0, "Acos", "(R)R"},
{0x6F3B2AF0, "Atan", "(R)R"},
{0x6F3B2B10, "Atan2", "(RR)R"},
{0x6F3B2BA0, "SquareRoot", "(R)R"},
{0x6F3B2C00, "Pow", "(RR)R"},
{0x6F3B2CC0, "I2R", "(I)R"},
{0x6F3B2CE0, "R2I", "(R)I"},
{0x6F3BAAA0, "I2S", "(I)S"},
{0x6F3BAAF0, "R2S", "(R)S"},
{0x6F3BAB40, "R2SW", "(RII)S"},
{0x6F3B2D10, "S2I", "(S)I"},
{0x6F3B2D50, "S2R", "(S)R"},
{0x6F3B2D00, "GetHandleId", "(Hhandle)I"},
{0x6F3BABA0, "SubString", "(SII)S"},
{0x6F3BAC20, "StringLength", "(S)I"},
{0x6F3BAC40, "StringCase", "(SB)S"},
{0x6F3B2D30, "StringHash", "(S)I"},
{0x6F3BACF0, "GetLocalizedString", "(S)S"},
{0x6F3B2D80, "GetLocalizedHotkey", "(S)I"},
{0x6F3B2600, "ConvertRace", "(I)Hrace"},
{0x6F3B2610, "ConvertAllianceType", "(I)Halliancetype"},
{0x6F3B2620, "ConvertRacePref", "(I)Hracepreference"},
{0x6F3B2630, "ConvertIGameState", "(I)Higamestate"},
{0x6F3B2640, "ConvertFGameState", "(I)Hfgamestate"},
{0x6F3B2650, "ConvertPlayerState", "(I)Hplayerstate"},
{0x6F3B2660, "ConvertPlayerScore", "(I)Hplayerscore"},
{0x6F3B2740, "ConvertStartLocPrio", "(I)Hstartlocprio"},
{0x6F3B2670, "ConvertPlayerGameResult", "(I)Hplayergameresult"},
{0x6F3B2680, "ConvertUnitState", "(I)Hunitstate"},
{0x6F3B2690, "ConvertAIDifficulty", "(I)Haidifficulty"},
{0x6F3B26A0, "ConvertGameEvent", "(I)Hgameevent"},
{0x6F3B26B0, "ConvertPlayerEvent", "(I)Hplayerevent"},
{0x6F3B26C0, "ConvertPlayerUnitEvent", "(I)Hplayerunitevent"},
{0x6F3B26D0, "ConvertUnitEvent", "(I)Hunitevent"},
{0x6F3B26E0, "ConvertWidgetEvent", "(I)Hwidgetevent"},
{0x6F3B26F0, "ConvertDialogEvent", "(I)Hdialogevent"},
{0x6F3B2700, "ConvertLimitOp", "(I)Hlimitop"},
{0x6F3B2710, "ConvertUnitType", "(I)Hunittype"},
{0x6F3B2720, "ConvertGameSpeed", "(I)Hgamespeed"},
{0x6F3B2730, "ConvertPlacement", "(I)Hplacement"},
{0x6F3B2750, "ConvertGameDifficulty", "(I)Hgamedifficulty"},
{0x6F3B2760, "ConvertGameType", "(I)Hgametype"},
{0x6F3B2770, "ConvertMapFlag", "(I)Hmapflag"},
{0x6F3B2780, "ConvertMapVisibility", "(I)Hmapvisibility"},
{0x6F3B2790, "ConvertMapSetting", "(I)Hmapsetting"},
{0x6F3B27A0, "ConvertMapDensity", "(I)Hmapdensity"},
{0x6F3B27B0, "ConvertMapControl", "(I)Hmapcontrol"},
{0x6F3B27C0, "ConvertPlayerColor", "(I)Hplayercolor"},
{0x6F3B27D0, "ConvertPlayerSlotState", "(I)Hplayerslotstate"},
{0x6F3B27E0, "ConvertVolumeGroup", "(I)Hvolumegroup"},
{0x6F3B27F0, "ConvertCameraField", "(I)Hcamerafield"},
{0x6F3B2810, "ConvertBlendMode", "(I)Hblendmode"},
{0x6F3B2800, "ConvertRarityControl", "(I)Hraritycontrol"},
{0x6F3B2820, "ConvertTexMapFlags", "(I)Htexmapflags"},
{0x6F3B2830, "ConvertFogState", "(I)Hfogstate"},
{0x6F3B2840, "ConvertEffectType", "(I)Heffecttype"},
{0x6F3B2850, "ConvertVersion", "(I)Hversion"},
{0x6F3B2860, "ConvertItemType", "(I)Hitemtype"},
{0x6F3B2870, "ConvertAttackType", "(I)Hattacktype"},
{0x6F3B2880, "ConvertDamageType", "(I)Hdamagetype"},
{0x6F3B2890, "ConvertWeaponType", "(I)Hweapontype"},
{0x6F3B28A0, "ConvertSoundType", "(I)Hsoundtype"},
{0x6F3B28B0, "ConvertPathingType", "(I)Hpathingtype"},
{0x6F3BADA0, "SetMapName", "(S)V"},
{0x6F3BADC0, "SetMapDescription", "(S)V"},
{0x6F3D4000, "SetTeams", "(I)V"},
{0x6F3BADF0, "SetPlayers", "(I)V"},
{0x6F3BAE10, "SetGameTypeSupported", "(HgametypeB)V"},
{0x6F3BAE70, "SetMapFlag", "(HmapflagB)V"},
{0x6F3BAED0, "SetGameSpeed", "(Hgamespeed)V"},
{0x6F3BAEF0, "SetGamePlacement", "(Hplacement)V"},
{0x6F3BAF10, "SetGameDifficulty", "(Hgamedifficulty)V"},
{0x6F3BAF30, "SetResourceDensity", "(Hmapdensity)V"},
{0x6F3BAF50, "SetCreatureDensity", "(Hmapdensity)V"},
{0x6F3BAF70, "DefineStartLocation", "(IRR)V"},
{0x6F3C0EA0, "DefineStartLocationLoc", "(IHlocation)V"},
{0x6F3BAF90, "SetStartLocPrioCount", "(II)V"},
{0x6F3BAFC0, "SetStartLocPrio", "(IIIHstartlocprio)V"},
{0x6F3BB000, "GetStartLocPrioSlot", "(II)I"},
{0x6F3BB030, "GetStartLocPrio", "(II)Hstartlocprio"},
{0x6F3BADE0, "GetTeams", "()I"},
{0x6F3BAE00, "GetPlayers", "()I"},
{0x6F3BAE40, "IsGameTypeSupported", "(Hgametype)B"},
{0x6F3BAEA0, "IsMapFlagSet", "(Hmapflag)B"},
{0x6F3BAE60, "GetGameTypeSelected", "()Hgametype"},
{0x6F3BAF00, "GetGamePlacement", "()Hplacement"},
{0x6F3BAEC0, "GetGameSpeed", "()Hgamespeed"},
{0x6F3BAF20, "GetGameDifficulty", "()Hgamedifficulty"},
{0x6F3BAF40, "GetResourceDensity", "()Hmapdensity"},
{0x6F3BAF60, "GetCreatureDensity", "()Hmapdensity"},
{0x6F3BB060, "GetStartLocationX", "(I)R"},
{0x6F3BB080, "GetStartLocationY", "(I)R"},
{0x6F3D04B0, "GetStartLocationLoc", "(I)Hlocation"},
{0x6F3C0EE0, "SetPlayerTeam", "(HplayerI)V"},
{0x6F3C0F80, "SetPlayerStartLocation", "(HplayerI)V"},
{0x6F3C0FA0, "ForcePlayerStartLocation", "(HplayerI)V"},
{0x6F3C1050, "SetPlayerAlliance", "(HplayerHplayerHalliancetypeB)V"},
{0x6F3C10E0, "SetPlayerTaxRate", "(HplayerHplayerHplayerstateI)V"},
{0x6F3C11A0, "SetPlayerRacePreference", "(HplayerHracepreference)V"},
{0x6F3C11D0, "SetPlayerRaceSelectable", "(HplayerB)V"},
{0x6F3C1200, "SetPlayerController", "(HplayerHmapcontrol)V"},
{0x6F3C1220, "SetPlayerColor", "(HplayerHplayercolor)V"},
{0x6F3C9800, "SetPlayerOnScoreScreen", "(HplayerB)V"},
{0x6F3C0F10, "SetPlayerName", "(HplayerS)V"},
{0x6F3C0F40, "GetPlayerTeam", "(Hplayer)I"},
{0x6F3C0F60, "GetPlayerName", "(Hplayer)S"},
{0x6F3C0FD0, "GetPlayerStartLocation", "(Hplayer)I"},
{0x6F3C0FF0, "GetPlayerStartLocationX", "(Hplayer)R"},
{0x6F3C1020, "GetPlayerStartLocationY", "(Hplayer)R"},
{0x6F3C1240, "GetPlayerColor", "(Hplayer)Hplayercolor"},
{0x6F3C1290, "GetPlayerSelectable", "(Hplayer)B"},
{0x6F3C12B0, "GetPlayerController", "(Hplayer)Hmapcontrol"},
{0x6F3C12D0, "GetPlayerSlotState", "(Hplayer)Hplayerslotstate"},
{0x6F3C1150, "GetPlayerTaxRate", "(HplayerHplayerHplayerstate)I"},
{0x6F3C1260, "IsPlayerRacePrefSet", "(HplayerHracepreference)B"},
{0x6F3D03B0, "Location", "(RR)Hlocation"},
{0x6F3C0DD0, "RemoveLocation", "(Hlocation)V"},
{0x6F3C0DF0, "MoveLocation", "(HlocationRR)V"},
{0x6F3C0E10, "GetLocationX", "(Hlocation)R"},
{0x6F3C0E30, "GetLocationY", "(Hlocation)R"},
{0x6F3C0E50, "GetLocationZ", "(Hlocation)R"},
{0x6F3D0500, "CreateTimer", "()Htimer"},
{0x6F3C1350, "DestroyTimer", "(Htimer)V"},
{0x6F3C1370, "TimerStart", "(HtimerRBC)V"},
{0x6F3C13E0, "TimerGetTimeout", "(Htimer)R"},
{0x6F3C13A0, "TimerGetElapsed", "(Htimer)R"},
{0x6F3C13C0, "TimerGetRemaining", "(Htimer)R"},
{0x6F3C1400, "PauseTimer", "(Htimer)V"},
{0x6F3C1420, "ResumeTimer", "(Htimer)V"},
{0x6F3C1D80, "GetExpiredTimer", "()Htimer"},
{0x6F3BB0A0, "Condition", "(C)Hconditionfunc"},
{0x6F3C1440, "DestroyCondition", "(Hconditionfunc)V"},
{0x6F3BB140, "Filter", "(C)Hfilterfunc"},
{0x6F3C1470, "DestroyFilter", "(Hfilterfunc)V"},
{0x6F3C14A0, "DestroyBoolExpr", "(Hboolexpr)V"},
{0x6F3D05F0, "And", "(HboolexprHboolexpr)Hboolexpr"},
{0x6F3D0710, "Or", "(HboolexprHboolexpr)Hboolexpr"},
{0x6F3D0830, "Not", "(Hboolexpr)Hboolexpr"},
{0x6F3D0930, "CreateRegion", "()Hregion"},
{0x6F3C14C0, "RemoveRegion", "(Hregion)V"},
{0x6F3C14E0, "RegionAddRect", "(HregionHrect)V"},
{0x6F3C1530, "RegionClearRect", "(HregionHrect)V"},
{0x6F3C1580, "RegionAddCell", "(HregionRR)V"},
{0x6F3C15B0, "RegionAddCellAtLoc", "(HregionHlocation)V"},
{0x6F3C15F0, "RegionClearCell", "(HregionRR)V"},
{0x6F3C1620, "RegionClearCellAtLoc", "(HregionHlocation)V"},
{0x6F3C1660, "IsUnitInRegion", "(HregionHunit)B"},
{0x6F3C1690, "IsPointInRegion", "(HregionRR)B"},
{0x6F3C16B0, "IsLocationInRegion", "(HregionHlocation)B"},
{0x6F3D0A20, "Rect", "(RRRR)Hrect"},
{0x6F3D0BD0, "RectFromLoc", "(HlocationHlocation)Hrect"},
{0x6F3C16F0, "RemoveRect", "(Hrect)V"},
{0x6F3C1710, "SetRect", "(HrectRRRR)V"},
{0x6F3C17F0, "SetRectFromLoc", "(HrectHlocationHlocation)V"},
{0x6F3C18E0, "GetRectCenterX", "(Hrect)R"},
{0x6F3C1910, "GetRectCenterY", "(Hrect)R"},
{0x6F3C19C0, "MoveRectTo", "(HrectRR)V"},
{0x6F3C19F0, "MoveRectToLoc", "(HrectHlocation)V"},
{0x6F3C1940, "GetRectMinX", "(Hrect)R"},
{0x6F3C1960, "GetRectMinY", "(Hrect)R"},
{0x6F3C1980, "GetRectMaxX", "(Hrect)R"},
{0x6F3C19A0, "GetRectMaxY", "(Hrect)R"},
{0x6F3D0D60, "GetWorldBounds", "()Hrect"},
{0x6F3C1A30, "SetFogStateRect", "(HplayerHfogstateHrectB)V"},
{0x6F3C1AB0, "SetFogStateRadius", "(HplayerHfogstateRRRB)V"},
{0x6F3C1B20, "SetFogStateRadiusLoc", "(HplayerHfogstateHlocationRB)V"},
{0x6F3BB210, "FogMaskEnable", "(B)V"},
{0x6F3BB230, "IsFogMaskEnabled", "()B"},
{0x6F3BB1E0, "FogEnable", "(B)V"},
{0x6F3BB200, "IsFogEnabled", "()B"},
{0x6F3D0E70, "CreateFogModifierRect", "(HplayerHfogstateHrectBB)Hfogmodifier"},
{0x6F3D0F90, "CreateFogModifierRadius", "(HplayerHfogstateRRRBB)Hfogmodifier"},
{0x6F3D10F0, "CreateFogModifierRadiusLoc", "(HplayerHfogstateHlocationRBB)Hfogmodifier"},
{0x6F3C1BA0, "DestroyFogModifier", "(Hfogmodifier)V"},
{0x6F3C1BC0, "FogModifierStart", "(Hfogmodifier)V"},
{0x6F3C1BE0, "FogModifierStop", "(Hfogmodifier)V"},
{0x6F3D11F0, "CreateTrigger", "()Htrigger"},
{0x6F3C1C00, "DestroyTrigger", "(Htrigger)V"},
{0x6F3C1C20, "ResetTrigger", "(Htrigger)V"},
{0x6F3C1C40, "EnableTrigger", "(Htrigger)V"},
{0x6F3C1C60, "DisableTrigger", "(Htrigger)V"},
{0x6F3C1C80, "IsTriggerEnabled", "(Htrigger)B"},
{0x6F3C1CA0, "TriggerWaitOnSleeps", "(HtriggerB)V"},
{0x6F3C1CC0, "IsTriggerWaitOnSleeps", "(Htrigger)B"},
{0x6F3D12E0, "TriggerRegisterVariableEvent", "(HtriggerSHlimitopR)Hevent"},
{0x6F3D1420, "TriggerRegisterTimerEvent", "(HtriggerRB)Hevent"},
{0x6F3D1550, "TriggerRegisterTimerExpireEvent", "(HtriggerHtimer)Hevent"},
{0x6F3D1630, "TriggerRegisterGameStateEvent", "(HtriggerHgamestateHlimitopR)Hevent"},
{0x6F3C2020, "GetEventGameState", "()Hgamestate"},
{0x6F3D17A0, "TriggerRegisterDialogEvent", "(HtriggerHdialog)Hevent"},
{0x6F3D1880, "TriggerRegisterDialogButtonEvent", "(HtriggerHbutton)Hevent"},
{0x6F3C1DE0, "GetClickedButton", "()Hbutton"},
{0x6F3C1E30, "GetClickedDialog", "()Hdialog"},
{0x6F3C1EA0, "GetTournamentFinishSoonTimeRemaining", "()R"},
{0x6F3C1ED0, "GetTournamentFinishNowRule", "()I"},
{0x6F3C1F00, "GetTournamentFinishNowPlayer", "()Hplayer"},
{0x6F3C1F60, "GetTournamentScore", "(Hplayer)I"},
{0x6F3C1F80, "GetSaveBasicFilename", "()S"},
{0x6F3D1960, "TriggerRegisterGameEvent", "(HtriggerHgameevent)Hevent"},
{0x6F3BB3E0, "GetWinningPlayer", "()Hplayer"},
{0x6F3D1A60, "TriggerRegisterPlayerStateEvent", "(HtriggerHplayerHplayerstateHlimitopR)Hevent"},
{0x6F3C2050, "GetEventPlayerState", "()Hplayerstate"},
{0x6F3D1C90, "TriggerRegisterPlayerEvent", "(HtriggerHplayerHplayerevent)Hevent"},
{0x6F3D1DD0, "TriggerRegisterPlayerUnitEvent", "(HtriggerHplayerHplayeruniteventHboolexpr)Hevent"},
{0x6F3C20F0, "GetAttacker", "()Hunit"},
{0x6F3C2390, "GetRescuer", "()Hunit"},
{0x6F3BB410, "GetDyingUnit", "()Hunit"},
{0x6F3C23F0, "GetKillingUnit", "()Hunit"},
{0x6F3BB430, "GetDecayingUnit", "()Hunit"},
{0x6F3BB450, "GetConstructingStructure", "()Hunit"},
{0x6F3BB470, "GetCancelledStructure", "()Hunit"},
{0x6F3BB490, "GetConstructedStructure", "()Hunit"},
{0x6F3C2450, "GetTrainedUnitType", "()I"},
{0x6F3BB4D0, "GetResearchingUnit", "()Hunit"},
{0x6F3C2870, "GetResearched", "()I"},
{0x6F3C2500, "GetTrainedUnit", "()Hunit"},
{0x6F3C2560, "GetSellingUnit", "()Hunit"},
{0x6F3C2750, "GetSoldUnit", "()Hunit"},
{0x6F3C27B0, "GetBuyingUnit", "()Hunit"},
{0x6F3C25F0, "GetSoldItem", "()Hitem"},
{0x6F3C2680, "GetChangingUnit", "()Hunit"},
{0x6F3C26E0, "GetChangingUnitPrevOwner", "()Hplayer"},
{0x6F3BB4B0, "GetDetectedUnit", "()Hunit"},
{0x6F3BB530, "GetOrderedUnit", "()Hunit"},
{0x6F3BB590, "OrderId", "(S)I"},
{0x6F3BB5C0, "OrderId2String", "(I)S"},
{0x6F3BB5F0, "AbilityId", "(S)I"},
{0x6F3BB620, "AbilityId2String", "(I)S"},
{0x6F3BB650, "UnitId", "(S)I"},
{0x6F3BB680, "UnitId2String", "(I)S"},
{0x6F3BB6B0, "GetObjectName", "(I)S"},
{0x6F3C2C80, "GetIssuedOrderId", "()I"},
{0x6F3C2D00, "GetOrderPointX", "()R"},
{0x6F3C2D50, "GetOrderPointY", "()R"},
{0x6F3D1FF0, "GetOrderPointLoc", "()Hlocation"},
{0x6F3C2DE0, "GetOrderTarget", "()Hwidget"},
{0x6F3C2F10, "GetOrderTargetDestructable", "()Hdestructable"},
{0x6F3C3040, "GetOrderTargetItem", "()Hitem"},
{0x6F3C3170, "GetOrderTargetUnit", "()Hunit"},
{0x6F3C3470, "GetSpellAbilityUnit", "()Hunit"},
{0x6F3C32A0, "GetSpellAbilityId", "()I"},
{0x6F3C3380, "GetSpellAbility", "()Hability"},
{0x6F3D2090, "GetSpellTargetLoc", "()Hlocation"},
{0x6F3C3580, "GetSpellTargetX", "()R"},
{0x6F3C3670, "GetSpellTargetY", "()R"},
{0x6F3C3760, "GetSpellTargetDestructable", "()Hdestructable"},
{0x6F3C38F0, "GetSpellTargetItem", "()Hitem"},
{0x6F3C3A80, "GetSpellTargetUnit", "()Hunit"},
{0x6F3C2150, "GetLevelingUnit", "()Hunit"},
{0x6F3C21B0, "GetLearningUnit", "()Hunit"},
{0x6F3C2210, "GetLearnedSkill", "()I"},
{0x6F3C2250, "GetLearnedSkillLevel", "()I"},
{0x6F3C2290, "GetRevivableUnit", "()Hunit"},
{0x6F3C22F0, "GetRevivingUnit", "()Hunit"},
{0x6F3C28F0, "GetSummoningUnit", "()Hunit"},
{0x6F3C2950, "GetSummonedUnit", "()Hunit"},
{0x6F3C29A0, "GetTransportUnit", "()Hunit"},
{0x6F3C2A00, "GetLoadedUnit", "()Hunit"},
{0x6F3C2A60, "GetManipulatingUnit", "()Hunit"},
{0x6F3C2B00, "GetManipulatedItem", "()Hitem"},
{0x6F3D1BA0, "TriggerRegisterPlayerAllianceChange", "(HtriggerHplayerHalliancetype)Hevent"},
{0x6F3D1EF0, "TriggerRegisterPlayerChatEvent", "(HtriggerHplayerSB)Hevent"},
{0x6F3C20B0, "GetEventPlayerChatString", "()S"},
{0x6F3C2080, "GetEventPlayerChatStringMatched", "()S"},
{0x6F3D21B0, "TriggerRegisterUnitStateEvent", "(HtriggerHunitHunitstateHlimitopR)Hevent"},
{0x6F3C3C10, "GetEventUnitState", "()Hunitstate"},
{0x6F3D22C0, "TriggerRegisterDeathEvent", "(HtriggerHwidget)Hevent"},
{0x6F3D23B0, "TriggerRegisterUnitEvent", "(HtriggerHunitHunitevent)Hevent"},
{0x6F3C3C40, "GetEventDamage", "()R"},
{0x6F3C3C60, "GetEventDamageSource", "()Hunit"},
{0x6F3C3CB0, "GetEventDetectingPlayer", "()Hplayer"},
{0x6F3C3D00, "GetEventTargetUnit", "()Hunit"},
{0x6F3D24D0, "TriggerRegisterFilterUnitEvent", "(HtriggerHunitHuniteventHboolexpr)Hevent"},
{0x6F3D25F0, "TriggerRegisterUnitInRange", "(HtriggerHunitRHboolexpr)Hevent"},
{0x6F3D2700, "TriggerRegisterEnterRegion", "(HtriggerHregionHboolexpr)Hevent"},
{0x6F3D2800, "TriggerRegisterLeaveRegion", "(HtriggerHregionHboolexpr)Hevent"},
{0x6F3C3D50, "GetTriggeringRegion", "()Hregion"},
{0x6F3BB6D0, "GetEnteringUnit", "()Hunit"},
{0x6F3BB6F0, "GetLeavingUnit", "()Hunit"},
{0x6F3C3DF0, "TriggerAddCondition", "(HtriggerHboolexpr)Htriggercondition"},
{0x6F3C3E40, "TriggerRemoveCondition", "(HtriggerHtriggercondition)V"},
{0x6F3C3E70, "TriggerClearConditions", "(Htrigger)V"},
{0x6F3C3E90, "TriggerAddAction", "(HtriggerC)Htriggeraction"},
{0x6F3C3ED0, "TriggerRemoveAction", "(HtriggerHtriggeraction)V"},
{0x6F3C3F00, "TriggerClearActions", "(Htrigger)V"},
{0x6F3B2DB0, "TriggerSleepAction", "(R)V"},
{0x6F3C3F20, "TriggerWaitForSound", "(HsoundR)V"},
{0x6F3C3F40, "TriggerExecute", "(Htrigger)V"},
{0x6F3C3F60, "TriggerExecuteWait", "(Htrigger)V"},
{0x6F3C3F80, "TriggerEvaluate", "(Htrigger)B"},
{0x6F3B2DC0, "TriggerSyncStart", "()V"},
{0x6F3BB710, "TriggerSyncReady", "()V"},
{0x6F3BB260, "GetTriggerWidget", "()Hwidget"},
{0x6F3C1D20, "GetTriggerDestructable", "()Hdestructable"},
{0x6F3BB410, "GetTriggerUnit", "()Hunit"},
{0x6F3BB280, "GetTriggerPlayer", "()Hplayer"},
{0x6F3BB2A0, "GetTriggeringTrigger", "()Htrigger"},
{0x6F3BB2C0, "GetTriggerEventId", "()Heventid"},
{0x6F3C1CE0, "GetTriggerEvalCount", "(Htrigger)I"},
{0x6F3C1D00, "GetTriggerExecCount", "(Htrigger)I"},
{0x6F3BB2E0, "GetFilterUnit", "()Hunit"},
{0x6F3BB300, "GetEnumUnit", "()Hunit"},
{0x6F3BB320, "GetEnumPlayer", "()Hplayer"},
{0x6F3BB340, "GetFilterPlayer", "()Hplayer"},
{0x6F3BB380, "GetFilterDestructable", "()Hdestructable"},
{0x6F3BB360, "GetEnumDestructable", "()Hdestructable"},
{0x6F3BB3C0, "GetFilterItem", "()Hitem"},
{0x6F3BB3A0, "GetEnumItem", "()Hitem"},
{0x6F3D2900, "CreateGroup", "()Hgroup"},
{0x6F3C3FA0, "DestroyGroup", "(Hgroup)V"},
{0x6F3C3FC0, "GroupAddUnit", "(HgroupHunit)V"},
{0x6F3C3FF0, "GroupRemoveUnit", "(HgroupHunit)V"},
{0x6F3C4020, "GroupClear", "(Hgroup)V"},
{0x6F3C4040, "GroupEnumUnitsOfType", "(HgroupSHboolexpr)V"},
{0x6F3C4090, "GroupEnumUnitsOfTypeCounted", "(HgroupSHboolexprI)V"},
{0x6F3C40E0, "GroupEnumUnitsInRect", "(HgroupHrectHboolexpr)V"},
{0x6F3C4140, "GroupEnumUnitsInRectCounted", "(HgroupHrectHboolexprI)V"},
{0x6F3C42C0, "GroupEnumUnitsOfPlayer", "(HgroupHplayerHboolexpr)V"},
{0x6F3C41A0, "GroupEnumUnitsInRange", "(HgroupRRRHboolexpr)V"},
{0x6F3C41E0, "GroupEnumUnitsInRangeOfLoc", "(HgroupHlocationRHboolexpr)V"},
{0x6F3C4230, "GroupEnumUnitsInRangeCounted", "(HgroupRRRHboolexprI)V"},
{0x6F3C4270, "GroupEnumUnitsInRangeOfLocCounted", "(HgroupHlocationRHboolexprI)V"},
{0x6F3CE590, "GroupEnumUnitsSelected", "(HgroupHplayerHboolexpr)V"},
{0x6F3C4320, "GroupImmediateOrder", "(HgroupS)B"},
{0x6F3C4300, "GroupImmediateOrderById", "(HgroupI)B"},
{0x6F3C4370, "GroupPointOrder", "(HgroupSRR)B"},
{0x6F3C43E0, "GroupPointOrderLoc", "(HgroupSHlocation)B"},
{0x6F3C4340, "GroupPointOrderById", "(HgroupIRR)B"},
{0x6F3C4390, "GroupPointOrderByIdLoc", "(HgroupIHlocation)B"},
{0x6F3C4440, "GroupTargetOrder", "(HgroupSHwidget)B"},
{0x6F3C4400, "GroupTargetOrderById", "(HgroupIHwidget)B"},
{0x6F3C44A0, "ForGroup", "(HgroupC)V"},
{0x6F3C4460, "FirstOfGroup", "(Hgroup)Hunit"},
{0x6F3D29F0, "CreateForce", "()Hforce"},
{0x6F3C44C0, "DestroyForce", "(Hforce)V"},
{0x6F3C44E0, "ForceAddPlayer", "(HforceHplayer)V"},
{0x6F3C4510, "ForceRemovePlayer", "(HforceHplayer)V"},
{0x6F3C4540, "ForceClear", "(Hforce)V"},
{0x6F3C4560, "ForceEnumPlayers", "(HforceHboolexpr)V"},
{0x6F3C4590, "ForceEnumPlayersCounted", "(HforceHboolexprI)V"},
{0x6F3C45C0, "ForceEnumAllies", "(HforceHplayerHboolexpr)V"},
{0x6F3C4600, "ForceEnumEnemies", "(HforceHplayerHboolexpr)V"},
{0x6F3C4640, "ForForce", "(HforceC)V"},
{0x6F3C4660, "GetWidgetLife", "(Hwidget)R"},
{0x6F3C4690, "SetWidgetLife", "(HwidgetR)V"},
{0x6F3C46B0, "GetWidgetX", "(Hwidget)R"},
{0x6F3C46F0, "GetWidgetY", "(Hwidget)R"},
{0x6F3BB790, "CreateDestructable", "(IRRRRI)Hdestructable"},
{0x6F3BB7E0, "CreateDestructableZ", "(IRRRRRI)Hdestructable"},
{0x6F3BB840, "CreateDeadDestructable", "(IRRRRI)Hdestructable"},
{0x6F3BB890, "CreateDeadDestructableZ", "(IRRRRRI)Hdestructable"},
{0x6F3C4730, "RemoveDestructable", "(Hdestructable)V"},
{0x6F3C4750, "KillDestructable", "(Hdestructable)V"},
{0x6F3C4770, "SetDestructableInvulnerable", "(HdestructableB)V"},
{0x6F3C4790, "IsDestructableInvulnerable", "(Hdestructable)B"},
{0x6F3C4A90, "EnumDestructablesInRect", "(HrectHboolexprC)V"},
{0x6F3C47B0, "GetDestructableTypeId", "(Hdestructable)I"},
{0x6F3C47D0, "GetDestructableX", "(Hdestructable)R"},
{0x6F3C4810, "GetDestructableY", "(Hdestructable)R"},
{0x6F3C4850, "SetDestructableLife", "(HdestructableR)V"},
{0x6F3C4890, "GetDestructableLife", "(Hdestructable)R"},
{0x6F3C48D0, "SetDestructableMaxLife", "(HdestructableR)V"},
{0x6F3C4920, "GetDestructableMaxLife", "(Hdestructable)R"},
{0x6F3C4870, "DestructableRestoreLife", "(HdestructableRB)V"},
{0x6F3C4A00, "QueueDestructableAnimation", "(HdestructableS)V"},
{0x6F3C4A20, "SetDestructableAnimation", "(HdestructableS)V"},
{0x6F3C4A40, "SetDestructableAnimationSpeed", "(HdestructableR)V"},
{0x6F3C4A60, "ShowDestructable", "(HdestructableB)V"},
{0x6F3C4BB0, "GetDestructableOccluderHeight", "(Hdestructable)R"},
{0x6F3C4BD0, "SetDestructableOccluderHeight", "(HdestructableR)V"},
{0x6F3C4C10, "GetDestructableName", "(Hdestructable)S"},
{0x6F3C5230, "CreateUnit", "(HplayerIRRR)Hunit"},
{0x6F3C52A0, "CreateUnitByName", "(HplayerSRRR)Hunit"},
{0x6F3C52D0, "CreateUnitAtLoc", "(HplayerIHlocationR)Hunit"},
{0x6F3C5320, "CreateUnitAtLocByName", "(HplayerSHlocationR)Hunit"},
{0x6F3C5350, "CreateCorpse", "(HplayerIRRR)Hunit"},
{0x6F3C5400, "GetUnitState", "(HunitHunitstate)R"},
{0x6F3C5440, "GetUnitFoodUsed", "(Hunit)I"},
{0x6F3C5460, "GetUnitFoodMade", "(Hunit)I"},
{0x6F3B2E00, "GetFoodMade", "(I)I"},
{0x6F3B2E10, "GetFoodUsed", "(I)I"},
{0x6F3C54A0, "SetUnitUseFood", "(HunitB)V"},
{0x6F3C5510, "GetUnitX", "(Hunit)R"},
{0x6F3C5550, "GetUnitY", "(Hunit)R"},
{0x6F3D2AE0, "GetUnitLoc", "(Hunit)Hlocation"},
{0x6F3D2B40, "GetUnitRallyPoint", "(Hunit)Hlocation"},
{0x6F3C5590, "GetUnitRallyUnit", "(Hunit)Hunit"},
{0x6F3C5690, "GetUnitRallyDestructable", "(Hunit)Hdestructable"},
{0x6F3C5790, "GetUnitFacing", "(Hunit)R"},
{0x6F3C5810, "GetUnitMoveSpeed", "(Hunit)R"},
{0x6F3C5870, "GetUnitDefaultMoveSpeed", "(Hunit)R"},
{0x6F3C5910, "GetUnitTypeId", "(Hunit)I"},
{0x6F3C5930, "GetUnitRace", "(Hunit)Hrace"},
{0x6F3C5950, "GetUnitName", "(Hunit)S"},
{0x6F3C5E80, "GetUnitPointValue", "(Hunit)I"},
{0x6F3B2E20, "GetUnitPointValueByType", "(I)I"},
{0x6F3C5970, "SetUnitX", "(HunitR)V"},
{0x6F3C59E0, "SetUnitY", "(HunitR)V"},
{0x6F3C5A50, "SetUnitPosition", "(HunitRR)V"},
{0x6F3C5AB0, "SetUnitPositionLoc", "(HunitHlocation)V"},
{0x6F3C5AF0, "SetUnitFacing", "(HunitR)V"},
{0x6F3C5B30, "SetUnitFacingTimed", "(HunitRR)V"},
{0x6F3C5C60, "SetUnitFlyHeight", "(HunitRR)V"},
{0x6F3C5C40, "SetUnitMoveSpeed", "(HunitR)V"},
{0x6F3C5CB0, "SetUnitTurnSpeed", "(HunitR)V"},
{0x6F3C5CD0, "SetUnitPropWindow", "(HunitR)V"},
{0x6F3C5480, "SetUnitCreepGuard", "(HunitB)V"},
{0x6F3C5D10, "GetUnitAcquireRange", "(Hunit)R"},
{0x6F3C5D40, "GetUnitTurnSpeed", "(Hunit)R"},
{0x6F3C5D70, "GetUnitPropWindow", "(Hunit)R"},
{0x6F3C5DA0, "GetUnitFlyHeight", "(Hunit)R"},
{0x6F3C5DC0, "GetUnitDefaultAcquireRange", "(Hunit)R"},
{0x6F3C5DF0, "GetUnitDefaultTurnSpeed", "(Hunit)R"},
{0x6F3C5E20, "GetUnitDefaultPropWindow", "(Hunit)R"},
{0x6F3C5E50, "GetUnitDefaultFlyHeight", "(Hunit)R"},
{0x6F3C5CF0, "SetUnitAcquireRange", "(HunitR)V"},
{0x6F3C5EA0, "SetUnitState", "(HunitHunitstateR)V"},
{0x6F3C5ED0, "SetUnitOwner", "(HunitHplayerB)V"},
{0x6F3C5F10, "SetUnitRescuable", "(HunitHplayerB)V"},
{0x6F3C5F40, "SetUnitRescueRange", "(HunitR)V"},
{0x6F3C5F60, "SetUnitColor", "(HunitHplayercolor)V"},
{0x6F3C6180, "QueueUnitAnimation", "(HunitS)V"},
{0x6F3C61A0, "SetUnitAnimation", "(HunitS)V"},
{0x6F3C61C0, "SetUnitAnimationWithRarity", "(HunitSHraritycontrol)V"},
{0x6F3C61F0, "SetUnitAnimationByIndex", "(HunitI)V"},
{0x6F3C6220, "AddUnitAnimationProperties", "(HunitSB)V"},
{0x6F3C62D0, "SetUnitScale", "(HunitRRR)V"},
{0x6F3C6300, "SetUnitTimeScale", "(HunitR)V"},
{0x6F3C6320, "SetUnitBlendTime", "(HunitR)V"},
{0x6F3C6340, "SetUnitVertexColor", "(HunitIIII)V"},
{0x6F3C64C0, "SetUnitLookAt", "(HunitSHunitRRR)V"},
{0x6F3C5FA0, "SetUnitPathing", "(HunitB)V"},
{0x6F3C65F0, "ResetUnitLookAt", "(Hunit)V"},
{0x6F3C6630, "SetHeroStr", "(HunitIB)V"},
{0x6F3C66A0, "SetHeroAgi", "(HunitIB)V"},
{0x6F3C6710, "SetHeroInt", "(HunitIB)V"},
{0x6F3C67E0, "GetHeroStr", "(HunitB)I"},
{0x6F3C6850, "GetHeroAgi", "(HunitB)I"},
{0x6F3C68C0, "GetHeroInt", "(HunitB)I"},
{0x6F3C6780, "GetHeroSkillPoints", "(Hunit)I"},
{0x6F3C6930, "UnitStripHeroLevel", "(HunitI)B"},
{0x6F3C69A0, "UnitModifySkillPoints", "(HunitI)B"},
{0x6F3C6A10, "GetHeroXP", "(Hunit)I"},
{0x6F3C6A70, "SetHeroXP", "(HunitIB)V"},
{0x6F3C6CF0, "AddHeroXP", "(HunitIB)V"},
{0x6F3C6D70, "SetHeroLevel", "(HunitIB)V"},
{0x6F3C6ED0, "GetHeroLevel", "(Hunit)I"},
{0x6F3C6F30, "GetUnitLevel", "(Hunit)I"},
{0x6F3C6FA0, "GetHeroProperName", "(Hunit)S"},
{0x6F3C6E10, "SuspendHeroXP", "(HunitB)V"},
{0x6F3C6E70, "IsSuspendedXP", "(Hunit)B"},
{0x6F3C7050, "SelectHeroSkill", "(HunitI)V"},
{0x6F3C7290, "GetUnitAbilityLevel", "(HunitI)I"},
{0x6F3C6AF0, "ReviveHero", "(HunitRRB)B"},
{0x6F3C6B80, "ReviveHeroLoc", "(HunitHlocationB)B"},
{0x6F3CE6D0, "SetUnitExploded", "(HunitB)V"},
{0x6F3C72F0, "SetUnitInvulnerable", "(HunitB)V"},
{0x6F3C7340, "PauseUnit", "(HunitB)V"},
{0x6F3C73A0, "IsUnitPaused", "(Hunit)B"},
{0x6F3C73F0, "UnitAddItem", "(HunitHitem)B"},
{0x6F3C74F0, "UnitAddItemById", "(HunitI)Hitem"},
{0x6F3C75B0, "UnitAddItemToSlotById", "(HunitII)B"},
{0x6F3C7660, "UnitRemoveItem", "(HunitHitem)V"},
{0x6F3C76A0, "UnitRemoveItemFromSlot", "(HunitI)Hitem"},
{0x6F3C76F0, "UnitHasItem", "(HunitHitem)B"},
{0x6F3C7730, "UnitItemInSlot", "(HunitI)Hitem"},
{0x6F3C8F00, "UnitInventorySize", "(Hunit)I"},
{0x6F3C8F30, "UnitDropItemPoint", "(HunitHitemRR)B"},
{0x6F3C9010, "UnitDropItemSlot", "(HunitHitemI)B"},
{0x6F3C8FA0, "UnitDropItemTarget", "(HunitHitemHwidget)B"},
{0x6F3C9090, "UnitUseItem", "(HunitHitem)B"},
{0x6F3C9100, "UnitUseItemPoint", "(HunitHitemRR)B"},
{0x6F3C9170, "UnitUseItemTarget", "(HunitHitemHwidget)B"},
{0x6F3C7780, "GetUnitCurrentOrder", "(Hunit)I"},
{0x6F3C77F0, "SetResourceAmount", "(HunitI)V"},
{0x6F3C7850, "AddResourceAmount", "(HunitI)V"},
{0x6F3C78B0, "GetResourceAmount", "(Hunit)I"},
{0x6F3C7910, "SelectUnit", "(HunitB)V"},
{0x6F3BBAA0, "ClearSelection", "()V"},
{0x6F3C6BD0, "UnitAddIndicator", "(HunitIIII)V"},
{0x6F3C6C60, "AddIndicator", "(HwidgetIIII)V"},
{0x6F3C8040, "KillUnit", "(Hunit)V"},
{0x6F3C8060, "RemoveUnit", "(Hunit)V"},
{0x6F3CE730, "ShowUnit", "(HunitB)V"},
{0x6F3C79C0, "IsUnitInForce", "(HunitHforce)B"},
{0x6F3C7A00, "IsUnitInGroup", "(HunitHgroup)B"},
{0x6F3C7A30, "IsUnitOwnedByPlayer", "(HunitHplayer)B"},
{0x6F3C7A70, "IsUnitAlly", "(HunitHplayer)B"},
{0x6F3C7AD0, "IsUnitEnemy", "(HunitHplayer)B"},
{0x6F3C7AF0, "IsUnitVisible", "(HunitHplayer)B"},
{0x6F3C7C80, "IsUnitDetected", "(HunitHplayer)B"},
{0x6F3C7CC0, "IsUnitInvisible", "(HunitHplayer)B"},
{0x6F3C7D00, "IsUnitFogged", "(HunitHplayer)B"},
{0x6F3C7D80, "IsUnitMasked", "(HunitHplayer)B"},
{0x6F3C7E00, "IsUnitSelected", "(HunitHplayer)B"},
{0x6F3C7E60, "IsUnitRace", "(HunitHrace)B"},
{0x6F3C7E90, "IsUnitType", "(HunitHunittype)B"},
{0x6F3C8020, "IsUnit", "(HunitHunit)B"},
{0x6F3C8090, "IsUnitInRange", "(HunitHunitR)B"},
{0x6F3C80E0, "IsUnitInRangeXY", "(HunitRRR)B"},
{0x6F3C8140, "IsUnitInRangeLoc", "(HunitHlocationR)B"},
{0x6F3C7B30, "IsUnitHidden", "(Hunit)B"},
{0x6F3C7B50, "IsUnitIllusion", "(Hunit)B"},
{0x6F3C7B70, "IsUnitInTransport", "(HunitHunit)B"},
{0x6F3C7BA0, "IsUnitLoaded", "(Hunit)B"},
{0x6F3B2E90, "IsHeroUnitId", "(I)B"},
{0x6F3B7F60, "IsUnitIdType", "(IHunittype)B"},
{0x6F3C8190, "GetOwningPlayer", "(Hunit)Hplayer"},
{0x6F3C81C0, "UnitShareVision", "(HunitHplayerB)V"},
{0x6F3C81F0, "UnitSuspendDecay", "(HunitB)V"},
{0x6F3C7BC0, "UnitAddType", "(HunitHunittype)B"},
{0x6F3C7C20, "UnitRemoveType", "(HunitHunittype)B"},
{0x6F3C82A0, "UnitAddAbility", "(HunitI)B"},
{0x6F3C8310, "UnitRemoveAbility", "(HunitI)B"},
{0x6F3C8250, "UnitMakeAbilityPermanent", "(HunitBI)B"},
{0x6F3C8360, "UnitHasBuffsEx", "(HunitBBBBBBB)B"},
{0x6F3C83A0, "UnitCountBuffsEx", "(HunitBBBBBBB)I"},
{0x6F3C83E0, "UnitRemoveBuffs", "(HunitBB)V"},
{0x6F3C8410, "UnitRemoveBuffsEx", "(HunitBBBBBBB)V"},
{0x6F3C8450, "UnitAddSleep", "(HunitB)V"},
{0x6F3C84A0, "UnitCanSleep", "(Hunit)B"},
{0x6F3C84D0, "UnitAddSleepPerm", "(HunitB)V"},
{0x6F3C8520, "UnitCanSleepPerm", "(Hunit)B"},
{0x6F3C8550, "UnitIsSleeping", "(Hunit)B"},
{0x6F3C8590, "UnitWakeUp", "(Hunit)V"},
{0x6F3C85D0, "UnitApplyTimedLife", "(HunitIR)V"},
{0x6F3C8640, "UnitIgnoreAlarm", "(HunitB)B"},
{0x6F3C8690, "UnitIgnoreAlarmToggled", "(Hunit)B"},
{0x6F3C8770, "UnitDamagePoint", "(HunitRRRRRBBHattacktypeHdamagetypeHweapontype)B"},
{0x6F3C8850, "UnitDamageTarget", "(HunitHwidgetRBBHattacktypeHdamagetypeHweapontype)B"},
{0x6F3C70B0, "DecUnitAbilityLevel", "(HunitI)I"},
{0x6F3C7130, "IncUnitAbilityLevel", "(HunitI)I"},
{0x6F3C71B0, "SetUnitAbilityLevel", "(HunitII)I"},
{0x6F3C86D0, "UnitResetCooldown", "(Hunit)V"},
{0x6F3C86F0, "UnitSetConstructionProgress", "(HunitI)V"},
{0x6F3C8720, "UnitSetUpgradeProgress", "(HunitI)V"},
{0x6F3C8750, "UnitPauseTimedLife", "(HunitB)V"},
{0x6F3CB860, "UnitSetUsesAltIcon", "(HunitB)V"},
{0x6F3C8900, "IssueImmediateOrderById", "(HunitI)B"},
{0x6F3C8940, "IssuePointOrderById", "(HunitIRR)B"},
{0x6F3C8980, "IssuePointOrderByIdLoc", "(HunitIHlocation)B"},
{0x6F3C89D0, "IssueTargetOrderById", "(HunitIHwidget)B"},
{0x6F3C8A20, "IssueInstantPointOrderById", "(HunitIRRHwidget)B"},
{0x6F3C8AB0, "IssueInstantTargetOrderById", "(HunitIHwidgetHwidget)B"},
{0x6F3C8BE0, "IssueBuildOrderById", "(HunitIRR)B"},
{0x6F3C8CA0, "IssueNeutralImmediateOrderById", "(HplayerHunitI)B"},
{0x6F3C8CE0, "IssueNeutralPointOrderById", "(HplayerHunitIRR)B"},
{0x6F3C8D30, "IssueNeutralTargetOrderById", "(HplayerHunitIHwidget)B"},
{0x6F3C8D80, "IssueImmediateOrder", "(HunitS)B"},
{0x6F3C8DA0, "IssuePointOrder", "(HunitSRR)B"},
{0x6F3C8DC0, "IssuePointOrderLoc", "(HunitSHlocation)B"},
{0x6F3C8E20, "IssueTargetOrder", "(HunitSHwidget)B"},
{0x6F3C8E40, "IssueInstantPointOrder", "(HunitSRRHwidget)B"},
{0x6F3C8E60, "IssueInstantTargetOrder", "(HunitSHwidgetHwidget)B"},
{0x6F3C8E80, "IssueBuildOrder", "(HunitSRR)B"},
{0x6F3C8EA0, "IssueNeutralImmediateOrder", "(HplayerHunitS)B"},
{0x6F3C8EC0, "IssueNeutralPointOrder", "(HplayerHunitSRR)B"},
{0x6F3C8EE0, "IssueNeutralTargetOrder", "(HplayerHunitSHwidget)B"},
{0x6F3C91F0, "WaygateGetDestinationX", "(Hunit)R"},
{0x6F3C9240, "WaygateGetDestinationY", "(Hunit)R"},
{0x6F3C9290, "WaygateSetDestination", "(HunitRR)V"},
{0x6F3C92D0, "WaygateActivate", "(HunitB)V"},
{0x6F3C9310, "WaygateIsActive", "(Hunit)B"},
{0x6F3B3270, "AddItemToAllStock", "(III)V"},
{0x6F3C9350, "AddItemToStock", "(HunitIII)V"},
{0x6F3B3290, "AddUnitToAllStock", "(III)V"},
{0x6F3C93A0, "AddUnitToStock", "(HunitIII)V"},
{0x6F3B32B0, "RemoveItemFromAllStock", "(I)V"},
{0x6F3C93F0, "RemoveItemFromStock", "(HunitI)V"},
{0x6F3B32C0, "RemoveUnitFromAllStock", "(I)V"},
{0x6F3C9430, "RemoveUnitFromStock", "(HunitI)V"},
{0x6F3B32D0, "SetAllItemTypeSlots", "(I)V"},
{0x6F3B32E0, "SetAllUnitTypeSlots", "(I)V"},
{0x6F3C9470, "SetItemTypeSlots", "(HunitI)V"},
{0x6F3C94B0, "SetUnitTypeSlots", "(HunitI)V"},
{0x6F3C94F0, "GetUnitUserData", "(Hunit)I"},
{0x6F3C9510, "SetUnitUserData", "(HunitI)V"},
{0x6F3BB9A0, "CreateItem", "(IRR)Hitem"},
{0x6F3C4C30, "RemoveItem", "(Hitem)V"},
{0x6F3C4E10, "GetItemPlayer", "(Hitem)Hplayer"},
{0x6F3C4C60, "GetItemTypeId", "(Hitem)I"},
{0x6F3C4D90, "GetItemX", "(Hitem)R"},
{0x6F3C4DD0, "GetItemY", "(Hitem)R"},
{0x6F3C4C80, "SetItemPosition", "(HitemRR)V"},
{0x6F3C4D00, "SetItemDropOnDeath", "(HitemB)V"},
{0x6F3C4D30, "SetItemDroppable", "(HitemB)V"},
{0x6F3C4D60, "SetItemPawnable", "(HitemB)V"},
{0x6F3C4EB0, "SetItemPlayer", "(HitemHplayerB)V"},
{0x6F3C4EE0, "SetItemInvulnerable", "(HitemB)V"},
{0x6F3C4F00, "IsItemInvulnerable", "(Hitem)B"},
{0x6F3C4E50, "GetItemLevel", "(Hitem)I"},
{0x6F3C4E70, "GetItemType", "(Hitem)Hitemtype"},
{0x6F3C4F20, "SetItemVisible", "(HitemB)V"},
{0x6F3C4F70, "IsItemVisible", "(Hitem)B"},
{0x6F3C5110, "EnumItemsInRect", "(HrectHboolexprC)V"},
{0x6F3C4F90, "IsItemOwned", "(Hitem)B"},
{0x6F3C4FD0, "IsItemPowerup", "(Hitem)B"},
{0x6F3C4FF0, "IsItemSellable", "(Hitem)B"},
{0x6F3C5010, "IsItemPawnable", "(Hitem)B"},
{0x6F3B2DD0, "IsItemIdPowerup", "(I)B"},
{0x6F3B2DE0, "IsItemIdSellable", "(I)B"},
{0x6F3B2DF0, "IsItemIdPawnable", "(I)B"},
{0x6F3C5030, "SetItemDropID", "(HitemI)V"},
{0x6F3C4E90, "GetItemName", "(Hitem)S"},
{0x6F3C5050, "GetItemCharges", "(Hitem)I"},
{0x6F3C5070, "SetItemCharges", "(HitemI)V"},
{0x6F3C50D0, "GetItemUserData", "(Hitem)I"},
{0x6F3C50F0, "SetItemUserData", "(HitemI)V"},
{0x6F3BBB30, "Player", "(I)Hplayer"},
{0x6F3BBB60, "GetLocalPlayer", "()Hplayer"},
{0x6F3C9530, "IsPlayerAlly", "(HplayerHplayer)B"},
{0x6F3C9580, "IsPlayerEnemy", "(HplayerHplayer)B"},
{0x6F3C95D0, "IsPlayerInForce", "(HplayerHforce)B"},
{0x6F3C9600, "IsPlayerObserver", "(Hplayer)B"},
{0x6F3C9620, "GetPlayerRace", "(Hplayer)Hrace"},
{0x6F3C9640, "GetPlayerId", "(Hplayer)I"},
{0x6F3C9660, "SetPlayerTechMaxAllowed", "(HplayerII)V"},
{0x6F3C9690, "GetPlayerTechMaxAllowed", "(HplayerI)I"},
{0x6F3C96D0, "AddPlayerTechResearched", "(HplayerII)V"},
{0x6F3C9730, "SetPlayerTechResearched", "(HplayerII)V"},
{0x6F3C9770, "GetPlayerTechResearched", "(HplayerIB)B"},
{0x6F3C97A0, "GetPlayerTechCount", "(HplayerIB)I"},
{0x6F3C97D0, "SetPlayerAbilityAvailable", "(HplayerIB)V"},
{0x6F3C9820, "GetPlayerUnitCount", "(HplayerB)I"},
{0x6F3C9850, "GetPlayerTypedUnitCount", "(HplayerSBB)I"},
{0x6F3C98C0, "GetPlayerStructureCount", "(HplayerB)I"},
{0x6F3C98F0, "IsVisibleToPlayer", "(RRHplayer)B"},
{0x6F3C9940, "IsLocationVisibleToPlayer", "(HlocationHplayer)B"},
{0x6F3C9980, "IsFoggedToPlayer", "(RRHplayer)B"},
{0x6F3C99D0, "IsLocationFoggedToPlayer", "(HlocationHplayer)B"},
{0x6F3C9A10, "IsMaskedToPlayer", "(RRHplayer)B"},
{0x6F3C9A60, "IsLocationMaskedToPlayer", "(HlocationHplayer)B"},
{0x6F3C9AA0, "SetPlayerState", "(HplayerHplayerstateI)V"},
{0x6F3C9B00, "GetPlayerState", "(HplayerHplayerstate)I"},
{0x6F3C9B70, "GetPlayerScore", "(HplayerHplayerscore)I"},
{0x6F3C9D70, "GetPlayerAlliance", "(HplayerHplayerHalliancetype)B"},
{0x6F3C9DC0, "RemovePlayer", "(HplayerHplayergameresult)V"},
{0x6F3C9DE0, "CachePlayerHeroData", "(Hplayer)V"},
{0x6F3C9E10, "GetPlayerHandicap", "(Hplayer)R"},
{0x6F3C9E30, "SetPlayerHandicap", "(HplayerR)V"},
{0x6F3C9EC0, "GetPlayerHandicapXP", "(Hplayer)R"},
{0x6F3C9EE0, "SetPlayerHandicapXP", "(HplayerR)V"},
{0x6F3C12F0, "SetPlayerUnitsOwner", "(HplayerI)V"},
{0x6F3C1310, "CripplePlayer", "(HplayerHforceB)V"},
{0x6F3B32F0, "VersionGet", "()Hversion"},
{0x6F3B3300, "VersionCompatible", "(Hversion)B"},
{0x6F3B3310, "VersionSupported", "(Hversion)B"},
{0x6F3BBBB0, "EndGame", "(B)V"},
{0x6F3BBC30, "ChangeLevel", "(SB)V"},
{0x6F3BBC00, "RestartGame", "(B)V"},
{0x6F3BBBE0, "ReloadGame", "()V"},
{0x6F3BBE60, "LoadGame", "(SB)V"},
{0x6F3BBEE0, "SaveGame", "(S)V"},
{0x6F3BBFB0, "RenameSaveDirectory", "(SS)B"},
{0x6F3BC070, "RemoveSaveDirectory", "(S)B"},
{0x6F3BC180, "CopySaveGame", "(SS)B"},
{0x6F3BC100, "SaveGameExists", "(S)B"},
{0x6F3BC2E0, "SetFloatGameState", "(HfgamestateR)V"},
{0x6F3BC310, "GetFloatGameState", "(Hfgamestate)R"},
{0x6F3BC350, "SetIntegerGameState", "(HigamestateI)V"},
{0x6F3BC380, "GetIntegerGameState", "(Higamestate)I"},
{0x6F3BB740, "SyncSelections", "()V"},
{0x6F3D2BC0, "DialogCreate", "()Hdialog"},
{0x6F3C9F00, "DialogDestroy", "(Hdialog)V"},
{0x6F3C9F20, "DialogSetAsync", "(Hdialog)V"},
{0x6F3C9F40, "DialogClear", "(Hdialog)V"},
{0x6F3C9F60, "DialogSetMessage", "(HdialogS)V"},
{0x6F3C9F90, "DialogAddButton", "(HdialogSI)Hbutton"},
{0x6F3C9FE0, "DialogAddQuitButton", "(HdialogBSI)Hbutton"},
{0x6F3CA030, "DialogDisplay", "(HplayerHdialogB)V"},
{0x6F3B3340, "SetMissionAvailable", "(IIB)V"},
{0x6F3B3370, "SetCampaignAvailable", "(IB)V"},
{0x6F3BC3D0, "SetCampaignMenuRace", "(Hrace)V"},
{0x6F3BC3B0, "SetCampaignMenuRaceEx", "(I)V"},
{0x6F3BC400, "ForceCampaignSelectScreen", "()V"},
{0x6F3B3400, "SetOpCinematicAvailable", "(IB)V"},
{0x6F3B3460, "SetEdCinematicAvailable", "(IB)V"},
{0x6F3B3430, "SetTutorialCleared", "(B)V"},
{0x6F3B33A0, "GetDefaultDifficulty", "()Hgamedifficulty"},
{0x6F3B33D0, "SetDefaultDifficulty", "(Hgamedifficulty)V"},
{0x6F3BC430, "ReloadGameCachesFromDisk", "()B"},
{0x6F3B3510, "SetCustomCampaignButtonVisible", "(IB)V"},
{0x6F3B3530, "GetCustomCampaignButtonVisible", "(I)B"},
{0x6F3B3550, "DoNotSaveReplay", "()V"},
{0x6F3D2CC0, "InitGameCache", "(S)Hgamecache"},
{0x6F3CA080, "SaveGameCache", "(Hgamecache)B"},
{0x6F3CA0A0, "StoreInteger", "(HgamecacheSSI)V"},
{0x6F3CA0F0, "StoreReal", "(HgamecacheSSR)V"},
{0x6F3CA140, "StoreBoolean", "(HgamecacheSSB)V"},
{0x6F3CA1A0, "StoreUnit", "(HgamecacheSSHunit)B"},
{0x6F3CA680, "StoreString", "(HgamecacheSSS)B"},
{0x6F3CA200, "SaveInteger", "(HhashtableIII)V"},
{0x6F3CA240, "SaveReal", "(HhashtableIIR)V"},
{0x6F3CA280, "SaveBoolean", "(HhashtableIIB)V"},
{0x6F3CA2C0, "SaveStr", "(HhashtableIIS)B"},
{0x6F3CA300, "SavePlayerHandle", "(HhashtableIIHplayer)B"},
{0x6F3CA320, "SaveWidgetHandle", "(HhashtableIIHwidget)B"},
{0x6F3CA340, "SaveDestructableHandle", "(HhashtableIIHdestructable)B"},
{0x6F3CA360, "SaveItemHandle", "(HhashtableIIHitem)B"},
{0x6F3CA380, "SaveUnitHandle", "(HhashtableIIHunit)B"},
{0x6F3CE8C0, "SaveAbilityHandle", "(HhashtableIIHability)B"},
{0x6F3CA3A0, "SaveTimerHandle", "(HhashtableIIHtimer)B"},
{0x6F3CA3C0, "SaveRegionHandle", "(HhashtableIIHregion)B"},
{0x6F3CA3E0, "SaveTriggerHandle", "(HhashtableIIHtrigger)B"},
{0x6F3CA400, "SaveTriggerConditionHandle", "(HhashtableIIHtriggercondition)B"},
{0x6F3CA420, "SaveTriggerActionHandle", "(HhashtableIIHtriggeraction)B"},
{0x6F3CA440, "SaveTriggerEventHandle", "(HhashtableIIHevent)B"},
{0x6F3CA460, "SaveForceHandle", "(HhashtableIIHforce)B"},
{0x6F3CA480, "SaveGroupHandle", "(HhashtableIIHgroup)B"},
{0x6F3CA4A0, "SaveLocationHandle", "(HhashtableIIHlocation)B"},
{0x6F3CA4C0, "SaveRectHandle", "(HhashtableIIHrect)B"},
{0x6F3CA4E0, "SaveBooleanExprHandle", "(HhashtableIIHboolexpr)B"},
{0x6F3CA500, "SaveSoundHandle", "(HhashtableIIHsound)B"},
{0x6F3CE8E0, "SaveEffectHandle", "(HhashtableIIHeffect)B"},
{0x6F3CE900, "SaveUnitPoolHandle", "(HhashtableIIHunitpool)B"},
{0x6F3CE920, "SaveItemPoolHandle", "(HhashtableIIHitempool)B"},
{0x6F3CE940, "SaveQuestHandle", "(HhashtableIIHquest)B"},
{0x6F3CE960, "SaveQuestItemHandle", "(HhashtableIIHquestitem)B"},
{0x6F3CE980, "SaveDefeatConditionHandle", "(HhashtableIIHdefeatcondition)B"},
{0x6F3CE9A0, "SaveTimerDialogHandle", "(HhashtableIIHtimerdialog)B"},
{0x6F3CE9C0, "SaveLeaderboardHandle", "(HhashtableIIHleaderboard)B"},
{0x6F3CE9E0, "SaveMultiboardHandle", "(HhashtableIIHmultiboard)B"},
{0x6F3CEA00, "SaveMultiboardItemHandle", "(HhashtableIIHmultiboarditem)B"},
{0x6F3CEA20, "SaveTrackableHandle", "(HhashtableIIHtrackable)B"},
{0x6F3CA520, "SaveDialogHandle", "(HhashtableIIHdialog)B"},
{0x6F3CA540, "SaveButtonHandle", "(HhashtableIIHbutton)B"},
{0x6F3CA5A0, "SaveTextTagHandle", "(HhashtableIIHtexttag)B"},
{0x6F3CA5C0, "SaveLightningHandle", "(HhashtableIIHlightning)B"},
{0x6F3CA5E0, "SaveImageHandle", "(HhashtableIIHimage)B"},
{0x6F3CA600, "SaveUbersplatHandle", "(HhashtableIIHubersplat)B"},
{0x6F3CA620, "SaveFogStateHandle", "(HhashtableIIHfogstate)B"},
{0x6F3CA640, "SaveFogModifierHandle", "(HhashtableIIHfogmodifier)B"},
{0x6F3CEA40, "SaveAgentHandle", "(HhashtableIIHagent)B"},
{0x6F3CA660, "SaveHashtableHandle", "(HhashtableIIHhashtable)B"},
{0x6F3CA6E0, "SyncStoredInteger", "(HgamecacheSS)V"},
{0x6F3CA730, "SyncStoredReal", "(HgamecacheSS)V"},
{0x6F3CA780, "SyncStoredBoolean", "(HgamecacheSS)V"},
{0x6F3CA7D0, "SyncStoredUnit", "(HgamecacheSS)V"},
{0x6F3CA820, "SyncStoredString", "(HgamecacheSS)V"},
{0x6F3CA870, "GetStoredInteger", "(HgamecacheSS)I"},
{0x6F3CA8C0, "GetStoredReal", "(HgamecacheSS)R"},
{0x6F3CA920, "GetStoredBoolean", "(HgamecacheSS)B"},
{0x6F3CA970, "RestoreUnit", "(HgamecacheSSHplayerRRR)Hunit"},
{0x6F3CAA40, "GetStoredString", "(HgamecacheSS)S"},
{0x6F3CAF30, "HaveStoredInteger", "(HgamecacheSS)B"},
{0x6F3CAF80, "HaveStoredReal", "(HgamecacheSS)B"},
{0x6F3CAFD0, "HaveStoredBoolean", "(HgamecacheSS)B"},
{0x6F3CB020, "HaveStoredUnit", "(HgamecacheSS)B"},
{0x6F3CB070, "HaveStoredString", "(HgamecacheSS)B"},
{0x6F3CB200, "FlushGameCache", "(Hgamecache)V"},
{0x6F3CB240, "FlushStoredMission", "(HgamecacheS)V"},
{0x6F3CB280, "FlushStoredInteger", "(HgamecacheSS)V"},
{0x6F3CB2D0, "FlushStoredReal", "(HgamecacheSS)V"},
{0x6F3CB320, "FlushStoredBoolean", "(HgamecacheSS)V"},
{0x6F3CB370, "FlushStoredUnit", "(HgamecacheSS)V"},
{0x6F3CB3C0, "FlushStoredString", "(HgamecacheSS)V"},
{0x6F3D2DF0, "InitHashtable", "()Hhashtable"},
{0x6F3CAA90, "LoadInteger", "(HhashtableII)I"},
{0x6F3CAAD0, "LoadReal", "(HhashtableII)R"},
{0x6F3CAB10, "LoadBoolean", "(HhashtableII)B"},
{0x6F3CAB50, "LoadStr", "(HhashtableII)S"},
{0x6F3CAB90, "LoadPlayerHandle", "(HhashtableII)Hplayer"},
{0x6F3CABB0, "LoadWidgetHandle", "(HhashtableII)Hwidget"},
{0x6F3CABD0, "LoadDestructableHandle", "(HhashtableII)Hdestructable"},
{0x6F3CABF0, "LoadItemHandle", "(HhashtableII)Hitem"},
{0x6F3CAC10, "LoadUnitHandle", "(HhashtableII)Hunit"},
{0x6F3CEA60, "LoadAbilityHandle", "(HhashtableII)Hability"},
{0x6F3CAC30, "LoadTimerHandle", "(HhashtableII)Htimer"},
{0x6F3CAC50, "LoadRegionHandle", "(HhashtableII)Hregion"},
{0x6F3CAC70, "LoadTriggerHandle", "(HhashtableII)Htrigger"},
{0x6F3CAC90, "LoadTriggerConditionHandle", "(HhashtableII)Htriggercondition"},
{0x6F3CACB0, "LoadTriggerActionHandle", "(HhashtableII)Htriggeraction"},
{0x6F3CACD0, "LoadTriggerEventHandle", "(HhashtableII)Hevent"},
{0x6F3CACF0, "LoadForceHandle", "(HhashtableII)Hforce"},
{0x6F3CAD10, "LoadGroupHandle", "(HhashtableII)Hgroup"},
{0x6F3CAD30, "LoadLocationHandle", "(HhashtableII)Hlocation"},
{0x6F3CAD50, "LoadRectHandle", "(HhashtableII)Hrect"},
{0x6F3CAD70, "LoadBooleanExprHandle", "(HhashtableII)Hboolexpr"},
{0x6F3CAD90, "LoadSoundHandle", "(HhashtableII)Hsound"},
{0x6F3CEA80, "LoadEffectHandle", "(HhashtableII)Heffect"},
{0x6F3CEAA0, "LoadUnitPoolHandle", "(HhashtableII)Hunitpool"},
{0x6F3CEAC0, "LoadItemPoolHandle", "(HhashtableII)Hitempool"},
{0x6F3CEAE0, "LoadQuestHandle", "(HhashtableII)Hquest"},
{0x6F3CEB00, "LoadQuestItemHandle", "(HhashtableII)Hquestitem"},
{0x6F3CEB20, "LoadDefeatConditionHandle", "(HhashtableII)Hdefeatcondition"},
{0x6F3CEB40, "LoadTimerDialogHandle", "(HhashtableII)Htimerdialog"},
{0x6F3CEB60, "LoadLeaderboardHandle", "(HhashtableII)Hleaderboard"},
{0x6F3CEB80, "LoadMultiboardHandle", "(HhashtableII)Hmultiboard"},
{0x6F3CEBA0, "LoadMultiboardItemHandle", "(HhashtableII)Hmultiboarditem"},
{0x6F3CEBC0, "LoadTrackableHandle", "(HhashtableII)Htrackable"},
{0x6F3CADB0, "LoadDialogHandle", "(HhashtableII)Hdialog"},
{0x6F3CADD0, "LoadButtonHandle", "(HhashtableII)Hbutton"},
{0x6F3CAE50, "LoadTextTagHandle", "(HhashtableII)Htexttag"},
{0x6F3CAE70, "LoadLightningHandle", "(HhashtableII)Hlightning"},
{0x6F3CAE90, "LoadImageHandle", "(HhashtableII)Himage"},
{0x6F3CAEB0, "LoadUbersplatHandle", "(HhashtableII)Hubersplat"},
{0x6F3CAED0, "LoadFogStateHandle", "(HhashtableII)Hfogstate"},
{0x6F3CAEF0, "LoadFogModifierHandle", "(HhashtableII)Hfogmodifier"},
{0x6F3CAF10, "LoadHashtableHandle", "(HhashtableII)Hhashtable"},
{0x6F3CB0C0, "HaveSavedInteger", "(HhashtableII)B"},
{0x6F3CB100, "HaveSavedReal", "(HhashtableII)B"},
{0x6F3CB140, "HaveSavedBoolean", "(HhashtableII)B"},
{0x6F3CB180, "HaveSavedString", "(HhashtableII)B"},
{0x6F3CB1C0, "HaveSavedHandle", "(HhashtableII)B"},
{0x6F3CB410, "RemoveSavedInteger", "(HhashtableII)V"},
{0x6F3CB450, "RemoveSavedReal", "(HhashtableII)V"},
{0x6F3CB490, "RemoveSavedBoolean", "(HhashtableII)V"},
{0x6F3CB4D0, "RemoveSavedString", "(HhashtableII)V"},
{0x6F3CB510, "RemoveSavedHandle", "(HhashtableII)V"},
{0x6F3CB550, "FlushParentHashtable", "(Hhashtable)V"},
{0x6F3CB590, "FlushChildHashtable", "(HhashtableI)V"},
{0x6F3B3560, "GetRandomInt", "(II)I"},
{0x6F3B35A0, "GetRandomReal", "(RR)R"},
{0x6F3D2ED0, "CreateUnitPool", "()Hunitpool"},
{0x6F3CB5C0, "DestroyUnitPool", "(Hunitpool)V"},
{0x6F3CB5E0, "UnitPoolAddUnitType", "(HunitpoolIR)V"},
{0x6F3CB600, "UnitPoolRemoveUnitType", "(HunitpoolI)V"},
{0x6F3CB620, "PlaceRandomUnit", "(HunitpoolHplayerRRR)Hunit"},
{0x6F3D2FC0, "CreateItemPool", "()Hitempool"},
{0x6F3CB6A0, "DestroyItemPool", "(Hitempool)V"},
{0x6F3CB6C0, "ItemPoolAddItemType", "(HitempoolIR)V"},
{0x6F3CB6E0, "ItemPoolRemoveItemType", "(HitempoolI)V"},
{0x6F3CB700, "PlaceRandomItem", "(HitempoolRR)Hitem"},
{0x6F3B3660, "ChooseRandomCreep", "(I)I"},
{0x6F3B3680, "ChooseRandomNPBuilding", "()I"},
{0x6F3B3690, "ChooseRandomItem", "(I)I"},
{0x6F3B36B0, "ChooseRandomItemEx", "(HitemtypeI)I"},
{0x6F3B36D0, "SetRandomSeed", "(I)V"},
{0x6F3CB900, "DisplayTextToPlayer", "(HplayerRRS)V"},
{0x6F3CB9B0, "DisplayTimedTextToPlayer", "(HplayerRRRS)V"},
{0x6F3CBA30, "DisplayTimedTextFromPlayer", "(HplayerRRRS)V"},
{0x6F3B4E60, "ClearTextMessages", "()V"},
{0x6F3B3880, "EnableUserControl", "(B)V"},
{0x6F3B38A0, "EnableUserUI", "(B)V"},
{0x6F3B38C0, "DisableRestartMission", "(B)V"},
{0x6F3B38E0, "ForceUIKey", "(S)V"},
{0x6F3B3990, "ForceUICancel", "()V"},
{0x6F3B3A10, "DisplayLoadDialog", "()V"},
{0x6F3B3840, "SetTerrainFog", "(RRRRR)V"},
{0x6F3B3850, "SetUnitFog", "(RRRRR)V"},
{0x6F3B81B0, "SetTerrainFogEx", "(IRRRRRR)V"},
{0x6F3B3860, "ResetTerrainFog", "()V"},
{0x6F3B3790, "SetDayNightModels", "(SS)V"},
{0x6F3B37D0, "SetSkyModel", "(S)V"},
{0x6F3BC460, "SuspendTimeOfDay", "(B)V"},
{0x6F3BC490, "SetTimeOfDayScale", "(R)V"},
{0x6F3BC4B0, "GetTimeOfDayScale", "()R"},
{0x6F3B3810, "ShowInterface", "(BR)V"},
{0x6F3BC4D0, "PauseGame", "(B)V"},
{0x6F3B4650, "PingMinimap", "(RRR)V"},
{0x6F3B8660, "PingMinimapEx", "(RRRIIIB)V"},
{0x6F3BC880, "SetIntroShotText", "(S)V"},
{0x6F3BC8A0, "SetIntroShotModel", "(S)V"},
{0x6F3B3B90, "EnableOcclusion", "(B)V"},
{0x6F3B3BB0, "EnableWorldFogBoundary", "(B)V"},
{0x6F3BC500, "PlayModelCinematic", "(S)V"},
{0x6F3BC520, "PlayCinematic", "(S)V"},
{0x6F3BC540, "SetAltMinimapIcon", "(S)V"},
{0x6F3BC580, "CreateTextTag", "()Htexttag"},
{0x6F3BC5A0, "DestroyTextTag", "(Htexttag)V"},
{0x6F3BC5D0, "SetTextTagText", "(HtexttagSR)V"},
{0x6F3BC610, "SetTextTagPos", "(HtexttagRRR)V"},
{0x6F3CB890, "SetTextTagPosUnit", "(HtexttagHunitR)V"},
{0x6F3BC6A0, "SetTextTagColor", "(HtexttagIIII)V"},
{0x6F3BC700, "SetTextTagVelocity", "(HtexttagRR)V"},
{0x6F3BC760, "SetTextTagVisibility", "(HtexttagB)V"},
{0x6F3BC790, "SetTextTagSuspended", "(HtexttagB)V"},
{0x6F3BC7C0, "SetTextTagPermanent", "(HtexttagB)V"},
{0x6F3BC7F0, "SetTextTagAge", "(HtexttagR)V"},
{0x6F3BC820, "SetTextTagLifespan", "(HtexttagR)V"},
{0x6F3BC850, "SetTextTagFadepoint", "(HtexttagR)V"},
{0x6F3B3A30, "SetReservedLocalHeroButtons", "(I)V"},
{0x6F3B3A50, "GetAllyColorFilterState", "()I"},
{0x6F3B3A70, "SetAllyColorFilterState", "(I)V"},
{0x6F3B3AA0, "GetCreepCampFilterState", "()B"},
{0x6F3B3AC0, "SetCreepCampFilterState", "(B)V"},
{0x6F3B3AF0, "EnableMinimapFilterButtons", "(BB)V"},
{0x6F3B3B30, "EnableDragSelect", "(BB)V"},
{0x6F3B3B50, "EnablePreSelect", "(BB)V"},
{0x6F3B3B70, "EnableSelect", "(BB)V"},
{0x6F3D30B0, "CreateTrackable", "(SRRR)Htrackable"},
{0x6F3D31C0, "TriggerRegisterTrackableHitEvent", "(HtriggerHtrackable)Hevent"},
{0x6F3D32A0, "TriggerRegisterTrackableTrackEvent", "(HtriggerHtrackable)Hevent"},
{0x6F3C3DA0, "GetTriggeringTrackable", "()Htrackable"},
{0x6F3BC970, "CreateQuest", "()Hquest"},
{0x6F3CBB20, "DestroyQuest", "(Hquest)V"},
{0x6F3CBB70, "QuestSetTitle", "(HquestS)V"},
{0x6F3CBBA0, "QuestSetDescription", "(HquestS)V"},
{0x6F3CBBD0, "QuestSetIconPath", "(HquestS)V"},
{0x6F3CBC00, "QuestSetRequired", "(HquestB)V"},
{0x6F3CBC20, "QuestSetCompleted", "(HquestB)V"},
{0x6F3CBC60, "QuestSetDiscovered", "(HquestB)V"},
{0x6F3CBC40, "QuestSetFailed", "(HquestB)V"},
{0x6F3CBC80, "QuestSetEnabled", "(HquestB)V"},
{0x6F3CBCA0, "IsQuestRequired", "(Hquest)B"},
{0x6F3CBCC0, "IsQuestCompleted", "(Hquest)B"},
{0x6F3CBCE0, "IsQuestDiscovered", "(Hquest)B"},
{0x6F3CBD00, "IsQuestFailed", "(Hquest)B"},
{0x6F3CBD20, "IsQuestEnabled", "(Hquest)B"},
{0x6F3D3380, "QuestCreateItem", "(Hquest)Hquestitem"},
{0x6F3CBD40, "QuestItemSetDescription", "(HquestitemS)V"},
{0x6F3CBD70, "QuestItemSetCompleted", "(HquestitemB)V"},
{0x6F3CBD90, "IsQuestItemCompleted", "(Hquestitem)B"},
{0x6F3BC9E0, "CreateDefeatCondition", "()Hdefeatcondition"},
{0x6F3CBDB0, "DestroyDefeatCondition", "(Hdefeatcondition)V"},
{0x6F3CBE00, "DefeatConditionSetDescription", "(HdefeatconditionS)V"},
{0x6F3BC920, "FlashQuestDialogButton", "()V"},
{0x6F3B3BE0, "ForceQuestDialogUpdate", "()V"},
{0x6F3D34B0, "CreateTimerDialog", "(Htimer)Htimerdialog"},
{0x6F3CBE30, "DestroyTimerDialog", "(Htimerdialog)V"},
{0x6F3CBE50, "TimerDialogSetTitle", "(HtimerdialogS)V"},
{0x6F3CBE80, "TimerDialogSetTitleColor", "(HtimerdialogIIII)V"},
{0x6F3CBED0, "TimerDialogSetTimeColor", "(HtimerdialogIIII)V"},
{0x6F3CBF20, "TimerDialogSetSpeed", "(HtimerdialogR)V"},
{0x6F3CBF50, "TimerDialogDisplay", "(HtimerdialogB)V"},
{0x6F3CBF70, "IsTimerDialogDisplayed", "(Htimerdialog)B"},
{0x6F3CBFA0, "TimerDialogSetRealTimeRemaining", "(HtimerdialogR)V"},
{0x6F3D35B0, "CreateLeaderboard", "()Hleaderboard"},
{0x6F3CBFD0, "DestroyLeaderboard", "(Hleaderboard)V"},
{0x6F3CC000, "LeaderboardGetItemCount", "(Hleaderboard)I"},
{0x6F3CC030, "LeaderboardSetSizeByItemCount", "(HleaderboardI)V"},
{0x6F3CC060, "LeaderboardAddItem", "(HleaderboardSIHplayer)V"},
{0x6F3CC0B0, "LeaderboardRemoveItem", "(HleaderboardI)V"},
{0x6F3CC0E0, "LeaderboardRemovePlayerItem", "(HleaderboardHplayer)V"},
{0x6F3CC120, "LeaderboardSortItemsByValue", "(HleaderboardB)V"},
{0x6F3CC150, "LeaderboardSortItemsByPlayer", "(HleaderboardB)V"},
{0x6F3CC180, "LeaderboardSortItemsByLabel", "(HleaderboardB)V"},
{0x6F3CC1B0, "LeaderboardClear", "(Hleaderboard)V"},
{0x6F3CC1D0, "LeaderboardDisplay", "(HleaderboardB)V"},
{0x6F3CC220, "IsLeaderboardDisplayed", "(Hleaderboard)B"},
{0x6F3CC2F0, "LeaderboardGetLabelText", "(Hleaderboard)S"},
{0x6F3CC340, "PlayerSetLeaderboard", "(HplayerHleaderboard)V"},
{0x6F3CC380, "PlayerGetLeaderboard", "(Hplayer)Hleaderboard"},
{0x6F3CC250, "LeaderboardHasPlayerItem", "(HleaderboardHplayer)B"},
{0x6F3CC2A0, "LeaderboardGetPlayerIndex", "(HleaderboardHplayer)I"},
{0x6F3CC3D0, "LeaderboardSetLabel", "(HleaderboardS)V"},
{0x6F3CC400, "LeaderboardSetLabelColor", "(HleaderboardIIII)V"},
{0x6F3CC450, "LeaderboardSetValueColor", "(HleaderboardIIII)V"},
{0x6F3CC4A0, "LeaderboardSetStyle", "(HleaderboardBBBB)V"},
{0x6F3CC4F0, "LeaderboardSetItemValue", "(HleaderboardII)V"},
{0x6F3CC520, "LeaderboardSetItemLabel", "(HleaderboardIS)V"},
{0x6F3CC560, "LeaderboardSetItemStyle", "(HleaderboardIBBB)V"},
{0x6F3CC5B0, "LeaderboardSetItemLabelColor", "(HleaderboardIIIII)V"},
{0x6F3CC600, "LeaderboardSetItemValueColor", "(HleaderboardIIIII)V"},
{0x6F3D36B0, "CreateMultiboard", "()Hmultiboard"},
{0x6F3CC650, "DestroyMultiboard", "(Hmultiboard)V"},
{0x6F3CC670, "MultiboardDisplay", "(HmultiboardB)V"},
{0x6F3CC6B0, "MultiboardMinimize", "(HmultiboardB)V"},
{0x6F3CC690, "IsMultiboardDisplayed", "(Hmultiboard)B"},
{0x6F3CC6D0, "IsMultiboardMinimized", "(Hmultiboard)B"},
{0x6F3CC6F0, "MultiboardClear", "(Hmultiboard)V"},
{0x6F3CC720, "MultiboardSetTitleText", "(HmultiboardS)V"},
{0x6F3CC750, "MultiboardGetTitleText", "(Hmultiboard)S"},
{0x6F3CC770, "MultiboardSetTitleTextColor", "(HmultiboardIIII)V"},
{0x6F3CC7B0, "MultiboardGetRowCount", "(Hmultiboard)I"},
{0x6F3CC7D0, "MultiboardGetColumnCount", "(Hmultiboard)I"},
{0x6F3CC7F0, "MultiboardSetColumnCount", "(HmultiboardI)V"},
{0x6F3CC810, "MultiboardSetRowCount", "(HmultiboardI)V"},
{0x6F3CC830, "MultiboardSetItemsStyle", "(HmultiboardBB)V"},
{0x6F3CC8A0, "MultiboardSetItemsValueColor", "(HmultiboardIIII)V"},
{0x6F3CC870, "MultiboardSetItemsValue", "(HmultiboardS)V"},
{0x6F3CC8F0, "MultiboardSetItemsWidth", "(HmultiboardR)V"},
{0x6F3CC920, "MultiboardSetItemsIcon", "(HmultiboardS)V"},
{0x6F3D37B0, "MultiboardGetItem", "(HmultiboardII)Hmultiboarditem"},
{0x6F3CC950, "MultiboardReleaseItem", "(Hmultiboarditem)V"},
{0x6F3CC970, "MultiboardSetItemStyle", "(HmultiboarditemBB)V"},
{0x6F3CC990, "MultiboardSetItemValue", "(HmultiboarditemS)V"},
{0x6F3CC9C0, "MultiboardSetItemValueColor", "(HmultiboarditemIIII)V"},
{0x6F3CCA00, "MultiboardSetItemWidth", "(HmultiboarditemR)V"},
{0x6F3CCA20, "MultiboardSetItemIcon", "(HmultiboarditemS)V"},
{0x6F3B3C00, "MultiboardSuppressDisplay", "(B)V"},
{0x6F3B86F0, "SetCameraBounds", "(RRRRRRRR)V"},
{0x6F3B45D0, "SetCameraPosition", "(RR)V"},
{0x6F3B4610, "SetCameraQuickPosition", "(RR)V"},
{0x6F3B46B0, "ResetToGameCamera", "(R)V"},
{0x6F3B46E0, "StopCamera", "()V"},
{0x6F3B4700, "PanCameraTo", "(RR)V"},
{0x6F3B4740, "PanCameraToTimed", "(RRR)V"},
{0x6F3B4790, "PanCameraToWithZ", "(RRR)V"},
{0x6F3B47D0, "PanCameraToTimedWithZ", "(RRRR)V"},
{0x6F3B4820, "SetCinematicCamera", "(S)V"},
{0x6F3B48B0, "SetCameraField", "(HcamerafieldRR)V"},
{0x6F3B48F0, "AdjustCameraField", "(HcamerafieldRR)V"},
{0x6F3CD760, "SetCameraTargetController", "(HunitRRB)V"},
{0x6F3CD7B0, "SetCameraOrientController", "(HunitRR)V"},
{0x6F3B4850, "SetCameraRotateMode", "(RRRR)V"},
{0x6F3D3D40, "CreateCameraSetup", "()Hcamerasetup"},
{0x6F3CD800, "CameraSetupSetField", "(HcamerasetupHcamerafieldRR)V"},
{0x6F3CD830, "CameraSetupGetField", "(HcamerasetupHcamerafield)R"},
{0x6F3CD870, "CameraSetupSetDestPosition", "(HcamerasetupRRR)V"},
{0x6F3D3E40, "CameraSetupGetDestPositionLoc", "(Hcamerasetup)Hlocation"},
{0x6F3CD8C0, "CameraSetupGetDestPositionX", "(Hcamerasetup)R"},
{0x6F3CD8E0, "CameraSetupGetDestPositionY", "(Hcamerasetup)R"},
{0x6F3CD900, "CameraSetupApply", "(HcamerasetupBB)V"},
{0x6F3CD930, "CameraSetupApplyWithZ", "(HcamerasetupR)V"},
{0x6F3CD960, "CameraSetupApplyForceDuration", "(HcamerasetupBR)V"},
{0x6F3CD990, "CameraSetupApplyForceDurationWithZ", "(HcamerasetupRR)V"},
{0x6F3B4930, "CameraSetTargetNoise", "(RR)V"},
{0x6F3B49E0, "CameraSetSourceNoise", "(RR)V"},
{0x6F3B4A70, "CameraSetTargetNoiseEx", "(RRB)V"},
{0x6F3B4B20, "CameraSetSourceNoiseEx", "(RRB)V"},
{0x6F3B4BB0, "CameraSetSmoothingFactor", "(R)V"},
{0x6F3B4BE0, "GetCameraMargin", "(I)R"},
{0x6F3B4C50, "GetCameraBoundMinX", "()R"},
{0x6F3B4C70, "GetCameraBoundMinY", "()R"},
{0x6F3B4C90, "GetCameraBoundMaxX", "()R"},
{0x6F3B4CB0, "GetCameraBoundMaxY", "()R"},
{0x6F3B4CD0, "GetCameraField", "(Hcamerafield)R"},
{0x6F3B4D00, "GetCameraTargetPositionX", "()R"},
{0x6F3B4D30, "GetCameraTargetPositionY", "()R"},
{0x6F3B4D60, "GetCameraTargetPositionZ", "()R"},
{0x6F3D3E90, "GetCameraTargetPositionLoc", "()Hlocation"},
{0x6F3B4D90, "GetCameraEyePositionX", "()R"},
{0x6F3B4DC0, "GetCameraEyePositionY", "()R"},
{0x6F3B4DF0, "GetCameraEyePositionZ", "()R"},
{0x6F3D3EE0, "GetCameraEyePositionLoc", "()Hlocation"},
{0x6F3B4E80, "SetCineFilterTexture", "(S)V"},
{0x6F3B4EB0, "SetCineFilterBlendMode", "(Hblendmode)V"},
{0x6F3B4EF0, "SetCineFilterTexMapFlags", "(Htexmapflags)V"},
{0x6F3B4F40, "SetCineFilterStartUV", "(RRRR)V"},
{0x6F3B5020, "SetCineFilterEndUV", "(RRRR)V"},
{0x6F3CEBE0, "SetCineFilterStartColor", "(IIII)V"},
{0x6F3CECD0, "SetCineFilterEndColor", "(IIII)V"},
{0x6F3B5100, "SetCineFilterDuration", "(R)V"},
{0x6F3B5120, "DisplayCineFilter", "(B)V"},
{0x6F3B5150, "IsCineFilterDisplayed", "()B"},
{0x6F3BCF80, "SetCinematicScene", "(IHplayercolorSSRR)V"},
{0x6F3B4E20, "EndCinematicScene", "()V"},
{0x6F3B4E40, "ForceCinematicSubtitles", "(B)V"},
{0x6F3B3E60, "NewSoundEnvironment", "(S)V"},
{0x6F3D38D0, "CreateSound", "(SBBBIIS)Hsound"},
{0x6F3D39F0, "CreateSoundFilenameWithLabel", "(SBBBIIS)Hsound"},
{0x6F3D3B10, "CreateSoundFromLabel", "(SBBBII)Hsound"},
{0x6F3D3C30, "CreateMIDISound", "(SII)Hsound"},
{0x6F3B3C20, "SetStackedSound", "(SRR)V"},
{0x6F3B3C80, "ClearStackedSound", "(SRR)V"},
{0x6F3CCA50, "SetStackedSoundRect", "(SHrect)V"},
{0x6F3CCB20, "ClearStackedSoundRect", "(SHrect)V"},
{0x6F3CCBF0, "SetSoundParamsFromLabel", "(HsoundS)V"},
{0x6F3CCC20, "SetSoundChannel", "(HsoundI)V"},
{0x6F3CCC40, "SetSoundVolume", "(HsoundI)V"},
{0x6F3CCC60, "SetSoundPitch", "(HsoundR)V"},
{0x6F3CCC80, "SetSoundPlayPosition", "(HsoundI)V"},
{0x6F3CCCA0, "SetSoundDistances", "(HsoundRR)V"},
{0x6F3CCCD0, "SetSoundDistanceCutoff", "(HsoundR)V"},
{0x6F3CCCF0, "SetSoundConeAngles", "(HsoundRRI)V"},
{0x6F3CCD30, "SetSoundConeOrientation", "(HsoundRRR)V"},
{0x6F3CCD90, "SetSoundPosition", "(HsoundRRR)V"},
{0x6F3CCDF0, "SetSoundVelocity", "(HsoundRRR)V"},
{0x6F3CCE50, "AttachSoundToUnit", "(HsoundHunit)V"},
{0x6F3CCE80, "StartSound", "(Hsound)V"},
{0x6F3CCEB0, "StopSound", "(HsoundBB)V"},
{0x6F3CCED0, "KillSoundWhenDone", "(Hsound)V"},
{0x6F3B3CE0, "SetMapMusic", "(SBI)V"},
{0x6F3B3D20, "ClearMapMusic", "()V"},
{0x6F3B3D30, "PlayMusic", "(S)V"},
{0x6F3B3D50, "PlayMusicEx", "(SII)V"},
{0x6F3B3D80, "StopMusic", "(B)V"},
{0x6F3B3D90, "ResumeMusic", "()V"},
{0x6F3B3DA0, "PlayThematicMusic", "(S)V"},
{0x6F3B3DC0, "PlayThematicMusicEx", "(SI)V"},
{0x6F3B3DE0, "EndThematicMusic", "()V"},
{0x6F3B3DF0, "SetMusicVolume", "(I)V"},
{0x6F3B3E00, "SetMusicPlayPosition", "(I)V"},
{0x6F3B3E10, "SetThematicMusicPlayPosition", "(I)V"},
{0x6F3CCEF0, "SetSoundDuration", "(HsoundI)V"},
{0x6F3CCF20, "GetSoundDuration", "(Hsound)I"},
{0x6F3B3E20, "GetSoundFileDuration", "(S)I"},
{0x6F3B3E30, "VolumeGroupSetVolume", "(HvolumegroupR)V"},
{0x6F3B3E50, "VolumeGroupReset", "()V"},
{0x6F3CCF40, "GetSoundIsPlaying", "(Hsound)B"},
{0x6F3CCF60, "GetSoundIsLoading", "(Hsound)B"},
{0x6F3CCF80, "RegisterStackedSound", "(HsoundBRR)V"},
{0x6F3CCFB0, "UnregisterStackedSound", "(HsoundBRR)V"},
{0x6F3CCFE0, "AddWeatherEffect", "(HrectI)Hweathereffect"},
{0x6F3B3E70, "RemoveWeatherEffect", "(Hweathereffect)V"},
{0x6F3B3E80, "EnableWeatherEffect", "(HweathereffectB)V"},
{0x6F3B3E90, "TerrainDeformCrater", "(RRRRIB)Hterraindeformation"},
{0x6F3B3F00, "TerrainDeformRipple", "(RRRRIIRRRB)Hterraindeformation"},
{0x6F3B3FA0, "TerrainDeformWave", "(RRRRRRRRII)Hterraindeformation"},
{0x6F3B4040, "TerrainDeformRandom", "(RRRRRII)Hterraindeformation"},
{0x6F3B40B0, "TerrainDeformStop", "(HterraindeformationI)V"},
{0x6F3B40C0, "TerrainDeformStopAll", "()V"},
{0x6F3CD240, "DestroyEffect", "(Heffect)V"},
{0x6F3BCA90, "AddSpecialEffect", "(SRR)Heffect"},
{0x6F3CD260, "AddSpecialEffectLoc", "(SHlocation)Heffect"},
{0x6F3CD2A0, "AddSpecialEffectTarget", "(SHwidgetS)Heffect"},
{0x6F3BCB10, "AddSpellEffect", "(SHeffecttypeRR)Heffect"},
{0x6F3CD320, "AddSpellEffectLoc", "(SHeffecttypeHlocation)Heffect"},
{0x6F3BCAE0, "AddSpellEffectById", "(IHeffecttypeRR)Heffect"},
{0x6F3CD2D0, "AddSpellEffectByIdLoc", "(IHeffecttypeHlocation)Heffect"},
{0x6F3CD4A0, "AddSpellEffectTarget", "(SHeffecttypeHwidgetS)Heffect"},
{0x6F3CD380, "AddSpellEffectTargetById", "(IHeffecttypeHwidgetS)Heffect"},
{0x6F3BCC20, "AddLightning", "(SBRRRR)Hlightning"},
{0x6F3BCB30, "AddLightningEx", "(SBRRRRRR)Hlightning"},
{0x6F3B4150, "DestroyLightning", "(Hlightning)B"},
{0x6F3B8310, "GetLightningColorA", "(Hlightning)R"},
{0x6F3B8370, "GetLightningColorR", "(Hlightning)R"},
{0x6F3B83D0, "GetLightningColorG", "(Hlightning)R"},
{0x6F3B8430, "GetLightningColorB", "(Hlightning)R"},
{0x6F3BCDA0, "MoveLightning", "(HlightningBRRRR)B"},
{0x6F3BCCC0, "MoveLightningEx", "(HlightningBRRRRRR)B"},
{0x6F3B8490, "SetLightningColor", "(HlightningRRRR)B"},
{0x6F3BCAB0, "GetAbilityEffect", "(SHeffecttypeI)S"},
{0x6F3BCE40, "GetAbilityEffectById", "(IHeffecttypeI)S"},
{0x6F3BCE60, "GetAbilitySound", "(SHsoundtype)S"},
{0x6F3BCEA0, "GetAbilitySoundById", "(IHsoundtype)S"},
{0x6F3B4190, "GetTerrainCliffLevel", "(RR)I"},
{0x6F3B8580, "SetWaterBaseColor", "(IIII)V"},
{0x6F3B4240, "SetWaterDeforms", "(B)V"},
{0x6F3BCED0, "GetTerrainType", "(RR)I"},
{0x6F3B4250, "GetTerrainVariance", "(RR)I"},
{0x6F3BCF20, "SetTerrainType", "(RRIIII)V"},
{0x6F3B42D0, "IsTerrainPathable", "(RRHpathingtype)B"},
{0x6F3B42F0, "SetTerrainPathable", "(RRHpathingtypeB)V"},
{0x6F3B4320, "CreateImage", "(SRRRRRRRRRI)Himage"},
{0x6F3B43B0, "DestroyImage", "(Himage)V"},
{0x6F3B43C0, "ShowImage", "(HimageB)V"},
{0x6F3B43E0, "SetImageConstantHeight", "(HimageBR)V"},
{0x6F3B4400, "SetImagePosition", "(HimageRRR)V"},
{0x6F3B85B0, "SetImageColor", "(HimageIIII)V"},
{0x6F3B4440, "SetImageRender", "(HimageB)V"},
{0x6F3B4460, "SetImageRenderAlways", "(HimageB)V"},
{0x6F3B4480, "SetImageAboveWater", "(HimageBB)V"},
{0x6F3B44A0, "SetImageType", "(HimageI)V"},
{0x6F3B85F0, "CreateUbersplat", "(RRSIIIIBB)Hubersplat"},
{0x6F3B44C0, "DestroyUbersplat", "(Hubersplat)V"},
{0x6F3B44D0, "ResetUbersplat", "(Hubersplat)V"},
{0x6F3B44E0, "FinishUbersplat", "(Hubersplat)V"},
{0x6F3B44F0, "ShowUbersplat", "(HubersplatB)V"},
{0x6F3B4510, "SetUbersplatRender", "(HubersplatB)V"},
{0x6F3B4530, "SetUbersplatRenderAlways", "(HubersplatB)V"},
{0x6F3CD4C0, "SetBlight", "(HplayerRRRB)V"},
{0x6F3CD5D0, "SetBlightLoc", "(HplayerHlocationRB)V"},
{0x6F3CD520, "SetBlightRect", "(HplayerHrectB)V"},
{0x6F3CD580, "SetBlightPoint", "(HplayerRRB)V"},
{0x6F3CD630, "CreateBlightedGoldmine", "(HplayerRRR)Hunit"},
{0x6F3B4550, "IsPointBlighted", "(RR)B"},
{0x6F3B4570, "SetDoodadAnimation", "(RRRIBSB)V"},
{0x6F3CD6F0, "SetDoodadAnimationRect", "(HrectISB)V"},
{0x6F3CB740, "StartMeleeAI", "(HplayerS)V"},
{0x6F3CB770, "StartCampaignAI", "(HplayerS)V"},
{0x6F3CB7A0, "CommandAI", "(HplayerII)V"},
{0x6F3CB7C0, "PauseCompAI", "(HplayerB)V"},
{0x6F3CB7E0, "GetAIDifficulty", "(Hplayer)Haidifficulty"},
{0x6F3CB820, "RemoveGuardPosition", "(Hunit)V"},
{0x6F3CB800, "RecycleGuardPosition", "(Hunit)V"},
{0x6F3CB840, "RemoveAllGuardPositions", "(Hplayer)V"},
{0x6F3D3F30, "ExecuteFunc", "(S)V"},
{0x6F3B3BC0, "Cheat", "(S)V"},
{0x6F3BC8C0, "IsNoVictoryCheat", "()B"},
{0x6F3BC8F0, "IsNoDefeatCheat", "()B"},
{0x6F3B5170, "Preload", "(S)V"},
{0x6F3B5190, "PreloadEnd", "(R)V"},
{0x6F3B51F0, "PreloadStart", "()V"},
{0x6F3B5210, "PreloadRefresh", "()V"},
{0x6F3B5220, "PreloadEndEx", "()V"},
{0x6F3B5290, "PreloadGenStart", "()V"},
{0x6F3B52B0, "PreloadGenClear", "()V"},
{0x6F3B52D0, "PreloadGenEnd", "(S)V"},
{0x6F3B5310, "Preloader", "(S)V"}}

function IntToHexString(i)
	p = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"}
	s = ""
	while(i>0) do
		k = i%16
		s = p[k+1]..s
		i=math.floor(i/16)
	end
	s = "0x"..s
	return s
end

function IntToDecString(i)
	p = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"}
	s = ""
	while(i>0) do
		k = i%10
		s = p[k+1]..s
		i=math.floor(i/10)
	end
	return s
end

ntable2 = {}
for i in pairs(ntable) do
	ntable2[i] = {}
	ntable2[i]["offset"] = ntable[i][1]-0x6F000000
	ntable2[i]["name"] = ntable[i][2]
	args = ntable[i][3]
	t = args:find(")")
	ntable2[i]["ret"] = args:sub(t+1,t+1)
	args = args:sub(2,t-1)
	-- ntable2[i]["args"] = args
	argt = {}
	p = 1
	while(args~="") do
		pI = args:find("I")
		pH = args:find("H")
		pR = args:find("R")
		pB = args:find("B")
		pS = args:find("S")
		pC = args:find("C")
		t = 999999
		if(pI~=nil) then
			t = math.min(pI,t)
		end
		if(pH~=nil) then
			t = math.min(pH,t)
		end
		if(pR~=nil) then
			t = math.min(pR,t)
		end
		if(pB~=nil) then
			t = math.min(pB,t)
		end
		if(pS~=nil) then
			t = math.min(pS,t)
		end
		if(pC~=nil) then
			t = math.min(pC,t)
		end
		if t == 999999 then
			args = ""
		else
			argt[p]=(args:sub(t,t))
			args = args:sub(t+1)
			p = p + 1
		end
	end
	ntable2[i]["args"] = argt
end

nativetype = io.open("reg.txt","w")
for i in pairs(ntable2) do
	native = ntable2[i]
	ret = native["ret"]
	str = "typedef "
	if(ret=="V") then
		str = str.."void   "
	elseif(ret=="B") then
		str = str.."bool   "
	elseif(ret=="R") then
		str = str.."int  "
	elseif(ret=="I") then
		str = str.."int    "
	elseif(ret=="H") then
		str = str.."jHANDLE"
	elseif(ret=="S") then
		str = str.."jSTRING"
	elseif(ret=="C") then
		str = str.."jCODE"
	end
	str = str.." (__cdecl* GAME_"..native["name"]..") ("
	for j in pairs(native["args"]) do
		arg = native["args"][j]
		if(arg=="H") then
			str = str.."jHANDLE"
		elseif(arg=="R") then
			str = str.."float*"
		elseif(arg=="I") then
			str = str.."int"
		elseif(arg=="S") then
			str = str.."jSTRING"
		elseif(arg=="B") then
			str = str.."int"
		elseif(arg=="C") then
			str = str.."jCODE"
		end
		if(native["args"][j+1]~=nil) then
			str = str..", "
		end
	end
	str = str..");\n"
	nativetype:write(str)
	io.flush()
end
io.close(nativetype)

nativenames = io.open("nativenames.txt","w")
for i in pairs(ntable2) do
	native = ntable2[i]
	name = native["name"]
	str = "GAME_"..name
	jtype = "GAME_"..name.." "
	length = jtype:len()
	p = ""
	j = 45-length
	while j>1 do
		p = p.." "
		j = j - 1
	end
	str = str..p
	length = jtype:len()
	p = ""
	j = 40-length
	while j>1 do
		p = p.." "
		j = j - 1
	end
	str = str.."j"..name..";\n"
	
	nativenames:write(str)
	io.flush()
end
io.close(nativenames)

initnatives = io.open("initnatives.txt","w")
for i in pairs(ntable2) do
	native = ntable2[i]
	name = native["name"]
	length = name:len()
	str = "j"..name
	p = ""
	j = 40-length
	while j>1 do
		p = p.." "
		j = j - 1
	end
	str = str..p
	str = str.." = (GAME_"..name..")"..p.."(dwGameDll + "..IntToHexString(native["offset"])..");\n"
	
	initnatives:write(str)
	io.flush()
end
io.close(initnatives)

extnatives = io.open("extnatives.txt","w")
for i in pairs(ntable2) do
	native = ntable2[i]
	name = native["name"]
	length = name:len()
	p = ""
	j = 45-length
	while j>1 do
		p = p.." "
		j = j - 1
	end
	str = "extern GAME_"..name..p.."j"..name..";\n"
	
	extnatives:write(str)
	io.flush()
end
io.close(extnatives)

cfunc = io.open("cfuncs.txt","w")
for i in pairs(ntable2) do
	native = ntable2[i]
	ret = native["ret"]
	name = native["name"]
	str = ""
	if(ret=="V") then
		str = " void   "
	elseif(ret=="B") then
		str = " bool   "
	elseif(ret=="R") then
		str = " float  "
	elseif(ret=="I") then
		str = " int    "
	elseif(ret=="H") then
		str = " jHANDLE"
	elseif(ret=="S") then
		str = " const char*"
	elseif(ret=="C") then
		str = " jCODE"
	end
	str=str.." "..name.." ("
	t = 1
	for j in pairs(native["args"]) do
		arg = native["args"][j]
		if(arg=="H") then
			str = str.."jHANDLE  HANDLE_"..IntToDecString(t)
		elseif(arg=="R") then
			str = str.."float   real_"..IntToDecString(t)
		elseif(arg=="I") then
			str = str.."int      integer_"..IntToDecString(t)
		elseif(arg=="S") then
			str = str.."const char*  STRING_"..IntToDecString(t)
		elseif(arg=="B") then
			str = str.."bool     BOOL_"..IntToDecString(t)
		elseif(arg=="C") then
			str = str.."jCODE     jCODE_"..IntToDecString(t)
		end
		if(native["args"][j+1]~=nil) then
			str = str..", "
		end
		t = t + 1
	end
	str = str..")\n{\n"
	if(ret=="V") then
	str=str.."    j"..name.."("
	elseif(ret=="S") then
		str=str.."    return (const char*)GetStringAddress(j"..name.."("
	elseif(ret=="R") then
		str=str.."    int ret = (j"..name.."("
	else
		str=str.."    return j"..name.."("
	end
	
	t = 1
	for j in pairs(native["args"]) do
		arg = native["args"][j]
		if(arg=="H") then
			str = str.."HANDLE_"..IntToDecString(t)
		elseif(arg=="R") then
			str = str.."&real_"..IntToDecString(t)
		elseif(arg=="I") then
			str = str.."integer_"..IntToDecString(t)
		elseif(arg=="S") then
			str = str.."RegStr(STRING_"..IntToDecString(t)..")"
		elseif(arg=="B") then
			str = str.."BOOL_"..IntToDecString(t)
		elseif(arg=="C") then
			str = str.."jCODE_"..IntToDecString(t)
		end
		if(native["args"][j+1]~=nil) then
			str = str..", "
		end
		t = t + 1
	end
	if(ret=="S") then
		str=str.."));"
	elseif(ret=="R") then
		str=str.."));\n\treturn *(float*)&ret;"
	else
		str=str..");"
	end
	str = str.."\n}\n"
	cfunc:write(str)
	io.flush()
end
io.close(cfunc)

cheaders = io.open("cheaders.txt","w")
for i in pairs(ntable2) do
	native = ntable2[i]
	ret = native["ret"]
	name = native["name"]
	str = " "
	if(ret=="V") then
		str = "void   "
	elseif(ret=="B") then
		str = "bool   "
	elseif(ret=="R") then
		str = "float  "
	elseif(ret=="I") then
		str = "int    "
	elseif(ret=="H") then
		str = "jHANDLE"
	elseif(ret=="S") then
		str = "const char*"
	end
	str=str.." "..name.." ("
	t = 1
	for j in pairs(native["args"]) do
		arg = native["args"][j]
		if(arg=="H") then
			str = str.."jHANDLE  HANDLE_"..IntToDecString(t)
		elseif(arg=="R") then
			str = str.."float*   real_"..IntToDecString(t)
		elseif(arg=="I") then
			str = str.."int      integer_"..IntToDecString(t)
		elseif(arg=="S") then
			str = str.."const char*  STRING_"..IntToDecString(t)
		elseif(arg=="B") then
			str = str.."bool     BOOL_"..IntToDecString(t)
		elseif(arg=="C") then
			str = str.."jCODE     jCODE_"..IntToDecString(t)
		end
		if(native["args"][j+1]~=nil) then
			str = str..", "
		end
		t = t + 1
	end
	str = str..");\n"
	cheaders:write(str)
	io.flush()
end
io.close(cheaders)

luareg = io.open("luareg.txt","w")
for i in pairs(ntable2) do
	native = ntable2[i]
	name = native["name"]
	
	str = "    binder->def(\""..name.."\","..name..");\n"
	luareg:write(str)
	io.flush()
end
io.close(luareg)

luahead = io.open("luahead.txt","w")
for i in pairs(ntable2) do
	native = ntable2[i]
	ret = native["ret"]
	name = native["name"]
	str = "int L"..name.."(lua_State* io_luaState);\n"
	luahead:write(str)
	io.flush()
end
luahead:close()