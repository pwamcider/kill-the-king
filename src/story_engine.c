#include <stdbool.h>
#include <stdlib.h>

#include "consequences.h"
#include "setup.h"
#include "story_engine.h"

// Starting Variables
// ------------------------------------------------------------

int ALARM;
int CHECKPOINT_ALARM;
Page* CURRENT_PAGE;
Page* CHECKPOINT;

// Functions
// ------------------------------------------------------------

bool IsOptionValid(Option* option)
{
    return option && option->prompt[0] && option->toPage;
}

int CountOptions(Page* page)
{
    int numOptions = 0;

    for (int i = 0; i < sizeof(page->options); i++)
    {
        if (!IsOptionValid(&page->options[i]))
        {
            break;
        }
        numOptions += 1;
        
    }
    return numOptions;
}

bool IsConsequenceValid(Consequence* consequence)
{
    return consequence && consequence->target && consequence->redirect; 
}

int CountConsequences(Ripple* ripple)
{
    int numConsequences = 0;

    for (int i = 0; i < sizeof(ripple->consequences); i++)
    {
        if (!IsConsequenceValid(&ripple->consequences[i]))
        {
            break;
        }
        numConsequences += 1;
    }
    return numConsequences;
}

Page* ApplyRipples(Option* option)
{
    if (option->causeRipple != NULL)
    {
        Ripple* ripple = option->causeRipple;

        int rippleIndex;

        for (int i = 0; i < NUM_RIPPLES; i++)
        {
            if (ripple == ALL_RIPPLES[i])
            {
                rippleIndex = i;
                break;
            }
        }
        ACTIVE_RIPPLES[rippleIndex] = true;
    }

    for (int i = 0; i < NUM_RIPPLES; i++)
    {
        if (ACTIVE_RIPPLES[i])
        {
            Ripple* ripple = ALL_RIPPLES[i];

            int numConsequences = CountConsequences(ripple);

            for (int j = 0; j < numConsequences; j++)
            {
                Option* target = ripple->consequences[j].target;
                Page* redirect = ripple->consequences[j].redirect;

                if (option == target)
                {
                    return redirect;
                }             
            }
        }
    }
    return option->toPage;
}

void CopyActiveRipples(void)
{
    for (int i = 0; i < NUM_RIPPLES; i++)
    {
        CHECKPOINT_RIPPLES[i] = ACTIVE_RIPPLES[i];
    }
}

void CopyCheckpointRipples(void) {
    for (int i = 0; i < NUM_RIPPLES; i++)
    {
        ACTIVE_RIPPLES[i] = CHECKPOINT_RIPPLES[i];
    }
}

void ResetAllRipples(void) {
    for (int i = 0; i < NUM_RIPPLES; i++)
    {
        ACTIVE_RIPPLES[i] = false;
        CHECKPOINT_RIPPLES[i] = false;
    }
}

void SaveCheckpoint(void)
{
    CHECKPOINT = CURRENT_PAGE;
    CHECKPOINT_ALARM = ALARM;
    CopyActiveRipples();
}

void LoadCheckpoint(Option* option)
{
    if (option->toPage != &QUIT)
    {
        CURRENT_PAGE = CHECKPOINT;
        ALARM = CHECKPOINT_ALARM;
        CopyCheckpointRipples();
    }
    else
        CURRENT_PAGE = &QUIT;
}

void CheckForPageFlags(Page* page)
{
    if (page->checkpoint)
    {
        SaveCheckpoint();
    }

    if (page->pageFlag)
    {
        *page->pageFlag = true;
    }

    if (page->raisedAlarm)
    {
        ALARM += 1;
    }

    if (page->gameOver)
    {
        ResetGameState();
    }
}