#pragma once

#include "pages.h"
#include "raylib.h"
#include "ui.h"

// Variables
// ------------------------------------------------------------

extern int FRAME_COUNTER;
extern int *FRAME_COUNTER_PTR;
extern Page *CURRENT_PAGE;

// Prototypes
// ------------------------------------------------------------

void InitGame(void);
void ShutdownGame(void);