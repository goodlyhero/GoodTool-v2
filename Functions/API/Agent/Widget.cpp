#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>
#include <CNatives.h>

float GetTerrainZ(float axisX, float axisY)
{
    if (pGetAxisZ > 0)
    {
        DWORD f = (fast_call(pGetAxisZ, -1, 0, SetRealIntoMemory(axisX), SetRealIntoMemory(axisY), 1));
        return *(float*)&f;
    }

    return 0.;
}

float GetWidgetTerrainZ(jHANDLE Widget)
{
    if (Widget != NULL)
    {
        return GetTerrainZ(GetWidgetX(Widget) , GetWidgetY(Widget));
    }

    return 0.;
}

int SetWidgetCoordinates(jHANDLE Widget, float x, float y)
{
    // This does NOT work for destructables/doodads
    DWORD pWidget = ConvertHandle(Widget);

        if (pWidget > 0 && pSetWidgetCoordinates > 0)
        {
            return this_call(pSetWidgetCoordinates, pWidget, SetRealIntoMemory(x), SetRealIntoMemory(x), 1, 1, -1, 0, 0, 0, 0, -1, 0);
        }

    return 0;
}

int SetWidgetPosition(jHANDLE Widget, float x, float y)
{
    // Works for destructables/doodads/items/units
    DWORD pWidget = ConvertHandle(Widget);
    DWORD pVal1 = 0;
    DWORD pVal2 = 0;

        if (pWidget > 0)
        {
            if (BitwiseAnd(ReadRealMemory(pWidget + 0x8C), ReadRealMemory(pWidget + 0x90)) != -1 && pGetAgentInternal > 0)
            {
                pVal1 = this_call(pGetAgentInternal, pWidget + 0x8C);

                if (pVal1 > 0 && pGetPressenseTagged > 0)
                {
                    pVal2 = fast_call(pGetPressenseTagged, ReadRealMemory(pVal1 + 0xC), ReadRealMemory(pVal1 + 0x10));

                    if (pVal2 > 0 && pAgentUpdate > 0)
                    {
                        if (ReadRealMemory(pVal2 + 0x0C) == 727803756 && ReadRealMemory(pVal2 + 0x20) == 0)
                        {
                            this_call(pAgentUpdate, pVal1, pWidget);
                        }
                    }
                }
            }

            if (pSetWidgetPosition > 0)
            {
                return this_call(pSetWidgetPosition, pWidget, (DWORD)&x, (DWORD)&y, -1);
            }
        }

    return 0;
}

int SetDestructablePosition(jHANDLE dest, float x, float y)
{
    return SetWidgetPosition(dest, x, y);
}