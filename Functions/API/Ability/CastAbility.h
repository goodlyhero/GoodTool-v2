#pragma once

#include <BasicConstants.h>

void CastAbilityPosition(int aid, jHANDLE source, float targX, float targY);

void CastAbilityTarget(DWORD aid, jHANDLE source, jHANDLE target);

void CastAbilityTargetGround(int aid, jHANDLE source, int lvl, float targX, float targY, bool remove);

void CastAbilityTargetWidget(int aid, jHANDLE source, jHANDLE target, int lvl, bool remove);

void CastAbilityTargetSelf(int aid, jHANDLE source, int lvl);
