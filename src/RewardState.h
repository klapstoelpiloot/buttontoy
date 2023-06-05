#include "../ButtonToy.h"

class RewardState : public virtual IState
{
private:

    int currentani;
    unsigned long anistarttime;

    void StartAni(int ani);
    void PlayRandomTune();
    void GreenFlashLEDs(unsigned long t);

public:

    RewardState();

    // Called when entering this state.
    virtual void Enter() override;

    // Called when leaving this state.
    virtual void Leave() override;

    // Called repeatedly to update states.
    virtual void Update() override;

    // Called when one of the buttons is pressed. Not called when a button is held down.
    // To check buttons being held down, use the Buttons object.
    virtual void OnButtonPress(int index) override;

    // Called when one of the buttons is released ofter being pressed.
    virtual void OnButtonRelease(int index) override;

    // Returns True when te puzzle is finished (when all LEDs are green)
    virtual bool IsFinished() override;
};
