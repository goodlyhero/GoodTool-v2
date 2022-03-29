#pragma once
int GetFileSizeFromMPQ(const char* source);
bool ExportFileFromMPQ(const char* source, const char* dest);
bool LoadDllFromMPQ(const char* source, const char* dest, const char* dllname);
bool LuaDoFileFromMPQ(const char* file);
bool GlobalDoFileFromMPQ(const char* file);