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
    Sound buttonSound = LoadSound("resources/temp_buttonfx.wav");
    Texture2D buttonSprite = LoadTexture("resources/temp_button.png");

    // Audio Setup

    // Button Setup
    enum ButtonState {
        BUTTON_IDLE = 0,
        BUTTON_HOVER = 1,
        BUTTON_PRESSED = 2,
    };

    enum ButtonState buttonState;
    float buttonFrameHeight = (float)buttonSprite.height/NUM_FRAMES;
    Rectangle buttonBounds = { screenWidth/3.0f, screenHeight/3.0f, (float)buttonSprite.width, buttonFrameHeight};
    Rectangle buttonSourceRec = { 0, 0, (float)buttonSprite.width, buttonFrameHeight };

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
        const bool isMouseOver = CheckCollisionPointRec(mousePosition, buttonBounds);

        if (isMouseOver)
        {
            buttonState = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? BUTTON_PRESSED : BUTTON_HOVER;
        }
        else
        {
            buttonState = BUTTON_IDLE;
        }

        if (isMouseOver && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            PlaySound(buttonSound);
        }
        
        buttonSourceRec.y = buttonState*buttonFrameHeight;


        // Draw
        // ------------------------------------------------------------

        BeginDrawing();

            ClearBackground(BLACK);

            DrawTextureRec(buttonSprite, buttonSourceRec, (Vector2){buttonBounds.x, buttonBounds.y }, WHITE);

            DrawTextEx(textFont, TextSubtext("You awaken in the dark. Your head pounds, and your muscles ache. The cold is in your bones.", 0, framesCounter/textPrintSpeed), textPosition, textSize, textSpacing, textColor);
            
        EndDrawing();
        
        // ------------------------------------------------------------
    }

    // De-Initialization
    // ------------------------------------------------------------

    UnloadFont(textFont);
    UnloadSound(buttonSound);
    UnloadTexture(buttonSprite);

    CloseAudioDevice();

    CloseWindow();

    // ------------------------------------------------------------

    return 0;

}