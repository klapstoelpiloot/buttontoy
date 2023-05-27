#include "IMelody.h"

// Duke Nukem (balloon score)
// ========================================================================================================
class Reward1 : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 9; }
    virtual int GetNotePause() override { return 0; }
    virtual bool GetAbsDurations() override { return true; }
    static int notes[];
    static int durations[];
    static int notecount;
};

int Reward1::notes[] = {
    150, REST, 200, REST, 220, REST, 280, REST, 310, REST, 360, REST, 450, REST, 600, REST, 800, REST, 1200, REST, 4000, REST,
    4000, 2500, 2000, 1200, 1000, 800, 500, 400, 300, 250, REST,
    4000, 2500, 2000, 1200, 1000, 800, 500, 400, 300, 250, REST,
    1200, 1000, 800, 500, 400, 300, 250, REST,
    500, 600, 800, 900, 1100, 1200, 1400, 1500
};

int Reward1::durations[] = {
    160, 240, 160, 180, 180, 200, 280, 200, 200, 200, 320, 260, 380, 330, 420, 330, 580, 410, 720, 420, 1200, 800,
    140, 290, 140, 170, 160, 100, 120, 130, 130, 710, 200,
    140, 290, 140, 170, 160, 100, 120, 130, 130, 710, 200,
    170, 160, 100, 120, 130, 130, 710, 200,
    340, 150, 60, 60, 120, 240, 120, 60
};

int Reward1::notecount = sizeof(Reward1::notes) / sizeof(Reward1::notes[0]);


// Prince of persia (life potion)
// ========================================================================================================
class Reward2 : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 9; }
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


// Tetris
// ========================================================================================================
class Reward3 : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 160; }
    virtual int GetNotePause() override { return 0; }
    virtual bool GetAbsDurations() override { return false; }
    static int notes[];
    static int durations[];
    static int notecount;
};

int Reward3::notes[] = {
    NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, REST, NOTE_A4
};

int Reward3::durations[] = {
    4, 8, 8, 4, 8, 8,
    4, 8, 8, 4, 8, 8,
    4, 8, 4, 4,
    4, 4, 128, 8
};

int Reward3::notecount = sizeof(Reward3::notes) / sizeof(Reward3::notes[0]);


// Pacman
// ========================================================================================================
class Reward4 : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 160; }
    virtual int GetNotePause() override { return 0; }
    virtual bool GetAbsDurations() override { return false; }
    static int notes[];
    static int durations[];
    static int notecount;
};

int Reward4::notes[] = {
  NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5,
  NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_C5,
  NOTE_C6, NOTE_G6, NOTE_E6, NOTE_C6, NOTE_G6, NOTE_E6,
  
  NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_B5,
  NOTE_FS5, NOTE_DS5, NOTE_DS5, NOTE_E5, NOTE_F5,
  NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_B5
};

int Reward4::durations[] = {
  16, 16, 16, 16,
  32, 16, 8, 16,
  16, 16, 16, 32, 16, 8,
  
  16, 16, 16, 16, 32,
  16, 8, 32, 32, 32,
  32, 32, 32, 32, 32, 16, 8
};

int Reward4::notecount = sizeof(Reward4::notes) / sizeof(Reward4::notes[0]);


// Something that got messed up in my Excel transmogrification but still sounds reasonably
// Yup, there are zero-duration notes in here. They don't play. It was supposed to be a different song and I'm tool lazy to get them out.
// ========================================================================================================
class Reward5 : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 160; }
    virtual int GetNotePause() override { return 0; }
    virtual bool GetAbsDurations() override { return false; }
    static int notes[];
    static int durations[];
    static int notecount;
};

