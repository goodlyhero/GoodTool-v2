#pragma once
void LoadSettings(void);
void LoadMods();
void SaveProperties();
bool LoadMod(const char* _path, const char* _name, const char* _initializer = NULL);