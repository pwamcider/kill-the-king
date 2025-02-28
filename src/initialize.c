#include "initialize.h"
#include "raylib.h"

// Variables
// ------------------------------------------------------------

int screenWidth = 1280;
int screenHeight = 720;

Font textFont; 
Sound buttonSound;
Texture2D buttonSprite;

// Functions
// ------------------------------------------------------------

int GetGameHeight(void) {
    return screenHeight;
}

int GetGameWidth(void) {
    return screenWidth;
}

 void InitGame(void){
    InitWindow(screenWidth, screenHeight, "Kill the King");
    InitAudioDevice();

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);
}

void ResourceLoad(void) {
    textFont = LoadFont("resources/fonts/pixantiqua.png");
    buttonSound = LoadSound("resources/temp_buttonfx.wav");
    buttonSprite = LoadTexture("resources/temp_button.png");
}