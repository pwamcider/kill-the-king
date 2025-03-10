#include "functions.h"
#include "raylib.h"
#include "resources.h"
#include "story_content.h"
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
        
        buttonDest[i].x = LAYOUT.buttonPosition[i].x;
        buttonDest[i].y = LAYOUT.buttonPosition[i].y;
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
    }

    // Drawing Frame
    // ------------------------------------------------------------

    BeginDrawing();

            ClearBackground(BLACK);
            
            SetTextLineSpacing(TEXT.vertSpacing);

            for (int i = 0; i < numOptions; i++)
            {
                DrawTexturePro(buttonSprite, buttonSource[i], buttonDest[i],
                               BUTTON.spriteOrigin, BUTTON.rotation, WHITE);
                DrawTextPro(
                    textFont,
                    currentPage->options[i].prompt,
                    LAYOUT.promptPosition[i], TEXT.origin, TEXT.rotation, TEXT.size, TEXT.spacing, TEXT.color
                );
            }
            DrawLineEx(LINE.start, LINE.stop, LINE.thickness, LINE.color);

            DrawTextPro(
                textFont,
                TextSubtext(currentPage->text, 0, framesCounter/TEXT.printSpeed),
                TEXT.position, TEXT.origin, TEXT.rotation, TEXT.size, TEXT.spacing, TEXT.color
            );
            
    EndDrawing();
};