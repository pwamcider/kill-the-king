#include "initialize.h"

// Functions
// ------------------------------------------------------------

 void InitGame(void){
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Kill the King");
    InitAudioDevice();

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);
}

void ShutdownGame(void){
    CloseAudioDevice();
    CloseWindow();
}