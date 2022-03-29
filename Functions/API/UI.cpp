#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>
#include <Functions.h>

int SetUIFramePoint(int pFrame, int point, int pParentFrame, int relativePoint, float x, float y)
{
    DWORD fid_1 = GetFrameType(pFrame);
    DWORD fid_2 = GetFrameType(pParentFrame);

        if (fid_1 != 0 && fid_2 != 0)
        {
            if (fid_1 != 9)
            {
                pFrame = GetFrameLayoutByType(pFrame, fid_1);
            }

            if (fid_2 != 9)
            {
                pParentFrame = GetFrameLayoutByType(pParentFrame, fid_2);
            }

            return SetCLayoutFramePoint(pFrame, point, pParentFrame, relativePoint, x, y);
        }

    return 0;
}

void HideUI(void)
{
    DWORD pRootFrame = GetRootFrame();

        if (pRootFrame > 0)
        {
            SetUIFramePoint(GetUIUpperButtonBarFrame(), ANCHOR_TOPLEFT, pRootFrame, ANCHOR_TOPLEFT, 0.0, 1.0);
            SetUIFramePoint(GetUIResourceBarFrame(), ANCHOR_TOPRIGHT, pRootFrame, ANCHOR_TOPRIGHT, 0.0, 1.0);

            SetUIFramePoint(GetUISimpleConsole(), ANCHOR_TOPLEFT, pRootFrame, ANCHOR_TOPLEFT, 10.0, 0.0);
            SetUIFramePoint(GetUISimpleConsole(), ANCHOR_TOPRIGHT, pRootFrame, ANCHOR_TOPRIGHT, -10.0, 0.0);

            SetUIFramePoint(GetUIPortrait(), ANCHOR_BOTTOMLEFT, pRootFrame, ANCHOR_BOTTOMLEFT, 1.0, 1.0);
            SetUIFramePoint(GetUIMinimap(), ANCHOR_BOTTOMLEFT, pRootFrame, ANCHOR_BOTTOMLEFT, 1.0, 1.0);

            SetUIFramePoint(GetUIPeonBar(), ANCHOR_BOTTOMLEFT, pRootFrame, ANCHOR_BOTTOMLEFT, 1.0, 1.0);
            SetUIFramePoint(GetUIHeroBar(), ANCHOR_TOPLEFT, pRootFrame, ANCHOR_TOPLEFT, 0.0, 1.0);

            SetUIFramePoint(GetUITimeOfDayIndicator(), ANCHOR_BOTTOMLEFT, pRootFrame, ANCHOR_BOTTOMLEFT, 1.0, 1.0);
            SetUIFramePoint(ReadRealMemory(GetUITimeOfDayIndicator() + 0x1B0), ANCHOR_TOP, pRootFrame, ANCHOR_TOP, 1.0, 0.0); // TimeOfDayIndicator UBERTIP;
            SetUIFramePoint(ReadRealMemory(GetUIInfoBar() + 0x14C), ANCHOR_BOTTOMRIGHT, pRootFrame, ANCHOR_TOPLEFT, 1.0, 0.0);// ConsoleInventoryCoverTexture;
            HideFrame(GetUITimeOfDayIndicator());
        }
}

void ShowUI(void)
{
    DWORD pRootFrame = GetRootFrame();

        if (pRootFrame > 0)
        {
            SetUIFramePoint(GetUIUpperButtonBarFrame(), ANCHOR_TOPLEFT, pRootFrame, ANCHOR_TOPLEFT, 0.0, 0.0);
            SetUIFramePoint(GetUIResourceBarFrame(), ANCHOR_TOPRIGHT, pRootFrame, ANCHOR_TOPRIGHT, 0.0, 0.0);

            SetUIFramePoint(GetUISimpleConsole(), ANCHOR_TOPLEFT, pRootFrame, ANCHOR_TOPLEFT, 0.0, 0.0);
            SetUIFramePoint(GetUISimpleConsole(), ANCHOR_TOPRIGHT, pRootFrame, ANCHOR_TOPRIGHT, 0.0, 0.0);

            SetUIFramePoint(GetUIPortrait(), ANCHOR_BOTTOMLEFT, pRootFrame, ANCHOR_BOTTOMLEFT, 0.207500, 0.030625);
            SetUIFramePoint(GetUIMinimap(), ANCHOR_BOTTOMLEFT, pRootFrame, ANCHOR_BOTTOMLEFT, 0.009375, 0.006875);

            SetUIFramePoint(GetUIPeonBar(), ANCHOR_BOTTOMLEFT, pRootFrame, ANCHOR_BOTTOMLEFT, 0.003750, 0.170000);
            SetUIFramePoint(GetUIHeroBar(), ANCHOR_TOPLEFT, pRootFrame, ANCHOR_TOPLEFT, 0.003750, -0.026250);

            SetUIFramePoint(GetUITimeOfDayIndicator(), ANCHOR_BOTTOMLEFT, pRootFrame, ANCHOR_BOTTOMLEFT, 0.0, 0.0);
            SetUIFramePoint(ReadRealMemory(GetUITimeOfDayIndicator() + 0x1B0), ANCHOR_TOP, pRootFrame, ANCHOR_TOP, 0.0, 0.0); // TimeOfDayIndicator UBERTIP;
            SetUIFramePoint(ReadRealMemory(GetUIInfoBar() + 0x14C), ANCHOR_BOTTOMRIGHT, pRootFrame, ANCHOR_TOPLEFT, -0.200000, 0.0); // ConsoleInventoryCoverTexture;
            ShowFrame(GetUITimeOfDayIndicator());
        }
}

