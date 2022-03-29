//library APIMemoryMPQ:
#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>
#include <Lua/LuaStates.h>
#include <string>

int GetFileSizeFromMPQ(const char* source)
{
	int a = 0;
	int b = 0;
	std_call(ReadRealMemory(pStorm279), (DWORD)source, (DWORD)&a, (DWORD)&b, 1, 0);

	return b;
}

bool ExportFileFromMPQ(const char* source, const char* dest)
{
	return fast_call(pExportFromMPQ, (DWORD)source, (DWORD)dest) > 0;
}

bool LoadDllFromMPQ(const char* source, const char* dest, const char* dllname)
{
	if (ExportFileFromMPQ(source, dest))
	{
		LoadLibrary(dllname);
		return true;
	}

	return false;
}

bool LuaDoFileFromMPQ(const char* file)
{
	if (GetFileSizeFromMPQ(file) > 0)
	{
		
		lua::TLua* state = lua::GetLocalState();
		if (state != NULL)
		{
			std::string data = StormGetFileAsString(file);

			mlog::Lua("running script from mpq: ", file, " : \n");
			//LogS() << data << std::endl;
			state->DoStr(data.c_str(),file);

			return true;
		}
		mlog::Error("Cant find local state");
		return false;
		
	}
	mlog::Error("Unable to find file: ", file);
	return false;
}


bool GlobalDoFileFromMPQ(const char* file)
{
	if (GetFileSizeFromMPQ(file) > 0)
	{

		lua::TLua* state = lua::GetGlobalState();
		if (state != NULL)
		{
			std::string data = StormGetFileAsString(file);

			mlog::Lua("running script from mpq: ", file, " : \n");
			//LogS() << data << std::endl;
			char* err = state->DoStr(data.c_str());
			if (err != NULL)
			{
				mlog::Error("error while running script from mpq: ", data.c_str(), ": ", err);
			}

			return true;
		}
		mlog::Error("Cant find local state");
		return false;

	}
	mlog::Error("Unable to find file: ", file);
	return false;
}
	//library APIMemoryMPQ ends