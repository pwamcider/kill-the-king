#pragma once

#include "pages.h"

#define NUM_RIPPLES 1

// Structs
// ------------------------------------------------------------

typedef struct Consequence
{
    Option* target;
    Page* redirect;
} Consequence;

typedef struct Ripple
{
    struct Consequence consequences[5];
} Ripple;

// Tracking
// ------------------------------------------------------------

extern Ripple* ALL_RIPPLES[NUM_RIPPLES];
extern bool ACTIVE_RIPPLES[NUM_RIPPLES];

// Prototypes
// ------------------------------------------------------------

void ResetRipples(void);

// Consequences
// ------------------------------------------------------------

extern Ripple BROKE_LEG;