#include "../IMelody.h"

class Tetris : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(melody[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 160; }
    virtual int GetNotePause() override { return 0; }
    static int melody[];
    static int durations[];
    static int notecount;
};

// Credit to HiBit (https://www.hibit.dev) for the melody below
int Tetris::melody[] = {
    NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5,
  
    NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, REST, 
  
    NOTE_E5, NOTE_C5,
    NOTE_D5, NOTE_B4,
    NOTE_C5, NOTE_A4,
    NOTE_GS4, NOTE_GS4, REST, 
    NOTE_E5, NOTE_C5,
    NOTE_D5, NOTE_B4,
    NOTE_C5, NOTE_E5, NOTE_A5,
    NOTE_GS5
};

int Tetris::durations[] = {
    4, 8, 8, 4, 8, 8,
    4, 8, 8, 4, 8, 8,
    4, 8, 4, 4,
    4, 4, 8, 4, 8, 8,
  
    4, 8, 4, 8, 8,
    4, 8, 4, 8, 8,
    4, 8, 8, 4, 4,
    4, 4, 4, 4,
  
    2, 2,
    2, 2,
    2, 2,
    2, 4, 8, 
    2, 2,
    2, 2,
    4, 4, 2,
    2
};

int Tetris::notecount = sizeof(melody) / sizeof(melody[0]);
