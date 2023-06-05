#pragma once
#include "src/Buttons.h"
#include "src/LEDs.h"
#include "src/Speaker.h"
#include "src/IState.h"

class ToggleSound0;

extern Buttons buttons;
extern LEDs leds;
extern Speaker speaker;
extern ToggleSound0 togglesound0;

// All colors that we use in puzzles are RED, BLUE, YELLOW, PURPLE and GREEN.
// Note that green is the last color, so we can exclude green by simply pretending the array is one smaller.
extern int ALL_COLORS[];
#define ALL_COLORS_COUNT        5
#define COLORS_NOGREEN_COUNT    (ALL_COLORS_COUNT - 1)

// Returns a random color for use in puzzles
int RandomColor();

// Returns a random color for use in puzzles, but never returns green
int RandomColorNoGreen();
