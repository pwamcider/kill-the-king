#pragma once

#include "raylib.h"

#define MAX_OPTIONS 4

// Structs
// ------------------------------------------------------------

typedef enum GameState {
    MAIN_MENU = 0,
    GAME_LOOP = 1,
} GameState;

typedef struct Button {
    float frameHeight;
    float rotation;
    int numFrames;
    Color color;
    Vector2 spriteOrigin;
} Button;

typedef struct Layout
{
    int numOptions;
    Rectangle buttonDest[MAX_OPTIONS];
    Rectangle buttonSource[MAX_OPTIONS];
    Vector2 buttonPosition[MAX_OPTIONS];
    Vector2 promptOffset;
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

// Declarations
// ------------------------------------------------------------

extern Button BUTTON;
extern GameState GAME_STATE;
extern int SCREEN_HEIGHT;
extern int SCREEN_WIDTH;
extern Layout LAYOUT;
extern Line LINE;
extern Text TEXT;

// Prototypes
// ------------------------------------------------------------

Vector2 CalculatePromptPos(float x, float y);