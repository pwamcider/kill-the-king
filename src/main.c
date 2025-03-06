#include "initialize.h"
#include "raylib.h"
#include "resources.h"
#include "update.h"

int main(void)
{
    InitGame();

    ResourceLoad();

    while (!WindowShouldClose())
    {
        UpdateGame();
    }

    ResourceUnload();

    ShutdownGame();

    return 0;
}