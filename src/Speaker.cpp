#include "Speaker.h"
#include "Arduino.h"

Speaker::Speaker() :
    melody(nullptr),
    currentnote(-1),
    nextnotetime(0),
    wholenoteduration(0)
{
}

void Speaker::Setup()
{
}

void Speaker::Update()
{
    if((melody != nullptr) && (millis() >= nextnotetime))
    {
        PlayNextNote();
    }
}

void Speaker::Play(IMelody& m)
{
    melody = &m;
    wholenoteduration = (60000 * 4) / melody->GetTempo();
    currentnote = -1;
    PlayNextNote();
}

void Speaker::Stop()
{
    noTone(PIN_SPEAKER);
    melody = nullptr;
    currentnote = -1;
}

void Speaker::PlayNextNote()
{
    if(currentnote >= melody->GetNoteCount())
    {
        Stop();
        return;
    }

    currentnote++;
    Note n = melody->GetNote(currentnote);
    int toneduration = wholenoteduration / n.Duration;
    int pauseduration = (melody->GetNotePause() > 0) ? (wholenoteduration / melody->GetNotePause()) : 0;
    if(n.Tone > 0)
    {
        tone(PIN_SPEAKER, n.Tone, toneduration);
    }
    nextnotetime = millis() + toneduration + pauseduration;
}
