#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <Calls.h>
#include <API/Frame/Frame Include.h>
#include <API/Memory/MemoryGameUI.h>

int GetFrameByName(const char* name, int id)
{
    return GetCFrameByName(name, id);
}

int CreateFrameEx(const char* baseframe, DWORD parent, int point, int relativepoint, int id)
{
    return CreateCFrameEx(baseframe, parent, point, relativepoint, id);
}

int CreateFrame(const char* baseframe, DWORD parent, int id)
{
    return CreateFrameEx(baseframe, parent, 0, 0, id);
}

int CreateSimpleFrame(int parent)
{
    return CreateCSimpleFrame(parent);
}

bool GetUnitFramePosition(DWORD pUnit)
{
    if (pGetUnitFramePosition > 0)
    {
        return fast_call(pGetUnitFramePosition, pUnit, pUnitFramePosition, 0);
    }

    return false;
}

int HideFrame(DWORD pFrame)
{
    return HideCLayer(pFrame);
}

int ShowFrame(DWORD pFrame)
{
    return ShowCLayer(pFrame);
}

int SetFrameAlpha(DWORD pFrame, DWORD alpha)
{
    return SetCLayerAlpha(pFrame, alpha);
}

int SetLayerFont(DWORD pFrame, const char* filename, float height, int flag)
{
    return SetCLayerFont(pFrame, filename, height, flag);
}

int SetFrameTooltip(DWORD pFrame, int pTooltip)
{
    return SetCLayerTooltip(pFrame, pTooltip);
}

int SetFrameFocus(DWORD pFrame, bool flag)
{
    return SetCEditBoxFocus(pFrame, flag);
}

int SetFrameCageMouse(DWORD pFrame, bool flag)
{
    return SetCLayoutFrameCageMouse(pFrame, flag);
}

int SetFrameAbsolutePoint(DWORD pFrame, int point, float x, float y)
{
    DWORD fid_1 = GetFrameType(pFrame);

    if (fid_1 > 0)
    {
        pFrame = GetFrameLayoutByType(pFrame, fid_1);
        return SetCLayoutFrameAbsolutePoint(pFrame, point, x, y);
    }

    return 0;
}

int SetFramePoint(DWORD pFrame, int point, DWORD pParentFrame, int relativePoint, float x, float y)
{
    DWORD fid_1 = GetFrameType(pFrame);
    DWORD fid_2 = GetFrameType(pParentFrame);

    if (fid_1 > 0 && fid_2 > 0)
    {
        pFrame = GetFrameLayoutByType(pFrame, fid_1);
        pParentFrame = GetFrameLayoutByType(pParentFrame, fid_2);
        return SetCLayoutFramePoint(pFrame, point, pParentFrame, relativePoint, x, y);
    }

    return 0;
}

int ClearFrameAllPoints(DWORD pFrame)
{
    return ClearCLayoutFrameAllPoints(pFrame);
}

int SetFrameWidth(DWORD pFrame, float width)
{
    return SetCLayoutFrameWidth(pFrame, width);
}

int SetFrameHeight(DWORD pFrame, float height)
{
    return SetCLayoutFrameHeight(pFrame, height);
}

int SetFrameAllPoints(DWORD pFrame, int relativeframe)
{
    return SetCLayoutFrameAllPoints(pFrame, relativeframe);
}

int SetFrameSize(DWORD pFrame, float width, float height)
{
    return SetCLayoutFrameSize(pFrame, width, height);
}

int SetLayoutFrameScale(DWORD pFrame, float scale)
{
    return SetCLayoutFrameScale(pFrame, scale);
}

int SetFrameVertexColour(DWORD pFrame, int colour)
{
    return SetCSimpleRegionVertexColour(pFrame, colour);
}

int SetFrameVertexColourEx(DWORD pFrame, int alpha, int red, int blue, int green)
{
    return SetCSimpleRegionVertexColourEx(pFrame, alpha, red, blue, green);
}

int GetFrameSkinByName(const char* name, int id)
{
    if (pGetFrameSkinByName > 0)
    {
        if (name != NULL)
        {
            return fast_call(pGetFrameSkinByName, (DWORD)name, id);
        }
    }

    return 0;
}

int DestroyFrame(DWORD pFrame)
{
    if (pDestroyFrame > 0)
    {
        if (pFrame > 0)
        {
            return this_call(pDestroyFrame, pFrame, 1);
        }
    }

    return 0;
}

bool GetFrameState(DWORD pFrame, int state)
{
    if (pFrame > 0)
    {
        return BitwiseAnd(state, ReadRealMemory(pFrame + 0x1D4)) == state;
    }

    return false;
}

bool IsFrameEnabled(DWORD pFrame)
{
    return GetFrameState(pFrame, 1);
}

