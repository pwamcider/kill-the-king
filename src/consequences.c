#include "consequences.h"

// Tracking
// ------------------------------------------------------------

bool ACTIVE_RIPPLES[NUM_RIPPLES];
bool CHECKPOINT_RIPPLES[NUM_RIPPLES];

Ripple *ALL_RIPPLES[] = {
    &BROKE_LEG,
};

// Consequences
// ------------------------------------------------------------

Ripple BROKE_LEG = {
    .consequences = {
        { .target = &TEST1.options[0], .redirect = &TEST2_BROKEN },
        { .target = &TEST1.options[1], .redirect = &DANCE_FAIL }
    }
};

