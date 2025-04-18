#pragma once

#include <stdbool.h>

#include "ui.h"

// Structs
// ------------------------------------------------------------

struct Page;

typedef struct Option
{
    char prompt[256];
    struct Ripple* causeRipple;
    struct Page* toPage;
} Option;

typedef struct Page
{
    char text[2048];
    struct Option options[MAX_OPTIONS];
    bool *pageFlag;
    bool checkpoint;
    bool gameOver;
    bool raisedAlarm;
    bool failState;
} Page;

// Pages
// ------------------------------------------------------------

extern Page DANCE_FAIL;
extern Page DANCE;
extern Page FAIL_STATE;
extern Page GAME_OVER;
extern Page MENU0;
extern Page QUIT;
extern Page TEST1;
extern Page TEST2_BROKEN;
extern Page TEST2;
extern Page TEST3;