int SetFrameState(DWORD pFrame, bool flag)
{
    if (pSetFrameState > 0)
    {
        if (pFrame > 0)
        {
            return this_call(pSetFrameState, pFrame, flag);
        }
    }

    return 0;
}

int EnableFrame(DWORD pFrame)
{
    return SetFrameState(pFrame, true);
}

int DisableFrame(DWORD pFrame)
{
    return SetFrameState(pFrame, false);
}

const char* GetFrameTextByName(const char* name, int id)
{
    return GetCSimpleFontTextByName(name, id);
}

int SetFrameTextColour(DWORD pFrame, DWORD colour)
{
    return SetCTextFrameTextColour(pFrame, colour);
}

int SetFrameTextColourEx(DWORD pFrame, int alpha, int red, int blue, int green)
{
    return SetCTextFrameTextColourEx(pFrame, alpha, red, green, blue);
}

int FindLayerUnderCursor(void)
{
    return FindCLayerUnderCursor();
}

int ClickFrame(DWORD pFrame)
{
    if (pClickFrame > 0)
    {
        if (pFrame > 0)
        {
            return this_call(pClickFrame, pFrame, 1);
        }
    }

    return 0;
}

int SetFrameModel(DWORD pFrame, const char* model, int modeltype, bool flag)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid == 15)
    {
        return AddCModelFrameModel(pFrame, model, modeltype);
    }

    if (fid == 25)
    {
        return SetCSpriteFrameArt(pFrame, model, modeltype, flag);
    }

    if (fid == 40)
    {
        return SetCStatusBarArt(pFrame, model, modeltype);
    }

    return 0;
}

int GetFrameAlpha(DWORD pFrame)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid > 0)
    {
        return ReadRealMemory(pFrame + 0xAC);
    }

    return 0;
}

int UpdateFrame(DWORD pFrame)
{
    if (pUpdateFrame > 0)
    {
        if (pFrame > 0)
        {
            return this_call(pUpdateFrame, pFrame, 0);
        }
    }

    return 0;
}

void SetFrameStepValue(DWORD pFrame, float step)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid == 24)
    {
        WriteRealMemory(pFrame + 0x1F8, SetRealIntoMemory(step));
    }
}

int GetFrameParent(DWORD pFrame)
{
    DWORD fid = GetFrameType(pFrame);
    DWORD pOff = 0;

    if (fid > 0)
    {
        if (! IsFrameLayout(pFrame))
        {
            pOff = 0x20;
        }
        else
        {
            pOff = 0x68; // if 1.29+ set pOff = 0x70;
        }

        if (pOff > 0)
        {
            return ReadRealMemory(pFrame + pOff);
        }
    }

    return 0;
}

int SetFrameParent(DWORD pFrame, int pParentFrame)
{
    if (GetFrameType(pFrame) > 0 && GetFrameType(pParentFrame) > 0)
    {
        if (IsFrameLayout(pFrame))
        {
            if (IsFrameLayout(pParentFrame))
            {
                return SetCSimpleFrameParent(pFrame, pParentFrame);
            }
        }
        else
        {
            if (IsFrameLayout(pParentFrame))
            {
                return SetCLayerOwner(pFrame, pParentFrame);
            }
        }
    }

    return 0;
}

const char* GetFrameName(DWORD pFrame)
{
    DWORD fid = GetFrameType(pFrame);
    DWORD pText = 0;

    if (fid > 0)
    {
        if (IsFrameLayout(pFrame))
        {
            pText = pFrame + 0x7C; // if 1.29+  0x80;
        }
        else
        {
            pText = pFrame + 0x160; // if 1.29+ 0x16C;
        }

        if (pText > 0)
        {
            return (char*)(ReadRealMemory(pText));
        }
    }

    return NULL;
}

int SetFrameTexture(DWORD pFrame, const char* texturepath, bool flag)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid == 1 || fid == 39 || fid == 64)
    {
        if (fid == 1)
        {
            return SetCBackDropFrameTexture(pFrame, texturepath, flag);
        }

        if (fid == 39)
        {
            return SetCSimpleStatusBarTexture(pFrame, texturepath, flag);
        }

        if (fid == 64)
        {
            return SetCSimpleTextureTexture(pFrame, texturepath, flag);
        }
    }

    return 0;
}

int SetFrameScale(DWORD pFrame, float scale)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid > 0)
    {
        if (fid == 19 || fid == 21 || fid == 22 || fid == 23 || fid == 39 || fid == 25)
        {
            if (fid == 19)
            {
                return SetCSimpleFontStringScale(pFrame, scale);
            }

            if (fid == 21)
            {
                return SetCSimpleGlueFrameScale(pFrame, scale);
            }

            if (fid == 22 || fid == 23 || fid == 39)
            {
                return SetCSimpleFrameScale(pFrame, scale);
            }

            if (fid == 25)
            {
                return SetCSpriteFrameScale(pFrame, scale);
            }
        }
        else
        {
            return SetLayoutFrameScale(pFrame, scale);
        }
    }

    return 0;
}

