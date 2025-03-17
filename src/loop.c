#include "loop.h"

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
            *FRAME_COUNTER_PTR = 0;
            PlaySound(buttonSound);
            CheckForConsequence(&CURRENT_PAGE->options[i]);
            CURRENT_PAGE = CURRENT_PAGE->options[i].toPage;
        }
        
        buttonSource[i].y = BUTTON.state*BUTTON.frameHeight;
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