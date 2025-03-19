#include "consequences.h"

// Consequences
// ------------------------------------------------------------

Ripple BROKE_LEG = {
    .consequences = {
        { .target = &TEST1.options[0], .redirect = &TEST2_BROKEN },
        { .target = &TEST1.options[1], .redirect = &DANCE_FAIL }
    }
};