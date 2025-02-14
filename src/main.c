#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "story_content.h"
#include "support_functions.h"

// ------------------------------------------------------------
// Definitions

#define NUM_BUTTON_FRAMES 3

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
    float buttonFrameHeight = (float)buttonSprite.height/NUM_BUTTON_FRAMES;
    Rectangle buttonSource = { 0, 0, (float)buttonSprite.width, buttonFrameHeight };
    Rectangle buttonDest = { 850, 75, (float)buttonSprite.width, buttonFrameHeight };
    Vector2 buttonSpriteOrigin = { 0, 0 };

    // Line Setup
    float lineThickness = 1;

    Color lineColor = WHITE;
    Vector2 lineStart = { screenWidth/2.0f, 50.0f };
    Vector2 lineStop = { screenWidth/2.0f, 670.0f };

    // Text Setup
    int textPrintSpeed = 2;    // Lower number increases speed.
    int textSize = 15;
    int textSpacing = 4;
    int textVertSpacing = 10;
    
    Color textColor = WHITE;
    Vector2 textPosition = { 50.0f, 50.0f };
    Vector2 textOrigin = { 0.0f, 0.0f };
    
    char *textString = "You awaken in the dark.\n"
                       "Your head pounds and your muscles ache.\n"
                       "The cold is in your bones.";

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
        const bool isMouseOver = CheckCollisionPointRec(mousePosition, buttonDest);

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
        
        buttonSource.y = buttonState*buttonFrameHeight;


        // Draw
        // ------------------------------------------------------------

        BeginDrawing();

            ClearBackground(BLACK);
            
            SetTextLineSpacing(textVertSpacing);

            DrawLineEx(lineStart, lineStop, lineThickness, lineColor);

            DrawTexturePro(buttonSprite, buttonSource, buttonDest, buttonSpriteOrigin, 0, WHITE);

            DrawTextPro(textFont, TextSubtext(textString, 0, framesCounter/textPrintSpeed), textPosition, textOrigin, 0.0f, textSize, textSpacing, textColor);
            
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