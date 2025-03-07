#include "initialize.h"
#include "ui.h"

// Structs
// ------------------------------------------------------------

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
    .start = { 0.0f, 0.0f }, 
    .stop = { 0.0f, 0.0f },
};

// Functions
// ------------------------------------------------------------

Vector2 GetLineStart() {
    return (Vector2){ FindScreenWidth()/2.0f, 50.0f };
};

Vector2 GetLineStop() {
    return (Vector2){ FindScreenWidth()/2.0f, 670.0f };
};