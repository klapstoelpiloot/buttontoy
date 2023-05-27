#include "RewardState.h"
#include "Arduino.h"
#include "RewardMelodies.h"

#define START_DELAY             800
#define GREEN_FLASH_DELAY       400
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

// List of reward sound effects
Reward1 sfx1;
Reward2 sfx2;
Reward3 sfx3;
Reward4 sfx4;
Reward5 sfx5;
Reward6 sfx6;
IMelody* rewardsfx[] = { &sfx1, &sfx2, &sfx3, &sfx4, &sfx5, &sfx6 };

enum Ani
{
    StartDelay,
    GreenFlashMusic,
    GreenFlashDelay,
    EndDelay,
    Finished
};

RewardState::RewardState() :
    currentani(Ani::StartDelay),
    anistarttime(0)
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
                PlayRandomTune();
                StartAni(Ani::GreenFlashMusic);
            }
            break;

        case Ani::GreenFlashMusic:
            GreenFlashLEDs(t);
            if(speaker.IsFinished())
            {
                speaker.Stop();
                StartAni(Ani::GreenFlashDelay);
            }
            break;

        case Ani::GreenFlashDelay:
            GreenFlashLEDs(t);
            if(t > (anistarttime + GREEN_FLASH_DELAY))
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

void RewardState::PlayRandomTune()
{
    int i = random(0, sizeof(rewardsfx) / sizeof(rewardsfx[0]));
    speaker.Play(*rewardsfx[i]);
}

void RewardState::GreenFlashLEDs(unsigned long t)
{
    // Cycle LEDS through colors
    for(int i = 0; i < NUM_LEDS; i++)
    {
        int c = (int)(((t + CYCLE_LED_OFFSET * (NUM_LEDS - i)) / CYCLE_INTERVAL) % CYCLE_NUM_COLORS);
        leds.Set(i, CYCLE_COLORS[c]);
    }
}
