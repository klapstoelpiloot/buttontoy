#undef PUZZLE
#define PUZZLE HelloWorld
#include "../PuzzleTemplate.h"

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    // Start with the LEDs off
    leds.SetAll(OFF);
}

void PUZZLE::Leave()
{
}

void PUZZLE::Update()
{
}

void PUZZLE::OnButtonPress(int index)
{
    // Turn the associated LED on (green) when a button is pushed
    leds.Set(index, GREEN);
}
