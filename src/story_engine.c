#include <stdbool.h>
#include <stdlib.h>

#include "consequences.h"
#include "story_engine.h"


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

void CheckForRipple(Option* option)
{

    if (option->toRipple != NULL)
    {
        Ripple *ripple = option->toRipple;

        int numConsequences = CountConsequences(ripple);

        for (int i = 0; i < numConsequences; i++)
        {
            Option* target = ripple->consequences[i].target;
            Page* redirect = ripple->consequences[i].redirect;

            target->toPage = redirect;
        }
    }
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
        // TODO - handle Game Over state.
    }
}