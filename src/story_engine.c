#include <stdbool.h>
#include <stdlib.h>

#include "consequences.h"
#include "story_engine.h"

// Starting Variables
// ------------------------------------------------------------

int ALARM = 0;
Page *CURRENT_PAGE = &TEST1;
Page* CHECKPOINT = NULL;

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
        if (ACTIVE_RIPPLES[i] == true)
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

    // TODO - Track how many ripples are active between a checkpoint and a game over?
    // Possibly: copy the state of the ACTIVE_RIPPLES array into a CHECKPOINT_RIPPLES array?
}

void CheckForPageFlags(Page* page)
{
    if (page->checkpoint)
    {
        CHECKPOINT = page;
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
        /* TODO - handle Game Over state.
        Considerations: if full game over, reset both ACTIVE_RIPPLES and CHECKPOINT_RIPPLES
        If simple death, and going back to checkpoint, take CHECKPOINT_RIPPLES and apply it to ACTIVE_RIPPLES,
        ensuring that the state of the game returns to pre-checkpoint status.
        ALSO: change alarmRaised to pre-death level?
        */
    }
}