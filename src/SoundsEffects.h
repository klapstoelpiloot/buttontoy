#include "IMelody.h"

class ToggleSound0 : public virtual IMelody
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

int ToggleSound0::notes[] = {
    50, 180, 50
};

int ToggleSound0::durations[] = {
    180, 160, 180
};

int ToggleSound0::notecount = sizeof(ToggleSound0::notes) / sizeof(ToggleSound0::notes[0]);

// ========================================================================================================

class ToggleSound1 : public virtual IMelody
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

int ToggleSound1::notes[] = {
    150, REST, 220, REST, 100
};

int ToggleSound1::durations[] = {
    160, 200, 160, 100, 180
};

int ToggleSound1::notecount = sizeof(ToggleSound1::notes) / sizeof(ToggleSound1::notes[0]);

// ========================================================================================================

class ToggleSound2 : public virtual IMelody
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

int ToggleSound2::notes[] = {
    150, REST, 220, REST, 100, REST, NOTE_C5, NOTE_E5
};

int ToggleSound2::durations[] = {
    160, 200, 160, 100, 180, 200, 800, 600
};

int ToggleSound2::notecount = sizeof(ToggleSound2::notes) / sizeof(ToggleSound2::notes[0]);

// ========================================================================================================

class ToggleSound3 : public virtual IMelody
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

int ToggleSound3::notes[] = {
    150, REST, 220, REST, 100, REST, NOTE_C5, NOTE_G5
};

int ToggleSound3::durations[] = {
    160, 200, 160, 100, 180, 200, 800, 600
};

int ToggleSound3::notecount = sizeof(ToggleSound3::notes) / sizeof(ToggleSound3::notes[0]);

// ========================================================================================================

class ToggleSound4 : public virtual IMelody
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

int ToggleSound4::notes[] = {
    150, REST, 220, REST, 100, REST, NOTE_C5, NOTE_G5, REST, NOTE_A5
};

int ToggleSound4::durations[] = {
    160, 200, 160, 100, 180, 200, 800, 600, 200, 600
};

int ToggleSound4::notecount = sizeof(ToggleSound4::notes) / sizeof(ToggleSound4::notes[0]);

// ========================================================================================================

class ToggleSound5 : public virtual IMelody
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

int ToggleSound5::notes[] = {
    150, REST, 220, REST, 100, REST, NOTE_C5, NOTE_G5, REST, NOTE_A5, REST, NOTE_B5
};

int ToggleSound5::durations[] = {
    160, 200, 160, 100, 180, 200, 800, 600, 200, 600, 200, 600
};

int ToggleSound5::notecount = sizeof(ToggleSound5::notes) / sizeof(ToggleSound5::notes[0]);

// ========================================================================================================

class ToggleSound6 : public virtual IMelody
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

int ToggleSound6::notes[] = {
    150, REST, 220, REST, 100, REST, NOTE_C5, NOTE_G5, REST, NOTE_A5, REST, NOTE_B5, REST, NOTE_D6
};

int ToggleSound6::durations[] = {
    160, 200, 160, 100, 180, 200, 800, 600, 200, 600, 200, 600, 200, 600
};

int ToggleSound6::notecount = sizeof(ToggleSound6::notes) / sizeof(ToggleSound6::notes[0]);
