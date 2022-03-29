#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <Windows.h>
#include <From MemHack.h>
#include <wininet.h>
#include <string>
#include <iostream>
#include <filesystem>
#include <Logs/Log.h>
namespace fs = std::filesystem;
struct mpqres
{
	std::string path;
	DWORD hmap;
	DWORD hres;
};

bool StormDownloadFileWithResources(const char* url, const char* data)
{
	mlog::Debug("loading file with url: ", url, " with name: ", data);
	char buffer[MAX_PATH];
	GetTempPathA(MAX_PATH, buffer);
	std::string temppath = buffer;
	std::string resname = i642s(GetTickCount64());
	std::string procname = std::to_string(GetCurrentProcessId());
	std::string respath = temppath + "." + procname + "\\";
	fs::create_directories(respath);
	std::string downloaded = respath + i642s(GetTickCount64());
	std::string goodtool = "GoodTool\\resources\\";
	std::string fileingt = goodtool + data;
	std::string mpq2 = downloaded + "t";
	std::string fileingtnew = goodtool + resname;
	mlog::Debug("Downloading file: ", downloaded.c_str());
	DownloadFile(url, downloaded.c_str());
	if (fs::exists(downloaded))
	{
		mlog::Debug("Downloaded file: ", downloaded.c_str()," trying to load file");
		DWORD tmpq = StormLoadMPQ(downloaded.c_str(), 3, 4);
		if (tmpq != NULL)
		{
			mlog::Debug("loaded mpq: ", downloaded.c_str());
			if (ExportFileFromMPQ(data, mpq2.c_str()))
			{
				mlog::Debug("file " ,mpq2.c_str(), " was exported");
				StormCloseArchive(tmpq);
				fs::remove(downloaded);
				if (fs::exists(fileingt)?fs::equivalent(mpq2,fileingt):false)
				{
					mlog::Debug("files are equal: ",mpq2,", ",fileingt);
					if(StormLoadMPQTemp(fileingt.c_str(), 3, 4)!=0) 
					{
						mlog::Debug("loaded file: ", fileingt.c_str());
						fs::remove(mpq2);
						return true;
					}
					fs::remove(mpq2);
					fs::remove(downloaded);
					mlog::Debug("failed to load mpq: ", fileingt.c_str());
					return false;
				}
				else
				{
					mlog::Debug("Trying to replace file: ", fileingt.c_str());
					fs::remove(fileingt);
					if (fs::exists(fileingt))
					{
						mlog::Debug("Can't replace file: ",fileingt.c_str());
						mlog::Debug("Trying to load: ",mpq2.c_str());
						if (StormLoadMPQTempR(mpq2.c_str(), 10, 4) != 0)
						{
							mlog::Debug("file was loaded: ", mpq2.c_str());
							return true;
						}
					}
					else
					{
						mlog::Debug("trying to copy file: ", mpq2.c_str(), " to ", fileingt.c_str());
						fs::create_directories(goodtool.c_str());
						fs::copy(mpq2.c_str(), fileingt.c_str());
						if (StormLoadMPQTemp(fileingt.c_str(), 10, 4) != 0)
						{
							mlog::Debug("file was loaded: ", fileingt.c_str());
							fs::remove(mpq2.c_str());
							return true;
						}
						else if (StormLoadMPQTempR(mpq2.c_str(), 10, 4) != 0)
						{
							mlog::Debug("file was loaded: ", mpq2.c_str());
							return true;
						}
						mlog::Debug("unable to load 2nd mpq");

						fs::remove(mpq2);
					}
				}
				
				
			}
			else
			{
				mlog::Debug("Export file failed: ", mpq2);
				StormCloseArchive(tmpq);
				fs::remove(downloaded);
			}
		}
		return false;
		mlog::Debug("cant load mpq: ", downloaded);
	}
	else
	{
		mlog::Debug("File: ", downloaded.c_str(), " does not exists");
		if (fs::exists(fileingt))
		{
			mlog::Debug("But file in \"", fileingt,"\" - exists -> try to load id");
			if (StormLoadMPQTemp(fileingt.c_str(), 30, 0) != 0) 
			{
				mlog::Debug(fileingt," loaded");
				return true;
			}
			mlog::Debug(fileingt, " wasnt loaded");
			return false;
		}
		else
		{
			mlog::Debug("But file in \"", fileingt, "\" - does not exists -> download failed");
			return false;
		}
	}
	mlog::Debug("no way to load file: ", data);
	return false;
}
std::string urlhash(const char* url)
{
	HINTERNET hinternet = InternetOpenA("GoodTool", INTERNET_OPEN_TYPE_DIRECT,NULL,NULL,NULL);
	hinternet = InternetOpenUrlA(hinternet, url, NULL, 0, NULL, NULL);
	char buffer[512];
	bool res = HttpQueryInfoA(hinternet, HTTP_QUERY_CONTENT_MD5, buffer, (LPDWORD)512, NULL);
	buffer[511] = 0;
	std::string h = buffer;
	return h;
}