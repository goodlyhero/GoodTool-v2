#include "MHport Common.h"


void initgameui()
{
    if (pGetGameUI > 0)
    {
        pGameUI = GetGameUI(0, 0);
    }
}