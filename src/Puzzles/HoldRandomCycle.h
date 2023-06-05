#undef PUZZLE
#define PUZZLE HoldRandomCycle
#include "../PuzzleTemplate.h"

unsigned long HoldRandomCycle_cycletime = 0;
#define HoldRandomCycle_CycleInterval    500

bool HoldRandomCycle_HoldState[NUM_BUTTONS];

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    for(int i = 0; i < NUM_BUTTONS; i++)
    {
        HoldRandomCycle_HoldState[i] = false;
    }

    // Start with the LEDs in random combinations.
    for(int i = 0; i < NUM_LEDS; i++)
    {
        leds.Set(i, RandomColorNoGreen());
    }

    // TODO: Maybe check that not all colors are the same?

    HoldRandomCycle_cycletime = millis() + HoldRandomCycle_CycleInterval;
}

void PUZZLE::Leave()
{
}

void PUZZLE::Update()
{
    unsigned long t = millis();
    if((t > HoldRandomCycle_cycletime) && !IsFinished())
    {
        bool anychanging = false;
        for(int i = 0; i < NUM_LEDS; i++)
        {
            if(!HoldRandomCycle_HoldState[i])
            {
                leds.Set(i, RandomColor());
                anychanging = true;
            }
        }

        if(anychanging)
        {
            speaker.Play(togglesound0);
        }

        HoldRandomCycle_cycletime += HoldRandomCycle_CycleInterval;
    }
}

void PUZZLE::OnButtonPress(int index)
{
    if(!HoldRandomCycle_HoldState[index])
    {
        HoldRandomCycle_HoldState[index] = true;
    }
    else
    {
        HoldRandomCycle_HoldState[index] = false;

        // Change to a random, but different color
        int currentcolor = leds.Get(index);
        do
        {
            leds.Set(index, RandomColor());
        }
        while(leds.Get(index) == currentcolor);
    }
}

void PUZZLE::OnButtonRelease(int index)
{
}
