#undef PUZZLE
#define PUZZLE CycleSequence
#include "../PuzzleTemplate.h"

int CycleSequence_NoGreens[] = { RED, BLUE, YELLOW, PURPLE };
#define CycleSequence_NoGreens_Count  sizeof(CycleSequence_NoGreens) / sizeof(CycleSequence_NoGreens[0])

unsigned long CycleSequence_cycletime = 0;
#define CycleSequence_CycleInterval    1000

ToggleSound0 CycleSequence_togglesound0;

int CycleSequence_NextColor(int index)
{
    switch(leds.Get(index))
    {
        case RED: return BLUE;
        case BLUE: return YELLOW;
        case YELLOW: return PURPLE;
        case PURPLE: return GREEN;
        case GREEN: return RED;
        default: return RED;
    }
}

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    // Start with the LEDs in random combinations.
    for(int i = 0; i < NUM_LEDS; i++)
    {
        leds.Set(i, CycleSequence_NoGreens[random(0, CycleSequence_NoGreens_Count)]);
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

        speaker.Play(CycleSequence_togglesound0);
        CycleSequence_cycletime += CycleSequence_CycleInterval;
    }
}

void PUZZLE::OnButtonPress(int index)
{
    leds.Set(index, CycleSequence_NextColor(index));
}
