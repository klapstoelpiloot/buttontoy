#include "../ButtonToy.h"

// Header for puzzles. All puzzles use the same header file.
// Make sure PUZZLE is defined before including this header.
class PUZZLE : public virtual IState
{
private:

public:

    PUZZLE();

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
    virtual bool IsFinished() override { return leds.AreAllGreen(); }
};
