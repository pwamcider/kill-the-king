#include "resources.h"

// Resource Definitions
// ------------------------------------------------------------

Font textFont; 
Sound buttonSound;
Texture2D buttonSprite;

// Resource Loading/Unloading
/// ------------------------------------------------------------

void ResourceLoad(void) {
    textFont = LoadFont("resources/fonts/pixantiqua.png");
    buttonSound = LoadSound("resources/temp_buttonfx.wav");
    buttonSprite = LoadTexture("resources/temp_button.png");
}

void ResourceUnload(void) {
    UnloadFont(textFont);
    UnloadSound(buttonSound);
    UnloadTexture(buttonSprite);
}