void EditBlackBorders(float topX, float topY, float botX, float botY)
{
    DWORD pRootFrame = GetRootFrame();
    DWORD pWorldFrameWar3 = GetUIWorldFrameWar3();

        if (pRootFrame > 0)
        {
            SetUIFramePoint(pWorldFrameWar3, ANCHOR_TOPRIGHT, pRootFrame, ANCHOR_TOPRIGHT, topX, topY);
            SetUIFramePoint(pWorldFrameWar3, ANCHOR_BOTTOMLEFT, pRootFrame, ANCHOR_BOTTOMLEFT, botX, botY);
        }
}

void HideBlackBorders(void)
{
    EditBlackBorders(0., 0., 0., 0.);
}

void ShowBlackBorders(void)
{
    EditBlackBorders(0., -.02, 0., .13);
}

void EditMiniMap(int point, float topX, float topY, float botX, float botY)
{
    DWORD pRootFrame = GetRootFrame();
    DWORD pMiniMapFrame = GetUIMinimap();

        if (pRootFrame > 0)
        {
            SetUIFramePoint(pMiniMapFrame, ANCHOR_TOPRIGHT, pRootFrame, point, topX, topY);
            SetUIFramePoint(pMiniMapFrame, ANCHOR_BOTTOMLEFT, pRootFrame, point, botX, botY);
        }
}

void HideMiniMap(void)
{
    float xMul = .8 / GetWindowWidth();
    float yMul = .6 / GetWindowHeight();

        EditMiniMap(ANCHOR_TOPRIGHT, -2. * xMul + xMul, 0., -2. * xMul, -yMul);
}

void ShowMiniMap(void)
{
    EditMiniMap(ANCHOR_BOTTOMLEFT, 0.14875, 0.145, 0.009375, 0.006875);
}

void EditCommandBarButton(int row, int column, int anchor, float offsetX, float offsetY, float width, float height)
{
    DWORD pButtonFrame = GetCommandBarButton(row, column);
    DWORD pRootFrame = GetRootFrame();

        if (pButtonFrame != NULL && pRootFrame != NULL)
        {
            if (width <= 0.f)
            {
                width = 0.01f;
            }
            SetFrameWidth(pButtonFrame, width);
            if (height <= 0.f)
            {
                height = 0.01f;
            }
            SetFrameHeight(pButtonFrame, height);
            SetUIFramePoint(pButtonFrame, ANCHOR_TOPLEFT, pRootFrame, anchor, offsetX, -offsetY);
        }
}

void EditItemBarButton(int buttonId, int anchor, float offsetX, float offsetY, float width, float height)
{
    DWORD pButtonFrame = GetItemBarButton(buttonId);
        DWORD pRootFrame = GetRootFrame();

        if( pButtonFrame > 0)
        {
            if( width >= 0.)
            {
                SetFrameWidth(pButtonFrame, width);
            }

            if( height >= 0.)
            {
                SetFrameHeight(pButtonFrame, height);
            }

            SetUIFramePoint(pButtonFrame, ANCHOR_TOPLEFT, pRootFrame, anchor, offsetX, -offsetY);
        }
}

