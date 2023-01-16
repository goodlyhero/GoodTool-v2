#include <BasicConstants.h>
#include <Windows.h>
#include <iostream>
#include <Functions.h>
#include <Logs/Log.h>
#include <Warcraft Functions.h>
#include <Extern Natives.h>
#include <From MemHack.h>
#include <Additional Native Constants.h>
#include <Mem_restorer.h>
#include <States.h>

#include <objidl.h>
#include <gdiplus.h>

#pragma comment (lib,"Gdiplus.lib")


using namespace Gdiplus;
//export module WarcraftFunctions;
void SetTls()
{
	DWORD Data = *(DWORD *)(dwGameDll + 0xACEB4C);
	DWORD TlsIndex = *(DWORD *)(dwGameDll + 0xAB7BF4);

	if (TlsIndex)
	{
		DWORD v5 = **(DWORD **)(*(DWORD *)(*(DWORD *)(dwGameDll + 0xACEB5C) + 4 * Data) + 44);
		TlsSetValue(TlsIndex, *(LPVOID *)(v5 + 520));
	}
}

void TextPrint(const char *szText, float fDuration)
{
	DWORD dwDuration = *((DWORD*)&fDuration);
	LogS() << "[message]: " << szText << std::endl;
	if (IsInGame())
	{
		__asm
		{
			PUSH	0xFFFFFFFF
			PUSH	dwDuration
			PUSH	szText
			PUSH	0x0
			PUSH	0x0
			MOV		ECX, [GAME_GlobalClass]
			MOV		ECX, [ECX]
			CALL	GAME_PrintToScreen
		}
	}
}

void TextPrintNoLog(char* szText, float fDuration)
{
	if (IsInGame())
	{
		DWORD dwDuration = *((DWORD*)&fDuration);
		__asm
		{
			PUSH	0xFFFFFFFF
			PUSH	dwDuration
			PUSH	szText
			PUSH	0x0
			PUSH	0x0
			MOV		ECX, [GAME_GlobalClass]
			MOV		ECX, [ECX]
			CALL	GAME_PrintToScreen
		}
	}
}

void TextPrintEx(char *szText, ...)
{
	char szTextEx[8192] = {NULL};

	va_list Args;
	va_start(Args, szText);
	vsprintf_s(szTextEx, szText, Args);
	va_end(Args);

	TextPrint(szTextEx);
	LogS() << "[message]: " << szTextEx << std::endl;
}

void cTextPrint(int count, ...)
{
	va_list tlist;
	if (count > 0)
	{
		va_start(tlist, count);
		char* buffer = copystr(va_arg(tlist, char*));
		char* temp;
		for (int i = 1; i < count; i++)
		{
			temp = va_arg(tlist, char*);
			char* t = newstr(buffer, temp);
			delete[] buffer;
			buffer = t;
		}
		TextPrint(buffer);
		LogS() << "[message]: " << buffer << std::endl;
	}
	return;
}

DWORD WarcraftVersion()
{
	DWORD dwHandle = NULL;
	DWORD dwLen    = GetFileVersionInfoSize("Game.dll", &dwHandle);

	LPVOID lpData = new char[dwLen];
	GetFileVersionInfo("Game.dll", dwHandle, dwLen, lpData);

	LPBYTE lpBuffer = NULL;
	UINT   uLen     = NULL;
	VerQueryValue(lpData, "\\", (LPVOID *)&lpBuffer, &uLen);

	VS_FIXEDFILEINFO *Version = (VS_FIXEDFILEINFO *)lpBuffer;

	return LOWORD(Version->dwFileVersionLS);
}

float GetMouseWorldX()
{
	return *(float*)(*(DWORD*)((*(DWORD*)(dwGameDll + 0xAB4F80)) + 0x3BC) + 0x310);
}

float GetMouseWorldY()
{
	return *(float*)(*(DWORD*)((*(DWORD*)(dwGameDll + 0xAB4F80)) + 0x3BC) + 0x314);
}

float GetMouseWorldZ()
{
	return *(float*)(*(DWORD*)((*(DWORD*)(dwGameDll + 0xAB4F80)) + 0x3BC) + 0x318);
}

