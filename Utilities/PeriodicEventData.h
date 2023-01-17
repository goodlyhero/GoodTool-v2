#pragma once
#define EVENT_CODE_INIT_WX 2
#define EVENT_CODE_INIT_SIMPLE 3
#define EVENT_CODE_RUN_LUA_LOCAL 4
#define EVENT_CODE_RUN_LUA_GLOBAL 5
void ProcessPeriodic();
void AddEvent(int code, void* data);

struct RUN_CODE_DATA {
	int32_t vmType;
	const char* ptr;
};