void EditMinimapButton(int buttonId, int anchor, float offsetX, float offsetY, float width, float height)
{
    DWORD pButtonFrame = GetMinimapButton(buttonId);
    DWORD pRootFrame = GetRootFrame();

        if (pButtonFrame > 0)
        {
            if (width >= 0.)
            {
                SetFrameWidth(pButtonFrame, width);
            }

            if (height >= 0.)
            {
                SetFrameHeight(pButtonFrame, height);
            }

            SetUIFramePoint(pButtonFrame, ANCHOR_TOPLEFT, pRootFrame, anchor, offsetX, -offsetY);
        }
}

void EditUpperButtonBarButton(int buttonId, int anchor, float offsetX, float offsetY, float width, float height)
{
    DWORD pButtonFrame = GetUpperButtonBarButton(buttonId);
    DWORD pRootFrame = GetRootFrame();

        if (pButtonFrame > 0)
        {
            if (width >= 0.)
            {
                SetFrameWidth(pButtonFrame, width);
            }

            if (height >= 0.)
            {
                SetFrameHeight(pButtonFrame, height);
            }

            if (buttonId == 0)
            {
                SetUIFramePoint(pButtonFrame, ANCHOR_TOPLEFT, pRootFrame, anchor, offsetX, -offsetY);
            }
            else
            {
                SetUIFramePoint(pButtonFrame, ANCHOR_LEFT, pRootFrame, anchor, offsetX, -(offsetY + GetFrameHeight(pButtonFrame) / 2.));
            }
        }
}

void EditHeroBarButton(int buttonId, int anchor, float offsetX, float offsetY, float width, float height)
{
    DWORD pButtonFrame = GetHeroBarButton(buttonId);
    DWORD pRootFrame = GetRootFrame();

        if (pButtonFrame > 0)
        {
            if (width >= 0.)
            {
                SetFrameWidth(pButtonFrame, width);
            }

            if (height >= 0.)
            {
                SetFrameHeight(pButtonFrame, height);
            }

            SetUIFramePoint(pButtonFrame, ANCHOR_TOPLEFT, pRootFrame, anchor, offsetX, -offsetY);
        }
}

void EditHeroBarHealthBar(int buttonId, int anchor, float offsetX, float offsetY, float width, float height)
{
    DWORD pHealthFrame = GetHeroBarHealthBar(buttonId);
    DWORD pRootFrame = GetRootFrame();

        if( pHealthFrame > 0)
        {
            if( width >= 0.)
            {
                SetFrameWidth(pHealthFrame, width);
            }

            if (height >= 0.)
            {
                SetFrameHeight(pHealthFrame, height);
            }

            SetUIFramePoint(pHealthFrame, ANCHOR_TOP, pRootFrame, anchor, offsetX + GetFrameWidth(pHealthFrame) / 2., -offsetY);
        }
}

void EditHeroBarManaBar(int buttonId, int anchor, float offsetX, float offsetY, float width, float height)
{
    DWORD pManaFrame = GetHeroBarManaBar(buttonId);
    DWORD pRootFrame = GetRootFrame();

        if (pManaFrame > 0)
        {
            if( width >= 0.)
            {
                SetFrameWidth(pManaFrame, width);
            }

            if( height >= 0.)
            {
                SetFrameHeight(pManaFrame, height);
            }

            SetUIFramePoint(pManaFrame, ANCHOR_TOP, pRootFrame, anchor, offsetX + GetFrameWidth(pManaFrame) / 2., -offsetY);
        }
}

void EditTooltip(int anchor, float offsetX, float offsetY, float width)
{
    DWORD pRootFrame = GetRootFrame();
    DWORD pTooltipFrame = fast_call(pGetTooltipFrame, 0);

        if (pTooltipFrame > 0)
        {
            if (width >= 0.)
            {
                SetFrameWidth(pTooltipFrame, width); // Borders;
                SetFrameWidth(ReadRealMemory(pTooltipFrame + 0x180), width); // Text;
            }
            //call SetUIFramePoint( pTooltipFrame, ANCHOR_BOTTOMRIGHT, pRootFrame, anchor, offsetX + GetFrameWidth( pTooltipFrame ), -( offsetY + GetFrameHeight( pTooltipFrame ) ) ) // offsetX = 0, offsetY = 0 - top left corner
            SetUIFramePoint(pTooltipFrame, ANCHOR_BOTTOMRIGHT, pRootFrame, anchor, offsetX, -offsetY); // offsetX = 0, offsetY = 0 - bottom right corner;
        }
}

void ShowAllUI(void)
{
    ShowBlackBorders();
    ShowUI();
    ShowMiniMap();
}

void HideAllUI(void)
{
    HideBlackBorders();
    HideUI();
    HideMiniMap();
}

