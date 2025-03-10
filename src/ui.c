#include "ui.h"

/// ------------------------------------------------------------

int SCREENWIDTH = 1280;
int SCREENHEIGHT = 720;

// Initializations
// ------------------------------------------------------------

Button BUTTON = {
    .frameHeight = 0.0,
    .numFrames = 3,
    .state = 0, // 0 = Idle, 1 = Hover, 2 = Pressed
    .color = WHITE,
    .spriteOrigin = { 0.0f, 0.0f },
};

Layout LAYOUT = {
    .buttonPosition = {
         { 850.0f, 200.0f }, {850.0f, 300.0f }, { 850.0f, 400.0f }, { 850.0f, 500.0f } 
    },
    .promptPosition = {
         { 800.0f, 200.0f }, {800.0f, 300.0f }, { 800.0f, 400.0f }, { 800.0f, 500.0f } 
    },
};

Line LINE = {
    .color = WHITE,
    .thickness = 1.0,
    .start = { 640.0f, 50.0f }, 
    .stop = { 640.0f, 670.0f },
};

Text TEXT = {
    .rotation = 0.0f,
    .printSpeed = 1,    // Lower number increases speed.
    .size = 15,
    .spacing = 4,
    .vertSpacing = 10,
    .color = WHITE,
    .origin = { 0.0f, 0.0f },
    .position = { 50.0f, 50.0f },
};