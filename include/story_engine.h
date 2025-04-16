#pragma once

#include "pages.h"

// Starting Variables
// ------------------------------------------------------------

extern int ALARM;
extern int CHECKPOINT_ALARM;
extern Page* CURRENT_PAGE;
extern Page* CHECKPOINT;

// Prototypes
// ------------------------------------------------------------

bool IsOptionValid(Option* option);
int CountOptions(Page* page);
Page* ApplyRipples(Option* option);
void CheckForPageFlags(Page* page);
void CopyActiveRipples(void);
void CopyCheckpointRipples(void);
void LoadCheckpoint(void);
void ResetAllRipples(void);
void SaveCheckpoint(void);