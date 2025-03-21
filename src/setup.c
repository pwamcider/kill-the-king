#include "raylib.h"
#include "setup.h"
#include "ui.h"

// Variables
// ------------------------------------------------------------

int FRAME_COUNTER = 0;
int *FRAME_COUNTER_PTR = &FRAME_COUNTER;
Page *CURRENT_PAGE = &TEST1;

// TODO - move CURRENT_PAGE to story_engine? or Pages?

// ------------------------------------------------------------

 void InitGame(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Kill the King");
    InitAudioDevice();

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);
}

void ShutdownGame(void){
    CloseAudioDevice();
    CloseWindow();
}