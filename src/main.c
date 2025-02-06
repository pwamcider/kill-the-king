#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ------------------------------------------------------------
// Definitions and Structures

// TODO HERE
// ------------------------------------------------------------


// ------------------------------------------------------------
// Program Entry Point
// ------------------------------------------------------------

int main(void)
{
    // Initialization
    // ------------------------------------------------------------

    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Kill the King");

    SetExitKey(KEY_NULL);

    SetTargetFPS(60);

    int framesCounter = 0;

    Vector2 testPosition = { 200.0f, 200.0f };

    Vector2 mousePosition;

    // Font Settings
    Font mainFont = LoadFont("resources/fonts/pixantiqua.png");

    // ------------------------------------------------------------

    // Core Game Loop
    while (!WindowShouldClose())
    {

        // Update
        // ------------------------------------------------------------
        framesCounter++;


        // Draw
        // ------------------------------------------------------------

        BeginDrawing();

            ClearBackground(BLACK);

            DrawTextEx(mainFont, "Testing", testPosition, (float)20, (float)4, WHITE);
            
        EndDrawing();

        // ------------------------------------------------------------
    }

    // De-Initialization
    // ------------------------------------------------------------

    UnloadFont(mainFont);

    CloseWindow();

    // ------------------------------------------------------------

    return 0;

}