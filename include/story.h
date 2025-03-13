#pragma once

#include <stdbool.h>
#include <stdlib.h>

// Structures
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


// Pages
// ------------------------------------------------------------

extern Page TEST1;
extern Page TEST2;


// Prototypes
// ------------------------------------------------------------

bool IsOptionValid(Option* option);
int CountOptions(Page* page);
void PlayPage(Page* page);