#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ------------------------------------------------------------
// Definitions, Prototypes

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

    Vector2 mousePosition;

    // Font Settings
    Font mainFont = LoadFont("resources/fonts/pixantiqua.png");
    Vector2 fontPosition = { 200.0f, 200.0f };
    Color fontColor = WHITE;
    float fontSize = 20;
    float fontSpacing = 4;

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

            DrawTextEx(mainFont, "Testing", fontPosition, fontSize, fontSpacing, fontColor);
            
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