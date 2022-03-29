#pragma once
#include <BasicConstants.h>

DWORD LoadTOCFile(const char* filename);

DWORD GetCFrameByName(const char* name, int id);;

int CreateCFrameEx(const char* baseframe, int parent, int point, int relativepoint, int id);

int CreateCFrame(const char* baseframe, int parent, int id);

int GetFrameLayoutByType(int pFrame, int fid);

int GetFrameLayout(int pFrame);

bool IsFrameLayoutByType(int pFrame, int fid);

bool IsFrameLayout(int pFrame);
