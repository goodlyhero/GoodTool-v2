#pragma once

void InitMapErrorHook();
void DetachMapErrorHook();


void InitInterestingTextHook();
void DetachInterestingTextHook();

void NetMsgInitHook();
void detachNetMsgInitHook();
void HookNetEvents();

void InitDebugHook();
void DetachDebugHook();