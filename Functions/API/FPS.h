#pragma once
int SetMaxFps(int fps);
void InitD3DVSync(bool enabled);
bool WGLExtensionSupported(const char* extension_name);
void  EnableVsync(bool enable);
void InitThreadCpuUsage();
double GetWar3CpuUsage();
void UpdateFPS();
int  EnableAutoFPSlimit(bool enable);