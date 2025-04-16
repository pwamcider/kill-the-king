#include "draw.h"
#include "raylib.h"
#include "resources.h"
#include "setup.h"
#include "story_engine.h"
#include "ui.h"

void DrawButtons(void) {
    for (int i = 0; i < LAYOUT.numOptions; i++)
    {
        DrawTexturePro(buttonSprite, LAYOUT.buttonSource[i], LAYOUT.buttonDest[i],
                        BUTTON.spriteOrigin, BUTTON.rotation, WHITE);
        DrawTextPro(
            textFont,
            CURRENT_PAGE->options[i].prompt,
            CalculatePromptPos(LAYOUT.buttonDest[i].x, LAYOUT.buttonDest[i].y),
            TEXT.origin, TEXT.rotation, TEXT.size, TEXT.spacing, TEXT.color
        );
    }
}

void DrawDivider(void) {
    DrawLineEx(LINE.start, LINE.stop, LINE.thickness, LINE.color);
}

void DrawPrompt(void) {
    DrawTextPro(
        textFont,
        TextSubtext(CURRENT_PAGE->text, TEXT.printStartPos, *FRAME_COUNTER_PTR/TEXT.printSpeed),
                    TEXT.position, TEXT.origin, TEXT.rotation, TEXT.size, TEXT.spacing, TEXT.color
    );
}

void DrawLoop(void) {
    BeginDrawing();

            ClearBackground(BLACK);
            
            SetTextLineSpacing(TEXT.vertSpacing);

            DrawButtons();

            DrawDivider();

            DrawPrompt();

    EndDrawing();
}

void DrawMain(void) {
    BeginDrawing();

        ClearBackground(BLACK);

        SetTextLineSpacing(TEXT.vertSpacing);

        DrawButtons();

        DrawPrompt();
        // TODO - remove this DrawPrompt() once main menu has art underneathe.

    EndDrawing();
}