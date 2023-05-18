#include "AnalogButtons.h"

AnalogButtons buttons;

void setup()
{
	Serial.begin(9600);
	buttons.Setup();
}

void loop()
{
	buttons.Update();

	bool addcomma = false;
	for(int i = 0; i < NUM_BUTTONS; i++)
	{
		if(buttons.IsDown(i))
		{
			if(addcomma)
			{
				Serial.print(", ");
			}
			Serial.print(i);
			addcomma = true;
		}
	}
	Serial.println();
}
