#include <Keyboard.h>

char CTRL_KEY = KEY_LEFT_CTRL;
char TAB_KEY = KEY_TAB;

const int RED_LED = 3;
const int GREEN_LED = 2;
const int BLUE_LED = 13;

const int START_BTN = 4;
const int STOP_BTN = 5;

//Function Prototypes
void  StatusBlink(int blinkTime);


void setup()
{

	pinMode(RED_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
	pinMode(BLUE_LED, OUTPUT);
	pinMode(START_BTN, INPUT);
	pinMode(STOP_BTN, INPUT);

	Keyboard.begin();

	digitalWrite(RED_LED, HIGH);
	digitalWrite(GREEN_LED, LOW);
	digitalWrite(BLUE_LED, LOW);
}

void loop()
{
	if (digitalRead(START_BTN) == HIGH)
	{
		Keyboard.press(CTRL_KEY);
		Keyboard.press('r');
		delay(200);
		Keyboard.releaseAll();
		StatusBlink(30000);
		digitalWrite(RED_LED, LOW);
		digitalWrite(GREEN_LED, HIGH);
	}

	else if (digitalRead(STOP_BTN) == HIGH)
	{
		Keyboard.press(TAB_KEY);
		delay(3000);
		Keyboard.releaseAll();
		StatusBlink(33000);
		digitalWrite(RED_LED, HIGH);
		digitalWrite(GREEN_LED, LOW);
	}
}

void StatusBlink(int blinkTime)
{
	int targetTime = 0;

	targetTime = (millis() + blinkTime);

	while (millis() < targetTime)
	{
		digitalWrite(BLUE_LED, HIGH);
		delay(500);
		digitalWrite(BLUE_LED, LOW);
		delay(500);
	}
}