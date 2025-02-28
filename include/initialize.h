#pragma once

#include "raylib.h"

// Variables
// ------------------------------------------------------------

extern int screenWidth;
extern int screenHeight;

extern Font textFont;
extern Sound buttonSound;
extern Texture2D buttonSprite;

// Prototypes
// ------------------------------------------------------------

int GetGameHeight(void);
int GetGameWidth(void);
void InitGame(void);
void ResourceLoad(void);