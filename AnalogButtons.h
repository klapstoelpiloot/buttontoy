#pragma once
#include "Defines.h"

class AnalogButtons
{
private:
	// These are only updated after debouncing/timeout
	bool down[NUM_BUTTONS];					// Is the button currently held down?
	bool pressed[NUM_BUTTONS];				// Is the button pressed since last Update()?

	// These are updated every Update() call
	bool measuredstate[NUM_BUTTONS];			// Measured state every update
	unsigned long changetime[NUM_BUTTONS];		// Last time the measuredstate changed
	
public:
	AnalogButtons();
	void Setup();
	void Update();
	bool IsDown(int button_index) { return down[button_index]; }
	bool IsPressed(int button_index) { return pressed[button_index]; }
};
