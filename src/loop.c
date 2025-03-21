#include "loop.h"
#include "raylib.h"
#include "resources.h"
#include "setup.h"
#include "story_engine.h"
#include "ui.h"

// ------------------------------------------------------------

void GameLoop(void) {
    *FRAME_COUNTER_PTR += 1;
    
    BUTTON.frameHeight = GetButtonSpriteHeight()/BUTTON.numFrames;

    int numOptions = CountOptions(CURRENT_PAGE);
    Rectangle buttonSource[numOptions];
    Rectangle buttonDest[numOptions];

    Vector2 mousePosition = GetMousePosition();

    for (int i = 0; i < numOptions; i++)
    {
        int buttonState = 0;

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
            buttonState = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? 1 : 2;
        }

        buttonSource[i].y = buttonState*BUTTON.frameHeight;

        if (isMouseOver && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            *FRAME_COUNTER_PTR = 0;
            PlaySound(buttonSound);
            CheckForPageFlags(CURRENT_PAGE);
            CheckForRipple(&CURRENT_PAGE->options[i]);
            CURRENT_PAGE = CURRENT_PAGE->options[i].toPage;

            // TODO - store ripples that have been activated thus far.
        }
    }

    // Draw Gameloop
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
                    CURRENT_PAGE->options[i].prompt,
                    LAYOUT.promptPosition[i], TEXT.origin, TEXT.rotation, TEXT.size, TEXT.spacing, TEXT.color
                );
            }
            DrawLineEx(LINE.start, LINE.stop, LINE.thickness, LINE.color);

            DrawTextPro(
                textFont,
                TextSubtext(CURRENT_PAGE->text, TEXT.printStartPos, *FRAME_COUNTER_PTR/TEXT.printSpeed),
                            TEXT.position, TEXT.origin, TEXT.rotation, TEXT.size, TEXT.spacing, TEXT.color
            );
            
    EndDrawing();

}