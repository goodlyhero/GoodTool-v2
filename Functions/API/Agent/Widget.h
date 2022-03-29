#pragma once

float GetTerrainZ(float axisX, float axisY);
float GetWidgetTerrainZ(jHANDLE Widget);
int SetWidgetCoordinates(jHANDLE Widget, float x, float y);
int SetWidgetPosition(jHANDLE Widget, float x, float y);
int SetDestructablePosition(jHANDLE dest, float x, float y);