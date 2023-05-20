#include "../IMelody.h"

class ButtonSFX : public virtual IMelody
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

// Reverse engineered this from a PC speaker recording by looking at a spectrogram all evening.
int ButtonSFX::notes[] = {
    150, REST, 220, REST, 100
};

int ButtonSFX::durations[] = {
    160, 200, 160, 100, 180
};

int ButtonSFX::notecount = sizeof(notes) / sizeof(notes[0]);
