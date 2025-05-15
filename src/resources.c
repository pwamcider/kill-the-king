#include "resources.h"

// Resource Definitions
// ------------------------------------------------------------

Font textFont; 
Sound buttonSound;
Texture2D buttonSprite;

// Resource Loading/Unloading
// ------------------------------------------------------------


void ResourceLoad(void) {
    textFont = LoadFont("resources/fonts/pixantiqua.png");
    buttonSound = LoadSound("resources/temp_buttonfx.wav");
    buttonSprite = LoadTexture("resources/button.png");
}

void ResourceUnload(void) {
    UnloadFont(textFont);
    UnloadSound(buttonSound);
    UnloadTexture(buttonSprite);
}

// Sprite Functions
// ------------------------------------------------------------

float GetButtonSpriteWidth(void) {
    return buttonSprite.width;
}

float GetButtonSpriteHeight(void) {
    return buttonSprite.height;
}