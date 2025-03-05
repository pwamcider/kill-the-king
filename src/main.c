#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "buttons.h"
#include "functions.h"
#include "initialize.h"
#include "raylib.h"
#include "resources.h"
#include "story_content.h"
#include "text.h"
#include "ui.h"

// ------------------------------------------------------------

int main(void)
{
    InitGame();

    ResourceLoad();

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
        BUTTON.frameHeight = GetButtonSpriteHeight()/BUTTON.numFrames;

        int numOptions = CountOptions(currentPage);
        BUTTON.offsetY = 1;
        Rectangle buttonSource[numOptions];
        Rectangle buttonDest[numOptions];

        for (int i = 0; i < numOptions; i++)
        {
            buttonSource[i].x = 0;
            buttonSource[i].y = 0;
            buttonSource[i].width = (float)buttonSprite.width;
            buttonSource[i].height = BUTTON.frameHeight;
            
            buttonDest[i].x = BUTTON.alignmentX;
            buttonDest[i].y = BUTTON.offsetY * (float)buttonSprite.height/BUTTON.numFrames;
            buttonDest[i].width = (float)buttonSprite.width;
            buttonDest[i].height = BUTTON.frameHeight;

            const bool isMouseOver = CheckCollisionPointRec(mousePosition, buttonDest[i]);

            if (isMouseOver)
            {
                BUTTON.state = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? 1 : 2;
            }
            else
            {
                BUTTON.state = 0;
            }

            if (isMouseOver && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                PlaySound(buttonSound);
                framesCounter = 0;
                currentPage = currentPage->options[i].toPage;
            }
            
            buttonSource[i].y = BUTTON.state*BUTTON.frameHeight;

            BUTTON.offsetY++;
        }

        // Draw
        // ------------------------------------------------------------

        BeginDrawing();

            ClearBackground(BLACK);
            
            SetTextLineSpacing(TEXT.vertSpacing);

            for (int i = 0; i < numOptions; i++)
            {
                DrawTexturePro(buttonSprite, buttonSource[i], buttonDest[i], BUTTON.spriteOrigin, 0, WHITE);
            }
            DrawLineEx(GetLineStart(), GetLineStop(), LINE.thickness, LINE.color);

            DrawTextPro(
                textFont,
                TextSubtext(currentPage->text, 0, framesCounter/TEXT.printSpeed),
                TEXT.position, TEXT.origin, TEXT.rotation, TEXT.size, TEXT.spacing, TEXT.color
            );
            
        EndDrawing();
        
        // ------------------------------------------------------------
    }

    // De-Initialization
    // ------------------------------------------------------------

    ResourceUnload();

    ShutdownGame();

    // ------------------------------------------------------------

    return 0;

}