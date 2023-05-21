#include "ButtonToy.h"
#include "src/RewardState.h"
#include "src/Melodies/ToggleSound.h"
#include "src/Puzzles/SimpleToggle.h"
#include "src/Puzzles/SimpleToggleRndStart.h"
#include "src/Puzzles/ThreeStateToggle.h"

// Global objects
Buttons buttons;
LEDs leds;
Speaker speaker;

// Allocation of puzzles
SimpleToggle simpletoggle;
SimpleToggleRndStart simpletogglerndstart;
ThreeStateToggle threestatetoggle;

// List of puzzles (add reference to puzzles in this array)
IState* puzzles[] = { &simpletoggle, &simpletogglerndstart, &threestatetoggle };
int puzzleindex = 0;
IState* currentstate = nullptr;

// State used when receiving a reward
RewardState reward;

// LED toggle sound
ToggleSound togglesound;

void setup()
{
    // Setup global objects
    buttons.Setup();
    leds.Setup();
    speaker.Setup();

    // We may need this for debugging
    Serial.begin(9600);

    // Initialize random numbers
    randomSeed(analogRead(PIN_UNCONNECTED));

    // Start the first puzzle
    currentstate = puzzles[puzzleindex];
    puzzles[puzzleindex]->Enter();
    buttons.FadeLed(true);
}

void loop()
{
    buttons.Update();
    speaker.Update();

    // If a button press was detected, notify the state machine about it
    for(int i = 0; i < NUM_BUTTONS; i++)
    {
        if(buttons.IsPressed(i))
        {
            if(speaker.IsFinished())
            {
                speaker.Play(togglesound);
            }
            currentstate->OnButtonPress(i);
        }
    }

    currentstate->Update();

    // Check if the current state is finished
    if(currentstate->IsFinished())
    {
        currentstate->Leave();

        // Next puzzle?
        if(currentstate == &reward)
        {
            // Go to the next puzzle
            puzzleindex++;
            if(puzzleindex == (sizeof(puzzles) / sizeof(puzzles[0])))
            {
                puzzleindex = 0;
            }
            currentstate = puzzles[puzzleindex];
        }
        else
        {
            // Reward the player
            currentstate = &reward;
        }
        currentstate->Enter();
    }
}
