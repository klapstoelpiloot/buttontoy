#include "RewardState.h"
#include "Arduino.h"
#include "Melodies/RewardSFX.h"

#define START_DELAY             400
#define END_DELAY               400
#define CYCLE_INTERVAL          1
#define CYCLE_LED_OFFSET        50
int CYCLE_COLORS[] = {
       OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,
       OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,
       OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,
       OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,
     GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
     GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN,
     GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE,
     WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
     GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE, GREEN, WHITE, WHITE,
     GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN, GREEN, WHITE, GREEN,
     GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,
       OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,   OFF, GREEN, GREEN,
       OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,
       OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,   OFF,   OFF, GREEN,
       OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF,   OFF
};
#define CYCLE_NUM_COLORS        (sizeof(CYCLE_COLORS) / sizeof(CYCLE_COLORS[0]))

RewardSFX sfx;

enum Ani
{
    StartDelay,
    GreenFlash,
    EndDelay,
    Finished
};

RewardState::RewardState() :
    currentani(Ani::StartDelay)
{
}

void RewardState::Enter()
{
    StartAni(Ani::StartDelay);
    buttons.FadeLed(false);
}

void RewardState::Leave()
{
    buttons.FadeLed(true);
}

void RewardState::Update()
{
    unsigned long t = millis();

    switch(currentani)
    {
        case Ani::StartDelay:
            if(t > (anistarttime + START_DELAY))
            {
                speaker.Play(sfx);
                StartAni(Ani::GreenFlash);
            }
            break;

        case Ani::GreenFlash:
            // Cycle LEDS through colors
            for(int i = 0; i < NUM_LEDS; i++)
            {
                int c = (((int)(t - anistarttime) + CYCLE_LED_OFFSET * (NUM_LEDS - i)) / CYCLE_INTERVAL) % CYCLE_NUM_COLORS;
                leds.Set(i, CYCLE_COLORS[c]);
            }
            if(speaker.IsFinished())
            {
                leds.SetAll(OFF);
                StartAni(Ani::EndDelay);
            }
            break;

        case Ani::EndDelay:
            if(t > (anistarttime + END_DELAY))
            {
                StartAni(Ani::Finished);
            }
            break;

        case Ani::Finished:
            break;
    }
}

void RewardState::OnButtonPress(int index)
{
    // This state doesn't respond to buttons
}

bool RewardState::IsFinished()
{
    return (currentani == Ani::Finished);
}

void RewardState::StartAni(int ani)
{
    currentani = ani;
    anistarttime = millis();
}
