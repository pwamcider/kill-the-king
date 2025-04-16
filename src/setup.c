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

void ResetGameState(void) {
    ResetAllRipples();
    ALARM = 0;
    CHECKPOINT = NULL;
    CHECKPOINT_ALARM = 0;
    GAME_STATE = MAIN_MENU;
}

void SetupGame(void) {
    InitGame();
    ResetGameState();
    CURRENT_PAGE = &MENU0;
}

void ShutdownGame(void){
    CloseAudioDevice();
    CloseWindow();
}