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
        if ((CURRENT_PAGE != &MENU0) && (CURRENT_PAGE != &QUIT ))
        {
            GAME_STATE = GAME_LOOP;
        }
        if (CURRENT_PAGE == &QUIT)
        {
            GAME_STATE = GAME_QUIT;
        }
        break;
    case GAME_LOOP:
        GameLoop();
        DrawLoop();
        if (CURRENT_PAGE == &QUIT)
        {
            GAME_STATE = GAME_QUIT;
        }
        break;
    case GAME_QUIT:
        break;
    default:
        break;
    }
}