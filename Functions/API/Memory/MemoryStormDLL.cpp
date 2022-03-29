#include <Windows.h>
#include <Functions.h>
#include <BasicConstants.h>
#include <Additional Native Constants.h>
#include <From MemHack.h>
#include <Calls.h>
#include <Logs/Log.h>
#include <list>
#include <Windows.h>
#include <memory>

DWORD result;
int StormAllocateMemory(int size, const char* name, int unk_1, int unk_2)
{
    if (pStormAllocateMemory > 0)
    {
        if (size > 0)
        {
            return std_call(pStormAllocateMemory, size, (DWORD)name, unk_1, unk_2);
        }
    }

    return 0;
}


int StormFreeMemory(int addr, const char* name, int unk_1, int unk_2)
{
    if (pStormFreeMemory > 0)
    {
        if (addr > 0)
        {
            return std_call(pStormFreeMemory, addr, (DWORD)name, unk_1, unk_2);
        }
    }

    return 0;
}

int StormGetMemorySize(int addr, const char* name, int unk_1)
{
    if (pStormGetMemorySize > 0)
    {
        if (addr > 0)
        {
            return std_call(pStormGetMemorySize, addr, (DWORD)name, unk_1);
        }
    }

    return 0;
}

int StormReallocateMemory(int addr, int size, const char* name, int unk_1, int unk_2)
{
    if (pStormReallocateMemory > 0)
    {
        if (size > 0)
        {
            return std_call(pStormReallocateMemory, addr, size, (DWORD)name, unk_1, unk_2);
        }
    }

    return 0;
}

int StormLoadMPQ(const char* mpq, int priority, int unk)
{
    int pMPQ;
    result = std_call(pStorm266, (DWORD)mpq, priority, unk,(DWORD)&pMPQ); //last - returns

    if (result == NULL)
    {
        mlog::Error("unable to load MPQ: ", mpq);
    }
    return pMPQ;
}

int StormOpenFileAsArchive(int mode, const char* mpq, int priority, int unk)
{
    int pMPQ;
    result = std_call(pStorm293, mode, (DWORD)mpq, priority, unk,(DWORD)&pMPQ); //last - returns
    if (result == NULL)
    {
        mlog::Error("unable to load MPQ: ", mpq);
    }
    return pMPQ;
}

DWORD StormOpenFile(const char* file)
{
    int a;
    std_call(pStorm267, (DWORD)file, (DWORD)&a); 
    return a;
}

DWORD StormGetFileSize(DWORD hfile, LPDWORD lpFileSizeHigh)
{
    return std_call(pStorm265, (DWORD)hfile, (DWORD)lpFileSizeHigh);
}

DWORD StormCloseFile(DWORD hfile)
{
    return std_call(pStorm253, hfile);
}

DWORD StormReadFile(DWORD hFile, void* pBuffer, DWORD nNumberOfBytesToRead, DWORD* pNumberOfBytesRead, DWORD lpDistanceToMoveHigh)
{
    return std_call(pStorm269, hFile, (DWORD)pBuffer, nNumberOfBytesToRead, (DWORD)pNumberOfBytesRead, lpDistanceToMoveHigh);
}

struct mpqdata
{
    std::string path;
    DWORD pMPQ;
    bool del;
};
std::list<std::shared_ptr<mpqdata>> loadedMPQ;

int StormLoadMPQTemp(const char* mpq, int priority, int unk)
{
    int pMPQ;
    result = std_call(pStorm266, (DWORD)mpq, priority, unk, (DWORD)&pMPQ); //last - returns
    if (pMPQ == NULL)
    {
        mlog::Error("unable to load MPQ: ", mpq);
    }
    if (pMPQ != NULL)
    {
        mpqdata a;
        a.path = mpq;
        a.pMPQ = pMPQ;
        a.del = false;
        loadedMPQ.push_back(std::make_shared<mpqdata>(a));
    }
    return pMPQ;
}

int StormLoadMPQTempR(const char* mpq, int priority, int unk)
{
    int pMPQ;
    result = std_call(pStorm266, (DWORD)mpq, priority, unk, (DWORD)&pMPQ); //last - returns
    if (pMPQ == NULL)
    {
        mlog::Error("unable to load MPQ: ", mpq);
    }
    if (pMPQ != NULL)
    {
        mpqdata a;
        a.path = mpq;
        a.pMPQ = pMPQ;
        a.del = true;
        loadedMPQ.push_back(std::make_shared<mpqdata>(a));
    }
    return pMPQ;
}

DWORD StormCloseArchive(DWORD pMPQ)
{
    return std_call(pStorm252, pMPQ);
}

void UnloadResources()
{
    for (auto a : loadedMPQ)
    {
        if (a != NULL)
        {
            auto bar = a.get();
            StormCloseArchive(bar->pMPQ);
            if (bar->del)
            {
                DeleteFileA(a.get()->path.c_str());
            }
        }
    }
    loadedMPQ.clear();
}

std::string StormGetFileAsString(const char* file)
{
    DWORD hfile = StormOpenFile(file);
    if (hfile == NULL) return "";
    DWORD len = StormGetFileSize(hfile, 0);
    char* buffer = new char[len + 1];
    StormReadFile(hfile, buffer, len, 0, 0);
    StormCloseFile(hfile);
    buffer[len] = 0;
    std::string ret = buffer;
    delete[] buffer;
    return ret;
}

int GetMPQLoadResult()
{
    return result;
}
