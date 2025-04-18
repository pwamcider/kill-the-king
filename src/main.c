#include "raylib.h"
#include "resources.h"
#include "setup.h"
#include "update.h"

int main(void)
{
    SetupGame();

    ResourceLoad();

    while (!WindowShouldClose())
    {
        UpdateGame();

        if (GAME_STATE == GAME_QUIT)
        {
            break;
        }
    }

    ResourceUnload();

    ShutdownGame();

    return 0;
}