#include "initialize.h"
#include "ui.h"

// ------------------------------------------------------------

Line LINE = {
    .color = WHITE,
    .thickness = 1.0,
    .start = { 0.0f, 0.0f }, 
    .stop = { 0.0f, 0.0f },
};

Vector2 GetLineStart() {
    return (Vector2){ FindScreenWidth()/2.0f, 50.0f };
};

Vector2 GetLineStop() {
    return (Vector2){ FindScreenWidth()/2.0f, 670.0f };
};