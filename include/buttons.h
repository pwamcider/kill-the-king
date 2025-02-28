#pragma once

#include "raylib.h"

// Declarations
// ------------------------------------------------------------

typedef struct Button {
    float frameHeight;
    int alignmentX;
    int numFrames;
    int offsetY;
    int state;
    Color color;
    Vector2 spriteOrigin;
} Button;

extern Button BUTTON;