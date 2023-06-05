#undef PUZZLE
#define PUZZLE HoldDown
#include "../PuzzleTemplate.h"

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    // Start with the LEDs red
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
    leds.Set(index, GREEN);
}

void PUZZLE::OnButtonRelease(int index)
{
    leds.Set(index, RED);
    speaker.Play(togglesound0);
}
