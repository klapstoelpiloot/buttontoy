#include "Arduino.h"
#include "Buttons.h"

#define SAMPLES_PER_LOOP    10
#define DEBOUNCE_TIMEOUT    50
#define LED_PWM_VALUE       255
#define LED_FADE_STEP       0.002

// Input values in the 10 bit ADC range.
// These values were measured and greatly depend on the resistors used in
// the R-2R DAC. You will have to measure your own values for your own DAC.
#define VALUE_REF           988
#define VALUE_RANGE         6
int VALUE_BUTTON[NUM_BUTTONS] = { 35, 67, 132, 258, 500 };

Buttons::Buttons() :
    ledfade(0.0f),
    ledstate(false),
    lastfadetime(0)
{
    for(int i = 0; i < NUM_BUTTONS; i++)
    {
        down[i] = false;
        pressed[i] = false;
        released[i] = false;
        measuredstate[i] = false;
        changetime[i] = 0;
    }
}

void Buttons::Setup()
{
    pinMode(PIN_BUTTON_LEDS, OUTPUT);
    analogWrite(PIN_BUTTON_LEDS, 0);

    // The R-2R DAC uses the 5V output provided by the Arduino,
    // so use the 5V VDD as analog reference.
    analogReference(VDD);

    // Because documentation says that analogRead() is incorrect
    // after analogReference() for a few reads, let's read a few times.
    for(int i = 0; i < 10; i++)
    {
        analogRead(PIN_BUTTONS);
    }
}

void Buttons::FadeLed(bool on)
{
    // Fade the button LEDs to the desired state slowly
    ledstate = on;
    lastfadetime = millis();
}

void Buttons::SetLed(bool on)
{
    // Change the button LEDs to the desired state immediately
    ledstate = on;
    lastfadetime = 0;
}

void Buttons::Update()
{
    unsigned long t = millis();

    // Fade the button LEDs depending on desired state
    unsigned long dt = t - lastfadetime;
    lastfadetime = t;
    if(ledstate && (ledfade < 1.0))
    {
        ledfade = constrain(ledfade + LED_FADE_STEP * (double)dt, 0.0f, 1.0f);
    }
    else if(!ledstate && (ledfade > 0.0))
    {
        ledfade = constrain(ledfade - LED_FADE_STEP * (double)dt, 0.0f, 1.0f);
    }

    // Apply PWM for the desired LED fade
    // Note that a linear PWM doesn't look linear with an LED, so we do a cubic ease-in
    int ledpwm = (int)(ledfade * ledfade * ledfade * LED_PWM_VALUE);
    analogWrite(PIN_BUTTON_LEDS, ledpwm);

    // Read the average value on the analog pin...
    // We don't bother converting it to a voltage, we can just work in the 1024 integer range.
    int rawvalue = 0;
    for(int i = 0; i < SAMPLES_PER_LOOP; i++)
    {
        rawvalue += analogRead(PIN_BUTTONS);
    }
    rawvalue = rawvalue / SAMPLES_PER_LOOP;

    // Determine the buttons pressed according to the measured value
    for(int i = NUM_BUTTONS - 1; i >= 0; i--)
    {
        if(rawvalue > (VALUE_BUTTON[i] - VALUE_RANGE))
        {
            // If the button value is in the rawvalue, then the
            // button is not pressed (pressed = grounded, no voltage)
            if(measuredstate[i] == true)
            {
                measuredstate[i] = false;
                changetime[i] = t;
            }
            rawvalue -= VALUE_BUTTON[i];
        }
        else
        {
            if(measuredstate[i] == false)
            {
                measuredstate[i] = true;
                changetime[i] = t;
            }
        }
    }

    // Debounce and updating states
    for(int i = 0; i < NUM_BUTTONS; i++)
    {
        pressed[i] = false;
        released[i] = false;

        if((measuredstate[i] != down[i]) && ((t - changetime[i]) > DEBOUNCE_TIMEOUT))
        {
            down[i] = measuredstate[i];

            if(measuredstate[i])
                pressed[i] = true;
            else
                released[i] = true;
        }
    }
}
