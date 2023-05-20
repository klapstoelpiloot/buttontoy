#include "../IMelody.h"

class RewardSFX : public virtual IMelody
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

int RewardSFX::notes[] = {
    150, REST, 200, REST, 220, REST, 280, REST, 310, REST, 360, REST, 450, REST, 600, REST, 800, REST, 1200, REST, 4000, REST,
    4000, 2500, 2000, 1200, 1000, 800, 500, 400, 300, 250, REST,
    4000, 2500, 2000, 1200, 1000, 800, 500, 400, 300, 250, REST,
    1200, 1000, 800, 500, 400, 300, 250, REST,
    500, 600, 800, 900, 1100, 1200, 1400, 1500,
    REST
};

int RewardSFX::durations[] = {
    160, 240, 160, 180, 180, 200, 280, 200, 200, 200, 320, 260, 380, 330, 420, 330, 580, 410, 720, 420, 1200, 800,
    140, 290, 140, 170, 160, 100, 120, 130, 130, 710, 200,
    140, 290, 140, 170, 160, 100, 120, 130, 130, 710, 200,
    170, 160, 100, 120, 130, 130, 710, 200,
    340, 150, 60, 60, 120, 240, 120, 60,
    3000
};

int RewardSFX::notecount = sizeof(notes) / sizeof(notes[0]);
