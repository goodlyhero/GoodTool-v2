#pragma once

void PatchSecure(DWORD addr, const char* data, size_t len);
void WriteIntSave(DWORD dest, int what);
void WriteDWORDSave(DWORD dest, DWORD what);