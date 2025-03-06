#include "buttons.h"

Button BUTTON = {
    .frameHeight = 0.0,
    .alignmentX = 850,
    .numFrames = 3,
    .offsetY = 1,
    .state = 0, // 0 = Idle, 1 = Hover, 2 = Pressed
    .color = WHITE,
    .spriteOrigin = { 0.0f, 0.0f },
};