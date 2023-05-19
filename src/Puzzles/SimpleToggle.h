#define PUZZLE SimpleToggle
#include "../PuzzleTemplate.h"

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    // Start with the LEDs in random red/green combinations.
    // Make sure there are 1 or 2 green and the rest red.
    leds.SetAll(RED);
    leds.Set(random(0, NUM_LEDS), GREEN);
    leds.Set(random(0, NUM_LEDS), GREEN);
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
        case RED: leds.Set(index, GREEN); break;
        case GREEN: leds.Set(index, BLUE); break;
        default: leds.Set(index, RED); break;
    }
}
