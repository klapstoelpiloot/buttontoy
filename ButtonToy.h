#pragma once
#include "src/Buttons.h"
#include "src/LEDs.h"
#include "src/Speaker.h"
#include "src/IState.h"

class ToggleSound0;
class ToggleSound1;
class ToggleSound2;
class ToggleSound3;
class ToggleSound4;
class ToggleSound5;
class ToggleSound6;

extern Buttons buttons;
extern LEDs leds;
extern Speaker speaker;
extern ToggleSound0 togglesound0;
extern ToggleSound1 togglesound1;
extern ToggleSound2 togglesound2;
extern ToggleSound3 togglesound3;
extern ToggleSound4 togglesound4;
extern ToggleSound5 togglesound5;
extern ToggleSound6 togglesound6;
extern IMelody* ledcountsounds[];

// All colors that we use in puzzles are RED, BLUE, YELLOW, PURPLE and GREEN.
// Note that green is the last color, so we can exclude green by simply pretending the array is one smaller.
extern int ALL_COLORS[];
#define ALL_COLORS_COUNT        5
#define COLORS_NOGREEN_COUNT    (ALL_COLORS_COUNT - 1)

// Returns a random color for use in puzzles
int RandomColor();

// Returns a random color for use in puzzles, but never returns green
int RandomColorNoGreen();

// Returns the index of the specified color in the ALL_COLORS array
// Returns -1 when the specified color is not in the ALL_COLORS array
int ColorIndex(int color);
