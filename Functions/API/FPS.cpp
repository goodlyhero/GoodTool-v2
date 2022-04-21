#include <Windows.h>
#include <gl/GL.h>
#include <memory>
#include <iostream>
#include <gl/GLU.h>
#include <Calls.h>
#include <wglext.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <thread>
#include <States.h>
#include "FPS.h"
BOOL vsyncEnabled = FALSE;

BOOL vsyncInitialized = FALSE;
BOOL FPS_LIMIT_ENABLED = FALSE;

ULARGE_INTEGER lastCPU, lastSysCPU, lastUserCPU;
int numProcessors;
unsigned int CPU_cores;
HANDLE Warcraft3_Process = NULL;
#define MAX_WAR3_FPS 80
#define MIN_WAR3_FPS 24
int CurrentFps = 64;

int SetMaxFps(int fps)
{
	cdecl_call(_SetMaxFps, (DWORD)fps);
	return fps;
}
void InitD3DVSync(bool enabled)
{
	vsyncEnabled = enabled;

	//if (/*OLD_D3D_PARAMETERS_LOADED &&*/ d3dreset_org && d3dreset_ptr)
	//{
	ShowWindow(hwndwc, SW_MINIMIZE);
	ShowWindow(hwndwc, SW_RESTORE);
	//}
}
// bool WGLExtensionSupported(const char* extension_name)
// {
// 	return false;
// 	// this is pointer to function which returns pointer to string with list of all wgl extensions
// 	PFNWGLGETEXTENSIONSSTRINGEXTPROC _wglGetExtensionsStringEXT = NULL;

// 	// determine pointer to wglGetExtensionsStringEXT function
// 	_wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)wglGetProcAddress("wglGetExtensionsStringEXT");

// 	if (_wglGetExtensionsStringEXT == NULL || strstr(_wglGetExtensionsStringEXT(), extension_name) == NULL)
// 	{
// 		// string was not found
// 		return false;
// 	}

// 	// extension is supported
// 	return true;
// }
// void EnableVsync(bool enable)
// {
// 	return;
// 	PFNWGLSWAPINTERVALEXTPROC       wglSwapIntervalEXT = NULL;
// 	PFNWGLGETSWAPINTERVALEXTPROC    wglGetSwapIntervalEXT = NULL;

// 	if (WGLExtensionSupported("WGL_EXT_swap_control"))
// 	{
// 		// Extension is supported, init pointers.
// 		wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");

// 		//// this is another function from WGL_EXT_swap_control extension
// 		//wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)wglGetProcAddress("wglGetSwapIntervalEXT");
// 		//
// 		if (wglSwapIntervalEXT)
// 		{
// 			wglSwapIntervalEXT(enable);
// 		}
// 	}



// 	WriteRealMemory((pGameDLL + 0x62D7FB), enable ? 0xFB : 0xFF);

// 	InitD3DVSync(enable);

// }
void InitThreadCpuUsage() {
	SYSTEM_INFO sysInfo;
	FILETIME ftime, fsys, fuser;


	numProcessors = std::thread::hardware_concurrency();
	if (numProcessors == 0)
	{
		GetSystemInfo(&sysInfo);
		numProcessors = sysInfo.dwNumberOfProcessors;
	}

	GetSystemTimeAsFileTime(&ftime);
	std::memcpy(&lastCPU, &ftime, sizeof(FILETIME));


	GetProcessTimes(Warcraft3_Process, &ftime, &ftime, &fsys, &fuser);
	std::memcpy(&lastSysCPU, &fsys, sizeof(FILETIME));
	std::memcpy(&lastUserCPU, &fuser, sizeof(FILETIME));
}
double GetWar3CpuUsage() {
	FILETIME ftime, fsys, fuser;
	ULARGE_INTEGER now, sys, user;
	double percent;
	GetSystemTimeAsFileTime(&ftime);
	std::memcpy(&now, &ftime, sizeof(FILETIME));
	GetProcessTimes(Warcraft3_Process, &ftime, &ftime, &fsys, &fuser);
	std::memcpy(&sys, &fsys, sizeof(FILETIME));
	std::memcpy(&user, &fuser, sizeof(FILETIME));
	percent = (double)((sys.QuadPart - lastSysCPU.QuadPart) +
		(user.QuadPart - lastUserCPU.QuadPart));
	percent /= (now.QuadPart - lastCPU.QuadPart);
	lastCPU = now;
	lastUserCPU = user;
	lastSysCPU = sys;
	return percent * 100.0;
}
void UpdateFPS()
{
	double currentcpuusage = GetWar3CpuUsage();
	if (currentcpuusage > 88.0)
	{
		if (CurrentFps > MIN_WAR3_FPS)
		{
			CurrentFps -= 4;
			if (IsInGame())
				SetMaxFps(CurrentFps);
		}
	}
	else if (currentcpuusage < 70.0)
	{
		if (CurrentFps < MAX_WAR3_FPS)
		{
			CurrentFps += 4;
			if (IsInGame())
				SetMaxFps(CurrentFps);
		}
	}
}
int EnableAutoFPSlimit(bool enable)
{
	FPS_LIMIT_ENABLED = enable;
	if (!FPS_LIMIT_ENABLED)
		SetMaxFps(200);
	return enable;
}
