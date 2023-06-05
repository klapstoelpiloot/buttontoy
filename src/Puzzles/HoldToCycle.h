#undef PUZZLE
#define PUZZLE HoldToCycle
#include "../PuzzleTemplate.h"

#define HoldToCycle_CycleInterval    500
unsigned long HoldToCycle_ChangeTime[NUM_LEDS];
int HoldToCycle_State[NUM_LEDS];

int HoldToCycle_Colors[NUM_LEDS][ALL_COLORS_COUNT] = {
    {RED, BLUE, YELLOW, PURPLE, GREEN},
    {BLUE, RED, PURPLE, YELLOW, GREEN},
    {YELLOW, BLUE, GREEN, PURPLE, RED},
    {PURPLE, GREEN, RED, BLUE, YELLOW},
    {RED, BLUE, GREEN, PURPLE, YELLOW},
};

int HoldToCycle_PrevGreenCount;

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    HoldToCycle_PrevGreenCount = 0;

    for(int i = 0; i < NUM_LEDS; i++)
    {
        HoldToCycle_ChangeTime[i] = 0;
    }

    // Start with the LEDs in random combinations.
    for(int i = 0; i < NUM_LEDS; i++)
    {
        HoldToCycle_State[i] = random(0, ALL_COLORS_COUNT - 1);
        leds.Set(i, HoldToCycle_Colors[i][HoldToCycle_State[i]]);
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
        if((HoldToCycle_ChangeTime[i] > 0) && (t > HoldToCycle_ChangeTime[i]) && !IsFinished())
        {
            HoldToCycle_State[i] = (HoldToCycle_State[i] + 1) % ALL_COLORS_COUNT;
            leds.Set(i, HoldToCycle_Colors[i][HoldToCycle_State[i]]);
            HoldToCycle_ChangeTime[i] += HoldToCycle_CycleInterval;
            anychanged = true;
        }
    }

    if(anychanged)
    {
        int greencount = leds.CountGreenLEDs();
        if(greencount <= HoldToCycle_PrevGreenCount)
        {
            speaker.Play(togglesound0);
        }
        else
        {
            speaker.Play(*ledcountsounds[greencount - 1]);
        }
        HoldToCycle_PrevGreenCount = greencount;
    }
}

void PUZZLE::OnButtonPress(int index)
{
    HoldToCycle_ChangeTime[index] = millis() + HoldToCycle_CycleInterval;
}

void PUZZLE::OnButtonRelease(int index)
{
    HoldToCycle_ChangeTime[index] = 0;
    HoldToCycle_State[index] = 0;
    leds.Set(index, HoldToCycle_Colors[index][HoldToCycle_State[index]]);
    speaker.Play(togglesound1);
}
