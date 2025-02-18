#include <stdbool.h>
#include <stdlib.h>

#include "functions.h"
#include "story_content.h"

// Variable Definitions
// ------------------------------------------------------------

int ALARM = 0;
Page* CHECKPOINT = NULL;

// Support Function Definitions
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
        numOptions++;
        
    }
    return numOptions;
}

void PlayPage(Page* page)
{
    if (page->checkpoint)
    {
        CHECKPOINT = page;
    }

    if (page->gameOver)
    {
        // TODO: game over state
        return PlayPage(CHECKPOINT);
    }
    
    if (page->raisedAlarm)
    {
        ALARM++;
    }
    
}