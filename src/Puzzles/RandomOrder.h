#undef PUZZLE
#define PUZZLE RandomOrder
#include "../PuzzleTemplate.h"

int RandomOrder_NoGreens[] = { RED, BLUE, YELLOW, PURPLE };
int RandomOrder_AllColors[] = { RED, BLUE, YELLOW, PURPLE, GREEN };
#define RandomOrder_NoGreens_Count  sizeof(RandomOrder_NoGreens) / sizeof(RandomOrder_NoGreens[0])
#define RandomOrder_AllColors_Count  sizeof(RandomOrder_AllColors) / sizeof(RandomOrder_AllColors[0])

PUZZLE::PUZZLE()
{
}

void PUZZLE::Enter()
{
    // Start with the LEDs in random combinations.
    for(int i = 0; i < NUM_LEDS; i++)
    {
        leds.Set(i, RandomOrder_NoGreens[random(0, RandomOrder_NoGreens_Count)]);
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
    int nextcolor = RandomOrder_AllColors[random(0, RandomOrder_AllColors_Count)];
    switch(leds.Get(index))
    {
        case RED:
        case BLUE:
        case YELLOW:
        case PURPLE:
            leds.Set(index, nextcolor);
            break;

        case GREEN:
            leds.Set(index, nextcolor);
            break;

        default:
            leds.Set(index, RED);
            break;
    }
}
