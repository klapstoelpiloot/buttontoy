#undef PUZZLE
#define PUZZLE TimeoutToggle
#include "../PuzzleTemplate.h"

#define RESET_COLOR_TIMEOUT     3000

unsigned long PUZZLE_lasttoggletime[NUM_LEDS];

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    for(int i = 0; i < NUM_LEDS; i++)
    {
        PUZZLE_lasttoggletime[i] = 0;
    }

    // Start with the LEDs in random combinations.
    leds.SetAll(RED);
    int rindex = random(0, NUM_LEDS);
    leds.Set(rindex, BLUE);
    PUZZLE_lasttoggletime[rindex] = millis();
}

void PUZZLE::Leave()
{
}

void PUZZLE::Update()
{
    unsigned long t = millis();
    for(int i = 0; i < NUM_LEDS; i++)
    {
        if((PUZZLE_lasttoggletime[i] > 0) && (t > (PUZZLE_lasttoggletime[i] + RESET_COLOR_TIMEOUT)))
        {
            leds.Set(i, RED);
            PUZZLE_lasttoggletime[i] = 0;
            speaker.Play(togglesound0);
        }
    }
}

void PUZZLE::OnButtonPress(int index)
{
    switch(leds.Get(index))
    {
        case RED: leds.Set(index, BLUE); break;
        case BLUE: leds.Set(index, GREEN); break;
        case GREEN: leds.Set(index, RED); break;
        default: leds.Set(index, RED); break;
    }
    PUZZLE_lasttoggletime[index] = millis();
}

void PUZZLE::OnButtonRelease(int index)
{
}
