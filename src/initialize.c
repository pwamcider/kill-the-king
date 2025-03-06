#include "initialize.h"

// Screen
// ------------------------------------------------------------

int screenWidth = 1280;
int screenHeight = 720;

// Functions
// ------------------------------------------------------------

int FindScreenWidth(void) {
    return screenWidth;
}

int FindScreenHeight(void) {
    return screenHeight;
}

 void InitGame(void){
    InitWindow(screenWidth, screenHeight, "Kill the King");
    InitAudioDevice();

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);
}

void ShutdownGame(void){
    CloseAudioDevice();
    CloseWindow();
}