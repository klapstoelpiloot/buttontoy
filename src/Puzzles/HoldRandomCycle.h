#undef PUZZLE
#define PUZZLE HoldRandomCycle
#include "../PuzzleTemplate.h"

#define HoldRandomCycle_CycleInterval    500
unsigned long HoldRandomCycle_ChangeTime[NUM_LEDS];

int HoldRandomCycle_PrevGreenCount;

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    HoldRandomCycle_PrevGreenCount = 0;

    for(int i = 0; i < NUM_LEDS; i++)
    {
        HoldRandomCycle_ChangeTime[i] = 0;
    }

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
    unsigned long t = millis();
    bool anychanged = false;

    for(int i = 0; i < NUM_LEDS; i++)
    {
        if((HoldRandomCycle_ChangeTime[i] > 0) && (t > HoldRandomCycle_ChangeTime[i]) && !IsFinished())
        {
            leds.Set(i, RandomColor());
            HoldRandomCycle_ChangeTime[i] += HoldRandomCycle_CycleInterval;
            anychanged = true;
        }
    }

    if(anychanged)
    {
        int greencount = leds.CountGreenLEDs();
        if(greencount <= HoldRandomCycle_PrevGreenCount)
        {
            speaker.Play(togglesound0);
        }
        else
        {
            speaker.Play(*ledcountsounds[greencount - 1]);
        }
        HoldRandomCycle_PrevGreenCount = greencount;
    }
}

void PUZZLE::OnButtonPress(int index)
{
    HoldRandomCycle_ChangeTime[index] = millis() + HoldRandomCycle_CycleInterval;

    // Change to a random, but different color
    int currentcolor = leds.Get(index);
    do
    {
        leds.Set(index, RandomColor());
    }
    while(leds.Get(index) == currentcolor);
}

void PUZZLE::OnButtonRelease(int index)
{
    HoldRandomCycle_ChangeTime[index] = 0;
}
