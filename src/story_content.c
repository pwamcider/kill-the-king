#include "story_content.h"

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