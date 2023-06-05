#include "ButtonToy.h"
#include "src/RewardState.h"
#include "src/SoundsEffects.h"

// Puzzle includes
#include "src/Puzzles/HelloWorld.h"
#include "src/Puzzles/SimpleToggle.h"
#include "src/Puzzles/ThreeStateToggle.h"
#include "src/Puzzles/FiveStateToggle.h"
#include "src/Puzzles/TimeoutToggle.h"
#include "src/Puzzles/RandomOrder.h"
#include "src/Puzzles/CycleSequence.h"
#include "src/Puzzles/LeftRightSwap.h"
#include "src/Puzzles/HoldDown.h"
#include "src/Puzzles/HoldRandomCycle.h"
#include "src/Puzzles/MirroredButtons.h"
#include "src/Puzzles/HoldToCycle.h"

// Global objects
Buttons buttons;
LEDs leds;
Speaker speaker;

// Allocation of puzzles
HelloWorld helloworld;
SimpleToggle simpletoggle;
ThreeStateToggle threestatetoggle;
FiveStateToggle fivestatetoggle;
TimeoutToggle timeouttoggle;
RandomOrder randomorder;
CycleSequence cyclesequence;
LeftRightSwap leftrightswap;
HoldDown holddown;
HoldRandomCycle holdrandomcycle;
MirroredButtons mirroredbuttons;
HoldToCycle holdtocycle;

// List of puzzles (add reference to puzzles in this array)
IState* puzzles[] = { &helloworld, &simpletoggle, &threestatetoggle, &fivestatetoggle, &randomorder, &timeouttoggle, &mirroredbuttons,
    &cyclesequence, &leftrightswap, &holddown, &holdrandomcycle, &holdtocycle };
int puzzleindex = 0;
IState* currentstate = nullptr;

// State used when receiving a reward
RewardState reward;

// LED toggle sounds
ToggleSound0 togglesound0;
ToggleSound1 togglesound1;
ToggleSound2 togglesound2;
ToggleSound3 togglesound3;
ToggleSound4 togglesound4;
ToggleSound5 togglesound5;
ToggleSound6 togglesound6;
IMelody* ledcountsounds[] = { &togglesound2, &togglesound3, &togglesound4, &togglesound5, &togglesound6 };

// The colors we use in puzzles
int ALL_COLORS[] = { RED, BLUE, YELLOW, PURPLE, GREEN };

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
        else if(buttons.IsReleased(i))
        {
            currentstate->OnButtonRelease(i);
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

// Returns a random color for use in puzzles
int RandomColor()
{
    return ALL_COLORS[random(0, ALL_COLORS_COUNT)];
}

// Returns a random color for use in puzzles, but never returns green
int RandomColorNoGreen()
{
    return ALL_COLORS[random(0, COLORS_NOGREEN_COUNT)];
}

// Returns the index of the specified color in the ALL_COLORS array
// Returns -1 when the specified color is not in the ALL_COLORS array
int ColorIndex(int color)
{
    for(int i = 0; i < ALL_COLORS_COUNT; i++)
    {
        if(ALL_COLORS[i] == color)
            return i;
    }

    return -1;
}
