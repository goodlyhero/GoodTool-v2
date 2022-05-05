#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <Logs\Log.h>
#include <Calls.h>
#include "FrameTypeHT.h"


DWORD GetGameUI(int bInit, int bRelease)
{
    return fast_call(pGetGameUI, bInit, bRelease);
}

DWORD GetRootFrame(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return pGameUI + 0xB4; //180;
    }

    return 0;
}

// Frame Game API Engine
DWORD GetUIWorldFrameWar3(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3BC); // if ReadRealMemory( GetUIWorldFrameWar3 + 0x1AC ) == 9 ???;
    }

    return 0;
}

DWORD GetUIMinimap(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3C0);
    }

    return 0;
}

DWORD GetUIInfoBar(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3C4);
    }

    return 0;
}

DWORD GetUICommandBar(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3C8);
    }

    return 0;
}

DWORD GetUIResourceBarFrame(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3CC);
    }

    return 0;
}

DWORD GetUIUpperButtonBarFrame(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3D0);
    }

    return 0;
}

DWORD GetUIUnknown1(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3D4); // ?;
    }

    return 0;
}

DWORD GetUIClickableBlock(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3D8);
    }

    return 0;
}

DWORD GetUIHeroBar(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3DC);
    }

    return 0;
}

DWORD GetUIPeonBar(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3E0);
    }

    return 0;
}

DWORD GetUIMessage(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3E4);
    }

    return 0;
}

DWORD GetUIUnitMessage(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3E8);
    }

    return 0;
}

DWORD GetUIChatMessage(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3EC);
    }

    return 0;
}

DWORD GetUITopMessage(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3F0);
    }

    return 0;
}

DWORD GetUIPortrait(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3F4);
    }

    return 0;
}

DWORD GetUITimeOfDayIndicator(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3F8);
    }

    return 0;
}

DWORD GetUIChatEditBar(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x3FC);
    }

    return 0;
}

DWORD GetUICinematicPanel(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x400);
    }

    return 0;
}

DWORD GetUIUnknown2(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x404);// ?;
    }

    return 0;
}

DWORD GetUIMinimapButton1(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x408);
    }

    return 0;
}

DWORD GetUIMinimapButton2(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x40C);
    }

    return 0;
}

DWORD GetUIMinimapButton3(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x410);
    }

    return 0;
}

DWORD GetUIMinimapButton4(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x414);
    }

    return 0;
}

DWORD GetUIMinimapButton5(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x418);
    }

    return 0;
}

DWORD GetUIFrameB(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x41C);
    }

    return 0;
}

DWORD GetUIMouseBorders(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x420);
    }

    return 0;
}

DWORD GetUIFrameA(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x424);
    }

    return 0;
}

DWORD GetUISimpleConsole(void)
{
    pGameUI = GetGameUI(0, 0);
    if (pGameUI > 0)
    {
        return ReadRealMemory(pGameUI + 0x428);
    }

    return 0;
}

DWORD GetPanelButton(int pFrame, int row, int column)
{
    if (pFrame > 0)
    {
        return ReadRealMemory(ReadRealMemory(0x10 * row + ReadRealMemory(pFrame + 0x154) + 0x8) + 0x4 * column);
    }

    return 0;
}

DWORD GetMinimapButton(int id)
{
    DWORD pMiniMap = GetUIMinimap();

    if (pMiniMap > 0)
    {
        if (id >= 0 && id <= 4)
        {
            return ReadRealMemory(pMiniMap + id * 4);
        }
    }

    return 0;
}

DWORD GetUpperButtonBarButton(int id)
{
    DWORD pOff = 0;
    DWORD pUpperButtonBar = GetUIUpperButtonBarFrame();

    if (pUpperButtonBar > 0)
    {
        if (id == 0)
        {
            pOff = 0x138;
        }
        else if (id == 1)
        {
            pOff = 0x130;
        }
        else if (id == 2)
        {
            pOff = 0x134;
        }
        else if (id == 3)
        {
            pOff = 0x160;
        }

        if (pOff > 0)
        {
            return ReadRealMemory(pUpperButtonBar + pOff);
        }
    }

    return 0;
}

