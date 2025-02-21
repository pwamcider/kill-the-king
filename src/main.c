#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "raylib.h"
#include "story_content.h"

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

    // TODO - clean all this stuff up!
    enum ButtonState buttonState;
    float buttonFrameHeight = (float)buttonSprite.height/NUM_BUTTON_FRAMES;
    int buttonAlignmentX = 850;
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

    // Startup Variables
    int framesCounter = 0;
    Vector2 mousePosition;
    Page *currentPage = &TEST1;


    // ------------------------------------------------------------

    // Core Game Loop
    while (!WindowShouldClose())
    {

        // Update
        // ------------------------------------------------------------
        framesCounter++;
        mousePosition = GetMousePosition();

        int numOptions = CountOptions(currentPage);
        int buttonOffsetY = 1;
        Rectangle buttonSource[numOptions];
        Rectangle buttonDest[numOptions];
        // TODO - may need to minus 1 for the above array, since numOptions returns the total count
        // but array is zero indexed

        for (int i = 0; i < numOptions; i++)
        {
            buttonSource[i].x = 0;
            buttonSource[i].y = 0;
            buttonSource[i].width = (float)buttonSprite.width;
            buttonSource[i].height = buttonFrameHeight;
            
            buttonDest[i].x = buttonAlignmentX;
            buttonDest[i].y = buttonOffsetY * (float)buttonSprite.height/NUM_BUTTON_FRAMES;
            buttonDest[i].width = (float)buttonSprite.width;
            buttonDest[i].height = buttonFrameHeight;

            const bool isMouseOver = CheckCollisionPointRec(mousePosition, buttonDest[i]);

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
                framesCounter = 0;
                currentPage = currentPage->options[i].toPage;
            }
            
            buttonSource[i].y = buttonState*buttonFrameHeight;

            buttonOffsetY++;
        }

        // Draw
        // ------------------------------------------------------------

        BeginDrawing();

            ClearBackground(BLACK);
            
            SetTextLineSpacing(textVertSpacing);

            for (int i = 0; i < numOptions; i++)
            {
                DrawTexturePro(buttonSprite, buttonSource[i], buttonDest[i], buttonSpriteOrigin, 0, WHITE);
            }
        
            DrawLineEx(lineStart, lineStop, lineThickness, lineColor);

            DrawTextPro(textFont, TextSubtext(currentPage->text, 0, framesCounter/textPrintSpeed),
            textPosition, textOrigin, 0.0f, textSize, textSpacing, textColor);
            
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