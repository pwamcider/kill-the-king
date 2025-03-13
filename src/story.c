#include "story.h"

// Variables
// ------------------------------------------------------------

int ALARM = 0;
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

// Pages
// ------------------------------------------------------------

Page TEST1 = {
    .text = "You're standing in the first room.",
    .options = {
        { .prompt = "Go to the second room.", .toPage = &TEST2 },
    },
};

Page TEST2 = {
    .text = "You're standing in the second room.",
    .options = {
        { .prompt = "Go to the first room.", .toPage = &TEST1 },
        { .prompt = "Run to the first room.", .toPage = &TEST1 },
    },
};