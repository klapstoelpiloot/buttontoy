#include "Arduino.h"
#include "Speaker.h"

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
    noTone(PIN_SPEAKER);
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
    currentnote++;
    if(currentnote >= melody->GetNoteCount())
    {
        Stop();
        return;
    }

    // Setup note
    Note n = melody->GetNote(currentnote);
    int toneduration;
    int pauseduration;
    if(melody->GetAbsDurations())
    {
        toneduration = n.Duration / melody->GetTempo();
        pauseduration = melody->GetNotePause() / melody->GetTempo();
    }
    else
    {
        toneduration = wholenoteduration / n.Duration;
        pauseduration = (melody->GetNotePause() > 0) ? (wholenoteduration / melody->GetNotePause()) : 0;
    }

    // Play the note
    if(n.Tone != REST)
    {
        tone(PIN_SPEAKER, n.Tone, toneduration);
    }
    else
    {
        noTone(PIN_SPEAKER);
    }

    nextnotetime = millis() + toneduration + pauseduration;
}
