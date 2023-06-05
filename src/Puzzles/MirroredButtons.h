#undef PUZZLE
#define PUZZLE MirroredButtons
#include "../PuzzleTemplate.h"

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    // Start with the LEDs in random combinations.
    for(int i = 0; i < NUM_LEDS; i++)
    {
        leds.Set(i, RandomColorNoGreen());
    }
}

void PUZZLE::Leave()
{
}

void PUZZLE::Update()
{
}

void PUZZLE::OnButtonPress(int index)
{
    int mirrorindex = (NUM_BUTTONS - 1) - index;
    leds.Set(mirrorindex, ALL_COLORS[(ColorIndex(leds.Get(mirrorindex)) + 1) % ALL_COLORS_COUNT]);
}

void PUZZLE::OnButtonRelease(int index)
{
}
