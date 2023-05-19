#include "ButtonToy.h"
#include "src/Puzzles/SimpleToggle.h"
#include "src/Melodies/Tetris.h"

// Global objects
Buttons buttons;
LEDs leds;
Speaker speaker;

// Allocation of puzzles
SimpleToggle simpletoggle;

// List of puzzles (add reference to puzzles in this array)
IState* puzzles[] = { &simpletoggle };
int puzzleindex = 0;

// Allocation of melodies
Tetris tetris;

// List of melodies (only for puzzle rewards)
IMelody* melodies[] = { &tetris };

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
    puzzles[puzzleindex]->Enter();
}

void loop()
{
    buttons.Update();
    speaker.Update();

    // If a button press was detected, notify the puzzle about it
    for(int i = 0; i < NUM_BUTTONS; i++)
    {
        if(buttons.IsPressed(i))
        {
            puzzles[puzzleindex]->OnButtonPress(i);
        }
    }

    puzzles[puzzleindex]->Update();

    // Check if a puzzle is finished
    if(puzzles[puzzleindex]->IsFinished())
    {
        // Go to the next puzzle
        puzzles[puzzleindex]->Leave();
        puzzleindex++;
        if(puzzleindex == (sizeof(puzzles) / sizeof(puzzles[0])))
        {
            puzzleindex = 0;
        }
        puzzles[puzzleindex]->Enter();
    }
}
