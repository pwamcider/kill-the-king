#pragma once

#include "raylib.h"

// Resource Declarations
// ------------------------------------------------------------

extern Font textFont;
extern Sound buttonSound;
extern Texture2D buttonSprite;

// Prototypes
// ------------------------------------------------------------

void ResourceLoad(void);
void ResourceUnload(void);