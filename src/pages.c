#include <stdlib.h>

#include "consequences.h"
#include "pages.h"

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
        { .prompt = "Go to the first room.", .toPage = &TEST1, .causeRipple = NULL },
        { .prompt = "Break leg on way to first room.", .toPage = &TEST1, .causeRipple = &BROKE_LEG },
    }
};

Page TEST2_BROKEN = {
    .text = "You're standing wobbly in the second room on one leg.",
    .options = {
        { .prompt = "Hobble to the first room.", .toPage = &TEST1 },
    }
};