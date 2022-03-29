#pragma once
#include <BasicConstants.h>


void StartAddressItemCooldown(int pUnit, int pItem, float cd);

void SetAddressItemIdType(int pItem, int id);

void SetAddressItemModel(int pItem, const char* model);

float GetAddressItemLife(int pItem);

void SetAddressItemLife(int pItem, float life);

float GetAddressItemMaxLife(int pItem);

void SetAddressItemMaxLife(int pItem, float life);

void StartItemCooldown(jHANDLE u, jHANDLE it, float cd);

void SetItemIdType(jHANDLE it, int id);

void SetItemModel(jHANDLE it, const char* model);

float GetItemLife(jHANDLE it);

void SetItemLife(jHANDLE it, float life);

float GetItemMaxLife(jHANDLE it);

void SetItemMaxLife(jHANDLE it, float life);