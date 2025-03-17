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

void CheckForConsequence(Option* option)
{
    if (option->toConsequence != NULL)
    {
        Option* target = option->toConsequence->target;
        Page* redirect = option->toConsequence->redirect;

        target->toPage = redirect;
    }
    return;
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
        { .prompt = "Go to the second room.", .toPage = &TEST2, .toConsequence = NULL },
        { .prompt = "Dance a bit.", .toPage = &DANCE }
    },
};

Page DANCE = {
    .text = "You dance around a bit, and feel real good.",
    .options = {
        { .prompt = "Continue.", .toPage = &TEST1, .toConsequence = NULL }
    },
};

Page DANCE_FAIL = {
    .text = "You can't dance right now. Because of the leg, remember?",
    .options = {
        { .prompt = "Continue.", .toPage = &TEST1, .toConsequence = NULL }
    },
};

Page TEST2 = {
    .text = "You're standing in the second room.",
    .options = {
        { .prompt = "Go to the first room.", .toPage = &TEST1, .toConsequence = NULL },
        { .prompt = "Break leg on way to first room.", .toPage = &TEST1, .toConsequence = &BROKE_LEG },
    },
};

// Consequences
// ------------------------------------------------------------

Consequence BROKE_LEG = {
    .target = &TEST1.options[1],
    .redirect = &DANCE_FAIL,
};