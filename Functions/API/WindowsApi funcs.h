#pragma once
typedef long HRESULT;
typedef unsigned long DWORD;
HRESULT DownloadFile(const char* url, const char* file);
bool CreateFolder(const char* path);
bool DirExists(const char*	dir);
bool FileExistsC(const char* file);
void CMessageBox(const char* msg, const char* name, DWORD style);
void CMessageBoxAbort(const char* msg, const char* name);
DWORD GetCurrentProcessIdA();
DWORD GetModuleHandleD(const char* name);
bool RemoveDir(const char* path);
bool RemoveFile(const char* path);
void SetWc3Top();

DWORD LGetModueHandle(const char* name);
DWORD LLoadLibrary(const char* name);
DWORD LGetModuleProcAddress(const char* modulename, const char* proc);
DWORD LGetModuleProcAddressS(const char* modulename, DWORD n);
void UpdateMouseLock(bool mode);
bool IsPtrOk(DWORD ptr);