#include "setup.h"

// Variables
// ------------------------------------------------------------

int FRAME_COUNTER = 0;
int *FRAME_COUNTER_PTR = &FRAME_COUNTER;
Page *CURRENT_PAGE = &TEST1;

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