#include <Additional Native Constants.h>
#include <Calls.h>
#include <Functions.h>
export module CIconCover;

export void SetCIconCoverTip(DWORD pIconFrame, char* d1, char* d2, char* d3)
{
	this_call(pSetCIconConverTip, pIconFrame, (DWORD)d1, (DWORD)d2, (DWORD)d3);
}