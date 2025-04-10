#include "draw.h"
#include "loop.h"
#include "pages.h"
#include "story_engine.h"
#include "ui.h"
#include "update.h"

// Game State Manager
// ------------------------------------------------------------

void UpdateGame(void) {
    switch (GAME_STATE)
    {
    case MAIN_MENU:
        GameLoop();
        DrawMain();
        if (CURRENT_PAGE != &MENU0)
        {
            GAME_STATE = GAME_LOOP;
        }
        break;
    case GAME_LOOP:
        GameLoop();
        DrawLoop();
        break;
    default:
        break;
    }
}