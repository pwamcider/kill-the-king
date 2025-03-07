#pragma once

#include "raylib.h"

// Structs
// ------------------------------------------------------------

typedef struct Layout
{
    Vector2 buttonPosition[4];
    Vector2 promptPosition[4];
} Layout;

typedef struct Line
{
    Color color;
    float thickness;
    Vector2 start;
    Vector2 stop;
} Line;

extern Layout LAYOUT;
extern Line LINE;

// Prototypes
// ------------------------------------------------------------

Vector2 GetLineStart();
Vector2 GetLineStop();