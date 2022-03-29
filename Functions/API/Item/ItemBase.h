#pragma once
typedef unsigned int jHANDLE;

int GetItemBaseDataById(int iid);
int GetItemBaseData(jHANDLE Item);
int GetItemBaseDataByIdCaching(int iid);
int GetItemBaseDataCaching(jHANDLE it);
int GetItemBaseTypeIdById(int iid);
int GetItemBaseTypeId(jHANDLE it);
int GetItemBaseGoldCostById(int iid);
int GetItemBaseGoldCost(jHANDLE it);
void SetItemBaseGoldCostById(int iid, int cost);
void SetItemBaseGoldCost(jHANDLE it, int cost);
int GetItemBaseLumberCostById(int iid);
int GetItemBaseLumberCost(jHANDLE it);
void SetItemBaseLumberCostById(int iid, int cost);
void SetItemBaseLumberCost(jHANDLE it, int cost);
int GetItemBaseLevelById(int iid);
int GetItemBaseLevel(jHANDLE it);
void SetItemBaseLevelById(int iid, int level);
void SetItemBaseLevel(jHANDLE it, int lvl);
bool IsItemBaseSellableById(int iid);
bool IsItemBaseSellable(jHANDLE it);
bool IsItemBasePawnableById(int iid);
bool IsItemBasePawnable(jHANDLE it);
bool IsItemBaseDroppableById(int iid);
bool IsItemBaseDroppable(jHANDLE it);
bool IsItemBaseDroppedOnDeathById(int iid);
bool IsItemBaseDroppedOnDeath(jHANDLE it);