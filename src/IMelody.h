#pragma once
#include "Notes.h"

class IMelody
{
public:

    virtual ~IMelody() = default;

protected:

    // Do not allow instantiation
    IMelody() { }
    IMelody(const IMelody&) { }
    IMelody& operator = (const IMelody&) { return *this; }

public:

    // Must return the note and duration for the given note index.
    virtual Note GetNote(int index) = 0;

    // Total number of notes (and rests) in the melody.
    virtual int GetNoteCount() = 0;

    // Speed at which to play the melody.
    virtual int GetTempo() = 0;

    // Duration of a pause after each note. Same unit as note durations.
    virtual int GetNotePause() = 0;

    // Return True when the durations are milliseconds which must be divided by GetTempo.
    // Return False when the durations are whole note dividers (whole note duration is set by GetTempo).
    virtual bool GetAbsDurations() = 0;
};
