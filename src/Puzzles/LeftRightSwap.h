#undef PUZZLE
#define PUZZLE LeftRightSwap
#include "../PuzzleTemplate.h"

int LeftRightSwap_NoGreens[] = { RED, BLUE, YELLOW };
#define LeftRightSwap_NoGreens_Count  sizeof(LeftRightSwap_NoGreens) / sizeof(LeftRightSwap_NoGreens[0])

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    // Start with the LEDs in random combinations.
    for(int i = 0; i < NUM_LEDS; i++)
    {
        leds.Set(i, LeftRightSwap_NoGreens[random(0, LeftRightSwap_NoGreens_Count)]);
    }

    // There must be at least one non-red
    leds.Set(random(0, NUM_LEDS), BLUE);
    leds.Set(random(0, NUM_LEDS), YELLOW);
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
            // Don't do anything
            break;

        case BLUE:
            // Swap with the left. Far left becomes green.
            if(index == 0)
            {
                leds.Set(index, GREEN);
            }
            else
            {
                int other = leds.Get(index - 1);
                leds.Set(index - 1, BLUE);
                leds.Set(index, other);
            }
            break;

        case YELLOW:
            // Swap with the right. Far right becomes green.
            if(index == (NUM_LEDS - 1))
            {
                leds.Set(index, GREEN);
            }
            else
            {
                int other = leds.Get(index + 1);
                leds.Set(index + 1, YELLOW);
                leds.Set(index, other);
            }
            break;

        case GREEN:
            leds.Set(index, RED);
            break;

        default:
            leds.Set(index, RED);
            break;
    }
}
