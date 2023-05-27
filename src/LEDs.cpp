#include "LEDs.h"
#include "Arduino.h"

// 2 dimensional array for LED pins
// First dimension is the LED index, second dimension is the color component (RGB)
#define INDEX_RED       0
#define INDEX_GREEN     1
#define INDEX_BLUE      2
#define NUM_COMPONENTS  3
int PINS[NUM_LEDS][NUM_COMPONENTS] = {
    { PIN_RED0, PIN_GREEN0, PIN_BLUE0 },
    { PIN_RED1, PIN_GREEN1, PIN_BLUE1 },
    { PIN_RED2, PIN_GREEN2, PIN_BLUE2 },
    { PIN_RED3, PIN_GREEN3, PIN_BLUE3 },
    { PIN_RED4, PIN_GREEN4, PIN_BLUE4 },
};

LEDs::LEDs()
{
    for(int i = 0; i < NUM_LEDS; i++)
    {
        ledstate[i] = OFF;
    }
}

void LEDs::Setup()
{
    for(int i = 0; i < NUM_LEDS; i++)
    {
        for(int c = 0; c < NUM_COMPONENTS; c++)
        {
            pinMode(PINS[i][c], OUTPUT);
            digitalWrite(PINS[i][c], LOW);
        }
    }
}

void LEDs::Set(int index, int state)
{
    ledstate[index] = state;
    bool r = (state & RED) == RED;
    bool g = (state & GREEN) == GREEN;
    bool b = (state & BLUE) == BLUE;
    digitalWrite(PINS[index][INDEX_RED], r ? HIGH : LOW);
    digitalWrite(PINS[index][INDEX_GREEN], g ? HIGH : LOW);
    digitalWrite(PINS[index][INDEX_BLUE], b ? HIGH : LOW);
}

void LEDs::SetAll(int state)
{
    for(int i = 0; i < NUM_LEDS; i++)
    {
        Set(i, state);
    }
}

int LEDs::CountGreenLEDs()
{
    int greencount = 0;
    for(int i = 0; i < NUM_LEDS; i++)
    {
        if(ledstate[i] == GREEN)
        {
            greencount++;
        }
    }
    return greencount;
}
