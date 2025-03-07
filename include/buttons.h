#pragma once

#include "raylib.h"

typedef struct Button {
    float frameHeight;
    int numFrames;
    int state;
    Color color;
    Vector2 spriteOrigin;
} Button;

extern Button BUTTON;