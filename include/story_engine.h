#pragma once

#include "pages.h"

// Starting Variables
// ------------------------------------------------------------

extern int ALARM;
extern Page *CURRENT_PAGE;
extern Page* CHECKPOINT;

// Prototypes
// ------------------------------------------------------------

bool IsOptionValid(Option* option);
int CountOptions(Page* page);
Page* ApplyRipples(Option* option);
void CheckForPageFlags(Page* page);