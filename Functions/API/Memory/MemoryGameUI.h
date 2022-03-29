#pragma once
#include <BasicConstants.h>


DWORD GetGameUI(int bInit, int bRelease);

DWORD GetRootFrame(void);

// Frame Game API Engine
DWORD GetUIWorldFrameWar3(void);

DWORD GetUIMinimap(void);

DWORD GetUIInfoBar(void);

DWORD GetUICommandBar(void);

DWORD GetUIResourceBarFrame(void);

DWORD GetUIUpperButtonBarFrame(void);

DWORD GetUIUnknown1(void);

DWORD GetUIClickableBlock(void);

DWORD GetUIHeroBar(void);

DWORD GetUIPeonBar(void);

DWORD GetUIMessage(void);

DWORD GetUIUnitMessage(void);

DWORD GetUIChatMessage(void);

DWORD GetUITopMessage(void);

DWORD GetUIPortrait(void);

DWORD GetUITimeOfDayIndicator(void);

DWORD GetUIChatEditBar(void);

DWORD GetUICinematicPanel(void);

DWORD GetUIUnknown2(void);

DWORD GetUIMinimapButton1(void);

DWORD GetUIMinimapButton2(void);

DWORD GetUIMinimapButton3(void);

DWORD GetUIMinimapButton4(void);

DWORD GetUIMinimapButton5(void);

DWORD GetUIFrameB(void);

DWORD GetUIMouseBorders(void);

DWORD GetUIFrameA(void);

DWORD GetUISimpleConsole(void);

DWORD GetPanelButton(int pFrame, int row, int column);

DWORD GetMinimapButton(int id);

DWORD GetUpperButtonBarButton(int id);

DWORD GetCommandBarButton(int row, int column);

DWORD GetSkillBarButton(int id);

DWORD GetItemBarButton(int id);

DWORD GetHeroBarButton(int id);

DWORD GetHeroBarHealthBar(int id);

DWORD GetHeroBarManaBar(int id);

void UpdateGameUI(void);

DWORD GetFrameType(DWORD pFrame);

DWORD SetWar3MapMap(const char* minimap);