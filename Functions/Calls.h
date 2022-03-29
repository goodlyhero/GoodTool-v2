#pragma once

inline DWORD this_call(DWORD pfuncaddr, DWORD arg1)
{
	return ((DWORD(__thiscall*) (DWORD i1))pfuncaddr)(arg1);
}
inline DWORD this_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2)
{
	return ((DWORD(__thiscall*) (DWORD i1, DWORD i2))pfuncaddr)(arg1, arg2);
}
inline DWORD this_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3)
{
	return ((DWORD(__thiscall*) (DWORD i1, DWORD i2, DWORD i3))pfuncaddr)(arg1, arg2, arg3);
}
inline DWORD this_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	return ((DWORD(__thiscall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4))pfuncaddr)(arg1, arg2, arg3, arg4);
}
inline DWORD this_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5)
{
	return ((DWORD(__thiscall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5))pfuncaddr)(arg1, arg2, arg3, arg4, arg5);
}
inline DWORD this_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6)
{
	return ((DWORD(__thiscall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6);
}
inline DWORD this_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7)
{
	return ((DWORD(__thiscall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
inline DWORD this_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8)
{
	return ((DWORD(__thiscall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD,DWORD,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
inline DWORD this_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9)
{
	return ((DWORD(__thiscall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD,DWORD,DWORD,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
inline DWORD this_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10)
{
	return ((DWORD(__thiscall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD,DWORD,DWORD,DWORD,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
inline DWORD this_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10, DWORD arg11)
{
	return ((DWORD(__thiscall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
inline DWORD this_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10, DWORD arg11, DWORD arg12)
{
	return ((DWORD(__thiscall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1)
{
	return ((DWORD(__fastcall*) (DWORD i1))pfuncaddr)(arg1);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2)
{
	return ((DWORD(__fastcall*) (DWORD i1, DWORD i2))pfuncaddr)(arg1, arg2);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3)
{
	return ((DWORD(__fastcall*) (DWORD i1, DWORD i2, DWORD i3))pfuncaddr)(arg1, arg2, arg3);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	return ((DWORD(__fastcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4))pfuncaddr)(arg1, arg2, arg3, arg4);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5)
{
	return ((DWORD(__fastcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5))pfuncaddr)(arg1, arg2, arg3, arg4, arg5);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6)
{
	return ((DWORD(__fastcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7)
{
	return ((DWORD(__fastcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8)
{
	return ((DWORD(__fastcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9)
{
	return ((DWORD(__fastcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10)
{
	return ((DWORD(__fastcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10, DWORD arg11)
{
	return ((DWORD(__fastcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
inline DWORD fast_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10, DWORD arg11, DWORD arg12)
{
	return ((DWORD(__fastcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1)
{
	return ((DWORD(__cdecl*) (DWORD i1))pfuncaddr)(arg1);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2)
{
	return ((DWORD(__cdecl*) (DWORD i1, DWORD i2))pfuncaddr)(arg1, arg2);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3)
{
	return ((DWORD(__cdecl*) (DWORD i1, DWORD i2, DWORD i3))pfuncaddr)(arg1, arg2, arg3);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	return ((DWORD(__cdecl*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4))pfuncaddr)(arg1, arg2, arg3, arg4);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5)
{
	return ((DWORD(__cdecl*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5))pfuncaddr)(arg1, arg2, arg3, arg4, arg5);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6)
{
	return ((DWORD(__cdecl*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7)
{
	return ((DWORD(__cdecl*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8)
{
	return ((DWORD(__cdecl*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9)
{
	return ((DWORD(__cdecl*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10)
{
	return ((DWORD(__cdecl*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10, DWORD arg11)
{
	return ((DWORD(__cdecl*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
inline DWORD cdecl_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10, DWORD arg11, DWORD arg12)
{
	return ((DWORD(__cdecl*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1)
{
	return ((DWORD(__stdcall*) (DWORD i1))pfuncaddr)(arg1);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2)
{
	return ((DWORD(__stdcall*) (DWORD i1, DWORD i2))pfuncaddr)(arg1, arg2);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3)
{
	return ((DWORD(__stdcall*) (DWORD i1, DWORD i2, DWORD i3))pfuncaddr)(arg1, arg2, arg3);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	return ((DWORD(__stdcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4))pfuncaddr)(arg1, arg2, arg3, arg4);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5)
{
	return ((DWORD(__stdcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5))pfuncaddr)(arg1, arg2, arg3, arg4, arg5);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6)
{
	return ((DWORD(__stdcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7)
{
	return ((DWORD(__stdcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5,DWORD,DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8)
{
	return ((DWORD(__stdcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9)
{
	return ((DWORD(__stdcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10)
{
	return ((DWORD(__stdcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10, DWORD arg11)
{
	return ((DWORD(__stdcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
inline DWORD std_call(DWORD pfuncaddr, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10, DWORD arg11, DWORD arg12)
{
	return ((DWORD(__stdcall*) (DWORD i1, DWORD i2, DWORD i3, DWORD i4, DWORD i5, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
