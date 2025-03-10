#pragma once

#include "raylib.h"

// Structs
// ------------------------------------------------------------

typedef struct Button {
    float frameHeight;
    float rotation;
    int numFrames;
    int state;
    Color color;
    Vector2 spriteOrigin;
} Button;

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

typedef struct Text {
    float rotation;
    int printSpeed;
    int printStartPos;
    int size;
    int spacing;
    int vertSpacing;
    Color color;
    Vector2 origin;
    Vector2 position;
} Text;

extern Button BUTTON;
extern Layout LAYOUT;
extern Line LINE;
extern Text TEXT;
extern int SCREENWIDTH;
extern int SCREENHEIGHT;