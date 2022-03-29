#pragma once

int SetUIFramePoint(int pFrame, int point, int pParentFrame, int relativePoint, float x, float y);

void HideUI(void);

void ShowUI(void);

void EditBlackBorders(float topX, float topY, float botX, float botY);

void HideBlackBorders(void);

void ShowBlackBorders(void);

void EditMiniMap(int point, float topX, float topY, float botX, float botY);

void HideMiniMap(void);

void ShowMiniMap(void);

void EditCommandBarButton(int row, int column, int anchor, float offsetX, float offsetY, float width, float height);

void EditItemBarButton(int buttonId, int anchor, float offsetX, float offsetY, float width, float height);

void EditMinimapButton(int buttonId, int anchor, float offsetX, float offsetY, float width, float height);

void EditUpperButtonBarButton(int buttonId, int anchor, float offsetX, float offsetY, float width, float height);

void EditHeroBarButton(int buttonId, int anchor, float offsetX, float offsetY, float width, float height);

void EditHeroBarHealthBar(int buttonId, int anchor, float offsetX, float offsetY, float width, float height);

void EditHeroBarManaBar(int buttonId, int anchor, float offsetX, float offsetY, float width, float height);

void EditTooltip(int anchor, float offsetX, float offsetY, float width);

void ShowAllUI(void);

void HideAllUI(void);