#include "ButtonToy.h"
#include "src/Puzzles/SimpleToggle.h"
#include "src/Puzzles/SimpleToggleRndStart.h"
#include "src/Melodies/Tetris.h"
#include "src/RewardState.h"
#include "src/Melodies/ButtonSFX.h"

// Global objects
Buttons buttons;
LEDs leds;
Speaker speaker;

// Allocation of puzzles
SimpleToggle simpletoggle;
SimpleToggleRndStart simpletogglerndstart;

// List of puzzles (add reference to puzzles in this array)
IState* puzzles[] = { &simpletoggle, &simpletogglerndstart };
int puzzleindex = 0;
IState* currentstate = nullptr;

// Allocation of melodies
Tetris tetris;

// List of melodies (only for puzzle rewards)
IMelody* melodies[] = { &tetris };

// When receiving a reward
RewardState reward;

// Button sound
ButtonSFX buttonsfx;

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
                speaker.Play(buttonsfx);
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
            // Play a random melody
            //int melodyindex = random(0, sizeof(melodies) / sizeof(melodies[0]));
            //speaker.Play(*melodies[melodyindex]);

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
