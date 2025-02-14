#pragma once

// Structure Definitions
// ------------------------------------------------------------

typedef struct Option
{
    char prompt[256];
    struct Event* to_event;
} Option;

typedef struct Page
{
    char text[2048];
    struct Option options[4];
    bool checkpoint;
    bool game_over;
    bool raised_alarm;
    bool* page_visited;
} Page;

// ------------------------------------------------------------