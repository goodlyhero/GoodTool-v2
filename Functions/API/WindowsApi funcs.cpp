
#include <Windows.h>
#include <urlmon.h>
#include <shlwapi.h>
#include <BasicConstants.h>
#include <States.h>
#include <String>
#include <Warcraft Functions.h>
HRESULT DownloadFile(const char* url, const char* file)
{
	return URLDownloadToFile(NULL, url, file, NULL, NULL);
}

bool CreateFolder(const char* path)
{
	return CreateDirectoryA(path, NULL);
}

bool DirExists(const char* dir)
{
	DWORD ftyp = GetFileAttributesA(dir);
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

bool FileExistsC(const char* file)
{
	return PathFileExistsA(file);
}

void CMessageBox(const char* msg,const char* name,DWORD style)
{
	MessageBox(hwndwc, msg, name, style);
}

void CMessageBoxAbort(const char* msg, const char* name)
{
	MessageBox(hwndwc, msg, name, MB_ICONERROR);
}

DWORD GetCurrentProcessIdA()
{
	return GetCurrentProcessId();
}

DWORD GetModuleHandleD(const char* name)
{
	return (DWORD)GetModuleHandleA(name);
}

bool RemoveDir(const char* path)
{
	return RemoveDirectoryA(path);
}

bool RemoveFile(const char* path)
{
	return DeleteFileA(path);
}

DWORD LGetModueHandle(const char* name)
{
	return (DWORD)GetModuleHandle(name);
}

DWORD LLoadLibrary(const char* name)
{
	return (DWORD)LoadLibraryA(name);
}
DWORD LGetModuleProcAddress(const char* modulename, const char* proc)
{
	return (DWORD)GetProcAddress(GetModuleHandle(modulename), proc);
}
DWORD LGetModuleProcAddressS(const char* modulename, DWORD n)
{
	return (DWORD)GetProcAddress(GetModuleHandle(modulename), (char*)n);
}

void SetWc3Top()
{
	//BringWindowToTop(hwndwc);
	SetWindowPos(hwndwc, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}



void UpdateMouseLock(bool mode)
{
	if ((GetForegroundWindow() == hwndwc) && IsInGame() && mode)
	{
		RECT r;
		POINT p;
		p.x = 0;
		p.y = 0;
		ClientToScreen(hwndwc, &p);
		GetClientRect(hwndwc, &r);
		r.left += p.x;
		r.right += p.x;
		r.top += p.y;
		r.bottom += p.y;
		//TextPrint(std::to_string(r.bottom).c_str());
		ClipCursor(&r);
	}
	else
	{
		ClipCursor(0);
	}
}

bool IsPtrOk(DWORD ptr)
{
	return !IsBadReadPtr((void*)ptr, PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY);
}