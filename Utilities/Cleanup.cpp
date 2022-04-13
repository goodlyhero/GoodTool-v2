#include <Windows.h>
#include "shlwapi.h"
#include <shellapi.h>
#include <winver.h>
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <BasicConstants.h>

namespace fs = std::filesystem;
namespace cleanup
{
	void Cleanup()
	{
		HMODULE hloader = GetModuleHandle("Loader.dll");
		HMODULE hgoodtool = GoodToolDll;
		char buffer[MAX_PATH];
		GetModuleFileName(hloader, buffer, sizeof(buffer));
		if(hloader!=0)
			FreeLibrary(hloader);
		auto LoaderPath = fs::absolute(fs::path(buffer));
		auto LoaderFolder = LoaderPath.parent_path();
		GetModuleFileName(hgoodtool, buffer, sizeof(buffer));
		auto ThisLibPath = fs::absolute(fs::path(buffer));
		auto LoaderContaining = ThisLibPath.parent_path();

		auto tempdir = fs::temp_directory_path();

		std::string Cleanup = "cmd /Q /c \"echo off & timeout 5 &";
		if (hloader != 0)
		{
			Cleanup += "del \"";
			Cleanup+= LoaderPath.string() += "\" /F /Q & ";
			Cleanup += "del \"";
			Cleanup += LoaderFolder.string() += "\"  /Q /F &";
		}
		if (hgoodtool != 0)
		{
			Cleanup += "del \"";
			Cleanup += ThisLibPath.string() += "\" /F /Q &";
			Cleanup += "del \"";
			Cleanup += ThisLibPath.string() += "\"  /Q /F &";
		}
		Cleanup += "timeout 100 \"";
		STARTUPINFOA si;
		PROCESS_INFORMATION pi;

		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));
		CreateProcessA(NULL, (char*)Cleanup.c_str(), NULL, NULL, false, CREATE_NO_WINDOW, NULL, tempdir.string().c_str(), &si, &pi);
	}
}