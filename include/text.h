#pragma once

#include "raylib.h"

// Declarations
// ------------------------------------------------------------

typedef struct Text {
    float rotation;
    int printSpeed;
    int size;
    int spacing;
    int vertSpacing;
    Color color;
    Vector2 origin;
    Vector2 position;
} Text;

extern Text TEXT;