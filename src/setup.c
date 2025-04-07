#include <stdlib.h>

#include "consequences.h"
#include "raylib.h"
#include "setup.h"
#include "story_engine.h"
#include "ui.h"

// Variables
// ------------------------------------------------------------

int FRAME_COUNTER = 0;
int *FRAME_COUNTER_PTR = &FRAME_COUNTER;

// ------------------------------------------------------------

 void InitGame(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Kill the King");
    InitAudioDevice();

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);
}

void SetupGame(void) {
    InitGame();
    ResetAllRipples();
    ALARM = 0;
    CURRENT_PAGE = &TEST1;
    CHECKPOINT = NULL;
}

void ShutdownGame(void){
    CloseAudioDevice();
    CloseWindow();
}