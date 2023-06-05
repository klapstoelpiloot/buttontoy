#undef PUZZLE
#define PUZZLE RandomOrder
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
    switch(leds.Get(index))
    {
        case RED:
        case BLUE:
        case YELLOW:
        case PURPLE:
        case GREEN:
            leds.Set(index, RandomColor());
            break;

        default:
            leds.Set(index, RED);
            break;
    }
}

void PUZZLE::OnButtonRelease(int index)
{
}
