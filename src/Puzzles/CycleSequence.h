#undef PUZZLE
#define PUZZLE CycleSequence
#include "../PuzzleTemplate.h"

unsigned long CycleSequence_cycletime = 0;
#define CycleSequence_CycleInterval    1000

int CycleSequence_NextColor(int index)
{
    return ALL_COLORS[(leds.Get(index) + 1) % ALL_COLORS_COUNT];
}

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

    CycleSequence_cycletime = millis() + CycleSequence_CycleInterval;
}

void PUZZLE::Leave()
{
}

void PUZZLE::Update()
{
    unsigned long t = millis();
    if((t > CycleSequence_cycletime) && !IsFinished())
    {
        for(int i = 0; i < NUM_LEDS; i++)
        {
            leds.Set(i, CycleSequence_NextColor(i));
        }

        speaker.Play(togglesound0);
        CycleSequence_cycletime += CycleSequence_CycleInterval;
    }
}

void PUZZLE::OnButtonPress(int index)
{
    leds.Set(index, CycleSequence_NextColor(index));
}

void PUZZLE::OnButtonRelease(int index)
{
}
