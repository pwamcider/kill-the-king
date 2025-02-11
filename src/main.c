#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "story_content.h"
#include "support_functions.h"

// ------------------------------------------------------------
// Definitions

#define NUM_FRAMES 3

// ------------------------------------------------------------

int main(void)
{
    // Initialization
    // ------------------------------------------------------------

    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Kill the King");
    InitAudioDevice();

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    // Resource Load
    Font textFont = LoadFont("resources/fonts/pixantiqua.png");
    Sound btnSound = LoadSound("resources/temp_buttonfx.wav");
    Texture2D btnSprite = LoadTexture("resources/temp_button.png");

    // Audio Setup

    // Button Setup
    bool btnAction = false;
    float btnFrameHeight = (float)btnSprite.height/NUM_FRAMES;
    int btnState = 0;    // 0-NORMAL, 2-HOVER, 2-PRESSED
    Rectangle btnBounds = { screenWidth/3.0f, screenHeight/3.0f, (float)btnSprite.width, btnFrameHeight};
    Rectangle btnSourceRec = { 0, 0, (float)btnSprite.width, btnFrameHeight };

    // Font Setup
    Color textColor = WHITE;
    Vector2 textPosition = { 200.0f, 200.0f };
    int textPrintSpeed = 2;    // Lower number increases speed.
    int textSize = 15;
    int textSpacing = 4;

    // Variables
    int framesCounter = 0;
    Vector2 mousePosition;

    // ------------------------------------------------------------

    // Core Game Loop
    while (!WindowShouldClose())
    {

        // Update
        // ------------------------------------------------------------
        framesCounter++;
        mousePosition = GetMousePosition();
        btnAction = false;

        if (CheckCollisionPointRec(mousePosition, btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                btnState = 2;
            }
            else
            {
                btnState = 1;
            }

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                btnAction = true;
            }
            
        }
        else
        {
            btnState = 0;
        }

        if (btnAction)
        {
            PlaySound(btnSound);
        }
        
        btnSourceRec.y = btnState*btnFrameHeight;


        // Draw
        // ------------------------------------------------------------

        BeginDrawing();

            ClearBackground(BLACK);

            DrawTextureRec(btnSprite, btnSourceRec, (Vector2){btnBounds.x, btnBounds.y }, WHITE);

            DrawTextEx(textFont, TextSubtext("You awaken in the dark. Your head pounds, and your muscles ache. The cold is in your bones.", 0, framesCounter/textPrintSpeed), textPosition, textSize, textSpacing, textColor);
            
        EndDrawing();
        
        // ------------------------------------------------------------
    }

    // De-Initialization
    // ------------------------------------------------------------

    UnloadFont(textFont);
    UnloadSound(btnSound);
    UnloadTexture(btnSprite);

    CloseAudioDevice();

    CloseWindow();

    // ------------------------------------------------------------

    return 0;

}