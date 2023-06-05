#pragma once
#include "Defines.h"

class Buttons
{
private:

    // These are only updated after debouncing/timeout.
    // `down` tells if a button is being held down.
    // `pressed` tells if a button was pressed since last Update()
    // `released` tells if a button was pressed since last Update()
    bool down[NUM_BUTTONS];
    bool pressed[NUM_BUTTONS];
    bool released[NUM_BUTTONS];

    // These are updated every Update() call.
    bool measuredstate[NUM_BUTTONS];
    unsigned long changetime[NUM_BUTTONS];

    // These are for the LEDs in the buttons
    double ledfade;
    bool ledstate;
    unsigned long lastfadetime;

public:

    Buttons();
    void Setup();
    void Update();
    bool IsDown(int index) { return down[index]; }
    bool IsPressed(int index) { return pressed[index]; }
    bool IsReleased(int index) { return released[index]; }
    void FadeLed(bool on);
    void SetLed(bool on);
};