int GetNativesCnt()
{
	return ReadRealMemory(pnativescnt);
}

int getfunccnt()
{
	DWORD jVM = GetJassVM(1);
	DWORD pfunclist = jVM + 10376;
	DWORD funcnt = ReadRealMemory(pfunclist);
	return ((DWORD*)funcnt)[1];
}

DWORD RegisterFunction(DWORD* func)
{
	return jRegisterFunction((DWORD)GetJassVM(1), (DWORD)func);
}

DWORD DRegisterFunction(DWORD func)
{
	return jRegisterFunction((DWORD)GetJassVM(1), (DWORD)func);
}

DWORD* CreateJassNcallFunction1arg(int n,DWORD func)
{
	DWORD* buffer = new DWORD[8];
	buffer[0] = *(DWORD*)("\x01\x04\x00\x0C");//�������� � ������� 1 �������
	buffer[1] = (DWORD)n;
	buffer[2] = *(DWORD*)("\x01\x00\x00\x13");//push
	buffer[3] = 0;
	buffer[4] = *(DWORD*)("\x00\x00\x00\x15");//�������� ��������� �������
	buffer[5] = func;
	buffer[6] = *(DWORD*)("\x00\x00\x00\x27");//���������� ���������
	buffer[7] = 0;
	return buffer;
}

DWORD* CreateJassFcallFunction1arg(int n,DWORD func)
{
	DWORD* buffer = new DWORD[8];
	buffer[0] = *(DWORD*)("\x1\x4\x0\xC");//�������� � ������� 1 �������
	buffer[1] = (DWORD)n;
	buffer[2] = *(DWORD*)("\x1\x0\x0\x13");//push
	buffer[3] = 0;
	buffer[4] = *(DWORD*)("\x0\x0\x0\x16");//�������� ��������� ���������
	buffer[5] = func;
	buffer[6] = *(DWORD*)("\x0\x0\x0\x27");//���������� ���������
	buffer[7] = 0;
	return buffer;
}

/*
DWORD* CreateJassAction(int n, DWORD func)
{
	DWORD* buffer = new DWORD[8];
	buffer[0] = *(DWORD*)("\x1\x4\x0\xC");//�������� � ������� 1 �������
	buffer[1] = (DWORD)n;
	buffer[2] = *(DWORD*)("\x1\x0\x0\x13");//push
	buffer[3] = 0;
	buffer[4] = *(DWORD*)("\x0\x0\x0\x15");//�������� ��������� �������
	buffer[5] = func;
	buffer[6] = *(DWORD*)("\x0\x0\x0\x27");//���������� ���������
	buffer[7] = 0;
	return buffer;
}*/

DWORD* CreatePureFunc()
{
	DWORD* buffer = new DWORD[8];
	buffer[0] = *(DWORD*)("\x0\x0\x0\x27");//���������� ���������
	buffer[1] = 0;
	return buffer;
}

/*
DWORD* CreateJassCondition(int n, DWORD func)
{
	DWORD* buffer = new DWORD[10];
	buffer[0] = *(DWORD*)("\x1\x4\x0\xC");//�������� � ������� 1 �������
	buffer[1] = (DWORD)n;
	buffer[2] = *(DWORD*)("\x1\x0\x0\x13");//push
	buffer[3] = 0;
	buffer[4] = *(DWORD*)("\x0\x0\x0\x15");//�������� ��������� �������
	buffer[5] = func;
	buffer[6] = *(DWORD*)("\x0\x0\x0\x27");//���������� ���������
	buffer[7] = 0;

	return buffer;
}*/
/*
void pTMPselectUnit(int unit, bool flag)
{
	DisplayTextToPlayer(GetLocalPlayer(), 0, 0, I2S(flag));
	jSelectUnit(unit,flag);
}*/

void UnlockChat()
{
	PatchSecure(dwGameDll + 0x2FDEC0, "\xEB\x1B", 2);
	PatchSecure(dwGameDll + 0x2FDB59, "\xEB\x08", 2);
}


int FirstLocalSelected()
{
	return ObjectToHandleId(GetLocalSelectedRealUnit());
}

