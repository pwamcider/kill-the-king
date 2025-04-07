#pragma once

#include "pages.h"

// Prototypes
// ------------------------------------------------------------

bool IsOptionValid(Option* option);
int CountOptions(Page* page);
Page* ApplyRipples(Option* option);
void CheckForPageFlags(Page* page);