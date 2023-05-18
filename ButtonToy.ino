#define BUTTONS_PIN		21

void setup()
{
	Serial.begin(9600);
	analogReference(VDD);
	analogRead(BUTTONS_PIN);
	analogRead(BUTTONS_PIN);
	analogRead(BUTTONS_PIN);
	analogRead(BUTTONS_PIN);
	analogRead(BUTTONS_PIN);
}

void loop()
{
	int sensorValue = analogRead(BUTTONS_PIN);
	float voltage = sensorValue * (5.0 / 1023.0);
	Serial.println(voltage);
}
