#include <Windows.h>
#include <Logs/Log.h>
#include <PeriodicEventData.h>
#include <LuaStates.h>
#include <wx/include/wx/app.h>
//#include "Edit/edit.h"
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam);
#define RUN_LUA 101
#define LUA_MODE 102
#define INSTANT_RUN 103
HINSTANCE hInst;
HWND mainwindow = NULL;
HWND Code1;
HWND LuaMode;
HWND InstantMode;
int MyWindows(HINSTANCE hInstance)
{
    WNDCLASSEX wc;
    HWND hWnd;
    MSG msg;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "Base";
    wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

    RegisterClassEx(&wc);

    if (!(hWnd = CreateWindowEx(NULL, "Base", "Main", WS_SIZEBOX | WS_VISIBLE | WS_MAXIMIZE,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInst, NULL)))
        return (0);

    ShowWindow(hWnd, SW_SHOWDEFAULT);
    UpdateWindow(hWnd);
    mainwindow = hWnd;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (msg.wParam);
}

bool GetCheckBoxState(HWND checkbox)
{
    UINT t = SendMessage(checkbox, BM_GETCHECK, 0, 0);

    if (t == BST_CHECKED)
        return true;
    return false;
}

char* getEditText(HWND edit)
{
    size_t len = GetWindowTextLength(Code1);
    char* buffer = new char[len + 1];
    GetWindowTextA(Code1, buffer, len + 1);
    return buffer;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hButton, hListBox, hComboBox, hWindow1;

    switch (message)
    {
    case WM_CREATE:
    {
        hButton = CreateWindow("BUTTON", "Run Script", WS_CHILD | WS_VISIBLE,
            33, 10, 350, 20, hWnd, (HMENU)RUN_LUA, hInst, 0);
        Code1 = CreateWindow("EDIT",								 //pre-defined class type in unicode definition
            "", WS_VSCROLL | ES_LEFT | ES_AUTOVSCROLL | ES_MULTILINE | WS_VISIBLE | WS_CHILD | WS_BORDER,	 //button attributes
            33,																 //x position relative to parent frame
            80,																 //y position relative to parent frame
            640,																 //width
            480,																 //height
            hWnd,															 //handle to parent window
            HMENU(1104),															 //window doesn't contain a menu
            hInst,
            nullptr);	//generic ponter value can be passed but is not needed
        LuaMode = CreateWindow("button", "Global", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 30, 50, 150, 20, hWnd, (HMENU)LUA_MODE, hInst, 0);
        InstantMode = CreateWindow("button", "Instant Run", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 200, 50, 150, 20, hWnd, (HMENU)INSTANT_RUN, hInst, 0);
        SendMessage(LuaMode, BM_SETCHECK, BST_CHECKED, 0);
        SendMessage(InstantMode, BM_SETCHECK, BST_UNCHECKED, 0);
    }
    break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case RUN_LUA:
        {

            //mlog::Debug("Inst mode state: ",GetCheckBoxState(InstantMode) ? "Instant mode" : "Not Instant Mode");
            //mlog::Debug("Lua mode: ",GetCheckBoxState(LuaMode) ? "Global" : "Local");
            if (!GetCheckBoxState(InstantMode))
            {
                AddEvent(EVENT_CODE_RUN_LUA, NULL);
            }
            else
            {
                size_t len = GetWindowTextLength(Code1);
                char* buffer = new char[len + 1];
                GetWindowTextA(Code1, buffer, len + 1);
                mlog::Lua("Trying To run code from menu:\n", buffer);
                bool globalstate = GetCheckBoxState(LuaMode);
                lua::TLua* state;
                if (globalstate)
                {
                    state = lua::GetGlobalState();
                    //mlog::Debug("Getting Global State");
                }
                else
                {
                    state = lua::GetLocalState();
                    //mlog::Debug("Getting Local State");
                }
                if (state != NULL && buffer != NULL)
                {
                    char* error = state->DoStr(buffer);
                    if (error != NULL)
                    {
                        TextPrint(error);
                        mlog::Lua("error, when running code from menu: ", error);
                    }

                }
                else
                {
                    //mlog::Debug("Buffer == NULL or cant find state");
                }
                delete[] buffer;
                return true;
            }
        }
        }
        break;

    case WM_DESTROY:
    {

        DestroyWindow(mainwindow);
        PostQuitMessage(NULL);
        return NULL;
    }
    break;
    }
    return (DefWindowProc(hWnd, message, wParam, lParam));
}

void DestroyWindows()
{
    SendMessage(mainwindow, WM_DESTROY, NULL, NULL);
}