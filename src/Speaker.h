#pragma once
#include "Defines.h"
#include "IMelody.h"

class Speaker
{
private:

    IMelody* melody;
    int currentnote;
    unsigned long nextnotetime;
    int wholenoteduration;

    void PlayNextNote();

public:

    Speaker();
    void Setup();
    void Update();
    void Play(IMelody& m);
    void Stop();
    bool IsFinished() { return (melody == nullptr); }
};
