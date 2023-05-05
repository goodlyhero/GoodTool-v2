#pragma once
#define EVENT_CODE_INIT_WX 2
#define EVENT_CODE_INIT_SIMPLE 3
#define EVENT_CODE_RUN_LUA_LOCAL 4
#define EVENT_CODE_RUN_LUA_GLOBAL 5
#define EVENT_CODE_RUN_LUA_LOCAL_FILE 6
#define EVENT_CODE_RUN_LUA_GLOBAL_FILE 7

void ProcessPeriodic();
void AddEvent(int code, void* data);
