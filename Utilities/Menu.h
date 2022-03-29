#pragma once
#include <Windows.h>
namespace menu
{
	int MyWindows(HINSTANCE hInstance);
	void DestroyWindows();
	extern char* EditText;
	extern bool LocalMode;
}