DWORD GetCommandBarButton(int row, int column)
{
    DWORD pCommandBar = GetUICommandBar();

    if (pCommandBar > 0)
    {
        if (row >= 0 && row <= 2 && column >= 0 && column <= 3)
        {
            return GetPanelButton(pCommandBar, row, column);
        }
    }

    return 0;
}

DWORD GetSkillBarButton(int id)
{
    DWORD pUIBar = GetUICommandBar();
    DWORD pSkillBar = 0;

    if (pUIBar > 0)
    {
        if (id >= 0 && id <= 11)
        {
            pSkillBar = ReadRealMemory(pUIBar + 0x154);

            if (pSkillBar > 0)
            {
                return ReadRealMemory(ReadRealMemory(pSkillBar + 0x8)) + id * 0x1C0;
            }
        }
    }

    return 0;
}

DWORD GetItemBarButton(int id)
{
    DWORD pInfoBar = GetUIInfoBar();
    DWORD pItemBar = 0;

    if (pInfoBar > 0)
    {
        if (id >= 0 && id <= 5)
        {
            pItemBar = ReadRealMemory(pInfoBar + 0x148);

            if (pItemBar > 0)
            {
                //return ReadRealMemory( ReadRealMemory( pItemBar + 0x130 ) + id * 0x8 + 0x4 )
                return ReadRealMemory(ReadRealMemory(pItemBar + 0x130) + 0x4) + id * 0x1C0;
            }
        }
    }

    return 0;
}

DWORD GetHeroBarButton(int id)
{
    DWORD pHeroBar = GetUIHeroBar();

    if (pHeroBar > 0)
    {
        if (id >= 0 && id <= 6)
        {
            return GetPanelButton(pHeroBar, id, 0);
        }
    }

    return 0;
}

DWORD GetHeroBarHealthBar(int id)
{
    DWORD pHeroBar = GetHeroBarButton(id);

    if (pHeroBar > 0)
    {
        return ReadRealMemory(pHeroBar + 0x1CC);
    }

    return 0;
}

DWORD GetHeroBarManaBar(int id)
{
    DWORD pHeroBar = GetHeroBarButton(id);

    if (pHeroBar > 0)
    {
        return ReadRealMemory(pHeroBar + 0x1D0);
    }

    return 0;
}

void UpdateGameUI(void)
{
    if (pUpdateUI > 0)
    {
        this_call(pUpdateUI, 0);
    }
}

DWORD GetFrameType(DWORD pFrame)
{
    if (pFrame > 0)
    {
        DWORD vtable = ReadRealMemory(pFrame);
        //mlog::Debug("GetFrameType Debug addr", std::to_string(vtable).c_str());
        auto tpair = MemHackTable_FrameVT.find(vtable);
        if (tpair != MemHackTable_FrameVT.end())
        {
            return tpair->second;
            //mlog::Debug("GetFrameType Debug type", std::to_string(tpair->second).c_str());
        }
    }

    return 0;
}

DWORD SetWar3MapMap(const char* minimap)
{
    DWORD pMiniMap = GetUIMinimap();
    DWORD l__pTexture = 0;
    DWORD pOldTexture = 0;
    float ftmp = 0;

    if (pMiniMap > 0)
    {
        if (minimap != NULL)
        {
            if (pMiniMap > 0)
            {
                l__pTexture = fast_call(pTextureLoadImageAnyExt, (DWORD)minimap, (DWORD) & (ftmp), (DWORD) & (ftmp));

                if (l__pTexture > 0)
                {
                    pOldTexture = ReadRealMemory(pMiniMap + 0x17C);
                    if (pOldTexture > 0)
                    {
                        WriteRealMemory(pMiniMap + 0x17C, l__pTexture);
                        return this_call(pTextureUnloadImage, pOldTexture);
                    }
                    else
                    {
                        this_call(pTextureUnloadImage, l__pTexture);
                    }
                }
            }
        }
    }
    return 0;
}