int Reward5::notes[] = {
  NOTE_B4	 , NOTE_E5	 , NOTE_B4	 , NOTE_E5
  , NOTE_B4	  , NOTE_E5	 , NOTE_B4,	 REST	  , NOTE_AS4	 , NOTE_B4
  , NOTE_B4	  , NOTE_AS4	 , NOTE_B4	 , NOTE_A4,	 REST	 , NOTE_GS4	 , NOTE_A4	 , NOTE_G4
  , NOTE_G4	  , NOTE_E4
  , NOTE_B4	 , NOTE_E5	 , NOTE_B4	 , NOTE_E5
  , NOTE_B4	  , NOTE_E5	 , NOTE_B4,	 REST	  , NOTE_AS4	 , NOTE_B4

  , NOTE_A4	 , NOTE_A4	 , NOTE_GS4	 , NOTE_A4
  , NOTE_D5	  , NOTE_C5	 , NOTE_B4	 , NOTE_A4
  , NOTE_B4	 , NOTE_E5	 , NOTE_B4	 , NOTE_E5
  , NOTE_B4	  , NOTE_E5	 , NOTE_B4,	 REST	  , NOTE_AS4	 , NOTE_B4
  , NOTE_D5	 , NOTE_D5	 , NOTE_B4	 , NOTE_A4
  , NOTE_G4	 , NOTE_E4
  , NOTE_E4	 , NOTE_G4
  , NOTE_B4	 , NOTE_D5

  , NOTE_F5	 , NOTE_E5	 , NOTE_AS4	 , NOTE_AS4	 , NOTE_B4	 , NOTE_G4
};

int Reward5::durations[] = {
0, 0, 0, 0,
8, 0, 8, 8, 8, 8, 
8, 8, 8, 8, 8, 8, 8, 8,
4, 0, 
0, 0, 0, 0,
8, 0, 8, 8, 8, 8,

0, 0, 8, 0,
8, 0, 0, 0,
0, 0, 0, 0, 
8, 0, 8, 8, 8, 8, 
4, 0, 8, 0,
0, 0,
2, 2,
2, 2,

0, 0, 8, 8, 4, 4
};

int Reward5::notecount = sizeof(Reward5::notes) / sizeof(Reward5::notes[0]);


// 
// ========================================================================================================
class Reward6 : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 280; }
    virtual int GetNotePause() override { return 64; }
    virtual bool GetAbsDurations() override { return false; }
    static int notes[];
    static int durations[];
    static int notecount;
};

int Reward6::notes[] = {
  NOTE_B4,  REST,  NOTE_E5,  REST,  NOTE_B4,  REST,  NOTE_E5,  REST,
  NOTE_B4,   NOTE_E5,  REST,  NOTE_B4,  REST,   NOTE_AS4,  NOTE_B4,  
  NOTE_B4,   NOTE_AS4,  NOTE_B4,  NOTE_A4,  REST,  NOTE_GS4,  NOTE_A4,  NOTE_G4,
  NOTE_G4,   NOTE_E4,  REST,  
  NOTE_B4,  REST,  NOTE_E5,  REST,  NOTE_B4,  REST,  NOTE_E5,  REST,
  NOTE_B4,   NOTE_E5,  REST,  NOTE_B4,  REST,   NOTE_AS4,  NOTE_B4, 

  NOTE_A4,  REST,  NOTE_A4,  REST,  NOTE_GS4,  NOTE_A4,  REST, 
  NOTE_D5,   NOTE_C5,  REST,  NOTE_B4,  REST,  NOTE_A4,  REST, 
  NOTE_B4,  REST,  NOTE_E5,  REST,  NOTE_B4,  REST,  NOTE_E5,  REST,
  NOTE_B4,   NOTE_E5,  REST,  NOTE_B4,  REST,   NOTE_AS4,  NOTE_B4, 
  NOTE_D5,  NOTE_D5,  REST,  NOTE_B4,  NOTE_A4,  REST, 
  NOTE_G4,  REST,  NOTE_E4
};

int Reward6::durations[] = {
8, 16, 8, 16, 8, 16, 8, 16,
8, 8, 16, 8, 8, 8, 8, 
8, 8, 8, 8, 8, 8, 8, 8,
4, 2, 32, 
8, 16, 8, 16, 8, 16, 8, 16,
8, 8, 16, 8, 8, 8, 8, 

8, 16, 8, 16, 8, 8, 16, 
8, 8, 16, 8, 16, 8, 16, 
8, 16, 8, 16, 8, 16, 8, 16,
8, 8, 16, 8, 8, 8, 8, 
4, 4, 16, 8, 4, 16, 
4, 16, 2
};

int Reward6::notecount = sizeof(Reward6::notes) / sizeof(Reward6::notes[0]);


