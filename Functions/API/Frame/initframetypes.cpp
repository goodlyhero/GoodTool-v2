#include <From MemHack.h>
#include <Logs/Log.h>
void initframetypes()
{
	AddFrameType("CBackdropFrame", 1, 0x96F3F4, 0x96F3CC);
	AddFrameType("CButtonFrame", 2, 0x96F6FC, 0x96F6D4);
	AddFrameType("CChatMode", 3, 0x93A8BC, 0x000000);
	AddFrameType("CCommandButton", 4, 0x93EBC4, 0x000000);
	AddFrameType("CCursorFrame", 5, 0x97063C, 0x970610);
	AddFrameType("CEditBox", 6, 0x96ECEC, 0x96ECC0);
	AddFrameType("CFrame", 7, 0x96DEB4, 0x96DE8C);
	AddFrameType("CFloatingFrame", 8, 0x96FAB4, 0x96FA88);
	AddFrameType("CGameUI", 9, 0x93631C, 0x9362F4);
	AddFrameType("CHeroBarButton", 10, 0x93F8DC, 0x93F8BC);
	AddFrameType("CHighlightFrame", 11, 0x96F974, 0x96F94C);
	AddFrameType("CLayoutFrame", 12, 0x96DE48, 0x000000);
	AddFrameType("CMessageFrame", 13, 0x96F864, 0x96F83C);
	AddFrameType("CMinimap", 14, 0x94002C, 0x940004);
	AddFrameType("CModelFrame", 15, 0x96F5AC, 0x96F584);
	AddFrameType("CPortraitButton", 16, 0x9401E4, 0x9401BC);
	AddFrameType("CScreenFrame", 17, 0x96E07C, 0x96E054);
	AddFrameType("CSimpleButton", 18, 0x96DC8C, 0x000000);
	AddFrameType("CSimpleFontString", 19, 0x96E404, 0x000000);
	AddFrameType("CSimpleFrame", 20, 0x96DFB4, 0x000000);
	AddFrameType("CSimpleGlueFrame", 21, 0x96EE04, 0x000000);
	AddFrameType("CUknown_1", 22, 0x000000, 0x000000);
	AddFrameType("CSimpleMessageFrame", 23, 0x96DD84, 0x000000);
	AddFrameType("CSlider", 24, 0x96F274, 0x96F24C);
	AddFrameType("CSpriteFrame", 25, 0x96E584, 0x96E558);
	AddFrameType("CStatBar", 26, 0x93E604, 0x000000);
	AddFrameType("CTextArea", 27, 0x96EFD4, 0x96EFAC);
	AddFrameType("CTextButtonFrame", 28, 0x96F114, 0x96F0E8);
	AddFrameType("CTextFrame", 29, 0x96E9B4, 0x96E988);
	AddFrameType("CUberToolTipWar3", 30, 0x93F68C, 0x000000);
	AddFrameType("CWorldFrameWar3", 31, 0x94157C, 0x941550);
	AddFrameType("CGlueButtonWar3", 32, 0x95C92C, 0x95C900);
	AddFrameType("CGlueTextButtonWar3", 33, 0x95A00C, 0x959FE0);
	AddFrameType("CGlueCheckBoxWar3", 34, 0x95C7EC, 0x95C7C0);
	AddFrameType("CGluePopupMenuWar3", 35, 0x959E84, 0x959E5C);
	AddFrameType("CGlueEditBoxWar3", 36, 0x95CA6C, 0x95CA40);
	AddFrameType("CSlashChatBox", 37, 0x95DAEC, 0x95DAC4);
	AddFrameType("CTimerTextFrame", 38, 0x95A564, 0x95A538);
	AddFrameType("CSimpleStatusBar", 39, 0x96E48C, 0x000000);
	AddFrameType("CStatusBar", 40, 0x970264, 0x97023C);
	AddFrameType("CUpperButtonBar", 41, 0x93C3E4, 0x93C3C4);
	AddFrameType("CResourceBar", 42, 0x93D22C, 0x000000);
	AddFrameType("CSimpleConsole", 43, 0x93BD2C, 0x000000);
	AddFrameType("CPeonBar", 44, 0x93FC0C, 0x93FBF0);
	AddFrameType("CHeroBar", 45, 0x93F974, 0x93F958);
	AddFrameType("CTimeOfDayIndicator", 46, 0x93FE64, 0x93FE38);
	AddFrameType("CInfoBar", 47, 0x94066C, 0x000000);
	AddFrameType("CTimeCover", 48, 0x93C054, 0x93C028);
	AddFrameType("CProgressIndicator", 49, 0x93834C, 0x000000);
	AddFrameType("CHeroLevelBar", 50, 0x93FA24, 0x000000);
	AddFrameType("CBuildTimeIndicator", 51, 0x93D684, 0x000000);
	AddFrameType("CInfoPanelDestructableDetail", 52, 0x93CE54, 0x000000);
	AddFrameType("CInfoPanelItemDetail", 53, 0x93B4C4, 0x000000);
	AddFrameType("CInfoPanelIconAlly", 54, 0x93B374, 0x000000);
	AddFrameType("CInfoPanelIconHero", 55, 0x93B284, 0x000000);
	AddFrameType("CInfoPanelIconGold", 56, 0x93B20C, 0x000000);
	AddFrameType("CInfoPanelIconFood", 57, 0x93B194, 0x000000);
	AddFrameType("CInfoPanelIconRank", 58, 0x93B11C, 0x000000);
	AddFrameType("CInfoPanelIconArmor", 59, 0x93B0A4, 0x000000);
	AddFrameType("CInfoPanelIconDamage", 60, 0x93B02C, 0x000000);
	AddFrameType("CInfoPanelCargoDetail", 61, 0x93CF8C, 0x000000);
	AddFrameType("CInfoPanelBuildingDetail", 62, 0x93DE9C, 0x000000);
	AddFrameType("CInfoPanelUnitDetail", 63, 0x93CF0C, 0x000000);
	AddFrameType("CSimpleTexture", 64, 0x96E440, 0x000000);
	AddFrameType("CIconCover", 65, 0x93ADFC, 0x000000);
	AddFrameType("CMinimap", 66, 0x941024, 0x000000);
	mlog::Debug("Initialized Frame Types");
}