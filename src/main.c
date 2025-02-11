#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "game_content.h"
#include "raylib.h"

// ------------------------------------------------------------
// Definitions

// TODO HERE
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
    Font textFont = LoadFont("resources/fonts/pixantiqua.png");
    Vector2 textPosition = { 200.0f, 200.0f };
    Color textColor = WHITE;
    int textPrintSpeed = 2;    // Lower number increases speed.
    int textSize = 15;
    int textSpacing = 4;

    // Test Button
    Rectangle btnBounds = { screenWidth/2.0f, screenHeight/2.0f, 200, 50};
    Vector2 btnPosition = { 0.0f, 0.0f };
    Color btnColor = WHITE;

    // ------------------------------------------------------------

    // Core Game Loop
    while (!WindowShouldClose())
    {

        // Update
        // ------------------------------------------------------------
        framesCounter++;
        mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                btnColor = RED;
            }
            else
            {
                btnColor = GRAY;
            }
        }
        else
        {
            btnColor = WHITE;
        }

        // Draw
        // ------------------------------------------------------------

        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectanglePro(btnBounds, btnPosition, 0, btnColor);

            DrawTextEx(textFont, TextSubtext("You awaken in the dark. Your head pounds, and your muscles ache. The cold is in your bones.", 0, framesCounter/textPrintSpeed), textPosition, textSize, textSpacing, textColor);
            
        EndDrawing();

        // ------------------------------------------------------------
    }

    // De-Initialization
    // ------------------------------------------------------------

    UnloadFont(textFont);

    CloseWindow();

    // ------------------------------------------------------------

    return 0;

}