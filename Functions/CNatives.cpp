#include "CNatives.h"
float   CDeg2Rad(float   real_1)
{
    int ret = (jDeg2Rad(&real_1));
    return *(float*)&ret;
}
float   CRad2Deg(float   real_1)
{
    int ret = (jRad2Deg(&real_1));
    return *(float*)&ret;
}
float   Sin(float   real_1)
{
    int ret = (jSin(&real_1));
    return *(float*)&ret;
}
float   Cos(float   real_1)
{
    int ret = (jCos(&real_1));
    return *(float*)&ret;
}
float   Tan(float   real_1)
{
    int ret = (jTan(&real_1));
    return *(float*)&ret;
}
float   Asin(float   real_1)
{
    int ret = (jAsin(&real_1));
    return *(float*)&ret;
}
float   Acos(float   real_1)
{
    int ret = (jAcos(&real_1));
    return *(float*)&ret;
}
float   Atan(float   real_1)
{
    int ret = (jAtan(&real_1));
    return *(float*)&ret;
}
float   Atan2(float   real_1, float   real_2)
{
    int ret = (jAtan2(&real_1, &real_2));
    return *(float*)&ret;
}
float   SquareRoot(float   real_1)
{
    int ret = (jSquareRoot(&real_1));
    return *(float*)&ret;
}
float   Pow(float   real_1, float   real_2)
{
    int ret = (jPow(&real_1, &real_2));
    return *(float*)&ret;
}
float   I2R(int      integer_1)
{
    int ret = (jI2R(integer_1));
    return *(float*)&ret;
}
int     R2I(float   real_1)
{
    return jR2I(&real_1);
}
const char* I2S(int      integer_1)
{
    return (const char*)GetStringAddress(jI2S(integer_1));
}
const char* R2S(float   real_1)
{
    return (const char*)GetStringAddress(jR2S(&real_1));
}
const char* R2SW(float   real_1, int      integer_2, int      integer_3)
{
    return (const char*)GetStringAddress(jR2SW(&real_1, integer_2, integer_3));
}
int     S2I(const char* STRING_1)
{
    return jS2I(RegStr(STRING_1));
}
float   S2R(const char* STRING_1)
{
    int ret = (jS2R(RegStr(STRING_1)));
    return *(float*)&ret;
}
int     GetHandleId(jHANDLE  HANDLE_1)
{
    return jGetHandleId(HANDLE_1);
}
const char* SubString(const char* STRING_1, int      integer_2, int      integer_3)
{
    return (const char*)GetStringAddress(jSubString(RegStr(STRING_1), integer_2, integer_3));
}
int     StringLength(const char* STRING_1)
{
    return jStringLength(RegStr(STRING_1));
}
const char* StringCase(const char* STRING_1, bool     BOOL_2)
{
    return (const char*)GetStringAddress(jStringCase(RegStr(STRING_1), BOOL_2));
}
int     StringHash(const char* STRING_1)
{
    return jStringHash(RegStr(STRING_1));
}
const char* GetLocalizedString(const char* STRING_1)
{
    return (const char*)GetStringAddress(jGetLocalizedString(RegStr(STRING_1)));
}
int     GetLocalizedHotkey(const char* STRING_1)
{
    return jGetLocalizedHotkey(RegStr(STRING_1));
}
jHANDLE ConvertRace(int      integer_1)
{
    return jConvertRace(integer_1);
}
jHANDLE ConvertAllianceType(int      integer_1)
{
    return jConvertAllianceType(integer_1);
}
jHANDLE ConvertRacePref(int      integer_1)
{
    return jConvertRacePref(integer_1);
}
jHANDLE ConvertIGameState(int      integer_1)
{
    return jConvertIGameState(integer_1);
}
jHANDLE ConvertFGameState(int      integer_1)
{
    return jConvertFGameState(integer_1);
}
jHANDLE ConvertPlayerState(int      integer_1)
{
    return jConvertPlayerState(integer_1);
}
jHANDLE ConvertPlayerScore(int      integer_1)
{
    return jConvertPlayerScore(integer_1);
}
jHANDLE ConvertStartLocPrio(int      integer_1)
{
    return jConvertStartLocPrio(integer_1);
}
jHANDLE ConvertPlayerGameResult(int      integer_1)
{
    return jConvertPlayerGameResult(integer_1);
}
jHANDLE ConvertUnitState(int      integer_1)
{
    return jConvertUnitState(integer_1);
}
jHANDLE ConvertAIDifficulty(int      integer_1)
{
    return jConvertAIDifficulty(integer_1);
}
jHANDLE ConvertGameEvent(int      integer_1)
{
    return jConvertGameEvent(integer_1);
}
jHANDLE ConvertPlayerEvent(int      integer_1)
{
    return jConvertPlayerEvent(integer_1);
}
jHANDLE ConvertPlayerUnitEvent(int      integer_1)
{
    return jConvertPlayerUnitEvent(integer_1);
}
jHANDLE ConvertUnitEvent(int      integer_1)
{
    return jConvertUnitEvent(integer_1);
}
jHANDLE ConvertWidgetEvent(int      integer_1)
{
    return jConvertWidgetEvent(integer_1);
}
jHANDLE ConvertDialogEvent(int      integer_1)
{
    return jConvertDialogEvent(integer_1);
}
jHANDLE ConvertLimitOp(int      integer_1)
{
    return jConvertLimitOp(integer_1);
}
jHANDLE ConvertUnitType(int      integer_1)
{
    return jConvertUnitType(integer_1);
}
jHANDLE ConvertGameSpeed(int      integer_1)
{
    return jConvertGameSpeed(integer_1);
}
jHANDLE ConvertPlacement(int      integer_1)
{
    return jConvertPlacement(integer_1);
}
jHANDLE ConvertGameDifficulty(int      integer_1)
{
    return jConvertGameDifficulty(integer_1);
}
jHANDLE ConvertGameType(int      integer_1)
{
    return jConvertGameType(integer_1);
}
jHANDLE ConvertMapFlag(int      integer_1)
{
    return jConvertMapFlag(integer_1);
}
jHANDLE ConvertMapVisibility(int      integer_1)
{
    return jConvertMapVisibility(integer_1);
}
jHANDLE ConvertMapSetting(int      integer_1)
{
    return jConvertMapSetting(integer_1);
}
jHANDLE ConvertMapDensity(int      integer_1)
{
    return jConvertMapDensity(integer_1);
}
jHANDLE ConvertMapControl(int      integer_1)
{
    return jConvertMapControl(integer_1);
}
jHANDLE ConvertPlayerColor(int      integer_1)
{
    return jConvertPlayerColor(integer_1);
}
jHANDLE ConvertPlayerSlotState(int      integer_1)
{
    return jConvertPlayerSlotState(integer_1);
}
jHANDLE ConvertVolumeGroup(int      integer_1)
{
    return jConvertVolumeGroup(integer_1);
}
jHANDLE ConvertCameraField(int      integer_1)
{
    return jConvertCameraField(integer_1);
}
jHANDLE ConvertBlendMode(int      integer_1)
{
    return jConvertBlendMode(integer_1);
}
jHANDLE ConvertRarityControl(int      integer_1)
{
    return jConvertRarityControl(integer_1);
}
jHANDLE ConvertTexMapFlags(int      integer_1)
{
    return jConvertTexMapFlags(integer_1);
}
jHANDLE ConvertFogState(int      integer_1)
{
    return jConvertFogState(integer_1);
}
jHANDLE ConvertEffectType(int      integer_1)
{
    return jConvertEffectType(integer_1);
}
jHANDLE ConvertVersion(int      integer_1)
{
    return jConvertVersion(integer_1);
}
jHANDLE ConvertItemType(int      integer_1)
{
    return jConvertItemType(integer_1);
}
jHANDLE ConvertAttackType(int      integer_1)
{
    return jConvertAttackType(integer_1);
}
jHANDLE ConvertDamageType(int      integer_1)
{
    return jConvertDamageType(integer_1);
}
jHANDLE ConvertWeaponType(int      integer_1)
{
    return jConvertWeaponType(integer_1);
}
jHANDLE ConvertSoundType(int      integer_1)
{
    return jConvertSoundType(integer_1);
}
jHANDLE ConvertPathingType(int      integer_1)
{
    return jConvertPathingType(integer_1);
}
void    SetMapName(const char* STRING_1)
{
    jSetMapName(RegStr(STRING_1));
}
void    SetMapDescription(const char* STRING_1)
{
    jSetMapDescription(RegStr(STRING_1));
}
void    SetTeams(int      integer_1)
{
    jSetTeams(integer_1);
}
void    SetPlayers(int      integer_1)
{
    jSetPlayers(integer_1);
}
void    SetGameTypeSupported(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetGameTypeSupported(HANDLE_1, BOOL_2);
}
void    SetMapFlag(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetMapFlag(HANDLE_1, BOOL_2);
}
void    SetGameSpeed(jHANDLE  HANDLE_1)
{
    jSetGameSpeed(HANDLE_1);
}
void    SetGamePlacement(jHANDLE  HANDLE_1)
{
    jSetGamePlacement(HANDLE_1);
}
void    SetGameDifficulty(jHANDLE  HANDLE_1)
{
    jSetGameDifficulty(HANDLE_1);
}
void    SetResourceDensity(jHANDLE  HANDLE_1)
{
    jSetResourceDensity(HANDLE_1);
}
void    SetCreatureDensity(jHANDLE  HANDLE_1)
{
    jSetCreatureDensity(HANDLE_1);
}
void    DefineStartLocation(int      integer_1, float   real_2, float   real_3)
{
    jDefineStartLocation(integer_1, &real_2, &real_3);
}
void    DefineStartLocationLoc(int      integer_1, jHANDLE  HANDLE_2)
{
    jDefineStartLocationLoc(integer_1, HANDLE_2);
}
void    SetStartLocPrioCount(int      integer_1, int      integer_2)
{
    jSetStartLocPrioCount(integer_1, integer_2);
}
void    SetStartLocPrio(int      integer_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    jSetStartLocPrio(integer_1, integer_2, integer_3, HANDLE_4);
}
int     GetStartLocPrioSlot(int      integer_1, int      integer_2)
{
    return jGetStartLocPrioSlot(integer_1, integer_2);
}
jHANDLE GetStartLocPrio(int      integer_1, int      integer_2)
{
    return jGetStartLocPrio(integer_1, integer_2);
}
int     GetTeams()
{
    return jGetTeams();
}
int     GetPlayers()
{
    return jGetPlayers();
}
bool    IsGameTypeSupported(jHANDLE  HANDLE_1)
{
    return jIsGameTypeSupported(HANDLE_1);
}
bool    IsMapFlagSet(jHANDLE  HANDLE_1)
{
    return jIsMapFlagSet(HANDLE_1);
}
jHANDLE GetGameTypeSelected()
{
    return jGetGameTypeSelected();
}
jHANDLE GetGamePlacement()
{
    return jGetGamePlacement();
}
jHANDLE GetGameSpeed()
{
    return jGetGameSpeed();
}
jHANDLE GetGameDifficulty()
{
    return jGetGameDifficulty();
}
jHANDLE GetResourceDensity()
{
    return jGetResourceDensity();
}
jHANDLE GetCreatureDensity()
{
    return jGetCreatureDensity();
}
float   GetStartLocationX(int      integer_1)
{
    int ret = (jGetStartLocationX(integer_1));
    return *(float*)&ret;
}
float   GetStartLocationY(int      integer_1)
{
    int ret = (jGetStartLocationY(integer_1));
    return *(float*)&ret;
}
jHANDLE GetStartLocationLoc(int      integer_1)
{
    return jGetStartLocationLoc(integer_1);
}
void    SetPlayerTeam(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetPlayerTeam(HANDLE_1, integer_2);
}
void    SetPlayerStartLocation(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetPlayerStartLocation(HANDLE_1, integer_2);
}
void    ForcePlayerStartLocation(jHANDLE  HANDLE_1, int      integer_2)
{
    jForcePlayerStartLocation(HANDLE_1, integer_2);
}
void    SetPlayerAlliance(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, bool     BOOL_4)
{
    jSetPlayerAlliance(HANDLE_1, HANDLE_2, HANDLE_3, BOOL_4);
}
void    SetPlayerTaxRate(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, int      integer_4)
{
    jSetPlayerTaxRate(HANDLE_1, HANDLE_2, HANDLE_3, integer_4);
}
void    SetPlayerRacePreference(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jSetPlayerRacePreference(HANDLE_1, HANDLE_2);
}
void    SetPlayerRaceSelectable(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetPlayerRaceSelectable(HANDLE_1, BOOL_2);
}
void    SetPlayerController(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jSetPlayerController(HANDLE_1, HANDLE_2);
}
void    SetPlayerColor(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jSetPlayerColor(HANDLE_1, HANDLE_2);
}
void    SetPlayerOnScoreScreen(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetPlayerOnScoreScreen(HANDLE_1, BOOL_2);
}
void    SetPlayerName(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jSetPlayerName(HANDLE_1, RegStr(STRING_2));
}
int     GetPlayerTeam(jHANDLE  HANDLE_1)
{
    return jGetPlayerTeam(HANDLE_1);
}
const char* GetPlayerName(jHANDLE  HANDLE_1)
{
    return (const char*)GetStringAddress(jGetPlayerName(HANDLE_1));
}
int     GetPlayerStartLocation(jHANDLE  HANDLE_1)
{
    return jGetPlayerStartLocation(HANDLE_1);
}
float   GetPlayerStartLocationX(jHANDLE  HANDLE_1)
{
    int ret = (jGetPlayerStartLocationX(HANDLE_1));
    return *(float*)&ret;
}
float   GetPlayerStartLocationY(jHANDLE  HANDLE_1)
{
    int ret = (jGetPlayerStartLocationY(HANDLE_1));
    return *(float*)&ret;
}
jHANDLE GetPlayerColor(jHANDLE  HANDLE_1)
{
    return jGetPlayerColor(HANDLE_1);
}
bool    GetPlayerSelectable(jHANDLE  HANDLE_1)
{
    return jGetPlayerSelectable(HANDLE_1);
}
jHANDLE GetPlayerController(jHANDLE  HANDLE_1)
{
    return jGetPlayerController(HANDLE_1);
}
jHANDLE GetPlayerSlotState(jHANDLE  HANDLE_1)
{
    return jGetPlayerSlotState(HANDLE_1);
}
int     GetPlayerTaxRate(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    return jGetPlayerTaxRate(HANDLE_1, HANDLE_2, HANDLE_3);
}
bool    IsPlayerRacePrefSet(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsPlayerRacePrefSet(HANDLE_1, HANDLE_2);
}
jHANDLE Location(float   real_1, float   real_2)
{
    return jLocation(&real_1, &real_2);
}
void    RemoveLocation(jHANDLE  HANDLE_1)
{
    jRemoveLocation(HANDLE_1);
}
void    MoveLocation(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jMoveLocation(HANDLE_1, &real_2, &real_3);
}
float   GetLocationX(jHANDLE  HANDLE_1)
{
    int ret = (jGetLocationX(HANDLE_1));
    return *(float*)&ret;
}
float   GetLocationY(jHANDLE  HANDLE_1)
{
    int ret = (jGetLocationY(HANDLE_1));
    return *(float*)&ret;
}
float   GetLocationZ(jHANDLE  HANDLE_1)
{
    int ret = (jGetLocationZ(HANDLE_1));
    return *(float*)&ret;
}
jHANDLE CreateTimer()
{
    return jCreateTimer();
}
void    DestroyTimer(jHANDLE  HANDLE_1)
{
    jDestroyTimer(HANDLE_1);
}
void    TimerStart(jHANDLE  HANDLE_1, float   real_2, bool     BOOL_3, jCODE     jCODE_4)
{
    jTimerStart(HANDLE_1, &real_2, BOOL_3, jCODE_4);
}
float   TimerGetTimeout(jHANDLE  HANDLE_1)
{
    int ret = (jTimerGetTimeout(HANDLE_1));
    return *(float*)&ret;
}
float   TimerGetElapsed(jHANDLE  HANDLE_1)
{
    int ret = (jTimerGetElapsed(HANDLE_1));
    return *(float*)&ret;
}
float   TimerGetRemaining(jHANDLE  HANDLE_1)
{
    int ret = (jTimerGetRemaining(HANDLE_1));
    return *(float*)&ret;
}
void    PauseTimer(jHANDLE  HANDLE_1)
{
    jPauseTimer(HANDLE_1);
}
void    ResumeTimer(jHANDLE  HANDLE_1)
{
    jResumeTimer(HANDLE_1);
}
jHANDLE GetExpiredTimer()
{
    return jGetExpiredTimer();
}
jHANDLE Condition(jCODE     jCODE_1)
{
    return jCondition(jCODE_1);
}
void    DestroyCondition(jHANDLE  HANDLE_1)
{
    jDestroyCondition(HANDLE_1);
}
jHANDLE Filter(jCODE     jCODE_1)
{
    return jFilter(jCODE_1);
}
void    DestroyFilter(jHANDLE  HANDLE_1)
{
    jDestroyFilter(HANDLE_1);
}
void    DestroyBoolExpr(jHANDLE  HANDLE_1)
{
    jDestroyBoolExpr(HANDLE_1);
}
jHANDLE And(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jAnd(HANDLE_1, HANDLE_2);
}
jHANDLE Or(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jOr(HANDLE_1, HANDLE_2);
}
jHANDLE Not(jHANDLE  HANDLE_1)
{
    return jNot(HANDLE_1);
}
jHANDLE CreateRegion()
{
    return jCreateRegion();
}
void    RemoveRegion(jHANDLE  HANDLE_1)
{
    jRemoveRegion(HANDLE_1);
}
void    RegionAddRect(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jRegionAddRect(HANDLE_1, HANDLE_2);
}
void    RegionClearRect(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jRegionClearRect(HANDLE_1, HANDLE_2);
}
void    RegionAddCell(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jRegionAddCell(HANDLE_1, &real_2, &real_3);
}
void    RegionAddCellAtLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jRegionAddCellAtLoc(HANDLE_1, HANDLE_2);
}
void    RegionClearCell(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jRegionClearCell(HANDLE_1, &real_2, &real_3);
}
void    RegionClearCellAtLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jRegionClearCellAtLoc(HANDLE_1, HANDLE_2);
}
bool    IsUnitInRegion(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitInRegion(HANDLE_1, HANDLE_2);
}
bool    IsPointInRegion(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    return jIsPointInRegion(HANDLE_1, &real_2, &real_3);
}
bool    IsLocationInRegion(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsLocationInRegion(HANDLE_1, HANDLE_2);
}
jHANDLE Rect(float   real_1, float   real_2, float   real_3, float   real_4)
{
    return jRect(&real_1, &real_2, &real_3, &real_4);
}
jHANDLE RectFromLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jRectFromLoc(HANDLE_1, HANDLE_2);
}
void    RemoveRect(jHANDLE  HANDLE_1)
{
    jRemoveRect(HANDLE_1);
}
void    CSetRect(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4, float   real_5)
{
    jSetRect(HANDLE_1, &real_2, &real_3, &real_4, &real_5);
}
void    SetRectFromLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    jSetRectFromLoc(HANDLE_1, HANDLE_2, HANDLE_3);
}
float   GetRectCenterX(jHANDLE  HANDLE_1)
{
    int ret = (jGetRectCenterX(HANDLE_1));
    return *(float*)&ret;
}
float   GetRectCenterY(jHANDLE  HANDLE_1)
{
    int ret = (jGetRectCenterY(HANDLE_1));
    return *(float*)&ret;
}
void    MoveRectTo(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jMoveRectTo(HANDLE_1, &real_2, &real_3);
}
void    MoveRectToLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jMoveRectToLoc(HANDLE_1, HANDLE_2);
}
float   GetRectMinX(jHANDLE  HANDLE_1)
{
    int ret = (jGetRectMinX(HANDLE_1));
    return *(float*)&ret;
}
float   GetRectMinY(jHANDLE  HANDLE_1)
{
    int ret = (jGetRectMinY(HANDLE_1));
    return *(float*)&ret;
}
float   GetRectMaxX(jHANDLE  HANDLE_1)
{
    int ret = (jGetRectMaxX(HANDLE_1));
    return *(float*)&ret;
}
float   GetRectMaxY(jHANDLE  HANDLE_1)
{
    int ret = (jGetRectMaxY(HANDLE_1));
    return *(float*)&ret;
}
jHANDLE GetWorldBounds()
{
    return jGetWorldBounds();
}
void    SetFogStateRect(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, bool     BOOL_4)
{
    jSetFogStateRect(HANDLE_1, HANDLE_2, HANDLE_3, BOOL_4);
}
void    SetFogStateRadius(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3, float   real_4, float   real_5, bool     BOOL_6)
{
    jSetFogStateRadius(HANDLE_1, HANDLE_2, &real_3, &real_4, &real_5, BOOL_6);
}
void    SetFogStateRadiusLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, float   real_4, bool     BOOL_5)
{
    jSetFogStateRadiusLoc(HANDLE_1, HANDLE_2, HANDLE_3, &real_4, BOOL_5);
}
void    FogMaskEnable(bool     BOOL_1)
{
    jFogMaskEnable(BOOL_1);
}
bool    IsFogMaskEnabled()
{
    return jIsFogMaskEnabled();
}
void    FogEnable(bool     BOOL_1)
{
    jFogEnable(BOOL_1);
}
bool    IsFogEnabled()
{
    return jIsFogEnabled();
}
jHANDLE CreateFogModifierRect(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, bool     BOOL_4, bool     BOOL_5)
{
    return jCreateFogModifierRect(HANDLE_1, HANDLE_2, HANDLE_3, BOOL_4, BOOL_5);
}
jHANDLE CreateFogModifierRadius(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3, float   real_4, float   real_5, bool     BOOL_6, bool     BOOL_7)
{
    return jCreateFogModifierRadius(HANDLE_1, HANDLE_2, &real_3, &real_4, &real_5, BOOL_6, BOOL_7);
}
jHANDLE CreateFogModifierRadiusLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, float   real_4, bool     BOOL_5, bool     BOOL_6)
{
    return jCreateFogModifierRadiusLoc(HANDLE_1, HANDLE_2, HANDLE_3, &real_4, BOOL_5, BOOL_6);
}
void    DestroyFogModifier(jHANDLE  HANDLE_1)
{
    jDestroyFogModifier(HANDLE_1);
}
void    FogModifierStart(jHANDLE  HANDLE_1)
{
    jFogModifierStart(HANDLE_1);
}
void    FogModifierStop(jHANDLE  HANDLE_1)
{
    jFogModifierStop(HANDLE_1);
}
jHANDLE CreateTrigger()
{
    return jCreateTrigger();
}
void    DestroyTrigger(jHANDLE  HANDLE_1)
{
    jDestroyTrigger(HANDLE_1);
}
void    ResetTrigger(jHANDLE  HANDLE_1)
{
    jResetTrigger(HANDLE_1);
}
void    EnableTrigger(jHANDLE  HANDLE_1)
{
    jEnableTrigger(HANDLE_1);
}
void    DisableTrigger(jHANDLE  HANDLE_1)
{
    jDisableTrigger(HANDLE_1);
}
bool    IsTriggerEnabled(jHANDLE  HANDLE_1)
{
    return jIsTriggerEnabled(HANDLE_1);
}
void    TriggerWaitOnSleeps(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jTriggerWaitOnSleeps(HANDLE_1, BOOL_2);
}
bool    IsTriggerWaitOnSleeps(jHANDLE  HANDLE_1)
{
    return jIsTriggerWaitOnSleeps(HANDLE_1);
}
jHANDLE TriggerRegisterVariableEvent(jHANDLE  HANDLE_1, const char* STRING_2, jHANDLE  HANDLE_3, float   real_4)
{
    return jTriggerRegisterVariableEvent(HANDLE_1, RegStr(STRING_2), HANDLE_3, &real_4);
}
jHANDLE TriggerRegisterTimerEvent(jHANDLE  HANDLE_1, float   real_2, bool     BOOL_3)
{
    return jTriggerRegisterTimerEvent(HANDLE_1, &real_2, BOOL_3);
}
jHANDLE TriggerRegisterTimerExpireEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jTriggerRegisterTimerExpireEvent(HANDLE_1, HANDLE_2);
}
jHANDLE TriggerRegisterGameStateEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, float   real_4)
{
    return jTriggerRegisterGameStateEvent(HANDLE_1, HANDLE_2, HANDLE_3, &real_4);
}
jHANDLE GetEventGameState()
{
    return jGetEventGameState();
}
jHANDLE TriggerRegisterDialogEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jTriggerRegisterDialogEvent(HANDLE_1, HANDLE_2);
}
jHANDLE TriggerRegisterDialogButtonEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jTriggerRegisterDialogButtonEvent(HANDLE_1, HANDLE_2);
}
jHANDLE GetClickedButton()
{
    return jGetClickedButton();
}
jHANDLE GetClickedDialog()
{
    return jGetClickedDialog();
}
float   GetTournamentFinishSoonTimeRemaining()
{
    int ret = (jGetTournamentFinishSoonTimeRemaining());
    return *(float*)&ret;
}
int     GetTournamentFinishNowRule()
{
    return jGetTournamentFinishNowRule();
}
jHANDLE GetTournamentFinishNowPlayer()
{
    return jGetTournamentFinishNowPlayer();
}
int     GetTournamentScore(jHANDLE  HANDLE_1)
{
    return jGetTournamentScore(HANDLE_1);
}
const char* GetSaveBasicFilename()
{
    return (const char*)GetStringAddress(jGetSaveBasicFilename());
}
jHANDLE TriggerRegisterGameEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jTriggerRegisterGameEvent(HANDLE_1, HANDLE_2);
}
jHANDLE GetWinningPlayer()
{
    return jGetWinningPlayer();
}
jHANDLE TriggerRegisterPlayerStateEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, jHANDLE  HANDLE_4, float   real_5)
{
    return jTriggerRegisterPlayerStateEvent(HANDLE_1, HANDLE_2, HANDLE_3, HANDLE_4, &real_5);
}
jHANDLE GetEventPlayerState()
{
    return jGetEventPlayerState();
}
jHANDLE TriggerRegisterPlayerEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    return jTriggerRegisterPlayerEvent(HANDLE_1, HANDLE_2, HANDLE_3);
}
jHANDLE TriggerRegisterPlayerUnitEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, jHANDLE  HANDLE_4)
{
    return jTriggerRegisterPlayerUnitEvent(HANDLE_1, HANDLE_2, HANDLE_3, HANDLE_4);
}
jHANDLE GetAttacker()
{
    return jGetAttacker();
}
jHANDLE GetRescuer()
{
    return jGetRescuer();
}
jHANDLE GetDyingUnit()
{
    return jGetDyingUnit();
}
jHANDLE GetKillingUnit()
{
    return jGetKillingUnit();
}
jHANDLE GetDecayingUnit()
{
    return jGetDecayingUnit();
}
jHANDLE GetConstructingStructure()
{
    return jGetConstructingStructure();
}
jHANDLE GetCancelledStructure()
{
    return jGetCancelledStructure();
}
jHANDLE GetConstructedStructure()
{
    return jGetConstructedStructure();
}
int     GetTrainedUnitType()
{
    return jGetTrainedUnitType();
}
jHANDLE GetResearchingUnit()
{
    return jGetResearchingUnit();
}
int     GetResearched()
{
    return jGetResearched();
}
jHANDLE GetTrainedUnit()
{
    return jGetTrainedUnit();
}
jHANDLE GetSellingUnit()
{
    return jGetSellingUnit();
}
jHANDLE GetSoldUnit()
{
    return jGetSoldUnit();
}
jHANDLE GetBuyingUnit()
{
    return jGetBuyingUnit();
}
jHANDLE GetSoldItem()
{
    return jGetSoldItem();
}
jHANDLE GetChangingUnit()
{
    return jGetChangingUnit();
}
jHANDLE GetChangingUnitPrevOwner()
{
    return jGetChangingUnitPrevOwner();
}
jHANDLE GetDetectedUnit()
{
    return jGetDetectedUnit();
}
jHANDLE GetOrderedUnit()
{
    return jGetOrderedUnit();
}
int     OrderId(const char* STRING_1)
{
    return jOrderId(RegStr(STRING_1));
}
const char* OrderId2String(int      integer_1)
{
    return (const char*)GetStringAddress(jOrderId2String(integer_1));
}
int     AbilityId(const char* STRING_1)
{
    return jAbilityId(RegStr(STRING_1));
}
const char* AbilityId2String(int      integer_1)
{
    return (const char*)GetStringAddress(jAbilityId2String(integer_1));
}
int     UnitId(const char* STRING_1)
{
    return jUnitId(RegStr(STRING_1));
}
const char* UnitId2String(int      integer_1)
{
    return (const char*)GetStringAddress(jUnitId2String(integer_1));
}
const char* GetObjectName(int      integer_1)
{
    return (const char*)GetStringAddress(jGetObjectName(integer_1));
}
int     GetIssuedOrderId()
{
    return jGetIssuedOrderId();
}
float   GetOrderPointX()
{
    int ret = (jGetOrderPointX());
    return *(float*)&ret;
}
float   GetOrderPointY()
{
    int ret = (jGetOrderPointY());
    return *(float*)&ret;
}
jHANDLE GetOrderPointLoc()
{
    return jGetOrderPointLoc();
}
jHANDLE GetOrderTarget()
{
    return jGetOrderTarget();
}
jHANDLE GetOrderTargetDestructable()
{
    return jGetOrderTargetDestructable();
}
jHANDLE GetOrderTargetItem()
{
    return jGetOrderTargetItem();
}
jHANDLE GetOrderTargetUnit()
{
    return jGetOrderTargetUnit();
}
jHANDLE GetSpellAbilityUnit()
{
    return jGetSpellAbilityUnit();
}
int     GetSpellAbilityId()
{
    return jGetSpellAbilityId();
}
jHANDLE GetSpellAbility()
{
    return jGetSpellAbility();
}
jHANDLE GetSpellTargetLoc()
{
    return jGetSpellTargetLoc();
}
float   GetSpellTargetX()
{
    int ret = (jGetSpellTargetX());
    return *(float*)&ret;
}
float   GetSpellTargetY()
{
    int ret = (jGetSpellTargetY());
    return *(float*)&ret;
}
jHANDLE GetSpellTargetDestructable()
{
    return jGetSpellTargetDestructable();
}
jHANDLE GetSpellTargetItem()
{
    return jGetSpellTargetItem();
}
jHANDLE GetSpellTargetUnit()
{
    return jGetSpellTargetUnit();
}
jHANDLE GetLevelingUnit()
{
    return jGetLevelingUnit();
}
jHANDLE GetLearningUnit()
{
    return jGetLearningUnit();
}
int     GetLearnedSkill()
{
    return jGetLearnedSkill();
}
int     GetLearnedSkillLevel()
{
    return jGetLearnedSkillLevel();
}
jHANDLE GetRevivableUnit()
{
    return jGetRevivableUnit();
}
jHANDLE GetRevivingUnit()
{
    return jGetRevivingUnit();
}
jHANDLE GetSummoningUnit()
{
    return jGetSummoningUnit();
}
jHANDLE GetSummonedUnit()
{
    return jGetSummonedUnit();
}
jHANDLE GetTransportUnit()
{
    return jGetTransportUnit();
}
jHANDLE GetLoadedUnit()
{
    return jGetLoadedUnit();
}
jHANDLE GetManipulatingUnit()
{
    return jGetManipulatingUnit();
}
jHANDLE GetManipulatedItem()
{
    return jGetManipulatedItem();
}
jHANDLE TriggerRegisterPlayerAllianceChange(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    return jTriggerRegisterPlayerAllianceChange(HANDLE_1, HANDLE_2, HANDLE_3);
}
jHANDLE TriggerRegisterPlayerChatEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, const char* STRING_3, bool     BOOL_4)
{
    return jTriggerRegisterPlayerChatEvent(HANDLE_1, HANDLE_2, RegStr(STRING_3), BOOL_4);
}
const char* GetEventPlayerChatString()
{
    return (const char*)GetStringAddress(jGetEventPlayerChatString());
}
const char* GetEventPlayerChatStringMatched()
{
    return (const char*)GetStringAddress(jGetEventPlayerChatStringMatched());
}
jHANDLE TriggerRegisterUnitStateEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, jHANDLE  HANDLE_4, float   real_5)
{
    return jTriggerRegisterUnitStateEvent(HANDLE_1, HANDLE_2, HANDLE_3, HANDLE_4, &real_5);
}
jHANDLE GetEventUnitState()
{
    return jGetEventUnitState();
}
jHANDLE TriggerRegisterDeathEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jTriggerRegisterDeathEvent(HANDLE_1, HANDLE_2);
}
jHANDLE TriggerRegisterUnitEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    return jTriggerRegisterUnitEvent(HANDLE_1, HANDLE_2, HANDLE_3);
}
float   GetEventDamage()
{
    int ret = (jGetEventDamage());
    return *(float*)&ret;
}
jHANDLE GetEventDamageSource()
{
    return jGetEventDamageSource();
}
jHANDLE GetEventDetectingPlayer()
{
    return jGetEventDetectingPlayer();
}
jHANDLE GetEventTargetUnit()
{
    return jGetEventTargetUnit();
}
jHANDLE TriggerRegisterFilterUnitEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, jHANDLE  HANDLE_4)
{
    return jTriggerRegisterFilterUnitEvent(HANDLE_1, HANDLE_2, HANDLE_3, HANDLE_4);
}
jHANDLE TriggerRegisterUnitInRange(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3, jHANDLE  HANDLE_4)
{
    return jTriggerRegisterUnitInRange(HANDLE_1, HANDLE_2, &real_3, HANDLE_4);
}
jHANDLE TriggerRegisterEnterRegion(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    return jTriggerRegisterEnterRegion(HANDLE_1, HANDLE_2, HANDLE_3);
}
jHANDLE TriggerRegisterLeaveRegion(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    return jTriggerRegisterLeaveRegion(HANDLE_1, HANDLE_2, HANDLE_3);
}
jHANDLE GetTriggeringRegion()
{
    return jGetTriggeringRegion();
}
jHANDLE GetEnteringUnit()
{
    return jGetEnteringUnit();
}
jHANDLE GetLeavingUnit()
{
    return jGetLeavingUnit();
}
jHANDLE TriggerAddCondition(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jTriggerAddCondition(HANDLE_1, HANDLE_2);
}
void    TriggerRemoveCondition(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jTriggerRemoveCondition(HANDLE_1, HANDLE_2);
}
void    TriggerClearConditions(jHANDLE  HANDLE_1)
{
    jTriggerClearConditions(HANDLE_1);
}
jHANDLE TriggerAddAction(jHANDLE  HANDLE_1, jCODE     jCODE_2)
{
    return jTriggerAddAction(HANDLE_1, jCODE_2);
}
void    TriggerRemoveAction(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jTriggerRemoveAction(HANDLE_1, HANDLE_2);
}
void    TriggerClearActions(jHANDLE  HANDLE_1)
{
    jTriggerClearActions(HANDLE_1);
}
void    TriggerSleepAction(float   real_1)
{
    jTriggerSleepAction(&real_1);
}
void    TriggerWaitForSound(jHANDLE  HANDLE_1, float   real_2)
{
    jTriggerWaitForSound(HANDLE_1, &real_2);
}
void    TriggerExecute(jHANDLE  HANDLE_1)
{
    jTriggerExecute(HANDLE_1);
}
void    TriggerExecuteWait(jHANDLE  HANDLE_1)
{
    jTriggerExecuteWait(HANDLE_1);
}
bool    TriggerEvaluate(jHANDLE  HANDLE_1)
{
    return jTriggerEvaluate(HANDLE_1);
}
void    TriggerSyncStart()
{
    jTriggerSyncStart();
}
void    TriggerSyncReady()
{
    jTriggerSyncReady();
}
jHANDLE GetTriggerWidget()
{
    return jGetTriggerWidget();
}
jHANDLE GetTriggerDestructable()
{
    return jGetTriggerDestructable();
}
jHANDLE GetTriggerUnit()
{
    return jGetTriggerUnit();
}
jHANDLE GetTriggerPlayer()
{
    return jGetTriggerPlayer();
}
jHANDLE GetTriggeringTrigger()
{
    return jGetTriggeringTrigger();
}
jHANDLE GetTriggerEventId()
{
    return jGetTriggerEventId();
}
int     GetTriggerEvalCount(jHANDLE  HANDLE_1)
{
    return jGetTriggerEvalCount(HANDLE_1);
}
int     GetTriggerExecCount(jHANDLE  HANDLE_1)
{
    return jGetTriggerExecCount(HANDLE_1);
}
jHANDLE GetFilterUnit()
{
    return jGetFilterUnit();
}
jHANDLE GetEnumUnit()
{
    return jGetEnumUnit();
}
jHANDLE GetEnumPlayer()
{
    return jGetEnumPlayer();
}
jHANDLE GetFilterPlayer()
{
    return jGetFilterPlayer();
}
jHANDLE GetFilterDestructable()
{
    return jGetFilterDestructable();
}
jHANDLE GetEnumDestructable()
{
    return jGetEnumDestructable();
}
jHANDLE GetFilterItem()
{
    return jGetFilterItem();
}
jHANDLE GetEnumItem()
{
    return jGetEnumItem();
}
jHANDLE CreateGroup()
{
    return jCreateGroup();
}
void    DestroyGroup(jHANDLE  HANDLE_1)
{
    jDestroyGroup(HANDLE_1);
}
void    GroupAddUnit(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jGroupAddUnit(HANDLE_1, HANDLE_2);
}
void    GroupRemoveUnit(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jGroupRemoveUnit(HANDLE_1, HANDLE_2);
}
void    GroupClear(jHANDLE  HANDLE_1)
{
    jGroupClear(HANDLE_1);
}
void    GroupEnumUnitsOfType(jHANDLE  HANDLE_1, const char* STRING_2, jHANDLE  HANDLE_3)
{
    jGroupEnumUnitsOfType(HANDLE_1, RegStr(STRING_2), HANDLE_3);
}
void    GroupEnumUnitsOfTypeCounted(jHANDLE  HANDLE_1, const char* STRING_2, jHANDLE  HANDLE_3, int      integer_4)
{
    jGroupEnumUnitsOfTypeCounted(HANDLE_1, RegStr(STRING_2), HANDLE_3, integer_4);
}
void    GroupEnumUnitsInRect(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    jGroupEnumUnitsInRect(HANDLE_1, HANDLE_2, HANDLE_3);
}
void    GroupEnumUnitsInRectCounted(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, int      integer_4)
{
    jGroupEnumUnitsInRectCounted(HANDLE_1, HANDLE_2, HANDLE_3, integer_4);
}
void    GroupEnumUnitsOfPlayer(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    jGroupEnumUnitsOfPlayer(HANDLE_1, HANDLE_2, HANDLE_3);
}
void    GroupEnumUnitsInRange(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4, jHANDLE  HANDLE_5)
{
    jGroupEnumUnitsInRange(HANDLE_1, &real_2, &real_3, &real_4, HANDLE_5);
}
void    GroupEnumUnitsInRangeOfLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3, jHANDLE  HANDLE_4)
{
    jGroupEnumUnitsInRangeOfLoc(HANDLE_1, HANDLE_2, &real_3, HANDLE_4);
}
void    GroupEnumUnitsInRangeCounted(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4, jHANDLE  HANDLE_5, int      integer_6)
{
    jGroupEnumUnitsInRangeCounted(HANDLE_1, &real_2, &real_3, &real_4, HANDLE_5, integer_6);
}
void    GroupEnumUnitsInRangeOfLocCounted(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3, jHANDLE  HANDLE_4, int      integer_5)
{
    jGroupEnumUnitsInRangeOfLocCounted(HANDLE_1, HANDLE_2, &real_3, HANDLE_4, integer_5);
}
void    GroupEnumUnitsSelected(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    jGroupEnumUnitsSelected(HANDLE_1, HANDLE_2, HANDLE_3);
}
bool    GroupImmediateOrder(jHANDLE  HANDLE_1, const char* STRING_2)
{
    return jGroupImmediateOrder(HANDLE_1, RegStr(STRING_2));
}
bool    GroupImmediateOrderById(jHANDLE  HANDLE_1, int      integer_2)
{
    return jGroupImmediateOrderById(HANDLE_1, integer_2);
}
bool    GroupPointOrder(jHANDLE  HANDLE_1, const char* STRING_2, float   real_3, float   real_4)
{
    return jGroupPointOrder(HANDLE_1, RegStr(STRING_2), &real_3, &real_4);
}
bool    GroupPointOrderLoc(jHANDLE  HANDLE_1, const char* STRING_2, jHANDLE  HANDLE_3)
{
    return jGroupPointOrderLoc(HANDLE_1, RegStr(STRING_2), HANDLE_3);
}
bool    GroupPointOrderById(jHANDLE  HANDLE_1, int      integer_2, float   real_3, float   real_4)
{
    return jGroupPointOrderById(HANDLE_1, integer_2, &real_3, &real_4);
}
bool    GroupPointOrderByIdLoc(jHANDLE  HANDLE_1, int      integer_2, jHANDLE  HANDLE_3)
{
    return jGroupPointOrderByIdLoc(HANDLE_1, integer_2, HANDLE_3);
}
bool    GroupTargetOrder(jHANDLE  HANDLE_1, const char* STRING_2, jHANDLE  HANDLE_3)
{
    return jGroupTargetOrder(HANDLE_1, RegStr(STRING_2), HANDLE_3);
}
bool    GroupTargetOrderById(jHANDLE  HANDLE_1, int      integer_2, jHANDLE  HANDLE_3)
{
    return jGroupTargetOrderById(HANDLE_1, integer_2, HANDLE_3);
}
void    ForGroup(jHANDLE  HANDLE_1, jCODE     jCODE_2)
{
    jForGroup(HANDLE_1, jCODE_2);
}
jHANDLE FirstOfGroup(jHANDLE  HANDLE_1)
{
    return jFirstOfGroup(HANDLE_1);
}
jHANDLE CreateForce()
{
    return jCreateForce();
}
void    DestroyForce(jHANDLE  HANDLE_1)
{
    jDestroyForce(HANDLE_1);
}
void    ForceAddPlayer(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jForceAddPlayer(HANDLE_1, HANDLE_2);
}
void    ForceRemovePlayer(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jForceRemovePlayer(HANDLE_1, HANDLE_2);
}
void    ForceClear(jHANDLE  HANDLE_1)
{
    jForceClear(HANDLE_1);
}
void    ForceEnumPlayers(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jForceEnumPlayers(HANDLE_1, HANDLE_2);
}
void    ForceEnumPlayersCounted(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, int      integer_3)
{
    jForceEnumPlayersCounted(HANDLE_1, HANDLE_2, integer_3);
}
void    ForceEnumAllies(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    jForceEnumAllies(HANDLE_1, HANDLE_2, HANDLE_3);
}
void    ForceEnumEnemies(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    jForceEnumEnemies(HANDLE_1, HANDLE_2, HANDLE_3);
}
void    ForForce(jHANDLE  HANDLE_1, jCODE     jCODE_2)
{
    jForForce(HANDLE_1, jCODE_2);
}
float   GetWidgetLife(jHANDLE  HANDLE_1)
{
    int ret = (jGetWidgetLife(HANDLE_1));
    return *(float*)&ret;
}
void    SetWidgetLife(jHANDLE  HANDLE_1, float   real_2)
{
    jSetWidgetLife(HANDLE_1, &real_2);
}
float   GetWidgetX(jHANDLE  HANDLE_1)
{
    int ret = (jGetWidgetX(HANDLE_1));
    return *(float*)&ret;
}
float   GetWidgetY(jHANDLE  HANDLE_1)
{
    int ret = (jGetWidgetY(HANDLE_1));
    return *(float*)&ret;
}
jHANDLE CreateDestructable(int      integer_1, float   real_2, float   real_3, float   real_4, float   real_5, int      integer_6)
{
    return jCreateDestructable(integer_1, &real_2, &real_3, &real_4, &real_5, integer_6);
}
jHANDLE CreateDestructableZ(int      integer_1, float   real_2, float   real_3, float   real_4, float   real_5, float   real_6, int      integer_7)
{
    return jCreateDestructableZ(integer_1, &real_2, &real_3, &real_4, &real_5, &real_6, integer_7);
}
jHANDLE CreateDeadDestructable(int      integer_1, float   real_2, float   real_3, float   real_4, float   real_5, int      integer_6)
{
    return jCreateDeadDestructable(integer_1, &real_2, &real_3, &real_4, &real_5, integer_6);
}
jHANDLE CreateDeadDestructableZ(int      integer_1, float   real_2, float   real_3, float   real_4, float   real_5, float   real_6, int      integer_7)
{
    return jCreateDeadDestructableZ(integer_1, &real_2, &real_3, &real_4, &real_5, &real_6, integer_7);
}
void    RemoveDestructable(jHANDLE  HANDLE_1)
{
    jRemoveDestructable(HANDLE_1);
}
void    KillDestructable(jHANDLE  HANDLE_1)
{
    jKillDestructable(HANDLE_1);
}
void    SetDestructableInvulnerable(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetDestructableInvulnerable(HANDLE_1, BOOL_2);
}
bool    IsDestructableInvulnerable(jHANDLE  HANDLE_1)
{
    return jIsDestructableInvulnerable(HANDLE_1);
}
void    EnumDestructablesInRect(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jCODE     jCODE_3)
{
    jEnumDestructablesInRect(HANDLE_1, HANDLE_2, jCODE_3);
}
int     GetDestructableTypeId(jHANDLE  HANDLE_1)
{
    return jGetDestructableTypeId(HANDLE_1);
}
float   GetDestructableX(jHANDLE  HANDLE_1)
{
    int ret = (jGetDestructableX(HANDLE_1));
    return *(float*)&ret;
}
float   GetDestructableY(jHANDLE  HANDLE_1)
{
    int ret = (jGetDestructableY(HANDLE_1));
    return *(float*)&ret;
}
void    SetDestructableLife(jHANDLE  HANDLE_1, float   real_2)
{
    jSetDestructableLife(HANDLE_1, &real_2);
}
float   GetDestructableLife(jHANDLE  HANDLE_1)
{
    int ret = (jGetDestructableLife(HANDLE_1));
    return *(float*)&ret;
}
void    SetDestructableMaxLife(jHANDLE  HANDLE_1, float   real_2)
{
    jSetDestructableMaxLife(HANDLE_1, &real_2);
}
float   GetDestructableMaxLife(jHANDLE  HANDLE_1)
{
    int ret = (jGetDestructableMaxLife(HANDLE_1));
    return *(float*)&ret;
}
void    DestructableRestoreLife(jHANDLE  HANDLE_1, float   real_2, bool     BOOL_3)
{
    jDestructableRestoreLife(HANDLE_1, &real_2, BOOL_3);
}
void    QueueDestructableAnimation(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jQueueDestructableAnimation(HANDLE_1, RegStr(STRING_2));
}
void    SetDestructableAnimation(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jSetDestructableAnimation(HANDLE_1, RegStr(STRING_2));
}
void    SetDestructableAnimationSpeed(jHANDLE  HANDLE_1, float   real_2)
{
    jSetDestructableAnimationSpeed(HANDLE_1, &real_2);
}
void    ShowDestructable(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jShowDestructable(HANDLE_1, BOOL_2);
}
float   GetDestructableOccluderHeight(jHANDLE  HANDLE_1)
{
    int ret = (jGetDestructableOccluderHeight(HANDLE_1));
    return *(float*)&ret;
}
void    SetDestructableOccluderHeight(jHANDLE  HANDLE_1, float   real_2)
{
    jSetDestructableOccluderHeight(HANDLE_1, &real_2);
}
const char* GetDestructableName(jHANDLE  HANDLE_1)
{
    return (const char*)GetStringAddress(jGetDestructableName(HANDLE_1));
}
jHANDLE CreateUnit(jHANDLE  HANDLE_1, int      integer_2, float   real_3, float   real_4, float   real_5)
{
    return jCreateUnit(HANDLE_1, integer_2, &real_3, &real_4, &real_5);
}
jHANDLE CreateUnitByName(jHANDLE  HANDLE_1, const char* STRING_2, float   real_3, float   real_4, float   real_5)
{
    return jCreateUnitByName(HANDLE_1, RegStr(STRING_2), &real_3, &real_4, &real_5);
}
jHANDLE CreateUnitAtLoc(jHANDLE  HANDLE_1, int      integer_2, jHANDLE  HANDLE_3, float   real_4)
{
    return jCreateUnitAtLoc(HANDLE_1, integer_2, HANDLE_3, &real_4);
}
jHANDLE CreateUnitAtLocByName(jHANDLE  HANDLE_1, const char* STRING_2, jHANDLE  HANDLE_3, float   real_4)
{
    return jCreateUnitAtLocByName(HANDLE_1, RegStr(STRING_2), HANDLE_3, &real_4);
}
jHANDLE CreateCorpse(jHANDLE  HANDLE_1, int      integer_2, float   real_3, float   real_4, float   real_5)
{
    return jCreateCorpse(HANDLE_1, integer_2, &real_3, &real_4, &real_5);
}
float   GetUnitState(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    int ret = (jGetUnitState(HANDLE_1, HANDLE_2));
    return *(float*)&ret;
}
int     GetUnitFoodUsed(jHANDLE  HANDLE_1)
{
    return jGetUnitFoodUsed(HANDLE_1);
}
int     GetUnitFoodMade(jHANDLE  HANDLE_1)
{
    return jGetUnitFoodMade(HANDLE_1);
}
int     GetFoodMade(int      integer_1)
{
    return jGetFoodMade(integer_1);
}
int     GetFoodUsed(int      integer_1)
{
    return jGetFoodUsed(integer_1);
}
void    SetUnitUseFood(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetUnitUseFood(HANDLE_1, BOOL_2);
}
float   GetUnitX(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitX(HANDLE_1));
    return *(float*)&ret;
}
float   GetUnitY(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitY(HANDLE_1));
    return *(float*)&ret;
}
jHANDLE GetUnitLoc(jHANDLE  HANDLE_1)
{
    return jGetUnitLoc(HANDLE_1);
}
jHANDLE GetUnitRallyPoint(jHANDLE  HANDLE_1)
{
    return jGetUnitRallyPoint(HANDLE_1);
}
jHANDLE GetUnitRallyUnit(jHANDLE  HANDLE_1)
{
    return jGetUnitRallyUnit(HANDLE_1);
}
jHANDLE GetUnitRallyDestructable(jHANDLE  HANDLE_1)
{
    return jGetUnitRallyDestructable(HANDLE_1);
}
float   GetUnitFacing(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitFacing(HANDLE_1));
    return *(float*)&ret;
}
float   GetUnitMoveSpeed(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitMoveSpeed(HANDLE_1));
    return *(float*)&ret;
}
float   GetUnitDefaultMoveSpeed(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitDefaultMoveSpeed(HANDLE_1));
    return *(float*)&ret;
}
int     GetUnitTypeId(jHANDLE  HANDLE_1)
{
    return jGetUnitTypeId(HANDLE_1);
}
jHANDLE GetUnitRace(jHANDLE  HANDLE_1)
{
    return jGetUnitRace(HANDLE_1);
}
const char* GetUnitName(jHANDLE  HANDLE_1)
{
    return (const char*)GetStringAddress(jGetUnitName(HANDLE_1));
}
int     GetUnitPointValue(jHANDLE  HANDLE_1)
{
    return jGetUnitPointValue(HANDLE_1);
}
int     GetUnitPointValueByType(int      integer_1)
{
    return jGetUnitPointValueByType(integer_1);
}
void    SetUnitX(jHANDLE  HANDLE_1, float   real_2)
{
    jSetUnitX(HANDLE_1, &real_2);
}
void    SetUnitY(jHANDLE  HANDLE_1, float   real_2)
{
    jSetUnitY(HANDLE_1, &real_2);
}
void    SetUnitPosition(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jSetUnitPosition(HANDLE_1, &real_2, &real_3);
}
void    SetUnitPositionLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jSetUnitPositionLoc(HANDLE_1, HANDLE_2);
}
void    SetUnitFacing(jHANDLE  HANDLE_1, float   real_2)
{
    jSetUnitFacing(HANDLE_1, &real_2);
}
void    SetUnitFacingTimed(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jSetUnitFacingTimed(HANDLE_1, &real_2, &real_3);
}
void    SetUnitFlyHeight(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jSetUnitFlyHeight(HANDLE_1, &real_2, &real_3);
}
void    SetUnitMoveSpeed(jHANDLE  HANDLE_1, float   real_2)
{
    jSetUnitMoveSpeed(HANDLE_1, &real_2);
}
void    SetUnitTurnSpeed(jHANDLE  HANDLE_1, float   real_2)
{
    jSetUnitTurnSpeed(HANDLE_1, &real_2);
}
void    SetUnitPropWindow(jHANDLE  HANDLE_1, float   real_2)
{
    jSetUnitPropWindow(HANDLE_1, &real_2);
}
void    SetUnitCreepGuard(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetUnitCreepGuard(HANDLE_1, BOOL_2);
}
float   GetUnitAcquireRange(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitAcquireRange(HANDLE_1));
    return *(float*)&ret;
}
float   GetUnitTurnSpeed(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitTurnSpeed(HANDLE_1));
    return *(float*)&ret;
}
float   GetUnitPropWindow(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitPropWindow(HANDLE_1));
    return *(float*)&ret;
}
float   GetUnitFlyHeight(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitFlyHeight(HANDLE_1));
    return *(float*)&ret;
}
float   GetUnitDefaultAcquireRange(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitDefaultAcquireRange(HANDLE_1));
    return *(float*)&ret;
}
float   GetUnitDefaultTurnSpeed(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitDefaultTurnSpeed(HANDLE_1));
    return *(float*)&ret;
}
float   GetUnitDefaultPropWindow(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitDefaultPropWindow(HANDLE_1));
    return *(float*)&ret;
}
float   GetUnitDefaultFlyHeight(jHANDLE  HANDLE_1)
{
    int ret = (jGetUnitDefaultFlyHeight(HANDLE_1));
    return *(float*)&ret;
}
void    SetUnitAcquireRange(jHANDLE  HANDLE_1, float   real_2)
{
    jSetUnitAcquireRange(HANDLE_1, &real_2);
}
void    SetUnitState(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3)
{
    jSetUnitState(HANDLE_1, HANDLE_2, &real_3);
}
void    SetUnitOwner(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, bool     BOOL_3)
{
    jSetUnitOwner(HANDLE_1, HANDLE_2, BOOL_3);
}
void    SetUnitRescuable(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, bool     BOOL_3)
{
    jSetUnitRescuable(HANDLE_1, HANDLE_2, BOOL_3);
}
void    SetUnitRescueRange(jHANDLE  HANDLE_1, float   real_2)
{
    jSetUnitRescueRange(HANDLE_1, &real_2);
}
void    SetUnitColor(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jSetUnitColor(HANDLE_1, HANDLE_2);
}
void    QueueUnitAnimation(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jQueueUnitAnimation(HANDLE_1, RegStr(STRING_2));
}
void    SetUnitAnimation(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jSetUnitAnimation(HANDLE_1, RegStr(STRING_2));
}
void    SetUnitAnimationWithRarity(jHANDLE  HANDLE_1, const char* STRING_2, jHANDLE  HANDLE_3)
{
    jSetUnitAnimationWithRarity(HANDLE_1, RegStr(STRING_2), HANDLE_3);
}
void    SetUnitAnimationByIndex(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetUnitAnimationByIndex(HANDLE_1, integer_2);
}
void    AddUnitAnimationProperties(jHANDLE  HANDLE_1, const char* STRING_2, bool     BOOL_3)
{
    jAddUnitAnimationProperties(HANDLE_1, RegStr(STRING_2), BOOL_3);
}
void    SetUnitScale(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4)
{
    jSetUnitScale(HANDLE_1, &real_2, &real_3, &real_4);
}
void    SetUnitTimeScale(jHANDLE  HANDLE_1, float   real_2)
{
    jSetUnitTimeScale(HANDLE_1, &real_2);
}
void    SetUnitBlendTime(jHANDLE  HANDLE_1, float   real_2)
{
    jSetUnitBlendTime(HANDLE_1, &real_2);
}
void    SetUnitVertexColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jSetUnitVertexColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
void    SetUnitLookAt(jHANDLE  HANDLE_1, const char* STRING_2, jHANDLE  HANDLE_3, float   real_4, float   real_5, float   real_6)
{
    jSetUnitLookAt(HANDLE_1, RegStr(STRING_2), HANDLE_3, &real_4, &real_5, &real_6);
}
void    SetUnitPathing(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetUnitPathing(HANDLE_1, BOOL_2);
}
void    ResetUnitLookAt(jHANDLE  HANDLE_1)
{
    jResetUnitLookAt(HANDLE_1);
}
void    SetHeroStr(jHANDLE  HANDLE_1, int      integer_2, bool     BOOL_3)
{
    jSetHeroStr(HANDLE_1, integer_2, BOOL_3);
}
void    SetHeroAgi(jHANDLE  HANDLE_1, int      integer_2, bool     BOOL_3)
{
    jSetHeroAgi(HANDLE_1, integer_2, BOOL_3);
}
void    SetHeroInt(jHANDLE  HANDLE_1, int      integer_2, bool     BOOL_3)
{
    jSetHeroInt(HANDLE_1, integer_2, BOOL_3);
}
int     GetHeroStr(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    return jGetHeroStr(HANDLE_1, BOOL_2);
}
int     GetHeroAgi(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    return jGetHeroAgi(HANDLE_1, BOOL_2);
}
int     GetHeroInt(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    return jGetHeroInt(HANDLE_1, BOOL_2);
}
int     GetHeroSkillPoints(jHANDLE  HANDLE_1)
{
    return jGetHeroSkillPoints(HANDLE_1);
}
bool    UnitStripHeroLevel(jHANDLE  HANDLE_1, int      integer_2)
{
    return jUnitStripHeroLevel(HANDLE_1, integer_2);
}
bool    UnitModifySkillPoints(jHANDLE  HANDLE_1, int      integer_2)
{
    return jUnitModifySkillPoints(HANDLE_1, integer_2);
}
int     GetHeroXP(jHANDLE  HANDLE_1)
{
    return jGetHeroXP(HANDLE_1);
}
void    SetHeroXP(jHANDLE  HANDLE_1, int      integer_2, bool     BOOL_3)
{
    jSetHeroXP(HANDLE_1, integer_2, BOOL_3);
}
void    AddHeroXP(jHANDLE  HANDLE_1, int      integer_2, bool     BOOL_3)
{
    jAddHeroXP(HANDLE_1, integer_2, BOOL_3);
}
void    SetHeroLevel(jHANDLE  HANDLE_1, int      integer_2, bool     BOOL_3)
{
    jSetHeroLevel(HANDLE_1, integer_2, BOOL_3);
}
int     GetHeroLevel(jHANDLE  HANDLE_1)
{
    return jGetHeroLevel(HANDLE_1);
}
int     GetUnitLevel(jHANDLE  HANDLE_1)
{
    return jGetUnitLevel(HANDLE_1);
}
const char* GetHeroProperName(jHANDLE  HANDLE_1)
{
    return (const char*)GetStringAddress(jGetHeroProperName(HANDLE_1));
}
void    SuspendHeroXP(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSuspendHeroXP(HANDLE_1, BOOL_2);
}
bool    IsSuspendedXP(jHANDLE  HANDLE_1)
{
    return jIsSuspendedXP(HANDLE_1);
}
void    SelectHeroSkill(jHANDLE  HANDLE_1, int      integer_2)
{
    jSelectHeroSkill(HANDLE_1, integer_2);
}
int     GetUnitAbilityLevel(jHANDLE  HANDLE_1, int      integer_2)
{
    return jGetUnitAbilityLevel(HANDLE_1, integer_2);
}
bool    ReviveHero(jHANDLE  HANDLE_1, float   real_2, float   real_3, bool     BOOL_4)
{
    return jReviveHero(HANDLE_1, &real_2, &real_3, BOOL_4);
}
bool    ReviveHeroLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, bool     BOOL_3)
{
    return jReviveHeroLoc(HANDLE_1, HANDLE_2, BOOL_3);
}
void    SetUnitExploded(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetUnitExploded(HANDLE_1, BOOL_2);
}
void    SetUnitInvulnerable(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetUnitInvulnerable(HANDLE_1, BOOL_2);
}
void    PauseUnit(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jPauseUnit(HANDLE_1, BOOL_2);
}
bool    IsUnitPaused(jHANDLE  HANDLE_1)
{
    return jIsUnitPaused(HANDLE_1);
}
bool    UnitAddItem(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jUnitAddItem(HANDLE_1, HANDLE_2);
}
jHANDLE UnitAddItemById(jHANDLE  HANDLE_1, int      integer_2)
{
    return jUnitAddItemById(HANDLE_1, integer_2);
}
bool    UnitAddItemToSlotById(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jUnitAddItemToSlotById(HANDLE_1, integer_2, integer_3);
}
void    UnitRemoveItem(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jUnitRemoveItem(HANDLE_1, HANDLE_2);
}
jHANDLE UnitRemoveItemFromSlot(jHANDLE  HANDLE_1, int      integer_2)
{
    return jUnitRemoveItemFromSlot(HANDLE_1, integer_2);
}
bool    UnitHasItem(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jUnitHasItem(HANDLE_1, HANDLE_2);
}
jHANDLE UnitItemInSlot(jHANDLE  HANDLE_1, int      integer_2)
{
    return jUnitItemInSlot(HANDLE_1, integer_2);
}
int     UnitInventorySize(jHANDLE  HANDLE_1)
{
    return jUnitInventorySize(HANDLE_1);
}
bool    UnitDropItemPoint(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3, float   real_4)
{
    return jUnitDropItemPoint(HANDLE_1, HANDLE_2, &real_3, &real_4);
}
bool    UnitDropItemSlot(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, int      integer_3)
{
    return jUnitDropItemSlot(HANDLE_1, HANDLE_2, integer_3);
}
bool    UnitDropItemTarget(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    return jUnitDropItemTarget(HANDLE_1, HANDLE_2, HANDLE_3);
}
bool    UnitUseItem(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jUnitUseItem(HANDLE_1, HANDLE_2);
}
bool    UnitUseItemPoint(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3, float   real_4)
{
    return jUnitUseItemPoint(HANDLE_1, HANDLE_2, &real_3, &real_4);
}
bool    UnitUseItemTarget(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    return jUnitUseItemTarget(HANDLE_1, HANDLE_2, HANDLE_3);
}
int     GetUnitCurrentOrder(jHANDLE  HANDLE_1)
{
    return jGetUnitCurrentOrder(HANDLE_1);
}
void    SetResourceAmount(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetResourceAmount(HANDLE_1, integer_2);
}
void    AddResourceAmount(jHANDLE  HANDLE_1, int      integer_2)
{
    jAddResourceAmount(HANDLE_1, integer_2);
}
int     GetResourceAmount(jHANDLE  HANDLE_1)
{
    return jGetResourceAmount(HANDLE_1);
}
void    SelectUnit(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSelectUnit(HANDLE_1, BOOL_2);
}
void    ClearSelection()
{
    jClearSelection();
}
void    UnitAddIndicator(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jUnitAddIndicator(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
void    AddIndicator(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jAddIndicator(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
void    KillUnit(jHANDLE  HANDLE_1)
{
    jKillUnit(HANDLE_1);
}
void    RemoveUnit(jHANDLE  HANDLE_1)
{
    jRemoveUnit(HANDLE_1);
}
void    ShowUnit(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jShowUnit(HANDLE_1, BOOL_2);
}
bool    IsUnitInForce(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitInForce(HANDLE_1, HANDLE_2);
}
bool    IsUnitInGroup(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitInGroup(HANDLE_1, HANDLE_2);
}
bool    IsUnitOwnedByPlayer(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitOwnedByPlayer(HANDLE_1, HANDLE_2);
}
bool    IsUnitAlly(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitAlly(HANDLE_1, HANDLE_2);
}
bool    IsUnitEnemy(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitEnemy(HANDLE_1, HANDLE_2);
}
bool    IsUnitVisible(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitVisible(HANDLE_1, HANDLE_2);
}
bool    IsUnitDetected(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitDetected(HANDLE_1, HANDLE_2);
}
bool    IsUnitInvisible(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitInvisible(HANDLE_1, HANDLE_2);
}
bool    IsUnitFogged(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitFogged(HANDLE_1, HANDLE_2);
}
bool    IsUnitMasked(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitMasked(HANDLE_1, HANDLE_2);
}
bool    IsUnitSelected(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitSelected(HANDLE_1, HANDLE_2);
}
bool    IsUnitRace(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitRace(HANDLE_1, HANDLE_2);
}
bool    IsUnitType(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitType(HANDLE_1, HANDLE_2);
}
bool    IsUnit(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnit(HANDLE_1, HANDLE_2);
}
bool    IsUnitInRange(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3)
{
    return jIsUnitInRange(HANDLE_1, HANDLE_2, &real_3);
}
bool    IsUnitInRangeXY(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4)
{
    return jIsUnitInRangeXY(HANDLE_1, &real_2, &real_3, &real_4);
}
bool    IsUnitInRangeLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3)
{
    return jIsUnitInRangeLoc(HANDLE_1, HANDLE_2, &real_3);
}
bool    IsUnitHidden(jHANDLE  HANDLE_1)
{
    return jIsUnitHidden(HANDLE_1);
}
bool    IsUnitIllusion(jHANDLE  HANDLE_1)
{
    return jIsUnitIllusion(HANDLE_1);
}
bool    IsUnitInTransport(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsUnitInTransport(HANDLE_1, HANDLE_2);
}
bool    IsUnitLoaded(jHANDLE  HANDLE_1)
{
    return jIsUnitLoaded(HANDLE_1);
}
bool    IsHeroUnitId(int      integer_1)
{
    return jIsHeroUnitId(integer_1);
}
bool    IsUnitIdType(int      integer_1, jHANDLE  HANDLE_2)
{
    return jIsUnitIdType(integer_1, HANDLE_2);
}
jHANDLE GetOwningPlayer(jHANDLE  HANDLE_1)
{
    return jGetOwningPlayer(HANDLE_1);
}
void    UnitShareVision(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, bool     BOOL_3)
{
    jUnitShareVision(HANDLE_1, HANDLE_2, BOOL_3);
}
void    UnitSuspendDecay(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jUnitSuspendDecay(HANDLE_1, BOOL_2);
}
bool    UnitAddType(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jUnitAddType(HANDLE_1, HANDLE_2);
}
bool    UnitRemoveType(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jUnitRemoveType(HANDLE_1, HANDLE_2);
}
bool    UnitAddAbility(jHANDLE  HANDLE_1, int      integer_2)
{
    return jUnitAddAbility(HANDLE_1, integer_2);
}
bool    UnitRemoveAbility(jHANDLE  HANDLE_1, int      integer_2)
{
    return jUnitRemoveAbility(HANDLE_1, integer_2);
}
bool    UnitMakeAbilityPermanent(jHANDLE  HANDLE_1, bool     BOOL_2, int      integer_3)
{
    return jUnitMakeAbilityPermanent(HANDLE_1, BOOL_2, integer_3);
}
bool    UnitHasBuffsEx(jHANDLE  HANDLE_1, bool     BOOL_2, bool     BOOL_3, bool     BOOL_4, bool     BOOL_5, bool     BOOL_6, bool     BOOL_7, bool     BOOL_8)
{
    return jUnitHasBuffsEx(HANDLE_1, BOOL_2, BOOL_3, BOOL_4, BOOL_5, BOOL_6, BOOL_7, BOOL_8);
}
int     UnitCountBuffsEx(jHANDLE  HANDLE_1, bool     BOOL_2, bool     BOOL_3, bool     BOOL_4, bool     BOOL_5, bool     BOOL_6, bool     BOOL_7, bool     BOOL_8)
{
    return jUnitCountBuffsEx(HANDLE_1, BOOL_2, BOOL_3, BOOL_4, BOOL_5, BOOL_6, BOOL_7, BOOL_8);
}
void    UnitRemoveBuffs(jHANDLE  HANDLE_1, bool     BOOL_2, bool     BOOL_3)
{
    jUnitRemoveBuffs(HANDLE_1, BOOL_2, BOOL_3);
}
void    UnitRemoveBuffsEx(jHANDLE  HANDLE_1, bool     BOOL_2, bool     BOOL_3, bool     BOOL_4, bool     BOOL_5, bool     BOOL_6, bool     BOOL_7, bool     BOOL_8)
{
    jUnitRemoveBuffsEx(HANDLE_1, BOOL_2, BOOL_3, BOOL_4, BOOL_5, BOOL_6, BOOL_7, BOOL_8);
}
void    UnitAddSleep(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jUnitAddSleep(HANDLE_1, BOOL_2);
}
bool    UnitCanSleep(jHANDLE  HANDLE_1)
{
    return jUnitCanSleep(HANDLE_1);
}
void    UnitAddSleepPerm(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jUnitAddSleepPerm(HANDLE_1, BOOL_2);
}
bool    UnitCanSleepPerm(jHANDLE  HANDLE_1)
{
    return jUnitCanSleepPerm(HANDLE_1);
}
bool    UnitIsSleeping(jHANDLE  HANDLE_1)
{
    return jUnitIsSleeping(HANDLE_1);
}
void    UnitWakeUp(jHANDLE  HANDLE_1)
{
    jUnitWakeUp(HANDLE_1);
}
void    UnitApplyTimedLife(jHANDLE  HANDLE_1, int      integer_2, float   real_3)
{
    jUnitApplyTimedLife(HANDLE_1, integer_2, &real_3);
}
bool    UnitIgnoreAlarm(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    return jUnitIgnoreAlarm(HANDLE_1, BOOL_2);
}
bool    UnitIgnoreAlarmToggled(jHANDLE  HANDLE_1)
{
    return jUnitIgnoreAlarmToggled(HANDLE_1);
}
bool    UnitDamagePoint(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4, float   real_5, float   real_6, bool     BOOL_7, bool     BOOL_8, jHANDLE  HANDLE_9, jHANDLE  HANDLE_10, jHANDLE  HANDLE_11)
{
    return jUnitDamagePoint(HANDLE_1, &real_2, &real_3, &real_4, &real_5, &real_6, BOOL_7, BOOL_8, HANDLE_9, HANDLE_10, HANDLE_11);
}
bool    UnitDamageTarget(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3, bool     BOOL_4, bool     BOOL_5, jHANDLE  HANDLE_6, jHANDLE  HANDLE_7, jHANDLE  HANDLE_8)
{
    return jUnitDamageTarget(HANDLE_1, HANDLE_2, &real_3, BOOL_4, BOOL_5, HANDLE_6, HANDLE_7, HANDLE_8);
}
int     DecUnitAbilityLevel(jHANDLE  HANDLE_1, int      integer_2)
{
    return jDecUnitAbilityLevel(HANDLE_1, integer_2);
}
int     IncUnitAbilityLevel(jHANDLE  HANDLE_1, int      integer_2)
{
    return jIncUnitAbilityLevel(HANDLE_1, integer_2);
}
int     SetUnitAbilityLevel(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jSetUnitAbilityLevel(HANDLE_1, integer_2, integer_3);
}
void    UnitResetCooldown(jHANDLE  HANDLE_1)
{
    jUnitResetCooldown(HANDLE_1);
}
void    UnitSetConstructionProgress(jHANDLE  HANDLE_1, int      integer_2)
{
    jUnitSetConstructionProgress(HANDLE_1, integer_2);
}
void    UnitSetUpgradeProgress(jHANDLE  HANDLE_1, int      integer_2)
{
    jUnitSetUpgradeProgress(HANDLE_1, integer_2);
}
void    UnitPauseTimedLife(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jUnitPauseTimedLife(HANDLE_1, BOOL_2);
}
void    UnitSetUsesAltIcon(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jUnitSetUsesAltIcon(HANDLE_1, BOOL_2);
}
bool    IssueImmediateOrderById(jHANDLE  HANDLE_1, int      integer_2)
{
    return jIssueImmediateOrderById(HANDLE_1, integer_2);
}
bool    IssuePointOrderById(jHANDLE  HANDLE_1, int      integer_2, float   real_3, float   real_4)
{
    return jIssuePointOrderById(HANDLE_1, integer_2, &real_3, &real_4);
}
bool    IssuePointOrderByIdLoc(jHANDLE  HANDLE_1, int      integer_2, jHANDLE  HANDLE_3)
{
    return jIssuePointOrderByIdLoc(HANDLE_1, integer_2, HANDLE_3);
}
bool    IssueTargetOrderById(jHANDLE  HANDLE_1, int      integer_2, jHANDLE  HANDLE_3)
{
    return jIssueTargetOrderById(HANDLE_1, integer_2, HANDLE_3);
}
bool    IssueInstantPointOrderById(jHANDLE  HANDLE_1, int      integer_2, float   real_3, float   real_4, jHANDLE  HANDLE_5)
{
    return jIssueInstantPointOrderById(HANDLE_1, integer_2, &real_3, &real_4, HANDLE_5);
}
bool    IssueInstantTargetOrderById(jHANDLE  HANDLE_1, int      integer_2, jHANDLE  HANDLE_3, jHANDLE  HANDLE_4)
{
    return jIssueInstantTargetOrderById(HANDLE_1, integer_2, HANDLE_3, HANDLE_4);
}
bool    IssueBuildOrderById(jHANDLE  HANDLE_1, int      integer_2, float   real_3, float   real_4)
{
    return jIssueBuildOrderById(HANDLE_1, integer_2, &real_3, &real_4);
}
bool    IssueNeutralImmediateOrderById(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, int      integer_3)
{
    return jIssueNeutralImmediateOrderById(HANDLE_1, HANDLE_2, integer_3);
}
bool    IssueNeutralPointOrderById(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, int      integer_3, float   real_4, float   real_5)
{
    return jIssueNeutralPointOrderById(HANDLE_1, HANDLE_2, integer_3, &real_4, &real_5);
}
bool    IssueNeutralTargetOrderById(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jIssueNeutralTargetOrderById(HANDLE_1, HANDLE_2, integer_3, HANDLE_4);
}
bool    IssueImmediateOrder(jHANDLE  HANDLE_1, const char* STRING_2)
{
    return jIssueImmediateOrder(HANDLE_1, RegStr(STRING_2));
}
bool    IssuePointOrder(jHANDLE  HANDLE_1, const char* STRING_2, float   real_3, float   real_4)
{
    return jIssuePointOrder(HANDLE_1, RegStr(STRING_2), &real_3, &real_4);
}
bool    IssuePointOrderLoc(jHANDLE  HANDLE_1, const char* STRING_2, jHANDLE  HANDLE_3)
{
    return jIssuePointOrderLoc(HANDLE_1, RegStr(STRING_2), HANDLE_3);
}
bool    IssueTargetOrder(jHANDLE  HANDLE_1, const char* STRING_2, jHANDLE  HANDLE_3)
{
    return jIssueTargetOrder(HANDLE_1, RegStr(STRING_2), HANDLE_3);
}
bool    IssueInstantPointOrder(jHANDLE  HANDLE_1, const char* STRING_2, float   real_3, float   real_4, jHANDLE  HANDLE_5)
{
    return jIssueInstantPointOrder(HANDLE_1, RegStr(STRING_2), &real_3, &real_4, HANDLE_5);
}
bool    IssueInstantTargetOrder(jHANDLE  HANDLE_1, const char* STRING_2, jHANDLE  HANDLE_3, jHANDLE  HANDLE_4)
{
    return jIssueInstantTargetOrder(HANDLE_1, RegStr(STRING_2), HANDLE_3, HANDLE_4);
}
bool    IssueBuildOrder(jHANDLE  HANDLE_1, const char* STRING_2, float   real_3, float   real_4)
{
    return jIssueBuildOrder(HANDLE_1, RegStr(STRING_2), &real_3, &real_4);
}
bool    IssueNeutralImmediateOrder(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, const char* STRING_3)
{
    return jIssueNeutralImmediateOrder(HANDLE_1, HANDLE_2, RegStr(STRING_3));
}
bool    IssueNeutralPointOrder(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, const char* STRING_3, float   real_4, float   real_5)
{
    return jIssueNeutralPointOrder(HANDLE_1, HANDLE_2, RegStr(STRING_3), &real_4, &real_5);
}
bool    IssueNeutralTargetOrder(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, const char* STRING_3, jHANDLE  HANDLE_4)
{
    return jIssueNeutralTargetOrder(HANDLE_1, HANDLE_2, RegStr(STRING_3), HANDLE_4);
}
float   WaygateGetDestinationX(jHANDLE  HANDLE_1)
{
    int ret = (jWaygateGetDestinationX(HANDLE_1));
    return *(float*)&ret;
}
float   WaygateGetDestinationY(jHANDLE  HANDLE_1)
{
    int ret = (jWaygateGetDestinationY(HANDLE_1));
    return *(float*)&ret;
}
void    WaygateSetDestination(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jWaygateSetDestination(HANDLE_1, &real_2, &real_3);
}
void    WaygateActivate(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jWaygateActivate(HANDLE_1, BOOL_2);
}
bool    WaygateIsActive(jHANDLE  HANDLE_1)
{
    return jWaygateIsActive(HANDLE_1);
}
void    AddItemToAllStock(int      integer_1, int      integer_2, int      integer_3)
{
    jAddItemToAllStock(integer_1, integer_2, integer_3);
}
void    AddItemToStock(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4)
{
    jAddItemToStock(HANDLE_1, integer_2, integer_3, integer_4);
}
void    AddUnitToAllStock(int      integer_1, int      integer_2, int      integer_3)
{
    jAddUnitToAllStock(integer_1, integer_2, integer_3);
}
void    AddUnitToStock(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4)
{
    jAddUnitToStock(HANDLE_1, integer_2, integer_3, integer_4);
}
void    RemoveItemFromAllStock(int      integer_1)
{
    jRemoveItemFromAllStock(integer_1);
}
void    RemoveItemFromStock(jHANDLE  HANDLE_1, int      integer_2)
{
    jRemoveItemFromStock(HANDLE_1, integer_2);
}
void    RemoveUnitFromAllStock(int      integer_1)
{
    jRemoveUnitFromAllStock(integer_1);
}
void    RemoveUnitFromStock(jHANDLE  HANDLE_1, int      integer_2)
{
    jRemoveUnitFromStock(HANDLE_1, integer_2);
}
void    SetAllItemTypeSlots(int      integer_1)
{
    jSetAllItemTypeSlots(integer_1);
}
void    SetAllUnitTypeSlots(int      integer_1)
{
    jSetAllUnitTypeSlots(integer_1);
}
void    SetItemTypeSlots(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetItemTypeSlots(HANDLE_1, integer_2);
}
void    SetUnitTypeSlots(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetUnitTypeSlots(HANDLE_1, integer_2);
}
int     GetUnitUserData(jHANDLE  HANDLE_1)
{
    return jGetUnitUserData(HANDLE_1);
}
void    SetUnitUserData(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetUnitUserData(HANDLE_1, integer_2);
}
jHANDLE CreateItem(int      integer_1, float   real_2, float   real_3)
{
    return jCreateItem(integer_1, &real_2, &real_3);
}
void    RemoveItem(jHANDLE  HANDLE_1)
{
    jRemoveItem(HANDLE_1);
}
jHANDLE GetItemPlayer(jHANDLE  HANDLE_1)
{
    return jGetItemPlayer(HANDLE_1);
}
int     GetItemTypeId(jHANDLE  HANDLE_1)
{
    return jGetItemTypeId(HANDLE_1);
}
float   GetItemX(jHANDLE  HANDLE_1)
{
    int ret = (jGetItemX(HANDLE_1));
    return *(float*)&ret;
}
float   GetItemY(jHANDLE  HANDLE_1)
{
    int ret = (jGetItemY(HANDLE_1));
    return *(float*)&ret;
}
void    SetItemPosition(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jSetItemPosition(HANDLE_1, &real_2, &real_3);
}
void    SetItemDropOnDeath(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetItemDropOnDeath(HANDLE_1, BOOL_2);
}
void    SetItemDroppable(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetItemDroppable(HANDLE_1, BOOL_2);
}
void    SetItemPawnable(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetItemPawnable(HANDLE_1, BOOL_2);
}
void    SetItemPlayer(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, bool     BOOL_3)
{
    jSetItemPlayer(HANDLE_1, HANDLE_2, BOOL_3);
}
void    SetItemInvulnerable(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetItemInvulnerable(HANDLE_1, BOOL_2);
}
bool    IsItemInvulnerable(jHANDLE  HANDLE_1)
{
    return jIsItemInvulnerable(HANDLE_1);
}
int     GetItemLevel(jHANDLE  HANDLE_1)
{
    return jGetItemLevel(HANDLE_1);
}
jHANDLE GetItemType(jHANDLE  HANDLE_1)
{
    return jGetItemType(HANDLE_1);
}
void    SetItemVisible(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetItemVisible(HANDLE_1, BOOL_2);
}
bool    IsItemVisible(jHANDLE  HANDLE_1)
{
    return jIsItemVisible(HANDLE_1);
}
void    EnumItemsInRect(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jCODE     jCODE_3)
{
    jEnumItemsInRect(HANDLE_1, HANDLE_2, jCODE_3);
}
bool    IsItemOwned(jHANDLE  HANDLE_1)
{
    return jIsItemOwned(HANDLE_1);
}
bool    IsItemPowerup(jHANDLE  HANDLE_1)
{
    return jIsItemPowerup(HANDLE_1);
}
bool    IsItemSellable(jHANDLE  HANDLE_1)
{
    return jIsItemSellable(HANDLE_1);
}
bool    IsItemPawnable(jHANDLE  HANDLE_1)
{
    return jIsItemPawnable(HANDLE_1);
}
bool    IsItemIdPowerup(int      integer_1)
{
    return jIsItemIdPowerup(integer_1);
}
bool    IsItemIdSellable(int      integer_1)
{
    return jIsItemIdSellable(integer_1);
}
bool    IsItemIdPawnable(int      integer_1)
{
    return jIsItemIdPawnable(integer_1);
}
void    SetItemDropID(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetItemDropID(HANDLE_1, integer_2);
}
const char* GetItemName(jHANDLE  HANDLE_1)
{
    return (const char*)GetStringAddress(jGetItemName(HANDLE_1));
}
int     GetItemCharges(jHANDLE  HANDLE_1)
{
    return jGetItemCharges(HANDLE_1);
}
void    SetItemCharges(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetItemCharges(HANDLE_1, integer_2);
}
int     GetItemUserData(jHANDLE  HANDLE_1)
{
    return jGetItemUserData(HANDLE_1);
}
void    SetItemUserData(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetItemUserData(HANDLE_1, integer_2);
}
jHANDLE Player(int      integer_1)
{
    return jPlayer(integer_1);
}
jHANDLE GetLocalPlayer()
{
    return jGetLocalPlayer();
}
bool    IsPlayerAlly(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsPlayerAlly(HANDLE_1, HANDLE_2);
}
bool    IsPlayerEnemy(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsPlayerEnemy(HANDLE_1, HANDLE_2);
}
bool    IsPlayerInForce(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsPlayerInForce(HANDLE_1, HANDLE_2);
}
bool    IsPlayerObserver(jHANDLE  HANDLE_1)
{
    return jIsPlayerObserver(HANDLE_1);
}
jHANDLE GetPlayerRace(jHANDLE  HANDLE_1)
{
    return jGetPlayerRace(HANDLE_1);
}
int     GetPlayerId(jHANDLE  HANDLE_1)
{
    return jGetPlayerId(HANDLE_1);
}
void    SetPlayerTechMaxAllowed(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    jSetPlayerTechMaxAllowed(HANDLE_1, integer_2, integer_3);
}
int     GetPlayerTechMaxAllowed(jHANDLE  HANDLE_1, int      integer_2)
{
    return jGetPlayerTechMaxAllowed(HANDLE_1, integer_2);
}
void    AddPlayerTechResearched(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    jAddPlayerTechResearched(HANDLE_1, integer_2, integer_3);
}
void    SetPlayerTechResearched(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    jSetPlayerTechResearched(HANDLE_1, integer_2, integer_3);
}
bool    GetPlayerTechResearched(jHANDLE  HANDLE_1, int      integer_2, bool     BOOL_3)
{
    return jGetPlayerTechResearched(HANDLE_1, integer_2, BOOL_3);
}
int     GetPlayerTechCount(jHANDLE  HANDLE_1, int      integer_2, bool     BOOL_3)
{
    return jGetPlayerTechCount(HANDLE_1, integer_2, BOOL_3);
}
void    SetPlayerAbilityAvailable(jHANDLE  HANDLE_1, int      integer_2, bool     BOOL_3)
{
    jSetPlayerAbilityAvailable(HANDLE_1, integer_2, BOOL_3);
}
int     GetPlayerUnitCount(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    return jGetPlayerUnitCount(HANDLE_1, BOOL_2);
}
int     GetPlayerTypedUnitCount(jHANDLE  HANDLE_1, const char* STRING_2, bool     BOOL_3, bool     BOOL_4)
{
    return jGetPlayerTypedUnitCount(HANDLE_1, RegStr(STRING_2), BOOL_3, BOOL_4);
}
int     GetPlayerStructureCount(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    return jGetPlayerStructureCount(HANDLE_1, BOOL_2);
}
bool    IsVisibleToPlayer(float   real_1, float   real_2, jHANDLE  HANDLE_3)
{
    return jIsVisibleToPlayer(&real_1, &real_2, HANDLE_3);
}
bool    IsLocationVisibleToPlayer(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsLocationVisibleToPlayer(HANDLE_1, HANDLE_2);
}
bool    IsFoggedToPlayer(float   real_1, float   real_2, jHANDLE  HANDLE_3)
{
    return jIsFoggedToPlayer(&real_1, &real_2, HANDLE_3);
}
bool    IsLocationFoggedToPlayer(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsLocationFoggedToPlayer(HANDLE_1, HANDLE_2);
}
bool    IsMaskedToPlayer(float   real_1, float   real_2, jHANDLE  HANDLE_3)
{
    return jIsMaskedToPlayer(&real_1, &real_2, HANDLE_3);
}
bool    IsLocationMaskedToPlayer(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jIsLocationMaskedToPlayer(HANDLE_1, HANDLE_2);
}
void    SetPlayerState(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, int      integer_3)
{
    jSetPlayerState(HANDLE_1, HANDLE_2, integer_3);
}
int     GetPlayerState(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jGetPlayerState(HANDLE_1, HANDLE_2);
}
int     GetPlayerScore(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jGetPlayerScore(HANDLE_1, HANDLE_2);
}
bool    GetPlayerAlliance(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    return jGetPlayerAlliance(HANDLE_1, HANDLE_2, HANDLE_3);
}
void    RemovePlayer(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jRemovePlayer(HANDLE_1, HANDLE_2);
}
void    CachePlayerHeroData(jHANDLE  HANDLE_1)
{
    jCachePlayerHeroData(HANDLE_1);
}
float   GetPlayerHandicap(jHANDLE  HANDLE_1)
{
    int ret = (jGetPlayerHandicap(HANDLE_1));
    return *(float*)&ret;
}
void    SetPlayerHandicap(jHANDLE  HANDLE_1, float   real_2)
{
    jSetPlayerHandicap(HANDLE_1, &real_2);
}
float   GetPlayerHandicapXP(jHANDLE  HANDLE_1)
{
    int ret = (jGetPlayerHandicapXP(HANDLE_1));
    return *(float*)&ret;
}
void    SetPlayerHandicapXP(jHANDLE  HANDLE_1, float   real_2)
{
    jSetPlayerHandicapXP(HANDLE_1, &real_2);
}
void    SetPlayerUnitsOwner(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetPlayerUnitsOwner(HANDLE_1, integer_2);
}
void    CripplePlayer(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, bool     BOOL_3)
{
    jCripplePlayer(HANDLE_1, HANDLE_2, BOOL_3);
}
jHANDLE VersionGet()
{
    return jVersionGet();
}
bool    VersionCompatible(jHANDLE  HANDLE_1)
{
    return jVersionCompatible(HANDLE_1);
}
bool    VersionSupported(jHANDLE  HANDLE_1)
{
    return jVersionSupported(HANDLE_1);
}
void    EndGame(bool     BOOL_1)
{
    jEndGame(BOOL_1);
}
void    ChangeLevel(const char* STRING_1, bool     BOOL_2)
{
    jChangeLevel(RegStr(STRING_1), BOOL_2);
}
void    RestartGame(bool     BOOL_1)
{
    jRestartGame(BOOL_1);
}
void    ReloadGame()
{
    jReloadGame();
}
void    LoadGame(const char* STRING_1, bool     BOOL_2)
{
    jLoadGame(RegStr(STRING_1), BOOL_2);
}
void    SaveGame(const char* STRING_1)
{
    jSaveGame(RegStr(STRING_1));
}
bool    RenameSaveDirectory(const char* STRING_1, const char* STRING_2)
{
    return jRenameSaveDirectory(RegStr(STRING_1), RegStr(STRING_2));
}
bool    RemoveSaveDirectory(const char* STRING_1)
{
    return jRemoveSaveDirectory(RegStr(STRING_1));
}
bool    CopySaveGame(const char* STRING_1, const char* STRING_2)
{
    return jCopySaveGame(RegStr(STRING_1), RegStr(STRING_2));
}
bool    SaveGameExists(const char* STRING_1)
{
    return jSaveGameExists(RegStr(STRING_1));
}
void    SetFloatGameState(jHANDLE  HANDLE_1, float   real_2)
{
    jSetFloatGameState(HANDLE_1, &real_2);
}
float   GetFloatGameState(jHANDLE  HANDLE_1)
{
    int ret = (jGetFloatGameState(HANDLE_1));
    return *(float*)&ret;
}
void    SetIntegerGameState(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetIntegerGameState(HANDLE_1, integer_2);
}
int     GetIntegerGameState(jHANDLE  HANDLE_1)
{
    return jGetIntegerGameState(HANDLE_1);
}
void    SyncSelections()
{
    jSyncSelections();
}
jHANDLE DialogCreate()
{
    return jDialogCreate();
}
void    DialogDestroy(jHANDLE  HANDLE_1)
{
    jDialogDestroy(HANDLE_1);
}
void    DialogSetAsync(jHANDLE  HANDLE_1)
{
    jDialogSetAsync(HANDLE_1);
}
void    DialogClear(jHANDLE  HANDLE_1)
{
    jDialogClear(HANDLE_1);
}
void    DialogSetMessage(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jDialogSetMessage(HANDLE_1, RegStr(STRING_2));
}
jHANDLE DialogAddButton(jHANDLE  HANDLE_1, const char* STRING_2, int      integer_3)
{
    return jDialogAddButton(HANDLE_1, RegStr(STRING_2), integer_3);
}
jHANDLE DialogAddQuitButton(jHANDLE  HANDLE_1, bool     BOOL_2, const char* STRING_3, int      integer_4)
{
    return jDialogAddQuitButton(HANDLE_1, BOOL_2, RegStr(STRING_3), integer_4);
}
void    DialogDisplay(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, bool     BOOL_3)
{
    jDialogDisplay(HANDLE_1, HANDLE_2, BOOL_3);
}
void    SetMissionAvailable(int      integer_1, int      integer_2, bool     BOOL_3)
{
    jSetMissionAvailable(integer_1, integer_2, BOOL_3);
}
void    SetCampaignAvailable(int      integer_1, bool     BOOL_2)
{
    jSetCampaignAvailable(integer_1, BOOL_2);
}
void    SetCampaignMenuRace(jHANDLE  HANDLE_1)
{
    jSetCampaignMenuRace(HANDLE_1);
}
void    SetCampaignMenuRaceEx(int      integer_1)
{
    jSetCampaignMenuRaceEx(integer_1);
}
void    ForceCampaignSelectScreen()
{
    jForceCampaignSelectScreen();
}
void    SetOpCinematicAvailable(int      integer_1, bool     BOOL_2)
{
    jSetOpCinematicAvailable(integer_1, BOOL_2);
}
void    SetEdCinematicAvailable(int      integer_1, bool     BOOL_2)
{
    jSetEdCinematicAvailable(integer_1, BOOL_2);
}
void    SetTutorialCleared(bool     BOOL_1)
{
    jSetTutorialCleared(BOOL_1);
}
jHANDLE GetDefaultDifficulty()
{
    return jGetDefaultDifficulty();
}
void    SetDefaultDifficulty(jHANDLE  HANDLE_1)
{
    jSetDefaultDifficulty(HANDLE_1);
}
bool    ReloadGameCachesFromDisk()
{
    return jReloadGameCachesFromDisk();
}
void    SetCustomCampaignButtonVisible(int      integer_1, bool     BOOL_2)
{
    jSetCustomCampaignButtonVisible(integer_1, BOOL_2);
}
bool    GetCustomCampaignButtonVisible(int      integer_1)
{
    return jGetCustomCampaignButtonVisible(integer_1);
}
void    DoNotSaveReplay()
{
    jDoNotSaveReplay();
}
jHANDLE InitGameCache(const char* STRING_1)
{
    return jInitGameCache(RegStr(STRING_1));
}
bool    SaveGameCache(jHANDLE  HANDLE_1)
{
    return jSaveGameCache(HANDLE_1);
}
void    StoreInteger(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3, int      integer_4)
{
    jStoreInteger(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3), integer_4);
}
void    StoreReal(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3, float   real_4)
{
    jStoreReal(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3), &real_4);
}
void    StoreBoolean(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3, bool     BOOL_4)
{
    jStoreBoolean(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3), BOOL_4);
}
bool    StoreUnit(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3, jHANDLE  HANDLE_4)
{
    return jStoreUnit(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3), HANDLE_4);
}
bool    StoreString(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3, const char* STRING_4)
{
    return jStoreString(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3), RegStr(STRING_4));
}
void    SaveInteger(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4)
{
    jSaveInteger(HANDLE_1, integer_2, integer_3, integer_4);
}
void    SaveReal(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, float   real_4)
{
    jSaveReal(HANDLE_1, integer_2, integer_3, &real_4);
}
void    SaveBoolean(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, bool     BOOL_4)
{
    jSaveBoolean(HANDLE_1, integer_2, integer_3, BOOL_4);
}
bool    SaveStr(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, const char* STRING_4)
{
    return jSaveStr(HANDLE_1, integer_2, integer_3, RegStr(STRING_4));
}
bool    SavePlayerHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSavePlayerHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveWidgetHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveWidgetHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveDestructableHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveDestructableHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveItemHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveItemHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveUnitHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveUnitHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveAbilityHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveAbilityHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveTimerHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveTimerHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveRegionHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveRegionHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveTriggerHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveTriggerHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveTriggerConditionHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveTriggerConditionHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveTriggerActionHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveTriggerActionHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveTriggerEventHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveTriggerEventHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveForceHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveForceHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveGroupHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveGroupHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveLocationHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveLocationHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveRectHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveRectHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveBooleanExprHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveBooleanExprHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveSoundHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveSoundHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveEffectHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveEffectHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveUnitPoolHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveUnitPoolHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveItemPoolHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveItemPoolHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveQuestHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveQuestHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveQuestItemHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveQuestItemHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveDefeatConditionHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveDefeatConditionHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveTimerDialogHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveTimerDialogHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveLeaderboardHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveLeaderboardHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveMultiboardHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveMultiboardHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveMultiboardItemHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveMultiboardItemHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveTrackableHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveTrackableHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveDialogHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveDialogHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveButtonHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveButtonHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveTextTagHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveTextTagHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveLightningHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveLightningHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveImageHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveImageHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveUbersplatHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveUbersplatHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveFogStateHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveFogStateHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveFogModifierHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveFogModifierHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveAgentHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveAgentHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
bool    SaveHashtableHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, jHANDLE  HANDLE_4)
{
    return jSaveHashtableHandle(HANDLE_1, integer_2, integer_3, HANDLE_4);
}
void    SyncStoredInteger(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    jSyncStoredInteger(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
void    SyncStoredReal(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    jSyncStoredReal(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
void    SyncStoredBoolean(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    jSyncStoredBoolean(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
void    SyncStoredUnit(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    jSyncStoredUnit(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
void    SyncStoredString(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    jSyncStoredString(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
int     GetStoredInteger(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    return jGetStoredInteger(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
float   GetStoredReal(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    int ret = (jGetStoredReal(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3)));
    return *(float*)&ret;
}
bool    GetStoredBoolean(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    return jGetStoredBoolean(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
jHANDLE RestoreUnit(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3, jHANDLE  HANDLE_4, float   real_5, float   real_6, float   real_7)
{
    return jRestoreUnit(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3), HANDLE_4, &real_5, &real_6, &real_7);
}
const char* GetStoredString(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    return (const char*)GetStringAddress(jGetStoredString(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3)));
}
bool    HaveStoredInteger(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    return jHaveStoredInteger(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
bool    HaveStoredReal(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    return jHaveStoredReal(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
bool    HaveStoredBoolean(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    return jHaveStoredBoolean(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
bool    HaveStoredUnit(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    return jHaveStoredUnit(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
bool    HaveStoredString(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    return jHaveStoredString(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
void    FlushGameCache(jHANDLE  HANDLE_1)
{
    jFlushGameCache(HANDLE_1);
}
void    FlushStoredMission(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jFlushStoredMission(HANDLE_1, RegStr(STRING_2));
}
void    FlushStoredInteger(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    jFlushStoredInteger(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
void    FlushStoredReal(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    jFlushStoredReal(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
void    FlushStoredBoolean(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    jFlushStoredBoolean(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
void    FlushStoredUnit(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    jFlushStoredUnit(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
void    FlushStoredString(jHANDLE  HANDLE_1, const char* STRING_2, const char* STRING_3)
{
    jFlushStoredString(HANDLE_1, RegStr(STRING_2), RegStr(STRING_3));
}
jHANDLE InitHashtable()
{
    return jInitHashtable();
}
int     LoadInteger(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadInteger(HANDLE_1, integer_2, integer_3);
}
float   LoadReal(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    int ret = (jLoadReal(HANDLE_1, integer_2, integer_3));
    return *(float*)&ret;
}
bool    LoadBoolean(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadBoolean(HANDLE_1, integer_2, integer_3);
}
const char* LoadStr(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return (const char*)GetStringAddress(jLoadStr(HANDLE_1, integer_2, integer_3));
}
jHANDLE LoadPlayerHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadPlayerHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadWidgetHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadWidgetHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadDestructableHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadDestructableHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadItemHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadItemHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadUnitHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadUnitHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadAbilityHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadAbilityHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadTimerHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadTimerHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadRegionHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadRegionHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadTriggerHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadTriggerHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadTriggerConditionHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadTriggerConditionHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadTriggerActionHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadTriggerActionHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadTriggerEventHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadTriggerEventHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadForceHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadForceHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadGroupHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadGroupHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadLocationHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadLocationHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadRectHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadRectHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadBooleanExprHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadBooleanExprHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadSoundHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadSoundHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadEffectHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadEffectHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadUnitPoolHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadUnitPoolHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadItemPoolHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadItemPoolHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadQuestHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadQuestHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadQuestItemHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadQuestItemHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadDefeatConditionHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadDefeatConditionHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadTimerDialogHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadTimerDialogHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadLeaderboardHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadLeaderboardHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadMultiboardHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadMultiboardHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadMultiboardItemHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadMultiboardItemHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadTrackableHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadTrackableHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadDialogHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadDialogHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadButtonHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadButtonHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadTextTagHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadTextTagHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadLightningHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadLightningHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadImageHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadImageHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadUbersplatHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadUbersplatHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadFogStateHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadFogStateHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadFogModifierHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadFogModifierHandle(HANDLE_1, integer_2, integer_3);
}
jHANDLE LoadHashtableHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jLoadHashtableHandle(HANDLE_1, integer_2, integer_3);
}
bool    HaveSavedInteger(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jHaveSavedInteger(HANDLE_1, integer_2, integer_3);
}
bool    HaveSavedReal(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jHaveSavedReal(HANDLE_1, integer_2, integer_3);
}
bool    HaveSavedBoolean(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jHaveSavedBoolean(HANDLE_1, integer_2, integer_3);
}
bool    HaveSavedString(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jHaveSavedString(HANDLE_1, integer_2, integer_3);
}
bool    HaveSavedHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jHaveSavedHandle(HANDLE_1, integer_2, integer_3);
}
void    RemoveSavedInteger(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    jRemoveSavedInteger(HANDLE_1, integer_2, integer_3);
}
void    RemoveSavedReal(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    jRemoveSavedReal(HANDLE_1, integer_2, integer_3);
}
void    RemoveSavedBoolean(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    jRemoveSavedBoolean(HANDLE_1, integer_2, integer_3);
}
void    RemoveSavedString(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    jRemoveSavedString(HANDLE_1, integer_2, integer_3);
}
void    RemoveSavedHandle(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    jRemoveSavedHandle(HANDLE_1, integer_2, integer_3);
}
void    FlushParentHashtable(jHANDLE  HANDLE_1)
{
    jFlushParentHashtable(HANDLE_1);
}
void    FlushChildHashtable(jHANDLE  HANDLE_1, int      integer_2)
{
    jFlushChildHashtable(HANDLE_1, integer_2);
}
int     GetRandomInt(int      integer_1, int      integer_2)
{
    return jGetRandomInt(integer_1, integer_2);
}
float   GetRandomReal(float   real_1, float   real_2)
{
    int ret = (jGetRandomReal(&real_1, &real_2));
    return *(float*)&ret;
}
jHANDLE CreateUnitPool()
{
    return jCreateUnitPool();
}
void    DestroyUnitPool(jHANDLE  HANDLE_1)
{
    jDestroyUnitPool(HANDLE_1);
}
void    UnitPoolAddUnitType(jHANDLE  HANDLE_1, int      integer_2, float   real_3)
{
    jUnitPoolAddUnitType(HANDLE_1, integer_2, &real_3);
}
void    UnitPoolRemoveUnitType(jHANDLE  HANDLE_1, int      integer_2)
{
    jUnitPoolRemoveUnitType(HANDLE_1, integer_2);
}
jHANDLE PlaceRandomUnit(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3, float   real_4, float   real_5)
{
    return jPlaceRandomUnit(HANDLE_1, HANDLE_2, &real_3, &real_4, &real_5);
}
jHANDLE CreateItemPool()
{
    return jCreateItemPool();
}
void    DestroyItemPool(jHANDLE  HANDLE_1)
{
    jDestroyItemPool(HANDLE_1);
}
void    ItemPoolAddItemType(jHANDLE  HANDLE_1, int      integer_2, float   real_3)
{
    jItemPoolAddItemType(HANDLE_1, integer_2, &real_3);
}
void    ItemPoolRemoveItemType(jHANDLE  HANDLE_1, int      integer_2)
{
    jItemPoolRemoveItemType(HANDLE_1, integer_2);
}
jHANDLE PlaceRandomItem(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    return jPlaceRandomItem(HANDLE_1, &real_2, &real_3);
}
int     ChooseRandomCreep(int      integer_1)
{
    return jChooseRandomCreep(integer_1);
}
int     ChooseRandomNPBuilding()
{
    return jChooseRandomNPBuilding();
}
int     ChooseRandomItem(int      integer_1)
{
    return jChooseRandomItem(integer_1);
}
int     ChooseRandomItemEx(jHANDLE  HANDLE_1, int      integer_2)
{
    return jChooseRandomItemEx(HANDLE_1, integer_2);
}
void    SetRandomSeed(int      integer_1)
{
    jSetRandomSeed(integer_1);
}
void    DisplayTextToPlayer(jHANDLE  HANDLE_1, float   real_2, float   real_3, const char* STRING_4)
{
    jDisplayTextToPlayer(HANDLE_1, &real_2, &real_3, RegStr(STRING_4));
}
void    DisplayTimedTextToPlayer(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4, const char* STRING_5)
{
    jDisplayTimedTextToPlayer(HANDLE_1, &real_2, &real_3, &real_4, RegStr(STRING_5));
}
void    DisplayTimedTextFromPlayer(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4, const char* STRING_5)
{
    jDisplayTimedTextFromPlayer(HANDLE_1, &real_2, &real_3, &real_4, RegStr(STRING_5));
}
void    ClearTextMessages()
{
    jClearTextMessages();
}
void    EnableUserControl(bool     BOOL_1)
{
    jEnableUserControl(BOOL_1);
}
void    EnableUserUI(bool     BOOL_1)
{
    jEnableUserUI(BOOL_1);
}
void    DisableRestartMission(bool     BOOL_1)
{
    jDisableRestartMission(BOOL_1);
}
void    ForceUIKey(const char* STRING_1)
{
    jForceUIKey(RegStr(STRING_1));
}
void    ForceUICancel()
{
    jForceUICancel();
}
void    DisplayLoadDialog()
{
    jDisplayLoadDialog();
}
void    SetTerrainFog(float   real_1, float   real_2, float   real_3, float   real_4, float   real_5)
{
    jSetTerrainFog(&real_1, &real_2, &real_3, &real_4, &real_5);
}
void    SetUnitFog(float   real_1, float   real_2, float   real_3, float   real_4, float   real_5)
{
    jSetUnitFog(&real_1, &real_2, &real_3, &real_4, &real_5);
}
void    SetTerrainFogEx(int      integer_1, float   real_2, float   real_3, float   real_4, float   real_5, float   real_6, float   real_7)
{
    jSetTerrainFogEx(integer_1, &real_2, &real_3, &real_4, &real_5, &real_6, &real_7);
}
void    ResetTerrainFog()
{
    jResetTerrainFog();
}
void    SetDayNightModels(const char* STRING_1, const char* STRING_2)
{
    jSetDayNightModels(RegStr(STRING_1), RegStr(STRING_2));
}
void    SetSkyModel(const char* STRING_1)
{
    jSetSkyModel(RegStr(STRING_1));
}
void    SuspendTimeOfDay(bool     BOOL_1)
{
    jSuspendTimeOfDay(BOOL_1);
}
void    SetTimeOfDayScale(float   real_1)
{
    jSetTimeOfDayScale(&real_1);
}
float   GetTimeOfDayScale()
{
    int ret = (jGetTimeOfDayScale());
    return *(float*)&ret;
}
void    ShowInterface(bool     BOOL_1, float   real_2)
{
    jShowInterface(BOOL_1, &real_2);
}
void    PauseGame(bool     BOOL_1)
{
    jPauseGame(BOOL_1);
}
void    PingMinimap(float   real_1, float   real_2, float   real_3)
{
    jPingMinimap(&real_1, &real_2, &real_3);
}
void    PingMinimapEx(float   real_1, float   real_2, float   real_3, int      integer_4, int      integer_5, int      integer_6, bool     BOOL_7)
{
    jPingMinimapEx(&real_1, &real_2, &real_3, integer_4, integer_5, integer_6, BOOL_7);
}
void    SetIntroShotText(const char* STRING_1)
{
    jSetIntroShotText(RegStr(STRING_1));
}
void    SetIntroShotModel(const char* STRING_1)
{
    jSetIntroShotModel(RegStr(STRING_1));
}
void    EnableOcclusion(bool     BOOL_1)
{
    jEnableOcclusion(BOOL_1);
}
void    EnableWorldFogBoundary(bool     BOOL_1)
{
    jEnableWorldFogBoundary(BOOL_1);
}
void    PlayModelCinematic(const char* STRING_1)
{
    jPlayModelCinematic(RegStr(STRING_1));
}
void    PlayCinematic(const char* STRING_1)
{
    jPlayCinematic(RegStr(STRING_1));
}
void    SetAltMinimapIcon(const char* STRING_1)
{
    jSetAltMinimapIcon(RegStr(STRING_1));
}
jHANDLE CreateTextTag()
{
    return jCreateTextTag();
}
void    DestroyTextTag(jHANDLE  HANDLE_1)
{
    jDestroyTextTag(HANDLE_1);
}
void    SetTextTagText(jHANDLE  HANDLE_1, const char* STRING_2, float   real_3)
{
    jSetTextTagText(HANDLE_1, RegStr(STRING_2), &real_3);
}
void    SetTextTagPos(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4)
{
    jSetTextTagPos(HANDLE_1, &real_2, &real_3, &real_4);
}
void    SetTextTagPosUnit(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3)
{
    jSetTextTagPosUnit(HANDLE_1, HANDLE_2, &real_3);
}
void    SetTextTagColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jSetTextTagColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
void    SetTextTagVelocity(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jSetTextTagVelocity(HANDLE_1, &real_2, &real_3);
}
void    SetTextTagVisibility(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetTextTagVisibility(HANDLE_1, BOOL_2);
}
void    SetTextTagSuspended(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetTextTagSuspended(HANDLE_1, BOOL_2);
}
void    SetTextTagPermanent(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetTextTagPermanent(HANDLE_1, BOOL_2);
}
void    SetTextTagAge(jHANDLE  HANDLE_1, float   real_2)
{
    jSetTextTagAge(HANDLE_1, &real_2);
}
void    SetTextTagLifespan(jHANDLE  HANDLE_1, float   real_2)
{
    jSetTextTagLifespan(HANDLE_1, &real_2);
}
void    SetTextTagFadepoint(jHANDLE  HANDLE_1, float   real_2)
{
    jSetTextTagFadepoint(HANDLE_1, &real_2);
}
void    SetReservedLocalHeroButtons(int      integer_1)
{
    jSetReservedLocalHeroButtons(integer_1);
}
int     GetAllyColorFilterState()
{
    return jGetAllyColorFilterState();
}
void    SetAllyColorFilterState(int      integer_1)
{
    jSetAllyColorFilterState(integer_1);
}
bool    GetCreepCampFilterState()
{
    return jGetCreepCampFilterState();
}
void    SetCreepCampFilterState(bool     BOOL_1)
{
    jSetCreepCampFilterState(BOOL_1);
}
void    EnableMinimapFilterButtons(bool     BOOL_1, bool     BOOL_2)
{
    jEnableMinimapFilterButtons(BOOL_1, BOOL_2);
}
void    EnableDragSelect(bool     BOOL_1, bool     BOOL_2)
{
    jEnableDragSelect(BOOL_1, BOOL_2);
}
void    EnablePreSelect(bool     BOOL_1, bool     BOOL_2)
{
    jEnablePreSelect(BOOL_1, BOOL_2);
}
void    EnableSelect(bool     BOOL_1, bool     BOOL_2)
{
    jEnableSelect(BOOL_1, BOOL_2);
}
jHANDLE CreateTrackable(const char* STRING_1, float   real_2, float   real_3, float   real_4)
{
    return jCreateTrackable(RegStr(STRING_1), &real_2, &real_3, &real_4);
}
jHANDLE TriggerRegisterTrackableHitEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jTriggerRegisterTrackableHitEvent(HANDLE_1, HANDLE_2);
}
jHANDLE TriggerRegisterTrackableTrackEvent(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jTriggerRegisterTrackableTrackEvent(HANDLE_1, HANDLE_2);
}
jHANDLE GetTriggeringTrackable()
{
    return jGetTriggeringTrackable();
}
jHANDLE CreateQuest()
{
    return jCreateQuest();
}
void    DestroyQuest(jHANDLE  HANDLE_1)
{
    jDestroyQuest(HANDLE_1);
}
void    QuestSetTitle(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jQuestSetTitle(HANDLE_1, RegStr(STRING_2));
}
void    QuestSetDescription(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jQuestSetDescription(HANDLE_1, RegStr(STRING_2));
}
void    QuestSetIconPath(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jQuestSetIconPath(HANDLE_1, RegStr(STRING_2));
}
void    QuestSetRequired(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jQuestSetRequired(HANDLE_1, BOOL_2);
}
void    QuestSetCompleted(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jQuestSetCompleted(HANDLE_1, BOOL_2);
}
void    QuestSetDiscovered(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jQuestSetDiscovered(HANDLE_1, BOOL_2);
}
void    QuestSetFailed(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jQuestSetFailed(HANDLE_1, BOOL_2);
}
void    QuestSetEnabled(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jQuestSetEnabled(HANDLE_1, BOOL_2);
}
bool    IsQuestRequired(jHANDLE  HANDLE_1)
{
    return jIsQuestRequired(HANDLE_1);
}
bool    IsQuestCompleted(jHANDLE  HANDLE_1)
{
    return jIsQuestCompleted(HANDLE_1);
}
bool    IsQuestDiscovered(jHANDLE  HANDLE_1)
{
    return jIsQuestDiscovered(HANDLE_1);
}
bool    IsQuestFailed(jHANDLE  HANDLE_1)
{
    return jIsQuestFailed(HANDLE_1);
}
bool    IsQuestEnabled(jHANDLE  HANDLE_1)
{
    return jIsQuestEnabled(HANDLE_1);
}
jHANDLE QuestCreateItem(jHANDLE  HANDLE_1)
{
    return jQuestCreateItem(HANDLE_1);
}
void    QuestItemSetDescription(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jQuestItemSetDescription(HANDLE_1, RegStr(STRING_2));
}
void    QuestItemSetCompleted(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jQuestItemSetCompleted(HANDLE_1, BOOL_2);
}
bool    IsQuestItemCompleted(jHANDLE  HANDLE_1)
{
    return jIsQuestItemCompleted(HANDLE_1);
}
jHANDLE CreateDefeatCondition()
{
    return jCreateDefeatCondition();
}
void    DestroyDefeatCondition(jHANDLE  HANDLE_1)
{
    jDestroyDefeatCondition(HANDLE_1);
}
void    DefeatConditionSetDescription(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jDefeatConditionSetDescription(HANDLE_1, RegStr(STRING_2));
}
void    FlashQuestDialogButton()
{
    jFlashQuestDialogButton();
}
void    ForceQuestDialogUpdate()
{
    jForceQuestDialogUpdate();
}
jHANDLE CreateTimerDialog(jHANDLE  HANDLE_1)
{
    return jCreateTimerDialog(HANDLE_1);
}
void    DestroyTimerDialog(jHANDLE  HANDLE_1)
{
    jDestroyTimerDialog(HANDLE_1);
}
void    TimerDialogSetTitle(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jTimerDialogSetTitle(HANDLE_1, RegStr(STRING_2));
}
void    TimerDialogSetTitleColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jTimerDialogSetTitleColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
void    TimerDialogSetTimeColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jTimerDialogSetTimeColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
void    TimerDialogSetSpeed(jHANDLE  HANDLE_1, float   real_2)
{
    jTimerDialogSetSpeed(HANDLE_1, &real_2);
}
void    TimerDialogDisplay(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jTimerDialogDisplay(HANDLE_1, BOOL_2);
}
bool    IsTimerDialogDisplayed(jHANDLE  HANDLE_1)
{
    return jIsTimerDialogDisplayed(HANDLE_1);
}
void    TimerDialogSetRealTimeRemaining(jHANDLE  HANDLE_1, float   real_2)
{
    jTimerDialogSetRealTimeRemaining(HANDLE_1, &real_2);
}
jHANDLE CreateLeaderboard()
{
    return jCreateLeaderboard();
}
void    DestroyLeaderboard(jHANDLE  HANDLE_1)
{
    jDestroyLeaderboard(HANDLE_1);
}
int     LeaderboardGetItemCount(jHANDLE  HANDLE_1)
{
    return jLeaderboardGetItemCount(HANDLE_1);
}
void    LeaderboardSetSizeByItemCount(jHANDLE  HANDLE_1, int      integer_2)
{
    jLeaderboardSetSizeByItemCount(HANDLE_1, integer_2);
}
void    LeaderboardAddItem(jHANDLE  HANDLE_1, const char* STRING_2, int      integer_3, jHANDLE  HANDLE_4)
{
    jLeaderboardAddItem(HANDLE_1, RegStr(STRING_2), integer_3, HANDLE_4);
}
void    LeaderboardRemoveItem(jHANDLE  HANDLE_1, int      integer_2)
{
    jLeaderboardRemoveItem(HANDLE_1, integer_2);
}
void    LeaderboardRemovePlayerItem(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jLeaderboardRemovePlayerItem(HANDLE_1, HANDLE_2);
}
void    LeaderboardSortItemsByValue(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jLeaderboardSortItemsByValue(HANDLE_1, BOOL_2);
}
void    LeaderboardSortItemsByPlayer(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jLeaderboardSortItemsByPlayer(HANDLE_1, BOOL_2);
}
void    LeaderboardSortItemsByLabel(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jLeaderboardSortItemsByLabel(HANDLE_1, BOOL_2);
}
void    LeaderboardClear(jHANDLE  HANDLE_1)
{
    jLeaderboardClear(HANDLE_1);
}
void    LeaderboardDisplay(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jLeaderboardDisplay(HANDLE_1, BOOL_2);
}
bool    IsLeaderboardDisplayed(jHANDLE  HANDLE_1)
{
    return jIsLeaderboardDisplayed(HANDLE_1);
}
const char* LeaderboardGetLabelText(jHANDLE  HANDLE_1)
{
    return (const char*)GetStringAddress(jLeaderboardGetLabelText(HANDLE_1));
}
void    PlayerSetLeaderboard(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jPlayerSetLeaderboard(HANDLE_1, HANDLE_2);
}
jHANDLE PlayerGetLeaderboard(jHANDLE  HANDLE_1)
{
    return jPlayerGetLeaderboard(HANDLE_1);
}
bool    LeaderboardHasPlayerItem(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jLeaderboardHasPlayerItem(HANDLE_1, HANDLE_2);
}
int     LeaderboardGetPlayerIndex(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    return jLeaderboardGetPlayerIndex(HANDLE_1, HANDLE_2);
}
void    LeaderboardSetLabel(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jLeaderboardSetLabel(HANDLE_1, RegStr(STRING_2));
}
void    LeaderboardSetLabelColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jLeaderboardSetLabelColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
void    LeaderboardSetValueColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jLeaderboardSetValueColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
void    LeaderboardSetStyle(jHANDLE  HANDLE_1, bool     BOOL_2, bool     BOOL_3, bool     BOOL_4, bool     BOOL_5)
{
    jLeaderboardSetStyle(HANDLE_1, BOOL_2, BOOL_3, BOOL_4, BOOL_5);
}
void    LeaderboardSetItemValue(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    jLeaderboardSetItemValue(HANDLE_1, integer_2, integer_3);
}
void    LeaderboardSetItemLabel(jHANDLE  HANDLE_1, int      integer_2, const char* STRING_3)
{
    jLeaderboardSetItemLabel(HANDLE_1, integer_2, RegStr(STRING_3));
}
void    LeaderboardSetItemStyle(jHANDLE  HANDLE_1, int      integer_2, bool     BOOL_3, bool     BOOL_4, bool     BOOL_5)
{
    jLeaderboardSetItemStyle(HANDLE_1, integer_2, BOOL_3, BOOL_4, BOOL_5);
}
void    LeaderboardSetItemLabelColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5, int      integer_6)
{
    jLeaderboardSetItemLabelColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5, integer_6);
}
void    LeaderboardSetItemValueColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5, int      integer_6)
{
    jLeaderboardSetItemValueColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5, integer_6);
}
jHANDLE CreateMultiboard()
{
    return jCreateMultiboard();
}
void    DestroyMultiboard(jHANDLE  HANDLE_1)
{
    jDestroyMultiboard(HANDLE_1);
}
void    MultiboardDisplay(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jMultiboardDisplay(HANDLE_1, BOOL_2);
}
void    MultiboardMinimize(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jMultiboardMinimize(HANDLE_1, BOOL_2);
}
bool    IsMultiboardDisplayed(jHANDLE  HANDLE_1)
{
    return jIsMultiboardDisplayed(HANDLE_1);
}
bool    IsMultiboardMinimized(jHANDLE  HANDLE_1)
{
    return jIsMultiboardMinimized(HANDLE_1);
}
void    MultiboardClear(jHANDLE  HANDLE_1)
{
    jMultiboardClear(HANDLE_1);
}
void    MultiboardSetTitleText(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jMultiboardSetTitleText(HANDLE_1, RegStr(STRING_2));
}
const char* MultiboardGetTitleText(jHANDLE  HANDLE_1)
{
    return (const char*)GetStringAddress(jMultiboardGetTitleText(HANDLE_1));
}
void    MultiboardSetTitleTextColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jMultiboardSetTitleTextColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
int     MultiboardGetRowCount(jHANDLE  HANDLE_1)
{
    return jMultiboardGetRowCount(HANDLE_1);
}
int     MultiboardGetColumnCount(jHANDLE  HANDLE_1)
{
    return jMultiboardGetColumnCount(HANDLE_1);
}
void    MultiboardSetColumnCount(jHANDLE  HANDLE_1, int      integer_2)
{
    jMultiboardSetColumnCount(HANDLE_1, integer_2);
}
void    MultiboardSetRowCount(jHANDLE  HANDLE_1, int      integer_2)
{
    jMultiboardSetRowCount(HANDLE_1, integer_2);
}
void    MultiboardSetItemsStyle(jHANDLE  HANDLE_1, bool     BOOL_2, bool     BOOL_3)
{
    jMultiboardSetItemsStyle(HANDLE_1, BOOL_2, BOOL_3);
}
void    MultiboardSetItemsValueColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jMultiboardSetItemsValueColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
void    MultiboardSetItemsValue(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jMultiboardSetItemsValue(HANDLE_1, RegStr(STRING_2));
}
void    MultiboardSetItemsWidth(jHANDLE  HANDLE_1, float   real_2)
{
    jMultiboardSetItemsWidth(HANDLE_1, &real_2);
}
void    MultiboardSetItemsIcon(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jMultiboardSetItemsIcon(HANDLE_1, RegStr(STRING_2));
}
jHANDLE MultiboardGetItem(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    return jMultiboardGetItem(HANDLE_1, integer_2, integer_3);
}
void    MultiboardReleaseItem(jHANDLE  HANDLE_1)
{
    jMultiboardReleaseItem(HANDLE_1);
}
void    MultiboardSetItemStyle(jHANDLE  HANDLE_1, bool     BOOL_2, bool     BOOL_3)
{
    jMultiboardSetItemStyle(HANDLE_1, BOOL_2, BOOL_3);
}
void    MultiboardSetItemValue(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jMultiboardSetItemValue(HANDLE_1, RegStr(STRING_2));
}
void    MultiboardSetItemValueColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jMultiboardSetItemValueColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
void    MultiboardSetItemWidth(jHANDLE  HANDLE_1, float   real_2)
{
    jMultiboardSetItemWidth(HANDLE_1, &real_2);
}
void    MultiboardSetItemIcon(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jMultiboardSetItemIcon(HANDLE_1, RegStr(STRING_2));
}
void    MultiboardSuppressDisplay(bool     BOOL_1)
{
    jMultiboardSuppressDisplay(BOOL_1);
}
void    SetCameraBounds(float   real_1, float   real_2, float   real_3, float   real_4, float   real_5, float   real_6, float   real_7, float   real_8)
{
    jSetCameraBounds(&real_1, &real_2, &real_3, &real_4, &real_5, &real_6, &real_7, &real_8);
}
void    SetCameraPosition(float   real_1, float   real_2)
{
    jSetCameraPosition(&real_1, &real_2);
}
void    SetCameraQuickPosition(float   real_1, float   real_2)
{
    jSetCameraQuickPosition(&real_1, &real_2);
}
void    ResetToGameCamera(float   real_1)
{
    jResetToGameCamera(&real_1);
}
void    StopCamera()
{
    jStopCamera();
}
void    PanCameraTo(float   real_1, float   real_2)
{
    jPanCameraTo(&real_1, &real_2);
}
void    PanCameraToTimed(float   real_1, float   real_2, float   real_3)
{
    jPanCameraToTimed(&real_1, &real_2, &real_3);
}
void    PanCameraToWithZ(float   real_1, float   real_2, float   real_3)
{
    jPanCameraToWithZ(&real_1, &real_2, &real_3);
}
void    PanCameraToTimedWithZ(float   real_1, float   real_2, float   real_3, float   real_4)
{
    jPanCameraToTimedWithZ(&real_1, &real_2, &real_3, &real_4);
}
void    SetCinematicCamera(const char* STRING_1)
{
    jSetCinematicCamera(RegStr(STRING_1));
}
void    SetCameraField(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jSetCameraField(HANDLE_1, &real_2, &real_3);
}
void    AdjustCameraField(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jAdjustCameraField(HANDLE_1, &real_2, &real_3);
}
void    SetCameraTargetController(jHANDLE  HANDLE_1, float   real_2, float   real_3, bool     BOOL_4)
{
    jSetCameraTargetController(HANDLE_1, &real_2, &real_3, BOOL_4);
}
void    SetCameraOrientController(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jSetCameraOrientController(HANDLE_1, &real_2, &real_3);
}
void    SetCameraRotateMode(float   real_1, float   real_2, float   real_3, float   real_4)
{
    jSetCameraRotateMode(&real_1, &real_2, &real_3, &real_4);
}
jHANDLE CreateCameraSetup()
{
    return jCreateCameraSetup();
}
void    CameraSetupSetField(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3, float   real_4)
{
    jCameraSetupSetField(HANDLE_1, HANDLE_2, &real_3, &real_4);
}
float   CameraSetupGetField(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    int ret = (jCameraSetupGetField(HANDLE_1, HANDLE_2));
    return *(float*)&ret;
}
void    CameraSetupSetDestPosition(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4)
{
    jCameraSetupSetDestPosition(HANDLE_1, &real_2, &real_3, &real_4);
}
jHANDLE CameraSetupGetDestPositionLoc(jHANDLE  HANDLE_1)
{
    return jCameraSetupGetDestPositionLoc(HANDLE_1);
}
float   CameraSetupGetDestPositionX(jHANDLE  HANDLE_1)
{
    int ret = (jCameraSetupGetDestPositionX(HANDLE_1));
    return *(float*)&ret;
}
float   CameraSetupGetDestPositionY(jHANDLE  HANDLE_1)
{
    int ret = (jCameraSetupGetDestPositionY(HANDLE_1));
    return *(float*)&ret;
}
void    CameraSetupApply(jHANDLE  HANDLE_1, bool     BOOL_2, bool     BOOL_3)
{
    jCameraSetupApply(HANDLE_1, BOOL_2, BOOL_3);
}
void    CameraSetupApplyWithZ(jHANDLE  HANDLE_1, float   real_2)
{
    jCameraSetupApplyWithZ(HANDLE_1, &real_2);
}
void    CameraSetupApplyForceDuration(jHANDLE  HANDLE_1, bool     BOOL_2, float   real_3)
{
    jCameraSetupApplyForceDuration(HANDLE_1, BOOL_2, &real_3);
}
void    CameraSetupApplyForceDurationWithZ(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jCameraSetupApplyForceDurationWithZ(HANDLE_1, &real_2, &real_3);
}
void    CameraSetTargetNoise(float   real_1, float   real_2)
{
    jCameraSetTargetNoise(&real_1, &real_2);
}
void    CameraSetSourceNoise(float   real_1, float   real_2)
{
    jCameraSetSourceNoise(&real_1, &real_2);
}
void    CameraSetTargetNoiseEx(float   real_1, float   real_2, bool     BOOL_3)
{
    jCameraSetTargetNoiseEx(&real_1, &real_2, BOOL_3);
}
void    CameraSetSourceNoiseEx(float   real_1, float   real_2, bool     BOOL_3)
{
    jCameraSetSourceNoiseEx(&real_1, &real_2, BOOL_3);
}
void    CameraSetSmoothingFactor(float   real_1)
{
    jCameraSetSmoothingFactor(&real_1);
}
float   GetCameraMargin(int      integer_1)
{
    int ret = (jGetCameraMargin(integer_1));
    return *(float*)&ret;
}
float   GetCameraBoundMinX()
{
    int ret = (jGetCameraBoundMinX());
    return *(float*)&ret;
}
float   GetCameraBoundMinY()
{
    int ret = (jGetCameraBoundMinY());
    return *(float*)&ret;
}
float   GetCameraBoundMaxX()
{
    int ret = (jGetCameraBoundMaxX());
    return *(float*)&ret;
}
float   GetCameraBoundMaxY()
{
    int ret = (jGetCameraBoundMaxY());
    return *(float*)&ret;
}
float   GetCameraField(jHANDLE  HANDLE_1)
{
    int ret = (jGetCameraField(HANDLE_1));
    return *(float*)&ret;
}
float   GetCameraTargetPositionX()
{
    int ret = (jGetCameraTargetPositionX());
    return *(float*)&ret;
}
float   GetCameraTargetPositionY()
{
    int ret = (jGetCameraTargetPositionY());
    return *(float*)&ret;
}
float   GetCameraTargetPositionZ()
{
    int ret = (jGetCameraTargetPositionZ());
    return *(float*)&ret;
}
jHANDLE GetCameraTargetPositionLoc()
{
    return jGetCameraTargetPositionLoc();
}
float   GetCameraEyePositionX()
{
    int ret = (jGetCameraEyePositionX());
    return *(float*)&ret;
}
float   GetCameraEyePositionY()
{
    int ret = (jGetCameraEyePositionY());
    return *(float*)&ret;
}
float   GetCameraEyePositionZ()
{
    int ret = (jGetCameraEyePositionZ());
    return *(float*)&ret;
}
jHANDLE GetCameraEyePositionLoc()
{
    return jGetCameraEyePositionLoc();
}
void    SetCineFilterTexture(const char* STRING_1)
{
    jSetCineFilterTexture(RegStr(STRING_1));
}
void    SetCineFilterBlendMode(jHANDLE  HANDLE_1)
{
    jSetCineFilterBlendMode(HANDLE_1);
}
void    SetCineFilterTexMapFlags(jHANDLE  HANDLE_1)
{
    jSetCineFilterTexMapFlags(HANDLE_1);
}
void    SetCineFilterStartUV(float   real_1, float   real_2, float   real_3, float   real_4)
{
    jSetCineFilterStartUV(&real_1, &real_2, &real_3, &real_4);
}
void    SetCineFilterEndUV(float   real_1, float   real_2, float   real_3, float   real_4)
{
    jSetCineFilterEndUV(&real_1, &real_2, &real_3, &real_4);
}
void    SetCineFilterStartColor(int      integer_1, int      integer_2, int      integer_3, int      integer_4)
{
    jSetCineFilterStartColor(integer_1, integer_2, integer_3, integer_4);
}
void    SetCineFilterEndColor(int      integer_1, int      integer_2, int      integer_3, int      integer_4)
{
    jSetCineFilterEndColor(integer_1, integer_2, integer_3, integer_4);
}
void    SetCineFilterDuration(float   real_1)
{
    jSetCineFilterDuration(&real_1);
}
void    DisplayCineFilter(bool     BOOL_1)
{
    jDisplayCineFilter(BOOL_1);
}
bool    IsCineFilterDisplayed()
{
    return jIsCineFilterDisplayed();
}
void    SetCinematicScene(int      integer_1, jHANDLE  HANDLE_2, const char* STRING_3, const char* STRING_4, float   real_5, float   real_6)
{
    jSetCinematicScene(integer_1, HANDLE_2, RegStr(STRING_3), RegStr(STRING_4), &real_5, &real_6);
}
void    EndCinematicScene()
{
    jEndCinematicScene();
}
void    ForceCinematicSubtitles(bool     BOOL_1)
{
    jForceCinematicSubtitles(BOOL_1);
}
void    NewSoundEnvironment(const char* STRING_1)
{
    jNewSoundEnvironment(RegStr(STRING_1));
}
jHANDLE CreateSound(const char* STRING_1, bool     BOOL_2, bool     BOOL_3, bool     BOOL_4, int      integer_5, int      integer_6, const char* STRING_7)
{
    return jCreateSound(RegStr(STRING_1), BOOL_2, BOOL_3, BOOL_4, integer_5, integer_6, RegStr(STRING_7));
}
jHANDLE CreateSoundFilenameWithLabel(const char* STRING_1, bool     BOOL_2, bool     BOOL_3, bool     BOOL_4, int      integer_5, int      integer_6, const char* STRING_7)
{
    return jCreateSoundFilenameWithLabel(RegStr(STRING_1), BOOL_2, BOOL_3, BOOL_4, integer_5, integer_6, RegStr(STRING_7));
}
jHANDLE CreateSoundFromLabel(const char* STRING_1, bool     BOOL_2, bool     BOOL_3, bool     BOOL_4, int      integer_5, int      integer_6)
{
    return jCreateSoundFromLabel(RegStr(STRING_1), BOOL_2, BOOL_3, BOOL_4, integer_5, integer_6);
}
jHANDLE CreateMIDISound(const char* STRING_1, int      integer_2, int      integer_3)
{
    return jCreateMIDISound(RegStr(STRING_1), integer_2, integer_3);
}
void    SetStackedSound(const char* STRING_1, float   real_2, float   real_3)
{
    jSetStackedSound(RegStr(STRING_1), &real_2, &real_3);
}
void    ClearStackedSound(const char* STRING_1, float   real_2, float   real_3)
{
    jClearStackedSound(RegStr(STRING_1), &real_2, &real_3);
}
void    SetStackedSoundRect(const char* STRING_1, jHANDLE  HANDLE_2)
{
    jSetStackedSoundRect(RegStr(STRING_1), HANDLE_2);
}
void    ClearStackedSoundRect(const char* STRING_1, jHANDLE  HANDLE_2)
{
    jClearStackedSoundRect(RegStr(STRING_1), HANDLE_2);
}
void    SetSoundParamsFromLabel(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jSetSoundParamsFromLabel(HANDLE_1, RegStr(STRING_2));
}
void    SetSoundChannel(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetSoundChannel(HANDLE_1, integer_2);
}
void    SetSoundVolume(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetSoundVolume(HANDLE_1, integer_2);
}
void    SetSoundPitch(jHANDLE  HANDLE_1, float   real_2)
{
    jSetSoundPitch(HANDLE_1, &real_2);
}
void    SetSoundPlayPosition(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetSoundPlayPosition(HANDLE_1, integer_2);
}
void    SetSoundDistances(jHANDLE  HANDLE_1, float   real_2, float   real_3)
{
    jSetSoundDistances(HANDLE_1, &real_2, &real_3);
}
void    SetSoundDistanceCutoff(jHANDLE  HANDLE_1, float   real_2)
{
    jSetSoundDistanceCutoff(HANDLE_1, &real_2);
}
void    SetSoundConeAngles(jHANDLE  HANDLE_1, float   real_2, float   real_3, int      integer_4)
{
    jSetSoundConeAngles(HANDLE_1, &real_2, &real_3, integer_4);
}
void    SetSoundConeOrientation(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4)
{
    jSetSoundConeOrientation(HANDLE_1, &real_2, &real_3, &real_4);
}
void    SetSoundPosition(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4)
{
    jSetSoundPosition(HANDLE_1, &real_2, &real_3, &real_4);
}
void    SetSoundVelocity(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4)
{
    jSetSoundVelocity(HANDLE_1, &real_2, &real_3, &real_4);
}
void    AttachSoundToUnit(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2)
{
    jAttachSoundToUnit(HANDLE_1, HANDLE_2);
}
void    StartSound(jHANDLE  HANDLE_1)
{
    jStartSound(HANDLE_1);
}
void    StopSound(jHANDLE  HANDLE_1, bool     BOOL_2, bool     BOOL_3)
{
    jStopSound(HANDLE_1, BOOL_2, BOOL_3);
}
void    KillSoundWhenDone(jHANDLE  HANDLE_1)
{
    jKillSoundWhenDone(HANDLE_1);
}
void    SetMapMusic(const char* STRING_1, bool     BOOL_2, int      integer_3)
{
    jSetMapMusic(RegStr(STRING_1), BOOL_2, integer_3);
}
void    ClearMapMusic()
{
    jClearMapMusic();
}
void    PlayMusic(const char* STRING_1)
{
    jPlayMusic(RegStr(STRING_1));
}
void    PlayMusicEx(const char* STRING_1, int      integer_2, int      integer_3)
{
    jPlayMusicEx(RegStr(STRING_1), integer_2, integer_3);
}
void    StopMusic(bool     BOOL_1)
{
    jStopMusic(BOOL_1);
}
void    ResumeMusic()
{
    jResumeMusic();
}
void    PlayThematicMusic(const char* STRING_1)
{
    jPlayThematicMusic(RegStr(STRING_1));
}
void    PlayThematicMusicEx(const char* STRING_1, int      integer_2)
{
    jPlayThematicMusicEx(RegStr(STRING_1), integer_2);
}
void    EndThematicMusic()
{
    jEndThematicMusic();
}
void    SetMusicVolume(int      integer_1)
{
    jSetMusicVolume(integer_1);
}
void    SetMusicPlayPosition(int      integer_1)
{
    jSetMusicPlayPosition(integer_1);
}
void    SetThematicMusicPlayPosition(int      integer_1)
{
    jSetThematicMusicPlayPosition(integer_1);
}
void    SetSoundDuration(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetSoundDuration(HANDLE_1, integer_2);
}
int     GetSoundDuration(jHANDLE  HANDLE_1)
{
    return jGetSoundDuration(HANDLE_1);
}
int     GetSoundFileDuration(const char* STRING_1)
{
    return jGetSoundFileDuration(RegStr(STRING_1));
}
void    VolumeGroupSetVolume(jHANDLE  HANDLE_1, float   real_2)
{
    jVolumeGroupSetVolume(HANDLE_1, &real_2);
}
void    VolumeGroupReset()
{
    jVolumeGroupReset();
}
bool    GetSoundIsPlaying(jHANDLE  HANDLE_1)
{
    return jGetSoundIsPlaying(HANDLE_1);
}
bool    GetSoundIsLoading(jHANDLE  HANDLE_1)
{
    return jGetSoundIsLoading(HANDLE_1);
}
void    RegisterStackedSound(jHANDLE  HANDLE_1, bool     BOOL_2, float   real_3, float   real_4)
{
    jRegisterStackedSound(HANDLE_1, BOOL_2, &real_3, &real_4);
}
void    UnregisterStackedSound(jHANDLE  HANDLE_1, bool     BOOL_2, float   real_3, float   real_4)
{
    jUnregisterStackedSound(HANDLE_1, BOOL_2, &real_3, &real_4);
}
jHANDLE AddWeatherEffect(jHANDLE  HANDLE_1, int      integer_2)
{
    return jAddWeatherEffect(HANDLE_1, integer_2);
}
void    RemoveWeatherEffect(jHANDLE  HANDLE_1)
{
    jRemoveWeatherEffect(HANDLE_1);
}
void    EnableWeatherEffect(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jEnableWeatherEffect(HANDLE_1, BOOL_2);
}
jHANDLE TerrainDeformCrater(float   real_1, float   real_2, float   real_3, float   real_4, int      integer_5, bool     BOOL_6)
{
    return jTerrainDeformCrater(&real_1, &real_2, &real_3, &real_4, integer_5, BOOL_6);
}
jHANDLE TerrainDeformRipple(float   real_1, float   real_2, float   real_3, float   real_4, int      integer_5, int      integer_6, float   real_7, float   real_8, float   real_9, bool     BOOL_10)
{
    return jTerrainDeformRipple(&real_1, &real_2, &real_3, &real_4, integer_5, integer_6, &real_7, &real_8, &real_9, BOOL_10);
}
jHANDLE TerrainDeformWave(float   real_1, float   real_2, float   real_3, float   real_4, float   real_5, float   real_6, float   real_7, float   real_8, int      integer_9, int      integer_10)
{
    return jTerrainDeformWave(&real_1, &real_2, &real_3, &real_4, &real_5, &real_6, &real_7, &real_8, integer_9, integer_10);
}
jHANDLE TerrainDeformRandom(float   real_1, float   real_2, float   real_3, float   real_4, float   real_5, int      integer_6, int      integer_7)
{
    return jTerrainDeformRandom(&real_1, &real_2, &real_3, &real_4, &real_5, integer_6, integer_7);
}
void    TerrainDeformStop(jHANDLE  HANDLE_1, int      integer_2)
{
    jTerrainDeformStop(HANDLE_1, integer_2);
}
void    TerrainDeformStopAll()
{
    jTerrainDeformStopAll();
}
void    DestroyEffect(jHANDLE  HANDLE_1)
{
    jDestroyEffect(HANDLE_1);
}
jHANDLE AddSpecialEffect(const char* STRING_1, float   real_2, float   real_3)
{
    return jAddSpecialEffect(RegStr(STRING_1), &real_2, &real_3);
}
jHANDLE AddSpecialEffectLoc(const char* STRING_1, jHANDLE  HANDLE_2)
{
    return jAddSpecialEffectLoc(RegStr(STRING_1), HANDLE_2);
}
jHANDLE AddSpecialEffectTarget(const char* STRING_1, jHANDLE  HANDLE_2, const char* STRING_3)
{
    return jAddSpecialEffectTarget(RegStr(STRING_1), HANDLE_2, RegStr(STRING_3));
}
jHANDLE AddSpellEffect(const char* STRING_1, jHANDLE  HANDLE_2, float   real_3, float   real_4)
{
    return jAddSpellEffect(RegStr(STRING_1), HANDLE_2, &real_3, &real_4);
}
jHANDLE AddSpellEffectLoc(const char* STRING_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    return jAddSpellEffectLoc(RegStr(STRING_1), HANDLE_2, HANDLE_3);
}
jHANDLE AddSpellEffectById(int      integer_1, jHANDLE  HANDLE_2, float   real_3, float   real_4)
{
    return jAddSpellEffectById(integer_1, HANDLE_2, &real_3, &real_4);
}
jHANDLE AddSpellEffectByIdLoc(int      integer_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3)
{
    return jAddSpellEffectByIdLoc(integer_1, HANDLE_2, HANDLE_3);
}
jHANDLE AddSpellEffectTarget(const char* STRING_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, const char* STRING_4)
{
    return jAddSpellEffectTarget(RegStr(STRING_1), HANDLE_2, HANDLE_3, RegStr(STRING_4));
}
jHANDLE AddSpellEffectTargetById(int      integer_1, jHANDLE  HANDLE_2, jHANDLE  HANDLE_3, const char* STRING_4)
{
    return jAddSpellEffectTargetById(integer_1, HANDLE_2, HANDLE_3, RegStr(STRING_4));
}
jHANDLE AddLightning(const char* STRING_1, bool     BOOL_2, float   real_3, float   real_4, float   real_5, float   real_6)
{
    return jAddLightning(RegStr(STRING_1), BOOL_2, &real_3, &real_4, &real_5, &real_6);
}
jHANDLE AddLightningEx(const char* STRING_1, bool     BOOL_2, float   real_3, float   real_4, float   real_5, float   real_6, float   real_7, float   real_8)
{
    return jAddLightningEx(RegStr(STRING_1), BOOL_2, &real_3, &real_4, &real_5, &real_6, &real_7, &real_8);
}
bool    DestroyLightning(jHANDLE  HANDLE_1)
{
    return jDestroyLightning(HANDLE_1);
}
float   GetLightningColorA(jHANDLE  HANDLE_1)
{
    int ret = (jGetLightningColorA(HANDLE_1));
    return *(float*)&ret;
}
float   GetLightningColorR(jHANDLE  HANDLE_1)
{
    int ret = (jGetLightningColorR(HANDLE_1));
    return *(float*)&ret;
}
float   GetLightningColorG(jHANDLE  HANDLE_1)
{
    int ret = (jGetLightningColorG(HANDLE_1));
    return *(float*)&ret;
}
float   GetLightningColorB(jHANDLE  HANDLE_1)
{
    int ret = (jGetLightningColorB(HANDLE_1));
    return *(float*)&ret;
}
bool    MoveLightning(jHANDLE  HANDLE_1, bool     BOOL_2, float   real_3, float   real_4, float   real_5, float   real_6)
{
    return jMoveLightning(HANDLE_1, BOOL_2, &real_3, &real_4, &real_5, &real_6);
}
bool    MoveLightningEx(jHANDLE  HANDLE_1, bool     BOOL_2, float   real_3, float   real_4, float   real_5, float   real_6, float   real_7, float   real_8)
{
    return jMoveLightningEx(HANDLE_1, BOOL_2, &real_3, &real_4, &real_5, &real_6, &real_7, &real_8);
}
bool    SetLightningColor(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4, float   real_5)
{
    return jSetLightningColor(HANDLE_1, &real_2, &real_3, &real_4, &real_5);
}
const char* GetAbilityEffect(const char* STRING_1, jHANDLE  HANDLE_2, int      integer_3)
{
    return (const char*)GetStringAddress(jGetAbilityEffect(RegStr(STRING_1), HANDLE_2, integer_3));
}
const char* GetAbilityEffectById(int      integer_1, jHANDLE  HANDLE_2, int      integer_3)
{
    return (const char*)GetStringAddress(jGetAbilityEffectById(integer_1, HANDLE_2, integer_3));
}
const char* GetAbilitySound(const char* STRING_1, jHANDLE  HANDLE_2)
{
    return (const char*)GetStringAddress(jGetAbilitySound(RegStr(STRING_1), HANDLE_2));
}
const char* GetAbilitySoundById(int      integer_1, jHANDLE  HANDLE_2)
{
    return (const char*)GetStringAddress(jGetAbilitySoundById(integer_1, HANDLE_2));
}
int     GetTerrainCliffLevel(float   real_1, float   real_2)
{
    return jGetTerrainCliffLevel(&real_1, &real_2);
}
void    SetWaterBaseColor(int      integer_1, int      integer_2, int      integer_3, int      integer_4)
{
    jSetWaterBaseColor(integer_1, integer_2, integer_3, integer_4);
}
void    SetWaterDeforms(bool     BOOL_1)
{
    jSetWaterDeforms(BOOL_1);
}
int     GetTerrainType(float   real_1, float   real_2)
{
    return jGetTerrainType(&real_1, &real_2);
}
int     GetTerrainVariance(float   real_1, float   real_2)
{
    return jGetTerrainVariance(&real_1, &real_2);
}
void    SetTerrainType(float   real_1, float   real_2, int      integer_3, int      integer_4, int      integer_5, int      integer_6)
{
    jSetTerrainType(&real_1, &real_2, integer_3, integer_4, integer_5, integer_6);
}
bool    IsTerrainPathable(float   real_1, float   real_2, jHANDLE  HANDLE_3)
{
    return jIsTerrainPathable(&real_1, &real_2, HANDLE_3);
}
void    SetTerrainPathable(float   real_1, float   real_2, jHANDLE  HANDLE_3, bool     BOOL_4)
{
    jSetTerrainPathable(&real_1, &real_2, HANDLE_3, BOOL_4);
}
jHANDLE CreateImage(const char* STRING_1, float   real_2, float   real_3, float   real_4, float   real_5, float   real_6, float   real_7, float   real_8, float   real_9, float   real_10, int      integer_11)
{
    return jCreateImage(RegStr(STRING_1), &real_2, &real_3, &real_4, &real_5, &real_6, &real_7, &real_8, &real_9, &real_10, integer_11);
}
void    DestroyImage(jHANDLE  HANDLE_1)
{
    jDestroyImage(HANDLE_1);
}
void    ShowImage(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jShowImage(HANDLE_1, BOOL_2);
}
void    SetImageConstantHeight(jHANDLE  HANDLE_1, bool     BOOL_2, float   real_3)
{
    jSetImageConstantHeight(HANDLE_1, BOOL_2, &real_3);
}
void    SetImagePosition(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4)
{
    jSetImagePosition(HANDLE_1, &real_2, &real_3, &real_4);
}
void    SetImageColor(jHANDLE  HANDLE_1, int      integer_2, int      integer_3, int      integer_4, int      integer_5)
{
    jSetImageColor(HANDLE_1, integer_2, integer_3, integer_4, integer_5);
}
void    SetImageRender(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetImageRender(HANDLE_1, BOOL_2);
}
void    SetImageRenderAlways(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetImageRenderAlways(HANDLE_1, BOOL_2);
}
void    SetImageAboveWater(jHANDLE  HANDLE_1, bool     BOOL_2, bool     BOOL_3)
{
    jSetImageAboveWater(HANDLE_1, BOOL_2, BOOL_3);
}
void    SetImageType(jHANDLE  HANDLE_1, int      integer_2)
{
    jSetImageType(HANDLE_1, integer_2);
}
jHANDLE CreateUbersplat(float   real_1, float   real_2, const char* STRING_3, int      integer_4, int      integer_5, int      integer_6, int      integer_7, bool     BOOL_8, bool     BOOL_9)
{
    return jCreateUbersplat(&real_1, &real_2, RegStr(STRING_3), integer_4, integer_5, integer_6, integer_7, BOOL_8, BOOL_9);
}
void    DestroyUbersplat(jHANDLE  HANDLE_1)
{
    jDestroyUbersplat(HANDLE_1);
}
void    ResetUbersplat(jHANDLE  HANDLE_1)
{
    jResetUbersplat(HANDLE_1);
}
void    FinishUbersplat(jHANDLE  HANDLE_1)
{
    jFinishUbersplat(HANDLE_1);
}
void    ShowUbersplat(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jShowUbersplat(HANDLE_1, BOOL_2);
}
void    SetUbersplatRender(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetUbersplatRender(HANDLE_1, BOOL_2);
}
void    SetUbersplatRenderAlways(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jSetUbersplatRenderAlways(HANDLE_1, BOOL_2);
}
void    SetBlight(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4, bool     BOOL_5)
{
    jSetBlight(HANDLE_1, &real_2, &real_3, &real_4, BOOL_5);
}
void    SetBlightLoc(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, float   real_3, bool     BOOL_4)
{
    jSetBlightLoc(HANDLE_1, HANDLE_2, &real_3, BOOL_4);
}
void    SetBlightRect(jHANDLE  HANDLE_1, jHANDLE  HANDLE_2, bool     BOOL_3)
{
    jSetBlightRect(HANDLE_1, HANDLE_2, BOOL_3);
}
void    SetBlightPoint(jHANDLE  HANDLE_1, float   real_2, float   real_3, bool     BOOL_4)
{
    jSetBlightPoint(HANDLE_1, &real_2, &real_3, BOOL_4);
}
jHANDLE CreateBlightedGoldmine(jHANDLE  HANDLE_1, float   real_2, float   real_3, float   real_4)
{
    return jCreateBlightedGoldmine(HANDLE_1, &real_2, &real_3, &real_4);
}
bool    IsPointBlighted(float   real_1, float   real_2)
{
    return jIsPointBlighted(&real_1, &real_2);
}
void    SetDoodadAnimation(float   real_1, float   real_2, float   real_3, int      integer_4, bool     BOOL_5, const char* STRING_6, bool     BOOL_7)
{
    jSetDoodadAnimation(&real_1, &real_2, &real_3, integer_4, BOOL_5, RegStr(STRING_6), BOOL_7);
}
void    SetDoodadAnimationRect(jHANDLE  HANDLE_1, int      integer_2, const char* STRING_3, bool     BOOL_4)
{
    jSetDoodadAnimationRect(HANDLE_1, integer_2, RegStr(STRING_3), BOOL_4);
}
void    StartMeleeAI(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jStartMeleeAI(HANDLE_1, RegStr(STRING_2));
}
void    StartCampaignAI(jHANDLE  HANDLE_1, const char* STRING_2)
{
    jStartCampaignAI(HANDLE_1, RegStr(STRING_2));
}
void    CommandAI(jHANDLE  HANDLE_1, int      integer_2, int      integer_3)
{
    jCommandAI(HANDLE_1, integer_2, integer_3);
}
void    PauseCompAI(jHANDLE  HANDLE_1, bool     BOOL_2)
{
    jPauseCompAI(HANDLE_1, BOOL_2);
}
jHANDLE GetAIDifficulty(jHANDLE  HANDLE_1)
{
    return jGetAIDifficulty(HANDLE_1);
}
void    RemoveGuardPosition(jHANDLE  HANDLE_1)
{
    jRemoveGuardPosition(HANDLE_1);
}
void    RecycleGuardPosition(jHANDLE  HANDLE_1)
{
    jRecycleGuardPosition(HANDLE_1);
}
void    RemoveAllGuardPositions(jHANDLE  HANDLE_1)
{
    jRemoveAllGuardPositions(HANDLE_1);
}
void    ExecuteFunc(const char* STRING_1)
{
    jExecuteFunc(RegStr(STRING_1));
}
void    Cheat(const char* STRING_1)
{
    jCheat(RegStr(STRING_1));
}
bool    IsNoVictoryCheat()
{
    return jIsNoVictoryCheat();
}
bool    IsNoDefeatCheat()
{
    return jIsNoDefeatCheat();
}
void    Preload(const char* STRING_1)
{
    jPreload(RegStr(STRING_1));
}
void    PreloadEnd(float   real_1)
{
    jPreloadEnd(&real_1);
}
void    PreloadStart()
{
    jPreloadStart();
}
void    PreloadRefresh()
{
    jPreloadRefresh();
}
void    PreloadEndEx()
{
    jPreloadEndEx();
}
void    PreloadGenStart()
{
    jPreloadGenStart();
}
void    PreloadGenClear()
{
    jPreloadGenClear();
}
void    PreloadGenEnd(const char* STRING_1)
{
    jPreloadGenEnd(RegStr(STRING_1));
}
void    Preloader(const char* STRING_1)
{
    jPreloader(RegStr(STRING_1));
}
