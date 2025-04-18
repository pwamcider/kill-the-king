#include <stdlib.h>

#include "consequences.h"
#include "pages.h"
#include "story_engine.h"

// Pages
// ------------------------------------------------------------

Page MENU0 = {
    .text = "KILL THE KING",
    // TODO - remove this text once main menu art is in.
    .options = {
        { .prompt = "Start Game", .toPage = &TEST1 },
        { .prompt = "Quit Game", .toPage = &QUIT }
    }
};

Page QUIT;

Page GAME_OVER = {
    .text = "Game over. Thank you for playing.",
    .options = {
        { .prompt = "Main Menu", .toPage = &MENU0 },
        { .prompt = "Quit Game", .toPage = &QUIT }
    },
    .gameOver = true
};

Page FAIL_STATE = {
    .text ="You died.",
    .options = {
        { .prompt = "Return to checkpoint.", .toPage = &GAME_OVER },
        { .prompt = "Quit Game", .toPage = &QUIT }
    },
    .failState = true
};

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
        { .prompt = "Go to the first room.", .toPage = &TEST1, },
        { .prompt = "Break leg on way to first room.", .toPage = &TEST1, .causeRipple = &BROKE_LEG },
        { .prompt = "Go to the third room.", .toPage =&TEST3 }
    }
};

Page TEST2_BROKEN = {
    .text = "You're standing wobbly in the second room on one leg.",
    .options = {
        { .prompt = "Hobble to the first room.", .toPage = &TEST1 },
        { .prompt = "Hobble to the third room.", .toPage = &TEST3 }
    }
};

Page TEST3 = {
    .text = "You're standing in the third room with no way out.", 
    .options = {
        { .prompt = "Walk into the bottomless pit\n"
                    "and fall to your death.", .toPage = &FAIL_STATE },
        { .prompt = "Go back to the first room. This one's awful.", .toPage = &TEST1 },
        { .prompt = "Game Over test.", .toPage = &GAME_OVER }
    },
    .checkpoint = true
};