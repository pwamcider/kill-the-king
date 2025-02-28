#pragma once

#include "raylib.h"

// Resource Declarations
// ------------------------------------------------------------

extern Font textFont;
extern Sound buttonSound;
extern Texture2D buttonSprite;

// Prototypes
// ------------------------------------------------------------

float GetButtonSpriteHeight(void);
float GetButtonSpriteWidth(void);
void ResourceLoad(void);
void ResourceUnload(void);