#pragma once

#include "raylib.h"

// Declarations
// ------------------------------------------------------------

typedef struct Line
{
    Color color;
    float thickness;
    Vector2 start;
    Vector2 stop;
} Line;

extern Line LINE;

// Prototypes
// ------------------------------------------------------------

Vector2 GetLineStart();
Vector2 GetLineStop();