#include "buttons.h"
#include "functions.h"
#include "raylib.h"
#include "resources.h"
#include "story_content.h"
#include "text.h"
#include "ui.h"
#include "update.h"

// Startup Variables
// ------------------------------------------------------------

int framesCounter = 0;
Page *currentPage = &TEST1;
Vector2 mousePosition;

// Gameloop Function
// ------------------------------------------------------------

void UpdateGame(void) {
    BUTTON.frameHeight = GetButtonSpriteHeight()/BUTTON.numFrames;
    BUTTON.offsetY = 1;
    framesCounter++;
    mousePosition = GetMousePosition();

    int numOptions = CountOptions(currentPage);
    Rectangle buttonSource[numOptions];
    Rectangle buttonDest[numOptions];

    for (int i = 0; i < numOptions; i++)
    {
        buttonSource[i].x = 0.0f;
        buttonSource[i].y = 0.0f;
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

    // Drawing Frame
    // ------------------------------------------------------------

    BeginDrawing();

            ClearBackground(BLACK);
            
            SetTextLineSpacing(TEXT.vertSpacing);

            for (int i = 0; i < numOptions; i++)
            {
                // TODO - set custom color elsewhere; maybe in TEXT struct?
                // TODO - remove rectangle if we're not using it.
                // TODO - refine naming of accentPosition
                Color myColor = { 40, 40, 40, 255 };
                Vector2 accentPosition = { buttonDest[i].x, buttonDest[i].y - 5 };
                DrawTexturePro(buttonSprite, buttonSource[i], buttonDest[i], BUTTON.spriteOrigin, 0, WHITE);
                // DrawRectangle((int)accentPosition.x, (int)accentPosition.y, 250, 25, myColor);
                DrawTextPro(
                    textFont,
                    currentPage->options[i].prompt,
                    accentPosition, TEXT.origin, TEXT.rotation, TEXT.size, TEXT.spacing, TEXT.color
                );
            }
            DrawLineEx(GetLineStart(), GetLineStop(), LINE.thickness, LINE.color);

            DrawTextPro(
                textFont,
                TextSubtext(currentPage->text, 0, framesCounter/TEXT.printSpeed),
                TEXT.position, TEXT.origin, TEXT.rotation, TEXT.size, TEXT.spacing, TEXT.color
            );
            
    EndDrawing();
};