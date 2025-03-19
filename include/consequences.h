#pragma once

#include "pages.h"

// Struct
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

// Consequences
// ------------------------------------------------------------

extern Ripple BROKE_LEG;