#define GetFilePointer(hFile) SetFilePointer(hFile, 0, NULL, FILE_CURRENT)
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes

	ImageCodecInfo* pImageCodecInfo = NULL;

	GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;  // Failure

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;  // Failure

	GetImageEncoders(num, size, pImageCodecInfo);

	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}

	free(pImageCodecInfo);
	return -1;  // Failure
}


int SaveJpeg(HBITMAP hBmp, LPCWSTR lpszFilename, ULONG uQuality)
{
	ULONG* pBitmap = NULL;
	CLSID imageCLSID;
	EncoderParameters encoderParams;
	int iRes = 0;

	typedef Status(WINAPI* pGdipCreateBitmapFromHBITMAP)(HBITMAP, HPALETTE, ULONG**);
	pGdipCreateBitmapFromHBITMAP lGdipCreateBitmapFromHBITMAP;

	typedef Status(WINAPI* pGdipSaveImageToFile)(ULONG*, const WCHAR*, const CLSID*, const EncoderParameters*);
	pGdipSaveImageToFile lGdipSaveImageToFile;

	// load GdipCreateBitmapFromHBITMAP
	lGdipCreateBitmapFromHBITMAP = (pGdipCreateBitmapFromHBITMAP)GetProcAddress(GetModuleHandle(NULL), "GdipCreateBitmapFromHBITMAP");
	if (lGdipCreateBitmapFromHBITMAP == NULL)
	{
		// error
		return 0;
	}

	// load GdipSaveImageToFile
	lGdipSaveImageToFile = (pGdipSaveImageToFile)GetProcAddress(GetModuleHandle(NULL), "GdipSaveImageToFile");
	if (lGdipSaveImageToFile == NULL)
	{
		// error
		return 0;
	}

	lGdipCreateBitmapFromHBITMAP(hBmp, NULL, &pBitmap);

	iRes = GetEncoderClsid(L"image/jpeg", &imageCLSID);
	if (iRes == -1)
	{
		// error
		return 0;
	}
	encoderParams.Count = 1;
	encoderParams.Parameter[0].NumberOfValues = 1;
	encoderParams.Parameter[0].Guid = EncoderQuality;
	encoderParams.Parameter[0].Type = EncoderParameterValueTypeLong;
	encoderParams.Parameter[0].Value = &uQuality;

	lGdipSaveImageToFile(pBitmap, lpszFilename, &imageCLSID, &encoderParams);


	return 1;
}

