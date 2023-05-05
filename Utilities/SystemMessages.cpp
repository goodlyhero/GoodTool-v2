// GoodToolTestRecciever.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <future>

#include "SystemMessages.h"
#include "GoodToolRun.h"
#include "PeriodicEventData.h"


HWND MessageRecievingWindow;

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
) {
    switch (uMsg) {
    case WM_COPYDATA: {
        if (lParam == NULL) {
            std::cout << "Sended data is NULL" << std::endl;
            return NULL;
        }
        COPYDATASTRUCT* data = (COPYDATASTRUCT*)lParam;


        size_t len = data->cbData;
        int32_t msg = data->dwData;
        switch (msg) {
        case EVENT_CODE_RUN_LUA_LOCAL:
        case EVENT_CODE_RUN_LUA_GLOBAL:
        case EVENT_CODE_RUN_LUA_LOCAL_FILE:
        case EVENT_CODE_RUN_LUA_GLOBAL_FILE:
        {
            const char* code = (char*)(data->lpData);
            char* pcode2 = new char[len];
            memcpy(pcode2, code, len);
            AddEvent(msg, pcode2);
            //std::cout << "running code: \n==============================\n" << code << "\n===========================" << std::endl;
            break;
            
        }
        default: {
            std::cout << "Unknown GoodTool message: " << msg << std::endl;
        }
        }
        std::cout << "success" << std::endl;
        return NULL;
    }
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
};

void ProcessSystemMessages()
{
    using namespace std;
    string gclass = GOODTOOL_CLASS;
    string fname_base = GOODTOOL_WINDNAME_BASE;
    string fname = fname_base;
    int i = 0;
    while (FindWindow(NULL, fname.c_str()) != NULL) {
        std::cout << "Window name: " << fname << "is already used" << std::endl;
        fname = fname_base + to_string(i);
        i++;
    }
    std::cout << "Creating window: " << fname << std::endl;
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), NULL, WindowProc, 0L, 0L, GetModuleHandle(NULL), LoadIcon(NULL, IDI_APPLICATION), LoadCursor(NULL, IDC_ARROW), NULL, NULL, GOODTOOL_CLASS, LoadIcon(NULL, IDI_APPLICATION) };

    if (!RegisterClassEx(&wc))
    {
        std::cout << "Window class registration failed" << std::endl;
        return;
    }
    std::cout << fname << std::endl;
    HWND MessageRecievingWindow = CreateWindowExA(0, gclass.c_str(), fname.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 200, 200, NULL, NULL, GetModuleHandle(NULL), NULL);
    if (!MessageRecievingWindow) {
        std::cout << "Window creation failed" << std::endl;
    }
    else {
        //std::cout << "Created Window: " << MessageRecievingWindow << std::endl;
    }
    //if (PostMessage(hwnd, WM_CLOSE, 0, 0)) {std::cout << "message sended" << std::endl;}
    MSG Msg;
    ShowWindow(MessageRecievingWindow,false);
    UpdateWindow(MessageRecievingWindow);

    do
    {
        if (GetMessage(&Msg, NULL, 0, 0) == NULL) { Sleep(1); break; }

        if (Msg.message == WM_CLOSE) {
            TranslateMessage(&Msg);
            DispatchMessage(&Msg);
            break;
        }
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    } while (true);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);
}
DWORD CALLBACK ProcessSystemMessagesCallback(void*) {
    ProcessSystemMessages();
    return NULL;
}

void InitMessageWindow() {
    CreateThread(NULL, 0, ProcessSystemMessagesCallback, NULL, 0, NULL);
}

void ProcessSystemMessage() {
    MSG Msg;
    if (GetMessage(&Msg, NULL, 0, 0) == NULL) { return; }
    std::cout << "Processing message: " << Msg.message << std::endl;
    if (Msg.message == WM_COPYDATA) {
        std::cout << "WM_COPYDATA";
    }
    if (Msg.message == WM_CLOSE) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
        return;
    }
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
}