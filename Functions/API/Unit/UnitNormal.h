#include <Windows.h>

#define NULLIFY_RESULT_NULLED 0
#define NULLIFY_RESULT_EMPTY 1
#define NULLIFY_RESULT_ATKDISABLED 2
#define NULLIFY_RESULT_NOATTACK 3

int GetUnitTypeIdReal(DWORD u);

void SetUnitTypeId(DWORD u, int i);

int MorphUnitToTypeId(DWORD u, int id);

int GetHeroNeededXPForLevel(DWORD u, int level);

int GetHeroNeededXP(DWORD u);

int GetUnitVertexColour(DWORD u);

int GetUnitVertexColourA(DWORD u);

int GetUnitVertexColourR(DWORD u);

int GetUnitVertexColourG(DWORD u);

int GetUnitVertexColourB(DWORD u);

void SetUnitModel(DWORD u, const char* model);

int SetUnitTexture(DWORD u, const char* texturepath, int textureId);

float GetUnitImpactZ(DWORD u);

void SetUnitImpactZ(DWORD u, float impactZ);

void RedrawUnit(DWORD u);

bool IsAttackDisabled(DWORD u);

void UnitDisableAttack(DWORD u);

void UnitEnableAttack(DWORD u);

int GetUnitCritterFlag(DWORD u);

void SetUnitCritterFlag(DWORD u, int id);

float GetUnitTimedLife(DWORD u);

void SetUnitTimedLife(DWORD u, float dur);

void SetUnitPhased(DWORD u);

void UnitApplySilence(DWORD u, bool flag);

void UnitDisableAbilities(DWORD u, bool flag);

void UnitSetStunFlag(DWORD u, bool add);

bool IsUnitStunned(DWORD u);

void UnitApplyStun(DWORD u);

bool IsUnitMovementDisabled(DWORD u);

void SetUnitControl(DWORD u, int flagval, int moveval, int atackval, int invval);

void UnitDisableControl(DWORD u);

void UnitEnableControl(DWORD u);

void UnitRemoveMovementDisables(DWORD u);

void SetUnitMovement(int pData, bool flag);

void UnitEnableMovement(DWORD u);

void UnitDisableMovement(DWORD u);

void UnitDisableMovementEx(DWORD u, bool disable);

bool IsUnitInventoryDisabled(DWORD u);

void UnitEnableInventory(DWORD u, bool flag);

int GetAddressLocustFlags(int pAddr1, int pAddr2);

void SetLocustFlags(DWORD u, int i);

void UnitEnableTruesightImmunity(DWORD u);

void UnitDisableTruesightImmunity(DWORD u);

int GetUnitFlags(DWORD u);

void SetUnitFlags(DWORD u, int i);

void AddUnitFlags(DWORD u, int i);

int GetUnitFlags_2(DWORD u);

void SetUnitFlags_2(DWORD u, int i);

void AddUnitFlags_2(DWORD u, int i);

int GetUnitVisibilityClass(DWORD u);

void SetUnitVisibleByPlayer(DWORD u, int p, int c);

bool IsUnitInvulnerable(DWORD u);

int GetUnitInvulnerableCounter(DWORD u);

void SetUnitInvulnerableCounter(DWORD u, int i);

void ModifyInvulnerableCounter(DWORD u, int diff);

bool IsUnitInvulnerable2(DWORD u);

void SetUnitFacingInstant(DWORD u, float a);

int GetUnitMoveType(DWORD u);

void SetUnitMoveType(DWORD u, int m_type);

int GetHeroPrimaryAttribute(DWORD u);

void SetHeroPrimaryAttribute(DWORD u, int i);

int GetUnitAttackAbility(DWORD u);

void SetUnitAttackAbility(DWORD u, int pAddr);

int GetUnitAttackOffsetValue(DWORD u, int pOff);

float GetUnitNextAttackTimestamp(DWORD u);

bool UnitResetAttackCooldown(DWORD u);

DWORD UnitNullifyCurrentAttack(DWORD u);

bool AddUnitExtraAttack(DWORD u);

