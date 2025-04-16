#pragma once

#include "pages.h"

// Variables
// ------------------------------------------------------------

extern int FRAME_COUNTER;
extern int *FRAME_COUNTER_PTR;

// Prototypes
// ------------------------------------------------------------

void InitGame(void);
void ResetGameState(void);
void SetupGame(void);
void ShutdownGame(void);