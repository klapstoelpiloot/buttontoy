#pragma once
#include "Defines.h"

class LEDs
{
private:

    // Current state of the LEDs
    int ledstate[NUM_LEDS];

public:

    LEDs();
    void Setup();
    int Get(int index) { return ledstate[index]; }
    void Set(int index, int state);
    void SetAll(int state);
    bool AreAllGreen();
};