int GetUnitAttackTypeByIndex(DWORD u, int index);

int GetUnitAttackType1(DWORD u);

int GetUnitAttackType2(DWORD u);

void SetUnitAttackOffsetValue(DWORD u, int offset, int val);

void SetUnitAttackTypeByIndex(DWORD u, int i, int attacknum);

void SetUnitAttackType1(DWORD u, int i);

void SetUnitAttackType2(DWORD u, int i);

int GetUnitWeaponSound(DWORD u);

void SetUnitWeaponSound(DWORD u, int i);

int GetUnitWeaponType(DWORD u);

void SetUnitWeaponType(DWORD u, int i);

int GetUnitBaseDamage(DWORD u);

void SetUnitBaseDamage(DWORD u, int i);

void AddUnitBaseDamage(DWORD u, int bonus);

int GetUnitBonusDamage(DWORD u);

void SetUnitBonusDamage(DWORD u, int i);

void AddUnitBonusDamage(DWORD u, int i);

int GetUnitTotalDamage(DWORD u);

int GetUnitBaseAttributeDamage(DWORD u);

void SetUnitBaseAttributeDamage(DWORD u, int i);

int GetUnitDamageDicesSideCount(DWORD u);

void SetUnitDamageDicesSideCount(DWORD u, int i);

int GetUnitDamageDicesCount(DWORD u);

void SetUnitDamageDicesCount(DWORD u, int i);

float GetUnitAttackRangeByIndex(DWORD u, int index);

void SetUnitAttackRangeByIndex(DWORD u, int index, float r);

float GetUnitAttackRange1(DWORD u);

void SetUnitAttackRange1(DWORD u, float r);

float GetUnitAttackRange2(DWORD u);

void SetUnitAttackRange2(DWORD u, float r);

float GetUnitBATByIndex(DWORD u, int index);

void SetUnitBATByIndex(DWORD u, int index, float r);

float GetUnitBAT1(DWORD u);

void SetUnitBAT1(DWORD u, float r);

float GetUnitBAT2(DWORD u);

void SetUnitBAT2(DWORD u, float r);

float GetUnitAttackPointByIndex(DWORD u, int index);

void SetUnitAttackPointByIndex(DWORD u, int index, float r);

float GetUnitAttackPoint1(DWORD u);

void SetUnitAttackPoint1(DWORD u, float r);

float GetUnitAttackPoint2(DWORD u);

void SetUnitAttackPoint2(DWORD u, float r);

int GetUnitAttackEnabledIndex(DWORD u);

float GetUnitAttackBackswing(DWORD u);

void SetUnitAttackBackswing(DWORD u, float r);

float GetUnitAttackSpeed(DWORD u);

void SetUnitAttackSpeed(DWORD u, float r);

void AddUnitAttackSpeed(DWORD u, float r);

float GetUnitAttackDamage(DWORD u);

int GetUnitArmourType(DWORD u);

void SetUnitArmourType(DWORD u, int id);

float GetUnitArmour(DWORD u);

void SetUnitArmour(DWORD u, float r);

void AddUnitArmour(DWORD u, float value);

float GetUnitTimeScale(DWORD u);

float GetUnitBaseMoveSpeed(DWORD u);

float GetUnitBonusMoveSpeed(DWORD u);

bool SetUnitBonusMoveSpeed(DWORD u, float r);

void AddUnitBonusMovespeed(DWORD u, float r);

void SetUnitMaxLife(DWORD u, float newhp);

void AddUnitMaxLife(DWORD u, float value);

void SetUnitMaxMana(DWORD u, float newmp);

void AddUnitMaxMana(DWORD u, float value);

float GetWidgetLifeRegen(DWORD u);

float GetUnitLifeRegen(DWORD u);

void SetUnitLifeRegen(DWORD u, float r);

void AddUnitLifeRegen(DWORD u, float r);

float GetUnitManaRegen(DWORD u);

void SetUnitManaRegen(DWORD u, float r);

void AddUnitManaRegen(DWORD u, float r);
