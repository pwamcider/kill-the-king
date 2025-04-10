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
    }

    ResourceUnload();

    ShutdownGame();

    return 0;
}