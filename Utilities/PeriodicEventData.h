#pragma once
#define EVENT_CODE_RUN_LUA 1
#define EVENT_CODE_INIT_WX 2
#define EVENT_CODE_INIT_SIMPLE 3
void ProcessPeriodic();
void AddEvent(int code, void* data);