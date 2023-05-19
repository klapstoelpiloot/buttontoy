#pragma once

class IState
{
public:

    virtual ~IState() = default;

protected:

    // Make this an interface, do not allow instantiation
    IState() { }
    IState(const IState&) { }
    IState& operator = (const IState&) { return *this; }

public:

    // Called when entering this state.
    virtual void Enter() = 0;

    // Called when leaving this state.
    virtual void Leave() = 0;

    // Called repeatedly to update states.
    virtual void Update() = 0;

    // Called when one of the buttons is pressed. Not called when a button is held down.
    // To check buttons being held down, use the Buttons object.
    virtual void OnButtonPress(int index) = 0;

    // Must return True when this state is finished for the game to continue to the next state.
    virtual bool IsFinished() = 0;
};
