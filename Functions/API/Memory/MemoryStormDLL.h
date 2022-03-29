#pragma once

int StormAllocateMemory(int size, const char* name, int unk_1, int unk_2);
int StormFreeMemory(int addr, const char* name, int unk_1, int unk_2);
int StormGetMemorySize(int addr, const char* name, int unk_1);
int StormReallocateMemory(int addr, int size, const char* name, int unk_1, int unk_2);
int StormLoadMPQ(const char* mpq, int priority, int unk);
int GetMPQLoadResult();
int StormLoadMPQTemp(const char* mpq, int priority, int unk);
void UnloadResources();
int StormLoadMPQTempR(const char* mpq, int priority, int unk);
bool RemoveDir(const char* path);
bool RemoveFile(const char* path);

int StormLoadMPQ(const char* mpq, int priority, int unk);
int StormOpenFileAsArchive(int mode, const char* mpq, int priority, int unk);
DWORD StormOpenFile(const char* file);
DWORD StormGetFileSize(DWORD hfile, LPDWORD lpFileSizeHigh);
DWORD StormCloseFile(DWORD hfile);
DWORD StormReadFile(DWORD hFile, void* pBuffer, DWORD nNumberOfBytesToRead, DWORD* pNumberOfBytesRead, DWORD lpDistanceToMoveHigh);
std::string StormGetFileAsString(const char* file);
DWORD StormCloseArchive(DWORD pMPQ);