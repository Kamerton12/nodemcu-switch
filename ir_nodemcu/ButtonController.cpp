#include "ButtonController.h"

ButtonController::ButtonController(int pin, int delay, std::function<void()> callback)
{
	this->pin = pin;
	this->delay = delay;
	this->callback = callback;
	lastUpdateTime = 0;
}

void ButtonController::setup() {
	pinMode(pin, INPUT_PULLUP);
}

void ButtonController::update() {
	unsigned long currentTime = millis();
	int state = digitalRead(pin);
	if (lastUpdateTime + (unsigned long)delay < currentTime) {
		if (state == LOW && prevState == HIGH) {
			callback();
			lastUpdateTime = currentTime;
		}
	}
	prevState = state;
}
