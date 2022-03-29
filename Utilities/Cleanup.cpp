#include <Windows.h>
#include "shlwapi.h"
#include <shellapi.h>
#include <winver.h>
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;
namespace cleanup
{
	void Cleanup()
	{
		HMODULE hloader = GetModuleHandle("Loader.dll");
		HMODULE hgoodtool = GetModuleHandleA("GoodTool.dll");
		char buffer[MAX_PATH];
		GetTempPathA(MAX_PATH, buffer);
		std::string temp = buffer;
		GetModuleFileNameA(hloader, buffer, MAX_PATH);
		std::string loader = buffer;
		GetModuleFileNameA(hgoodtool, buffer, MAX_PATH);
		std::string goodtool = buffer;
		std::string path = temp + "." + std::to_string(GetCurrentProcessId()) + "\\";
		fs::create_directories(path);
		std::string bat = path + "Cleanup.bat";
		std::ofstream cleanupBat;
		cleanupBat.open(bat);
		cleanupBat << "timeout 2\n";
		if (hgoodtool != 0)
		{
			cleanupBat << "del " << goodtool << " / F\n";
		}
		if (hloader != 0)

		{
			cleanupBat << "del " << loader << " / F\n";
		}

		cleanupBat << "del " << temp << " / S / Q / F\n";
		cleanupBat << "del " << temp << "\n";
		cleanupBat << "(goto) 2>nul & del \" % ~f0\"\n";
		cleanupBat.close();
		if (hloader != 0)
		{
			FreeLibrary(hloader);
		}

		ShellExecuteA(NULL, NULL, bat.c_str(), NULL, NULL, NULL);
	}
}