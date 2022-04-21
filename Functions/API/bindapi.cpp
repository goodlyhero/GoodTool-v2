#include "LuaFunctions.h"
#include "LuaStates.h"
#include <luabinder.hpp>
#include <From MemHack.h>
#include <Calls.h>
#include <DmgEventData.h>
#include <../main.h>
#include <Logs/Log.h>
#include <MPQres.h>
#include <PrintDmg.h>
#include <Windows.h>
#include <lua/Events.h>
#include <States.h>
import UIHooks;
import CursorAPI;
import LuaApiFuncs;
import ClassInfoGame;
import RenderHook;
import JassLuaThreadInteraction;
import JassNamesMemory;
import APITimerEx;
import MemoryCNetData;
import HookOnTick;
//#include <iostream>
#define id(x) #x
#define FastBind(x) binder->def(id(x),x)
void bindapi(lua::TLua& Lua)
{
	lua_State* lua = Lua.lua;
	auto binder = Lua.binder;
	binder->def("GetAbilityBaseDataByAddress", GetAbilityBaseDataByAddress);
	binder->def("GetAddressAbilityTypeId", GetAddressAbilityBaseId);
	binder->def("GetAddressAbilityBaseId", GetAddressAbilityOrderId);
	binder->def("GetAddressAbilityOrderId", GetAddressAbilityOrderId);
	binder->def("IsAddressAbilityOnCooldown", IsAddressAbilityOnCooldown);
	binder->def("IsAddressAbilitySafe", IsAddressAbilitySafe);
	binder->def("IsAddressAbilityUsable", IsAddressAbilityUsable);
	binder->def("GetAddressAbilityCastpoint", GetAddressAbilityCastpoint);
	binder->def("SetAddressAbilityCastpoint", SetAddressAbilityCastpoint);
	binder->def("GetAddressAbilityBackswing", GetAddressAbilityBackswing);
	binder->def("SetAddressAbilityBackswing", SetAddressAbilityBackswing);
	binder->def("GetAddressAbilityManaCost", GetAddressAbilityManaCost);
	binder->def("SetAddressAbilityManaCost", SetAddressAbilityManaCost);
	binder->def("GetAddressAbilityCooldownStamp", GetAddressAbilityCooldownStamp);
	binder->def("GetAddressAbilityCurrentCooldown", GetAddressAbilityCurrentCooldown);
	binder->def("SetAddressAbilityCooldown", SetAddressAbilityCooldown);
	binder->def("StartAddressAbilityCooldown", StartAddressAbilityCooldown);
	binder->def("GetAddressAbilityCastTime", GetAddressAbilityCastTime);
	binder->def("SetAddressAbilityCastTime", SetAddressAbilityCastTime);
	binder->def("SetAddressAbilityDisabled", SetAddressAbilityDisabled);
	binder->def("GetAddressAbilityDisabled", GetAddressAbilityDisabled);
	binder->def("SetAddressAbilityHidden", SetAddressAbilityHidden);
	binder->def("AddAddressAbilityHidden", AddAddressAbilityHidden);
	binder->def("GetAddressAbilityDisabledEx", GetAddressAbilityDisabledEx);
	binder->def("SetAddressAbilityDisabledEx", SetAddressAbilityDisabledEx);
	binder->def("ShowAddressAbility", ShowAddressAbility);
	binder->def("SilenceAddressAbility", SilenceAddressAbility);
	binder->def("GetAbilityBaseDataById", GetAbilityBaseDataById);
	binder->def("GetAbilityBaseDataByIdCaching", GetAbilityBaseDataByIdCaching);
	binder->def("GetAbilityBaseUIById", GetAbilityBaseUIById);
	binder->def("GetAbilityBaseUICaching", GetAbilityBaseUICaching);
	binder->def("SetAbilityBaseHotkeyParam", SetAbilityBaseHotkeyParam);
	binder->def("GetAbilityBaseHotkeyParam", GetAbilityBaseHotkeyParam);
	binder->def("SetAbilityBaseIntegerParam", SetAbilityBaseIntegerParam);
	binder->def("GetAbilityBaseIntegerParam", GetAbilityBaseIntegerParam);
	binder->def("SetAbilityBaseRealParam", SetAbilityBaseRealParam);
	binder->def("GetAbilityBaseRealParam", GetAbilityBaseRealParam);
	binder->def("SetAbilityBaseBoolParam", SetAbilityBaseBoolParam);
	binder->def("GetAbilityBaseBoolParam", GetAbilityBaseBoolParam);
	binder->def("SetAbilityBaseStringParam", SetAbilityBaseStringParam);
	binder->def("GetAbilityBaseStringParam", GetAbilityBaseStringParam);
	binder->def("GetAbilityBaseStringParam2", GetAbilityBaseStringParam2);
	binder->def("SetAbilityBaseStringParam2", SetAbilityBaseStringParam2);
	binder->def("GetAbilityBaseMaxLevel", GetAbilityBaseMaxLevel);
	binder->def("GetAbilityBaseManaCost", GetAbilityBaseManaCost);
	binder->def("SetAbilityBaseManaCost", SetAbilityBaseManaCost);
	binder->def("GetAbilityBaseCooldown", GetAbilityBaseCooldown);
	binder->def("SetAbilityBaseCooldown", SetAbilityBaseCooldown);
	binder->def("GetAbilityBaseEffectSound", GetAbilityBaseEffectSound);
	binder->def("SetAbilityBaseEffectSound", SetAbilityBaseEffectSound);
	binder->def("GetAbilityBaseGlobalMessage", GetAbilityBaseGlobalMessage);
	binder->def("SetAbilityBaseGlobalMessage", SetAbilityBaseGlobalMessage);
	binder->def("GetAbilityBaseGlobalSound", GetAbilityBaseGlobalSound);
	binder->def("SetAbilityBaseGlobalSound", SetAbilityBaseGlobalSound);
	binder->def("GetAbilityBaseButtonX", GetAbilityBaseButtonX);
	binder->def("SetAbilityBaseButtonX", SetAbilityBaseButtonX);
	binder->def("GetAbilityBaseButtonY", GetAbilityBaseButtonY);
	binder->def("SetAbilityBaseButtonY", SetAbilityBaseButtonY);
	binder->def("GetAbilityBaseUnButtonX", GetAbilityBaseUnButtonX);
	binder->def("SetAbilityBaseUnButtonX", SetAbilityBaseUnButtonX);
	binder->def("GetAbilityBaseUnButtonY", GetAbilityBaseUnButtonY);
	binder->def("SetAbilityBaseUnButtonY", SetAbilityBaseUnButtonY);
	binder->def("GetAbilityBaseResearchButtonX", GetAbilityBaseResearchButtonX);
	binder->def("SetAbilityBaseResearchButtonX", SetAbilityBaseResearchButtonX);
	binder->def("GetAbilityBaseResearchButtonY", GetAbilityBaseResearchButtonY);
	binder->def("SetAbilityBaseResearchButtonY", SetAbilityBaseResearchButtonY);
	binder->def("GetAbilityBaseMissileSpeed", GetAbilityBaseMissileSpeed);
	binder->def("SetAbilityBaseMissileSpeed", SetAbilityBaseMissileSpeed);
	binder->def("GetAbilityBaseMissileArc", GetAbilityBaseMissileArc);
	binder->def("SetAbilityBaseMissileArc", SetAbilityBaseMissileArc);
	binder->def("IsAbilityMissileHoming", IsAbilityMissileHoming);
	binder->def("SetAbilityBaseMissileHoming", SetAbilityBaseMissileHoming);
	binder->def("GetAbilityBaseSpellDetails", GetAbilityBaseSpellDetails);
	binder->def("SetAbilityBaseSpellDetails", SetAbilityBaseSpellDetails);
	binder->def("GetAbilityBaseHotkeyId", GetAbilityBaseHotkeyId);
	binder->def("SetAbilityBaseHotkeyId", SetAbilityBaseHotkeyId);
	binder->def("GetAbilityBaseUnHotkeyId", GetAbilityBaseUnHotkeyId);
	binder->def("SetAbilityBaseUnHotkeyId", SetAbilityBaseUnHotkeyId);
	binder->def("GetAbilityBaseResearchHotkeyId", GetAbilityBaseResearchHotkeyId);
	binder->def("SetAbilityBaseResearchHotkeyId", SetAbilityBaseResearchHotkeyId);
	binder->def("GetAbilityBaseTip", GetAbilityBaseTip);
	binder->def("SetAbilityBaseTip", SetAbilityBaseTip);
	binder->def("GetAbilityBaseUbertip", GetAbilityBaseUbertip);
	binder->def("SetAbilityBaseUbertip", SetAbilityBaseUbertip);
	binder->def("SetAbilityBaseHotkeyCommon", SetAbilityBaseHotkeyCommon);
	binder->def("IsEffectHidden", IsEffectHidden);
	binder->def("ShowEffect", ShowEffect);
	binder->def("SetEffectAlpha", SetEffectAlpha);
	binder->def("GetEffectColour", GetEffectColour);
	binder->def("SetEffectColour", SetEffectColour);
	binder->def("SetEffectColourEx", SetEffectColourEx);
	binder->def("SetEffectVertexColour", SetEffectVertexColour);
	binder->def("GetEffectColourA", GetEffectColourA);
	binder->def("SetEffectColourA", SetEffectColourA);
	binder->def("GetEffectColourR", GetEffectColourR);
	binder->def("SetEffectColourR", SetEffectColourR);
	binder->def("GetEffectColourG", GetEffectColourG);
	binder->def("SetEffectColourG", SetEffectColourG);
	binder->def("GetEffectColourB", GetEffectColourB);
	binder->def("SetEffectColourB", SetEffectColourB);
	binder->def("SetEffectAnimationByIndex", SetEffectAnimationByIndex);
	binder->def("SetEffectModel", SetEffectModel);
	binder->def("GetEffectX", GetEffectX);
	binder->def("SetEffectX", SetEffectX);
	binder->def("GetEffectY", GetEffectY);
	binder->def("SetEffectY", SetEffectY);
	binder->def("GetEffectZ", GetEffectZ);
	binder->def("SetEffectZ", SetEffectZ);
	binder->def("SetEffectPosition", SetEffectPosition);
	binder->def("GetEffectTimeScale", GetEffectTimeScale);
	binder->def("SetEffectTimeScale", SetEffectTimeScale);
	binder->def("GetEffectScale", GetEffectScale);
	binder->def("SetEffectScale", SetEffectScale);
	binder->def("SetEffectScaleEx", SetEffectScaleEx);
	binder->def("SetEffectSpaceRotation", SetEffectSpaceRotation);
	binder->def("GetEffectRoll", GetEffectRoll);
	binder->def("SetEffectRoll", SetEffectRoll);
	binder->def("GetEffectPitch", GetEffectPitch);
	binder->def("SetEffectPitch", SetEffectPitch);
	binder->def("GetEffectFacing", GetEffectFacing);
	binder->def("SetEffectFacing", SetEffectFacing);
	binder->def("ResetEffectMatrix", ResetEffectMatrix);
	binder->def("IsTrackableHidden", IsTrackableHidden);
	binder->def("ShowTrackable", ShowTrackable);
	binder->def("SetTrackableAlpha", SetTrackableAlpha);
	binder->def("GetTrackableColour", GetTrackableColour);
	binder->def("SetTrackableColour", SetTrackableColour);
	binder->def("SetTrackableColourEx", SetTrackableColourEx);
	binder->def("SetTrackableVertexColour", SetTrackableVertexColour);
	binder->def("GetTrackableColourA", GetTrackableColourA);
	binder->def("GetTrackableColourR", GetTrackableColourR);
	binder->def("SetTrackableColourR", SetTrackableColourR);
	binder->def("GetTrackableColourG", GetTrackableColourG);
	binder->def("SetTrackableColourA", SetTrackableColourA);
	binder->def("SetTrackableColourG", SetTrackableColourG);
	binder->def("GetTrackableColourB", GetTrackableColourB);
	binder->def("SetTrackableColourB", SetTrackableColourB);
	binder->def("SetTrackableAnimationByIndex", SetTrackableAnimationByIndex);
	binder->def("SetTrackableModel", SetTrackableModel);
	binder->def("GetTrackableX", GetTrackableX);
	binder->def("SetTrackableX", SetTrackableX);
	binder->def("GetTrackableY", GetTrackableY);
	binder->def("SetTrackableY", SetTrackableY);
	binder->def("GetTrackableZ", GetTrackableZ);
	binder->def("SetTrackableZ", SetTrackableZ);
	binder->def("SetTrackablePosition", SetTrackablePosition);
	binder->def("GetTrackableTimeScale", GetTrackableTimeScale);
	binder->def("SetTrackableTimeScale", SetTrackableTimeScale);
	binder->def("GetTrackableScale", GetTrackableScale);
	binder->def("SetTrackableScale", SetTrackableScale);
	binder->def("SetTrackableScaleEx", SetTrackableScaleEx);
	binder->def("SetTrackableSpaceRotation", SetTrackableSpaceRotation);
	binder->def("GetTrackableRoll", GetTrackableRoll);
	binder->def("SetTrackableRoll", SetTrackableRoll);
	binder->def("GetTrackablePitch", GetTrackablePitch);
	binder->def("SetTrackablePitch", SetTrackablePitch);
	binder->def("GetTrackableFacing", GetTrackableFacing);
	binder->def("SetTrackableFacing", SetTrackableFacing);
	binder->def("ResetTrackableMatrix", ResetTrackableMatrix);
	FastBind(GetTerrainZ);
	FastBind(GetWidgetTerrainZ);
	FastBind(SetWidgetCoordinates);
	FastBind(SetWidgetPosition);
	FastBind(SetDestructablePosition);
	FastBind(LoadCBackDropFrameTexture);
	FastBind(SetCBackDropFrameTexture);
	FastBind(SetCEditBoxFocus);
	FastBind(SetCEditBoxFont);
	FastBind(GetCEditBoxText);
	FastBind(SetCEditBoxText);
	FastBind(LoadTOCFile);

	FastBind(GetCFrameByName);

	FastBind(CreateCFrameEx);

	FastBind(CreateCFrame);

	FastBind(GetFrameLayoutByType);

	FastBind(GetFrameLayout);

	FastBind(IsFrameLayoutByType);

	FastBind(IsFrameLayout);
	FastBind(FindCLayerUnderCursorEx);

	FastBind(FindCLayerUnderCursor);

	FastBind(SetCLayerOwner);

	FastBind(HideCLayer);

	FastBind(ShowCLayer);

	FastBind(SetCLayerAlpha);

	FastBind(SetCLayerFont);

	FastBind(SetCLayerTooltip);

	FastBind(SetCLayoutFrameAbsolutePoint);

	FastBind(SetCLayoutFrameCageMouse);

	FastBind(ClearCLayoutFrameAllPoints);

	FastBind(SetCLayoutFrameWidth);

	FastBind(SetCLayoutFrameHeight);

	FastBind(SetCLayoutFrameAllPoints);
	FastBind(SetCLayoutFrameSize);

	FastBind(SetCLayoutFramePoint);
	FastBind(SetCLayoutFrameScale);

	FastBind(GetCLayoutFrameHeight);
	FastBind(AddCModelFrameModel);
	FastBind(GetCModelFrameHeight);

	FastBind(CreateCSimpleButton);
	FastBind(DestroyCSimpleButton);
	FastBind(SetCSimpleButtonStateTexture);
	FastBind(SetCSimpleButtonState);
	FastBind(CreateCSimpleFont);
	FastBind(GetCSimpleFontByName);
	FastBind(GetCSimpleFontTextByName);
	FastBind(SetCSimpleFontStringScale);
	FastBind(SetCSimpleFontStringFont);
	FastBind(GetCSimpleFontStringHeight);
	FastBind(SetCSimpleFontText);
	FastBind(CreateCSimpleFrame);
	FastBind(CreateCSimpleConsole);
	FastBind(GetCSimpleFrameByName);
	FastBind(SetCSimpleFrameScale);
	FastBind(SetCSimpleFramePriority);
	FastBind(SetCSimpleFrameParent);

	FastBind(SetCSimpleGlueFrameScale);

	FastBind(SetCSimpleMessageFrameFont);

	FastBind(SetCSimpleRegionVertexColour);
	FastBind(SetCSimpleRegionVertexColourEx);

	FastBind(SetCSimpleStatusBarTexture);

	FastBind(SetCSimpleStatusBarValue);

	FastBind(SetCSimpleStatusBarMinMaxValue);

	FastBind(CreateCSimpleTexture);

	FastBind(FillCSimpleTexture);

	FastBind(GetCSimpleTextureByName);

	FastBind(SetCSimpleTextureTexture);

	FastBind(SetCSliderCurrentValue);

	FastBind(SetCSpriteFrameArt);

	FastBind(GetCSpriteFrameHeight);

	FastBind(SetCSpriteFrameScale);

	FastBind(SetCStatusBarArt);

	FastBind(SetCStatusBarValue);

	FastBind(SetCStatusBarMinMaxValue);
	FastBind(SetCTextAreaText);

	FastBind(SetCTextFrameTextColour);

	FastBind(SetCTextFrameTextColourEx);

	FastBind(GetCTextFrameHeight);

	FastBind(SetCTextFrameText);
	FastBind(GetFrameByName);

	FastBind(CreateFrameEx);

	FastBind(CreateFrame);

	FastBind(CreateSimpleFrame);

	FastBind(GetUnitFramePosition);

	FastBind(HideFrame);

	FastBind(ShowFrame);

	FastBind(SetFrameAlpha);

	FastBind(SetLayerFont);

	FastBind(SetFrameTooltip);

	FastBind(SetFrameFocus);

	FastBind(SetFrameCageMouse);

	FastBind(SetFrameAbsolutePoint);

	FastBind(SetFramePoint);

	FastBind(ClearFrameAllPoints);

	FastBind(SetFrameWidth);

	FastBind(SetFrameHeight);

	FastBind(SetFrameAllPoints);

	FastBind(SetFrameSize);

	FastBind(SetLayoutFrameScale);

	FastBind(SetFrameVertexColour);

	FastBind(SetFrameVertexColourEx);

	FastBind(GetFrameSkinByName);

	FastBind(DestroyFrame);

	FastBind(GetFrameState);

	FastBind(IsFrameEnabled);

	FastBind(SetFrameState);
	FastBind(EnableFrame);

	FastBind(DisableFrame);

	FastBind(GetFrameTextByName);

	FastBind(SetFrameTextColour);

	FastBind(SetFrameTextColourEx);

	FastBind(FindLayerUnderCursor);

	FastBind(ClickFrame);

	FastBind(SetFrameModel);

	FastBind(GetFrameAlpha);

	FastBind(UpdateFrame);

	FastBind(SetFrameStepValue);

	FastBind(GetFrameParent);

	FastBind(SetFrameParent);

	FastBind(GetFrameName);

	FastBind(SetFrameTexture);

	FastBind(SetFrameScale);

	FastBind(GetFrameValue);

	FastBind(SetFrameValue);

	FastBind(SetFrameMinMaxValue);

	FastBind(SetFrameFont);

	FastBind(GetFrameWidth);

	FastBind(GetFrameHeight);

	FastBind(GetFramePoint);

	FastBind(GetFramePointParent);

	FastBind(GetFramePointRelativePoint);

	FastBind(GetFramePointX);

	FastBind(GetFramePointY);

	FastBind(GetFrameTextMaxLength);

	FastBind(SetFrameMaxTextLength);

	FastBind(GetFrameTextLength);

	FastBind(GetFrameText);

	FastBind(SetFrameText);

	FastBind(IsReplay);

	FastBind(SetAllyCheckbox);

	FastBind(EnableAllyCheckbox);

	FastBind(DisableAllyCheckbox);

	FastBind(DisableSaveGameMenu);


	FastBind(GetItemBaseDataById);
	FastBind(GetItemBaseData);
	FastBind(GetItemBaseDataByIdCaching);
	FastBind(GetItemBaseDataCaching);
	FastBind(GetItemBaseTypeIdById);
	FastBind(GetItemBaseTypeId);
	FastBind(GetItemBaseGoldCostById);
	FastBind(GetItemBaseGoldCost);
	FastBind(SetItemBaseGoldCostById);
	FastBind(SetItemBaseGoldCost);
	FastBind(GetItemBaseLumberCostById);
	FastBind(GetItemBaseLumberCost);
	FastBind(SetItemBaseLumberCostById);
	FastBind(SetItemBaseLumberCost);
	FastBind(GetItemBaseLevelById);
	FastBind(GetItemBaseLevel);
	FastBind(SetItemBaseLevelById);
	FastBind(SetItemBaseLevel);
	FastBind(IsItemBaseSellableById);
	FastBind(IsItemBaseSellable);
	FastBind(IsItemBasePawnableById);
	FastBind(IsItemBasePawnable);
	FastBind(IsItemBaseDroppableById);
	FastBind(IsItemBaseDroppable);
	FastBind(IsItemBaseDroppedOnDeathById);
	FastBind(IsItemBaseDroppedOnDeath);

	FastBind(StartAddressItemCooldown);

	FastBind(SetAddressItemIdType);

	FastBind(SetAddressItemModel);

	FastBind(GetAddressItemLife);

	FastBind(SetAddressItemLife);

	FastBind(GetAddressItemMaxLife);

	FastBind(SetAddressItemMaxLife);

	FastBind(StartItemCooldown);

	FastBind(SetItemIdType);

	FastBind(SetItemModel);

	FastBind(GetItemLife);

	FastBind(SetItemLife);

	FastBind(GetItemMaxLife);

	FastBind(SetItemMaxLife);
	FastBind(WriteNullTerminatedString);
	FastBind(SearchStringValueAddress);
	FastBind(SearchStringValue);
	FastBind(ReplaceStringValue);

	FastBind(ConvertHandleId);
	FastBind(ConvertHandle);
	FastBind(HandleIdToObject);
	FastBind(ObjectToHandleId);
	FastBind(GetJassVM);
	FastBind(GetJassTable);
	FastBind(GetStringAddress);
	FastBind(GetString);


	FastBind(GetAgentType);
	FastBind(ObjectToAbility);
	FastBind(ObjectToUnit);
	FastBind(GetAgentBaseDataById);
	FastBind(GetUnitAddressFloatsRelated);
	FastBind(GetUnitAddress);
	FastBind(GetSomeAddress);
	FastBind(GetSomeAddressForAbility);

	FastBind(GetGameUI);

	FastBind(GetRootFrame);

	FastBind(GetUIWorldFrameWar3);

	FastBind(GetUIMinimap);

	FastBind(GetUIInfoBar);

	FastBind(GetUICommandBar);

	FastBind(GetUIResourceBarFrame);

	FastBind(GetUIUpperButtonBarFrame);

	FastBind(GetUIUnknown1);

	FastBind(GetUIClickableBlock);

	FastBind(GetUIHeroBar);

	FastBind(GetUIPeonBar);

	FastBind(GetUIMessage);

	FastBind(GetUIUnitMessage);

	FastBind(GetUIChatMessage);

	FastBind(GetUITopMessage);

	FastBind(GetUIPortrait);

	FastBind(GetUITimeOfDayIndicator);

	FastBind(GetUIChatEditBar);

	FastBind(GetUICinematicPanel);

	FastBind(GetUIUnknown2);

	FastBind(GetUIMinimapButton1);

	FastBind(GetUIMinimapButton2);

	FastBind(GetUIMinimapButton3);

	FastBind(GetUIMinimapButton4);

	FastBind(GetUIMinimapButton5);

	FastBind(GetUIFrameB);

	FastBind(GetUIMouseBorders);

	FastBind(GetUIFrameA);

	FastBind(GetUISimpleConsole);

	FastBind(GetPanelButton);

	FastBind(GetMinimapButton);

	FastBind(GetUpperButtonBarButton);

	FastBind(GetCommandBarButton);

	FastBind(GetSkillBarButton);

	FastBind(GetItemBarButton);

	FastBind(GetHeroBarButton);

	FastBind(GetHeroBarHealthBar);

	FastBind(GetHeroBarManaBar);

	FastBind(UpdateGameUI);

	FastBind(GetFrameType);

	FastBind(SetWar3MapMap);

	FastBind(IsCommandButton);

	FastBind(GetButtonData);

	FastBind(GetButtonGoldCost);

	FastBind(GetButtonLumberCost);

	FastBind(GetButtonManaCost);

	FastBind(GetButtonCooldown);

	FastBind(IsButtonOnCooldown);

	FastBind(AddFrameType);


	FastBind(GetWindowWidth);

	FastBind(GetWindowHeight);
	FastBind(GetWindowX);

	FastBind(GetWindowY);
	FastBind(GetWindowCenterX);

	FastBind(GetWindowCenterY);

	FastBind(GetWarcraftWindow);

	FastBind(FromPixelX);

	FastBind(FromPixelY);


	FastBind(GetFileSizeFromMPQ);
	FastBind(ExportFileFromMPQ);
	FastBind(LoadDllFromMPQ);


	FastBind(GetARGBColour);
	FastBind(GetSpriteDataOffsetAddressR);
	FastBind(SetSpriteDataOffsetAddressR);
	FastBind(IsObjectHidden);
	FastBind(ShowObject);
	FastBind(GetObjectTypeId);
	FastBind(UpdateObjectColour);
	FastBind(SetObjectAlpha);
	FastBind(GetObjectColour);
	FastBind(SetObjectColour);
	FastBind(SetObjectColourEx);
	FastBind(SetObjectVertexColour);
	FastBind(GetObjectColourA);
	FastBind(SetObjectColourA);
	FastBind(GetObjectColourR);
	FastBind(SetObjectColourR);
	FastBind(GetObjectColourG);
	FastBind(SetObjectColourG);
	FastBind(GetObjectColourB);
	FastBind(SetObjectColourB);
	FastBind(SetObjectAnimationByIndex);
	FastBind(SetObjectModel);
	FastBind(GetObjectX);
	FastBind(SetObjectX);
	FastBind(GetObjectY);
	FastBind(SetObjectY);
	FastBind(GetObjectZ);
	FastBind(SetObjectZ);
	FastBind(SetObjectPosition);
	FastBind(GetObjectTimeScale);
	FastBind(SetObjectTimeScale);
	FastBind(GetObjectScale);
	FastBind(SetObjectScale);
	FastBind(SetObjectScaleEx);
	FastBind(SetObjectSpaceRotation);
	FastBind(GetObjectRoll);
	FastBind(SetObjectRoll);
	FastBind(GetObjectPitch);
	FastBind(SetObjectPitch);
	FastBind(GetObjectFacing);
	FastBind(SetObjectFacing);
	FastBind(ResetObjectMatrix);

	FastBind(StormAllocateMemory);
	FastBind(StormFreeMemory);
	FastBind(StormGetMemorySize);
	FastBind(StormReallocateMemory);

	FastBind(GetUnitBaseDataById);
	FastBind(GetUnitBaseData);
	FastBind(GetUnitBaseDataByIdCaching);
	FastBind(GetUnitBaseDataCaching);
	FastBind(GetUnitBaseUIDataById);
	FastBind(GetUnitBaseUIData);
	FastBind(GetUnitBaseUIDataByIdCaching);
	FastBind(GetUnitBaseUIDataCaching);
	FastBind(GetUnitBaseUIIntegerParam);
	FastBind(SetUnitBaseUIIntegerParam);
	FastBind(GetUnitBaseUIStringParam);
	FastBind(SetUnitBaseUIStringParam);
	FastBind(GetUnitBasePortraitById);
	FastBind(SetUnitBasePortraitById);
	FastBind(GetUnitBaseMissileArtById);
	FastBind(SetUnitBaseMissileArtById);
	FastBind(GetUnitBaseMissileSpeedById);
	FastBind(SetUnitBaseMissileSpeedById);
	FastBind(GetUnitBaseColorById);
	FastBind(GetUnitBaseModelById);
	FastBind(SetUnitBaseModelById);
	FastBind(GetUnitBaseTipById);
	FastBind(SetUnitBaseTipById);
	FastBind(GetUnitBaseUbertipById);
	FastBind(SetUnitBaseUbertipById);
	FastBind(GetUnitBaseHotkeyById);
	FastBind(SetUnitBaseHotkeyById);
	FastBind(GetUnitBaseModel);
	FastBind(SetUnitBaseModel);
	FastBind(GetUnitBasePortrait);
	FastBind(SetUnitBasePortrait);
	FastBind(GetUnitBaseMissileArt);
	FastBind(SetUnitBaseMissileArt);
	FastBind(GetUnitBaseMissileSpeed);
	FastBind(SetUnitBaseMissileSpeed);
	FastBind(GetUnitBaseColor);
	FastBind(GetUnitBaseTip);
	FastBind(SetUnitBaseTip);
	FastBind(GetUnitBaseUbertip);
	FastBind(SetUnitBaseUbertip);
	FastBind(GetUnitBaseHotkey);
	FastBind(SetUnitBaseHotkey);
	FastBind(GetHeroBasePrimaryAttributeById);
	FastBind(SetHeroBasePrimaryAttributeById);
	FastBind(GetHeroBasePrimaryAttribute);
	FastBind(SetHeroBasePrimaryAttribute);

	FastBind(GetUnitTypeIdReal);
	FastBind(SetUnitTypeId);
	FastBind(MorphUnitToTypeId);
	FastBind(GetHeroNeededXPForLevel);
	FastBind(GetHeroNeededXP);
	FastBind(GetUnitVertexColour);
	FastBind(GetUnitVertexColourA);
	FastBind(GetUnitVertexColourR);
	FastBind(GetUnitVertexColourG);
	FastBind(GetUnitVertexColourB);
	FastBind(SetUnitModel);
	FastBind(SetUnitTexture);
	FastBind(GetUnitImpactZ);
	FastBind(SetUnitImpactZ);
	FastBind(RedrawUnit);
	FastBind(IsAttackDisabled);
	FastBind(UnitDisableAttack);
	FastBind(UnitEnableAttack);
	FastBind(GetUnitCritterFlag);
	FastBind(SetUnitCritterFlag);
	FastBind(GetUnitTimedLife);
	FastBind(SetUnitTimedLife);
	FastBind(SetUnitPhased);
	FastBind(UnitApplySilence);
	FastBind(UnitDisableAbilities);
	FastBind(UnitSetStunFlag);
	FastBind(IsUnitStunned);
	FastBind(UnitApplyStun);
	FastBind(IsUnitMovementDisabled);
	FastBind(SetUnitControl);
	FastBind(UnitDisableControl);
	FastBind(UnitEnableControl);
	FastBind(UnitRemoveMovementDisables);
	FastBind(SetUnitMovement);
	FastBind(UnitEnableMovement);
	FastBind(UnitDisableMovement);
	FastBind(UnitDisableMovementEx);
	FastBind(IsUnitInventoryDisabled);
	FastBind(UnitEnableInventory);
	FastBind(GetAddressLocustFlags);
	FastBind(SetLocustFlags);
	FastBind(UnitEnableTruesightImmunity);
	FastBind(UnitDisableTruesightImmunity);
	FastBind(GetUnitFlags);
	FastBind(SetUnitFlags);
	FastBind(AddUnitFlags);
	FastBind(GetUnitFlags_2);
	FastBind(SetUnitFlags_2);
	FastBind(AddUnitFlags_2);
	FastBind(GetUnitVisibilityClass);
	FastBind(SetUnitVisibleByPlayer);
	FastBind(IsUnitInvulnerable);
	FastBind(GetUnitInvulnerableCounter);
	FastBind(SetUnitInvulnerableCounter);
	FastBind(ModifyInvulnerableCounter);
	FastBind(IsUnitInvulnerable2);
	FastBind(SetUnitFacingInstant);
	FastBind(GetUnitMoveType);
	FastBind(SetUnitMoveType);
	FastBind(GetHeroPrimaryAttribute);
	FastBind(SetHeroPrimaryAttribute);
	FastBind(GetUnitAttackAbility);
	FastBind(SetUnitAttackAbility);
	FastBind(GetUnitAttackOffsetValue);
	FastBind(GetUnitNextAttackTimestamp);
	FastBind(UnitResetAttackCooldown);
	FastBind(UnitNullifyCurrentAttack);
	FastBind(AddUnitExtraAttack);
	FastBind(GetUnitAttackTypeByIndex);
	FastBind(GetUnitAttackType1);
	FastBind(GetUnitAttackType2);
	FastBind(SetUnitAttackOffsetValue);
	FastBind(SetUnitAttackTypeByIndex);
	FastBind(SetUnitAttackType1);
	FastBind(SetUnitAttackType2);
	FastBind(GetUnitWeaponSound);
	FastBind(SetUnitWeaponSound);
	FastBind(GetUnitWeaponType);
	FastBind(SetUnitWeaponType);
	FastBind(GetUnitBaseDamage);
	FastBind(SetUnitBaseDamage);
	FastBind(AddUnitBaseDamage);
	FastBind(GetUnitBonusDamage);
	FastBind(SetUnitBonusDamage);
	FastBind(AddUnitBonusDamage);
	FastBind(GetUnitTotalDamage);
	FastBind(GetUnitBaseAttributeDamage);
	FastBind(SetUnitBaseAttributeDamage);
	FastBind(GetUnitDamageDicesSideCount);
	FastBind(SetUnitDamageDicesSideCount);
	FastBind(GetUnitDamageDicesCount);
	FastBind(SetUnitDamageDicesCount);
	FastBind(GetUnitAttackRangeByIndex);
	FastBind(SetUnitAttackRangeByIndex);
	FastBind(GetUnitAttackRange1);
	FastBind(SetUnitAttackRange1);
	FastBind(GetUnitAttackRange2);
	FastBind(SetUnitAttackRange2);
	FastBind(GetUnitBATByIndex);
	FastBind(SetUnitBATByIndex);
	FastBind(GetUnitBAT1);
	FastBind(SetUnitBAT1);
	FastBind(GetUnitBAT2);
	FastBind(SetUnitBAT2);
	FastBind(GetUnitAttackPointByIndex);
	FastBind(SetUnitAttackPointByIndex);
	FastBind(GetUnitAttackPoint1);
	FastBind(SetUnitAttackPoint1);
	FastBind(GetUnitAttackPoint2);
	FastBind(SetUnitAttackPoint2);
	FastBind(GetUnitAttackEnabledIndex);
	FastBind(GetUnitAttackBackswing);
	FastBind(SetUnitAttackBackswing);
	FastBind(GetUnitAttackSpeed);
	FastBind(SetUnitAttackSpeed);
	FastBind(AddUnitAttackSpeed);
	FastBind(GetUnitAttackDamage);
	FastBind(GetUnitArmourType);
	FastBind(SetUnitArmourType);
	FastBind(GetUnitArmour);
	FastBind(SetUnitArmour);
	FastBind(AddUnitArmour);
	FastBind(GetUnitTimeScale);
	FastBind(GetUnitBaseMoveSpeed);
	FastBind(GetUnitBonusMoveSpeed);
	FastBind(SetUnitBonusMoveSpeed);
	FastBind(AddUnitBonusMovespeed);
	FastBind(SetUnitMaxLife);
	FastBind(AddUnitMaxLife);
	FastBind(SetUnitMaxMana);
	FastBind(AddUnitMaxMana);
	FastBind(GetWidgetLifeRegen);
	FastBind(GetUnitLifeRegen);
	FastBind(SetUnitLifeRegen);
	FastBind(AddUnitLifeRegen);
	FastBind(GetUnitManaRegen);
	FastBind(SetUnitManaRegen);
	FastBind(AddUnitManaRegen);

	FastBind(GetAddressGroupUnitCount);
	FastBind(GetAddressGroupAddressUnitByIndex);
	FastBind(GetGroupUnitCount);
	FastBind(GetUnitFromGroupByIndex);
	FastBind(GetRandomUnitFromGroup);
	FastBind(ForEach);


	FastBind(GetLocalPlayerIdReal);
	FastBind(GetLocalPlayerReal);
	FastBind(GetLocalSelectedRealUnit);

	FastBind(SetUIFramePoint);

	FastBind(HideUI);

	FastBind(ShowUI);

	FastBind(EditBlackBorders);

	FastBind(HideBlackBorders);

	FastBind(ShowBlackBorders);

	FastBind(EditMiniMap);

	FastBind(HideMiniMap);

	FastBind(ShowMiniMap);

	FastBind(EditCommandBarButton);

	FastBind(EditItemBarButton);

	FastBind(EditMinimapButton);

	FastBind(EditUpperButtonBarButton);

	FastBind(EditHeroBarButton);

	FastBind(EditHeroBarHealthBar);

	FastBind(EditHeroBarManaBar);

	FastBind(EditTooltip);

	FastBind(ShowAllUI);

	FastBind(HideAllUI);
	FastBind(CastAbilityPosition);

	FastBind(CastAbilityTarget);

	FastBind(CastAbilityTargetGround);

	FastBind(CastAbilityTargetWidget);

	FastBind(CastAbilityTargetSelf);


	FastBind(GetUnitAbilityReal);

	FastBind(GetUnitAbilityData);

	FastBind(GetUnitAbility);

	FastBind(GetUnitAbilityBase);

	FastBind(GetUnitAbilityOrderId);

	FastBind(IsUnitAbilityOnCooldown);

	FastBind(IsUnitAbilitySafe);

	FastBind(IsUnitAbilityUsable);

	FastBind(GetUnitAbilityCastpoint);

	FastBind(SetUnitAbilityCastpoint);

	FastBind(GetUnitAbilityBackswing);

	FastBind(SetUnitAbilityBackswing);

	FastBind(GetUnitAbilityManaCost);

	FastBind(SetUnitAbilityManaCost);

	FastBind(GetUnitAbilityCooldownStamp);

	FastBind(GetUnitAbilityCurrentCooldown);

	FastBind(SetUnitAbilityCooldown);

	FastBind(AddUnitAbilityCooldown);

	FastBind(ReduceUnitAbilityCooldown);

	FastBind(ResetUnitAbilityCooldown);

	FastBind(StartUnitAbilityCooldown);

	FastBind(GetUnitAbilityCastTime);

	FastBind(SetUnitAbilityCastTime);

	FastBind(SetUnitAbilityDisabled);

	FastBind(GetUnitAbilityDisabled);

	FastBind(SetUnitAbilityHidden);

	FastBind(AddUnitAbilityHidden);

	FastBind(GetUnitAbilityDisabledEx);

	FastBind(SetUnitAbilityDisabledEx);

	FastBind(SilenceUnitAbility);

	FastBind(UnsilenceUnitAbility);

	FastBind(ShowUnitAbility);


	FastBind(GetAbilityBaseUI);

	FastBind(GetAbilityBaseId);

	FastBind(GetAbilityOrderId);

	FastBind(IsAbilityOnCooldown);

	FastBind(IsAbilitySafe);

	FastBind(IsAbilityUsable);

	FastBind(GetAbilityCastpoint);

	FastBind(SetAbilityCastpoint);

	FastBind(GetAbilityBackswing);

	FastBind(SetAbilityBackswing);

	FastBind(GetAbilityManaCost);

	FastBind(SetAbilityManaCost);

	FastBind(GetAbilityCooldownStamp);

	FastBind(GetAbilityCurrentCooldown);

	FastBind(SetAbilityCooldown);

	FastBind(AddAbilityCooldown);

	FastBind(ReduceAbilityCooldown);

	FastBind(ResetAbilityCooldown);

	FastBind(StartAbilityCooldown);

	FastBind(GetAbilityCastTime);

	FastBind(SetAbilityCastTime);

	FastBind(SetAbilityDisabled);

	FastBind(GetAbilityDisabled);

	FastBind(SetAbilityHidden);

	FastBind(AddAbilityHidden);

	FastBind(GetAbilityDisabledEx);

	FastBind(SetAbilityDisabledEx);

	FastBind(SilenceAbility);

	FastBind(UnsilenceAbility);

	FastBind(ShowAbility);

	FastBind(SetSource);
	FastBind(GetSource);
	FastBind(SetTarget);
	FastBind(GetTarget);
	FastBind(SetSourceHandle);
	FastBind(GetSourceHandle);
	FastBind(SetTargetHandle);
	FastBind(SetTargetHandle);
	FastBind(GetTargetHandle);
	FastBind(SetDmgType);
	FastBind(GetDmgType);
	FastBind(SetAtkType);
	FastBind(GetAtkType);
	FastBind(SetDmg);
	FastBind(GetDmg);
	FastBind(SetFlags);
	FastBind(GetFlags);

	FastBind(StormLoadMPQ);
	FastBind(GetMPQLoadResult);

	FastBind(DetachPreparations);

	FastBind(Nodesync);

	FastBind(DownloadFile);
	binder->def("CreateDir", CreateFolder);
	binder->def("FileExists", FileExistsC);
	FastBind(DirExists);
	FastBind(StormLoadMPQTemp);
	FastBind(CMessageBox);
	FastBind(CMessageBoxAbort);
	FastBind(LuaDoFileFromMPQ);
	FastBind(StormLoadMPQTempR);
	FastBind(StormLoadMPQ);
	FastBind(StormOpenFileAsArchive);
	FastBind(StormOpenFile);
	FastBind(MouseDownInstant);
	FastBind(MouseUpInstant);
	FastBind(MouseClickInstant);
	FastBind(StormGetFileSize);
	FastBind(StormCloseFile);
	FastBind(StormReadFile);
	FastBind(StormGetFileAsString);
	FastBind(PrintDmgMode);
	FastBind(StormDownloadFileWithResources);
	FastBind(RemoveDir);
	FastBind(RemoveFile);
	FastBind(SetWc3Top);
	FastBind(urlhash);
	FastBind(GetWidgetUnderCursor);
	FastBind(SetMaxFps);
	FastBind(InitD3DVSync);
	//FastBind(WGLExtensionSupported);
	//FastBind(EnableVsync);
	FastBind(InitThreadCpuUsage);
	FastBind(GetWar3CpuUsage);
	FastBind(UpdateFPS);
	FastBind(IsChatBoxOpen);
	FastBind(EnableAutoFPSlimit);
	FastBind(GetWidgetUnderCursor);
	FastBind(ToUpper);
	FastBind(_StrToVKey);
	FastBind(_VKeyToStr);
	FastBind(CovertKeyCodeToString);
	FastBind(CovertStringToKeyCode);
	FastBind(ConvertKeyStringToKeyCode);
	FastBind(IsKeyPressed);
	FastBind(GetWidgetUnderCursor);
	FastBind(HookKeyboard);
	FastBind(UpdateMouseLock);
	//binder->def("LLuaDoCString",lua::LocalLuaDoCString);
	binder->def("GetCurrentProcessId", GetCurrentProcessIdA);
	binder->def("GetModueHandle", LGetModueHandle);
	binder->def("LoadLibrary", LLoadLibrary);
	binder->def("GetModuleProcAddress", LGetModuleProcAddress);
	binder->def("GetModuleProcAddressS", LGetModuleProcAddressS);
	binder->def("IsInGame", IsInGame);
	binder->def("RegStr", RegisterStr);
	FastBind(IsSelectMode);
	FastBind(GetCurrentCursor);
	FastBind(GetCurrentCursorOrder);
	FastBind(SetCurrentCursorOrder);
	FastBind(CancelCurrentMode);
	FastBind(HookSpeedText);
	FastBind(GetAddressAbilityOwner);
	FastBind(ToRCString);
	FastBind(RealUnitAddAbilityEx);
	FastBind(RealUnitAddAbility2);
	FastBind(UnitAddAbility2);
	FastBind(RefindGameWindow);
	FastBind(GetFlagsFromVTable);
	FastBind(GetVTableFromName);
	FastBind(GetIdFromVtable);
	FastBind(GetNameFromVTable);
	FastBind(GetVTableFromId);
	FastBind(GetNameFromId);
	FastBind(GetIdFromName);
	FastBind(GetFlagsFromId);
	FastBind(IsPtrOk);
	FastBind(HookRender);
	FastBind(RenderStageEnable);
	FastBind(GetStageMode);
	FastBind(FindJassNameHandle);
	FastBind(FindJFuncByName);
	FastBind(GetJassNameById);
	FastBind(DRegisterFunction);
	FastBind(GetJassNamesCnt);
	FastBind(GetJassNameById);
	FastBind(TimerExGetTimeElapsed);
	FastBind(AnyTimerGetTimeElapsed);
	FastBind(ConvertJString);
	FastBind(GetEngineDataPointersWithId);
	FastBind(GetCNetData);
	FastBind(GetIdleTurnIdFromSyncData);
	FastBind(GetTurnIdFromSyncData);
	FastBind(HookOnTick);
	FastBind(SetGameSpeedMultiplier);
	FastBind(SetGameSpeedDivider);
	FastBind(GetGameSpeedMultiplier);
	FastBind(GetGameSpeedDivider);
	lua_setglobalfunction(lua, lua::GetAllUnitAbilitiesIterator, "UnitAbilities");

	//FastBind(HookJassRun);
}