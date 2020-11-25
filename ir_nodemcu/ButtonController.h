#ifndef _BUTTONCONTROLLER_h
#define _BUTTONCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ButtonController
{

 private:
	 int pin;
	 int delay;
	 std::function<void()> callback;
	 unsigned long lastUpdateTime;
	 int prevState;

 public:
	ButtonController(int pin, int delay, std::function<void()> callback);
	void setup();
	void update();
};

#endif

