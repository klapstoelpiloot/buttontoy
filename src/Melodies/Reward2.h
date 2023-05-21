#include "../IMelody.h"

class Reward2 : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 10; }
    virtual int GetNotePause() override { return 0; }
    virtual bool GetAbsDurations() override { return true; }
    static int notes[];
    static int durations[];
    static int notecount;
};

int Reward2::notes[] = {
    NOTE_GS3, NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4,
    NOTE_B3, NOTE_DS4, NOTE_FS4, NOTE_B4, NOTE_C5, NOTE_B4
};

int Reward2::durations[] = {
    850, 850, 850, 850, 850, 4160,
    1250, 1250, 1250, 1250, 1250, 8320
};

int Reward2::notecount = sizeof(Reward2::notes) / sizeof(Reward2::notes[0]);