bool SaveBMPFile(char* filename, HBITMAP bitmap, HDC bitmapDC, int width, int height) {
	bool Success = 0;
	HBITMAP OffscrBmp = NULL;
	HDC OffscrDC = NULL;
	LPBITMAPINFO lpbi = NULL;
	LPVOID lpvBits = NULL;
	HANDLE BmpFile = INVALID_HANDLE_VALUE;
	BITMAPFILEHEADER bmfh;
	if ((OffscrBmp = CreateCompatibleBitmap(bitmapDC, width, height)) == NULL)
		return 0;
	if ((OffscrDC = CreateCompatibleDC(bitmapDC)) == NULL)
		return 0;
	HBITMAP OldBmp = (HBITMAP)SelectObject(OffscrDC, OffscrBmp);
	BitBlt(OffscrDC, 0, 0, width, height, bitmapDC, 0, 0, SRCCOPY);
	if ((lpbi = (LPBITMAPINFO)(new char[sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD)])) == NULL)
		return 0;
	ZeroMemory(&lpbi->bmiHeader, sizeof(BITMAPINFOHEADER));
	lpbi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	SelectObject(OffscrDC, OldBmp);
	if (!GetDIBits(OffscrDC, OffscrBmp, 0, height, NULL, lpbi, DIB_RGB_COLORS))
		return 0;
	if ((lpvBits = new char[lpbi->bmiHeader.biSizeImage]) == NULL)
		return 0;
	if (!GetDIBits(OffscrDC, OffscrBmp, 0, height, lpvBits, lpbi, DIB_RGB_COLORS))
		return 0;
	if ((BmpFile = CreateFile(filename,
		GENERIC_WRITE,
		0, NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL)) == INVALID_HANDLE_VALUE)
		return 0;
	DWORD Written;
	bmfh.bfType = 19778;
	bmfh.bfReserved1 = bmfh.bfReserved2 = 0;
	if (!WriteFile(BmpFile, &bmfh, sizeof(bmfh), &Written, NULL))
		return 0;
	if (Written < sizeof(bmfh))
		return 0;
	if (!WriteFile(BmpFile, &lpbi->bmiHeader, sizeof(BITMAPINFOHEADER), &Written, NULL))
		return 0;
	if (Written < sizeof(BITMAPINFOHEADER))
		return 0;
	int PalEntries;
	if (lpbi->bmiHeader.biCompression == BI_BITFIELDS)
		PalEntries = 3;
	else PalEntries = (lpbi->bmiHeader.biBitCount <= 8) ?
		(int)(1 << lpbi->bmiHeader.biBitCount) : 0;
	if (lpbi->bmiHeader.biClrUsed)
		PalEntries = lpbi->bmiHeader.biClrUsed;
	if (PalEntries) {
		if (!WriteFile(BmpFile, &lpbi->bmiColors, PalEntries * sizeof(RGBQUAD), &Written, NULL))
			return 0;
		if (Written < PalEntries * sizeof(RGBQUAD))
			return 0;
	}
	bmfh.bfOffBits = GetFilePointer(BmpFile);
	if (!WriteFile(BmpFile, lpvBits, lpbi->bmiHeader.biSizeImage, &Written, NULL))
		return 0;
	if (Written < lpbi->bmiHeader.biSizeImage)
		return 0;
	bmfh.bfSize = GetFilePointer(BmpFile);
	SetFilePointer(BmpFile, 0, 0, FILE_BEGIN);
	if (!WriteFile(BmpFile, &bmfh, sizeof(bmfh), &Written, NULL))
		return 0;
	if (Written < sizeof(bmfh))
		return 0;


	CloseHandle(BmpFile);

	delete[](char*)lpvBits;
	delete[] lpbi;

	DeleteDC(OffscrDC);
	DeleteObject(OffscrBmp);


	return 1;
}

bool ScreenCapture(int x, int y, int width, int height, WCHAR* filename, HWND hwnd) {


	HDC hDC = GetDC(hwnd);
	HDC hDc = CreateCompatibleDC(hDC);


	HBITMAP hBmp = CreateCompatibleBitmap(hDC, width, height);


	HGDIOBJ old = SelectObject(hDc, hBmp);
	BitBlt(hDc, 0, 0, width, height, hDC, x, y, SRCCOPY);

	bool ret = SaveJpeg(hBmp, filename,0.5);


	SelectObject(hDc, old);

	DeleteObject(hBmp);

	DeleteDC(hDc);
	ReleaseDC(hwnd, hDC);

	return ret;
}

bool ScreenCaptureBMP(int x, int y, int width, int height, char* filename, HWND hwnd) {


	HDC hDC = GetDC(hwnd);
	HDC hDc = CreateCompatibleDC(hDC);


	HBITMAP hBmp = CreateCompatibleBitmap(hDC, width, height);


	HGDIOBJ old = SelectObject(hDc, hBmp);
	BitBlt(hDc, 0, 0, width, height, hDC, x, y, SRCCOPY);

	//bool ret = SaveJpeg(hBmp, filename,0.5);
	bool ret = SaveBMPFile(filename, hBmp, hDC, width, height);


	SelectObject(hDc, old);

	DeleteObject(hBmp);

	DeleteDC(hDc);
	ReleaseDC(hwnd, hDC);

	return ret;
}

void PrintWC3( const char* filename) {

	RECT wc3rect;
	GetClientRect(hwndwc, & wc3rect);

	int x = wc3rect.left;
	int y = wc3rect.top;

	int rx = wc3rect.right;
	int ry = wc3rect.bottom;

	int width = rx - x;
	int height = ry - y;
	//const size_t cSize = strlen(filename) + 1;
	//wchar_t* wc = new wchar_t[cSize];
	//size_t tmp = 0;
	//mbstowcs_s(&tmp, wc, cSize, NULL, cSize);

	ScreenCaptureBMP(x, y, width, height, (char*)filename, hwndwc);
	//delete[] wc;



}