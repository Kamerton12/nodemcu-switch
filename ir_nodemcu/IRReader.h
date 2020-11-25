#ifndef _IRREADER_h
#define _IRREADER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include <IRremoteESP8266.h>
	#include <IRrecv.h>
#else
	#include "WProgram.h"
#endif

class IRReader
{

private:
	int pin;
	int delay;
	unsigned long lastUpdateTime;
	bool enabled;
	std::function<void()> callback;
	IRrecv* irrecv;
	decode_results results;

 public:
	IRReader(int pin, int delay, std::function<void()> callback);
	void setup();
	void update();
};

#endif

