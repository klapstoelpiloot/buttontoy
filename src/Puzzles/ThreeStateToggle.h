#undef PUZZLE
#define PUZZLE ThreeStateToggle
#include "../PuzzleTemplate.h"

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    // Start with the LEDs in random combinations.
    leds.SetAll(RED);
    leds.Set(random(0, NUM_LEDS), GREEN);
    leds.Set(random(0, NUM_LEDS), BLUE);
}

void PUZZLE::Leave()
{
}

void PUZZLE::Update()
{
}

void PUZZLE::OnButtonPress(int index)
{
    switch(leds.Get(index))
    {
        case RED: leds.Set(index, BLUE); break;
        case BLUE: leds.Set(index, GREEN); break;
        case GREEN: leds.Set(index, RED); break;
        default: leds.Set(index, RED); break;
    }
}

void PUZZLE::OnButtonRelease(int index)
{
}
