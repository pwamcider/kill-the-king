#pragma once

#include "pages.h"

// Prototypes
// ------------------------------------------------------------

bool IsOptionValid(Option* option);
int CountOptions(Page* page);
void CheckForPageFlags(Page* page);
Page* ApplyRipples(Option* option);