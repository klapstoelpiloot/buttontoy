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

    virtual Note GetNote(int index) = 0;
    virtual int GetNoteCount() = 0;
    virtual int GetTempo() = 0;
    virtual int GetNotePause() = 0;
};
