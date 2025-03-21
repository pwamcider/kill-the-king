#pragma once

#include <stdbool.h>

// Structs
// ------------------------------------------------------------

struct Page;

typedef struct Option
{
    char prompt[256];
    struct Ripple* toRipple;
    struct Page* toPage;
} Option;

typedef struct Page
{
    char text[2048];
    struct Option options[4];
    bool *pageFlag;
    bool checkpoint;
    bool gameOver;
    bool raisedAlarm;
} Page;

// Variables
// ------------------------------------------------------------

extern int ALARM;
extern Page *CURRENT_PAGE;
extern Page* CHECKPOINT;

// Pages
// ------------------------------------------------------------

extern Page DANCE_FAIL;
extern Page DANCE;
extern Page TEST1;
extern Page TEST2_BROKEN;
extern Page TEST2;