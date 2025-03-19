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
        { .prompt = "Go to the second room.", .toPage = &TEST2 },
        { .prompt = "Dance a bit.", .toPage = &DANCE }
    }
};

Page DANCE = {
    .text = "You dance around a bit, and feel real good.",
    .options = {
        { .prompt = "Continue.", .toPage = &TEST1 }
    }
};

Page DANCE_FAIL = {
    .text = "You can't dance right now. Because of the leg, remember?",
    .options = {
        { .prompt = "Continue.", .toPage = &TEST1 }
    }
};

Page TEST2 = {
    .text = "You're standing in the second room.",
    .options = {
        { .prompt = "Go to the first room.", .toPage = &TEST1, .toRipple = NULL },
        { .prompt = "Break leg on way to first room.", .toPage = &TEST1, .toRipple = &BROKE_LEG },
    }
};

Page TEST2_BROKEN = {
    .text = "You're standing wobbly in the second room on one leg.",
    .options = {
        { .prompt = "Hobble to the first room.", .toPage = &TEST1 },
    }
};

// Consequences
// ------------------------------------------------------------

Ripple BROKE_LEG = {
    .consequences = {
        { .target = &TEST1.options[0], .redirect = &TEST2_BROKEN },
        { .target = &TEST1.options[1], .redirect = &DANCE_FAIL }
    }
};