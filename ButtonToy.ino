#include "ButtonToy.h"
#include "src/RewardState.h"
#include "src/SoundsEffects.h"

// Puzzle includes
#include "src/Puzzles/HelloWorld.h"
#include "src/Puzzles/SimpleToggle.h"
#include "src/Puzzles/SimpleToggleRndStart.h"
#include "src/Puzzles/ThreeStateToggle.h"
#include "src/Puzzles/FourStateToggle.h"
#include "src/Puzzles/FiveStateToggle.h"
#include "src/Puzzles/TimeoutToggle.h"

// Global objects
Buttons buttons;
LEDs leds;
Speaker speaker;

// Allocation of puzzles
HelloWorld helloworld;
SimpleToggle simpletoggle;
SimpleToggleRndStart simpletogglerndstart;
ThreeStateToggle threestatetoggle;
FourStateToggle fourstatetoggle;
FiveStateToggle fivestatetoggle;
TimeoutToggle timeouttoggle;

// List of puzzles (add reference to puzzles in this array)
IState* puzzles[] = { &helloworld, &simpletoggle, &simpletogglerndstart, &threestatetoggle, &fourstatetoggle, &fivestatetoggle, &timeouttoggle };
int puzzleindex = 0;
IState* currentstate = nullptr;

// State used when receiving a reward
RewardState reward;

// LED toggle sound
ToggleSound1 togglesound1;
ToggleSound2 togglesound2;
ToggleSound3 togglesound3;
ToggleSound4 togglesound4;
ToggleSound5 togglesound5;
ToggleSound6 togglesound6;
IMelody* ledcountsounds[] = { &togglesound2, &togglesound3, &togglesound4, &togglesound5, &togglesound6 };

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
    int greenbeforepress = leds.CountGreenLEDs();
    bool anybuttonpressed = false;
    for(int i = 0; i < NUM_BUTTONS; i++)
    {
        if(buttons.IsPressed(i))
        {
            anybuttonpressed = true;
            currentstate->OnButtonPress(i);
        }
    }

    // Make the appropriate sound for a button press
    if(anybuttonpressed && (currentstate != &reward))
    {
        int greenafterpress = leds.CountGreenLEDs();
        if(greenafterpress <= greenbeforepress)
        {
            speaker.Play(togglesound1);
        }
        else
        {
            speaker.Play(*ledcountsounds[greenafterpress - 1]);
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
