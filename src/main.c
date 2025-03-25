#include "loop.h"
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
        GameLoop();
    }

    ResourceUnload();

    ShutdownGame();

    return 0;
}