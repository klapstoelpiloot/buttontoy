#undef PUZZLE
#define PUZZLE SimpleToggle
#include "../PuzzleTemplate.h"

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    // Start with the LEDs all red
    leds.SetAll(RED);
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
        case GREEN: leds.Set(index, RED); break;
        default: leds.Set(index, RED); break;
    }
}

void PUZZLE::OnButtonRelease(int index)
{
}