float GetFrameValue(DWORD pFrame)
{
    DWORD fid = GetFrameType(pFrame);
    DWORD pOff = 0;

    if (fid == 24 || fid == 39 || fid == 40)
    {
        if (fid == 24)
        {
            pOff = 0x500; // if 1.29+ 0x516;
        }

        if (fid == 39)
        {
            pOff = 0x130; // if 1.29+ 0x12C;
        }

        if (fid == 40)
        {
            pOff = 0x1BC; // if 1.29+ 0x1CC;
        }

        if (pOff > 0)
        {
            return GetRealFromMemory(ReadRealMemory(pFrame + pOff));
        }
    }

    return 0.;
}

int SetFrameValue(DWORD pFrame, float value)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid == 24 || fid == 39 || fid == 40)
    {
        if (fid == 24)
        {
            return SetCSliderCurrentValue(pFrame, value);
        }

        if (fid == 39)
        {
            return SetCSimpleStatusBarValue(pFrame, value);
        }

        if (fid == 40)
        {
            return SetCStatusBarValue(pFrame, value);
        }
    }

    return 0;
}

int SetFrameMinMaxValue(DWORD pFrame, float minval, float maxval)
{
    DWORD fid = GetFrameType(pFrame);
    float cur_val = 0.;
    float new_val = 0.;

    if (fid == 24 || fid == 39 || fid == 40)
    {
        if (minval < maxval)
        {
            if (fid == 24)
            {
                WriteRealMemory(pFrame + 0x1EC, SetRealIntoMemory(minval));
                WriteRealMemory(pFrame + 0x1F0, SetRealIntoMemory(maxval));
                cur_val = GetRealFromMemory(ReadRealMemory(pFrame + 0x1F4));

                if (minval <= cur_val)
                {
                    if (cur_val > maxval)
                    {
                        new_val = maxval;
                    }
                }
                else
                {
                    new_val = minval;
                }

                return SetCSliderCurrentValue(pFrame, new_val);
            }

            if (fid == 39)
            {
                return SetCSimpleStatusBarMinMaxValue(pFrame, minval, maxval);
            }

            if (fid == 40)
            {
                return SetCStatusBarMinMaxValue(pFrame, minval, maxval);
            }
        }
    }

    return 0;
}
//===========================================

// Frame Point API Engine
int SetFrameFont(DWORD pFrame, const char* filename, float height, int flag)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid == 6 || fid == 19 || fid == 23)
    {
        if (fid == 6)
        {
            return SetCEditBoxFont(pFrame, filename, height, flag);
        }

        if (fid == 19)
        {
            return SetCSimpleFontStringFont(pFrame, filename, height, flag);
        }

        if (fid == 23)
        {
            return SetCSimpleMessageFrameFont(pFrame, filename, height, flag);
        }
    }
    else
    {
        if (! IsFrameLayoutByType(pFrame, fid))
        {
            return SetLayerFont(pFrame, filename, height, flag);
        }
    }

    return 0;
}

float GetFrameWidth(DWORD pFrame)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid > 0)
    {
        return GetRealFromMemory(ReadRealMemory(pFrame + 0x58));
    }

    return 0.;
}

float GetFrameHeight(DWORD pFrame)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid == 15 || fid == 19 || fid == 25 || fid == 29)
    {
        if (fid == 15)
        {
            return GetCModelFrameHeight(pFrame);
        }

        if (fid == 19)
        {
            return GetCSimpleFontStringHeight(pFrame);
        }

        if (fid == 25)
        {
            return GetCSpriteFrameHeight(pFrame);
        }

        if (fid == 29)
        {
            return GetCTextFrameHeight(pFrame);
        }
        // return GetRealFromMemory( ReadRealMemory( pFrame + 0x5C ) )
    }
    else
    {
        return GetCLayoutFrameHeight(pFrame);
    }

    return 0.;
}

int GetFramePoint(DWORD pFrame, int point)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid > 0)
    {
        return ReadRealMemory(pFrame + 0x4 * point + 0x8);
    }

    return 0;
}

int GetFramePointParent(DWORD pFrame, int point)
{
    DWORD pFramePoint = GetFramePoint(pFrame, point);

    if (pFramePoint > 0)
    {
        return ReadRealMemory(GetFramePoint(pFrame, point) + 0x4);
    }

    return 0;
}

int GetFramePointRelativePoint(DWORD pFrame, int point)
{
    DWORD pFramePoint = GetFramePoint(pFrame, point);

    if (pFramePoint > 0)
    {
        return ReadRealMemory(GetFramePoint(pFrame, point) + 0x8);
    }

    return 0;
}

