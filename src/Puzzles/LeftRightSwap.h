#undef PUZZLE
#define PUZZLE LeftRightSwap
#include "../PuzzleTemplate.h"

int LeftRightSwap_NoGreens[] = { RED, BLUE };
#define LeftRightSwap_NoGreens_Count  (sizeof(LeftRightSwap_NoGreens) / sizeof(LeftRightSwap_NoGreens[0]))

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

        case RED:
            // Swap with the right. Far right becomes green.
            if(index == (NUM_LEDS - 1))
            {
                leds.Set(index, GREEN);
            }
            else
            {
                int other = leds.Get(index + 1);
                leds.Set(index + 1, RED);
                leds.Set(index, other);
            }
            break;

        case GREEN:
            // Become either red or blue
            leds.Set(index, LeftRightSwap_NoGreens[random(0, LeftRightSwap_NoGreens_Count)]);
            break;

        default:
            leds.Set(index, RED);
            break;
    }
}

void PUZZLE::OnButtonRelease(int index)
{
}
