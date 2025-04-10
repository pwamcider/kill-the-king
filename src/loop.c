#include "loop.h"
#include "raylib.h"
#include "resources.h"
#include "setup.h"
#include "story_engine.h"

// ------------------------------------------------------------

void GameLoop(void) {
    *FRAME_COUNTER_PTR += 1;
    
    BUTTON.frameHeight = GetButtonSpriteHeight()/BUTTON.numFrames;

    LAYOUT.numOptions = CountOptions(CURRENT_PAGE);

    Vector2 mousePosition = GetMousePosition();

    for (int i = 0; i < LAYOUT.numOptions; i++)
    {
        int buttonState = 0;

        LAYOUT.buttonSource[i].x = 0.0f;
        LAYOUT.buttonSource[i].y = 0.0f;
        LAYOUT.buttonSource[i].width = (float)buttonSprite.width;
        LAYOUT.buttonSource[i].height = BUTTON.frameHeight;
        
        LAYOUT.buttonDest[i].x = LAYOUT.buttonPosition[i].x;
        LAYOUT.buttonDest[i].y = LAYOUT.buttonPosition[i].y;
        LAYOUT.buttonDest[i].width = (float)buttonSprite.width;
        LAYOUT.buttonDest[i].height = BUTTON.frameHeight;

        const bool isMouseOver = CheckCollisionPointRec(mousePosition, LAYOUT.buttonDest[i]);

        if (isMouseOver)
        {
            buttonState = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? 1 : 2;
        }

        LAYOUT.buttonSource[i].y = buttonState*BUTTON.frameHeight;

        if (isMouseOver && IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            *FRAME_COUNTER_PTR = 0;
            PlaySound(buttonSound);
            CheckForPageFlags(CURRENT_PAGE);
            Page* nextPage = ApplyRipples(&CURRENT_PAGE->options[i]);
            CURRENT_PAGE = nextPage;

            // TODO - Ensure that we run ResetRipples() whenever there is a game over state.
        }
    }
}