float GetFramePointX(DWORD pFrame, int point)
{
    DWORD pFramePoint = GetFramePoint(pFrame, point);

    if (pFramePoint > 0)
    {
        return GetRealFromMemory(ReadRealMemory(GetFramePoint(pFrame, point) + 0xC));
    }

    return 0.;
}

float GetFramePointY(DWORD pFrame, int point)
{
    DWORD pFramePoint = GetFramePoint(pFrame, point);

    if (pFramePoint > 0)
    {
        return GetRealFromMemory(ReadRealMemory(GetFramePoint(pFrame, point) + 0x10));
    }

    return 0.;
}
//===========================================

// Frame Text API Engine
int GetFrameTextMaxLength(DWORD pFrame)
{
    DWORD frameId = GetFrameType(pFrame);

    if (frameId == 6)
    {
        return ReadRealMemory(pFrame + 0x1F0);
    }

    return 0;
}

void SetFrameMaxTextLength(DWORD pFrame, int length)
{
    DWORD frameId = GetFrameType(pFrame);

    if (frameId == 6)
    {
        WriteRealMemory(pFrame + 0x1F0, length);
    }
}

int GetFrameTextLength(DWORD pFrame)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid == 6)
    {
        return ReadRealMemory(pFrame + 0x1F4);
    }

    return 0;
}

const char* GetFrameText(DWORD pFrame)
{
    DWORD fid = GetFrameType(pFrame);
    DWORD pFrameText = 0;

    if (fid > 0)
    {
        if (fid == 6)
        {
            pFrameText = ReadRealMemory(pFrame + 0x1E4);
        }

        if (fid == 19)
        {
            pFrameText = ReadRealMemory(pFrame + 0x01C);
        }

        if (fid == 27)
        {
            pFrameText = ReadRealMemory(pFrame + 0x230);
        }

        if (fid == 29)
        {
            pFrameText = ReadRealMemory(pFrame + 0x1E8);
        }

        if (pFrameText > 0)
        {
            return (char*)(pFrameText);
        }
    }

    return NULL;
}

int SetFrameText(DWORD pFrame, const char* text)
{
    DWORD fid = GetFrameType(pFrame);

    if (fid > 0)
    {
        if (fid == 6 || fid == 36 || fid == 37)
        {
            return SetCEditBoxText(pFrame, text);
        }

        if (fid == 19)
        {
            return SetCSimpleFontText(pFrame, text);
        }

        if (fid == 27)
        {
            return SetCTextAreaText(pFrame, text);
        }

        if (fid == 28 || fid == 33 || fid == 29 || fid == 38)
        {
            return SetCTextFrameText(pFrame, text);
        }
    }

    return 0;
}
//===========================================

bool IsReplay(void)
{
    return GetCFrameByName("ReplayVisionMenu", 0) != 0;
}

void SetAllyCheckbox(int mode)
{
    DWORD i = 0;
    DWORD pAllyCheckBoxAddr;

    while (i <= 11)
    {
        pAllyCheckBoxAddr = GetCFrameByName("UnitsCheckBox", i);

        if (pAllyCheckBoxAddr > 0)
        {
            pAllyCheckBoxAddr = pAllyCheckBoxAddr + 0x1D4;

            if (BitwiseAnd(ReadRealMemory(pAllyCheckBoxAddr), mode) == 0)
            { // BitwiseAnd( ReadRealMemory( pAllyCheckBoxAddr ), 1 ) == 0
                WriteRealMemory(pAllyCheckBoxAddr, ReadRealMemory(pAllyCheckBoxAddr) | mode);
            }
        }

        i = i + 1;
    }
}

void EnableAllyCheckbox(void)
{
    SetAllyCheckbox(1);
}

void DisableAllyCheckbox(void)
{
    SetAllyCheckbox(0);
}

void DisableSaveGameMenu(void)
{
    // SaveButton frame && menu are not rendered in the first seconds of init.
    // Thus, this function MUST be called with a delay after map init.
    DWORD pSaveGameSaveButton = GetCFrameByName("SaveGameFileEditBox", 0);

    if (pSaveGameSaveButton > 0)
    {
        WriteRealMemory(pSaveGameSaveButton + 0x1D4, 0);
        WriteRealMemory(pSaveGameSaveButton + 0x108, 0);
        WriteRealMemory(pSaveGameSaveButton + 0x1E8, 0);

        pSaveGameSaveButton = GetCFrameByName("FileListFrame", 0);
        if (pSaveGameSaveButton > 0)
        {
            WriteRealMemory(pSaveGameSaveButton + 0x10C, 0x3B03123E);
        }
    }
}