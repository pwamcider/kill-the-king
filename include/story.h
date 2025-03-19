#pragma once

#include <stdbool.h>
#include <stdlib.h>

// Structures
// ------------------------------------------------------------

/* TODO - an "updater" system. Uses a mix of structs that contain what the updates will be,
what flags they are triggered by and what changes they make to pages. Then, functions that run during game
loop that will trigger when a flag is detected. It then dynamically updates page content, either changing the text,
changing the prompts, or changing the pointers to redirect to a new node.

This system would require that Page structs have a pointer to specific update nodes. 
*/

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
    bool checkpoint;
    bool gameOver;
    bool raisedAlarm;
} Page;

typedef struct Consequence
{
    Option* target;
    Page* redirect;
} Consequence;

typedef struct Ripple
{
    struct Consequence consequences[5];
} Ripple;

// Prototypes
// ------------------------------------------------------------

bool IsOptionValid(Option* option);
int CountOptions(Page* page);
void CheckForRipple(Option* option);
void PlayPage(Page* page);

// Pages
// ------------------------------------------------------------

extern Page DANCE_FAIL;
extern Page DANCE;
extern Page TEST1;
extern Page TEST2_BROKEN;
extern Page TEST2;

// Consequences
// ------------------------------------------------------------

extern Ripple BROKE_LEG;