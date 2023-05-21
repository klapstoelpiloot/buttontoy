#include "../IMelody.h"

class ToggleSound : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 10; }
    virtual int GetNotePause() override { return 1; }
    virtual bool GetAbsDurations() override { return true; }
    static int notes[];
    static int durations[];
    static int notecount;
};

int ToggleSound::notes[] = {
    150, REST, 220, REST, 100
};

int ToggleSound::durations[] = {
    160, 200, 160, 100, 180
};

int ToggleSound::notecount = sizeof(ToggleSound::notes) / sizeof(ToggleSound::notes[0]);
