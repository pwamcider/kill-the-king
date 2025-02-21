#pragma once

#include <stdbool.h>

// Structure Definitions
// ------------------------------------------------------------

struct Page;

typedef struct Option
{
    char prompt[256];
    struct Page* toPage;
} Option;

typedef struct Page
{
    char text[2048];
    struct Option options[4];
    bool checkpoint;
    bool gameOver;
    bool raisedAlarm;
    bool* pageVisited;
} Page;


// Page Declarations
// ------------------------------------------------------------

extern Page TEST1;
extern Page TEST2;

// ------------------------------------------------------------