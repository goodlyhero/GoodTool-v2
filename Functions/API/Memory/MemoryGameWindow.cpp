#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <Calls.h>

float GetWindowWidth(void)
{
    if (pGetWindowWidth > 0)
    {
        return GetRealFromMemory(ReadRealMemory(pGetWindowWidth));
    }

    return 0.;
}

float GetWindowHeight(void)
{
    if( pGetWindowHeight > 0)
    {
        return GetRealFromMemory(ReadRealMemory(pGetWindowHeight));
    }

    return 0.;
}
DWORD GetWindowX(DWORD hwnd)
{
    DWORD buffer[5];
    DWORD pWRect = GetWindowRect((HWND)hwnd, (LPRECT)buffer);

        if (pWRect > 0)
        {
            return buffer[0];
        }

    return 0;
}

DWORD GetWindowY(DWORD hwnd)
{
    DWORD buffer[5];
    DWORD pWRect = GetWindowRect((HWND)hwnd, (LPRECT)buffer);

    if (pWRect > 0)
    {
        return buffer[1];
    }

    return 0;
}
float GetWindowCenterX(void)
{
    return GetWindowX((DWORD)hwndwc) + GetWindowWidth() * 0.5;
}

float GetWindowCenterY(void)
{
    return GetWindowY((DWORD)hwndwc) + GetWindowHeight() * 0.5;
}

int GetWarcraftWindow(void)
{
    DWORD hwnd = 0;

        if (pGetWarcraftWindow > 0)
        {
            hwnd = this_call(pGetWarcraftWindow, 0);
        }
        else
        {
            hwnd = (DWORD)FindWindow("Warcraft III", "Warcraft III");
        }

    return hwnd;
}

float FromPixelX(int i)
{
    return i * 0.8f/ GetWindowWidth();
}

float FromPixelY(int i)
{
    return i * 0.6f/ GetWindowHeight();
}