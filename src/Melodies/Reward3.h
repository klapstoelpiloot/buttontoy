#include "../IMelody.h"

class Reward3 : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 160; }
    virtual int GetNotePause() override { return 0; }
    virtual bool GetAbsDurations() override { return false; }
    static int notes[];
    static int durations[];
    static int notecount;
};

int Reward3::notes[] = {
    NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, REST, NOTE_A4
};

int Reward3::durations[] = {
    4, 8, 8, 4, 8, 8,
    4, 8, 8, 4, 8, 8,
    4, 8, 4, 4,
    4, 4, 128, 8
};

int Reward3::notecount = sizeof(Reward3::notes) / sizeof(Reward3::notes[0]);
