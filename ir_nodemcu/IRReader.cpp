#include "IRReader.h"

void print_uint64_t(uint64_t);

IRReader::IRReader(int pin, int delay, std::function<void()> callback)
{
	this->pin = pin;
	this->delay = delay;
	this->callback = callback;
	lastUpdateTime = 0;
	enabled = false;
}

void IRReader::setup() 
{
	pinMode(pin, INPUT);

	irrecv = new IRrecv(pin);
}

void IRReader::update()
{
	unsigned long currentTime = millis();
	if (lastUpdateTime + (unsigned long)delay < currentTime) {
		if(!enabled){
			irrecv->enableIRIn();
			enabled = true;
		}
		if (irrecv->decode(&results)) {
			print_uint64_t(results.value);
			if (results.value == 65596 || results.value == 60)
			{
				Serial.println("Toggle");
				lastUpdateTime = millis();
				callback();
				if(enabled){
					irrecv->disableIRIn();
					enabled = false;
				}
			}
			if (enabled) {
				irrecv->resume();
			}
		}
	}
}

void print_uint64_t(uint64_t num) {

    char rev[128];
    char* p = rev + 1;

    while (num > 0) {
        *p++ = '0' + (num % 10);
        num /= 10;
    }
    p--;
    /*Print the number which is now in reverse*/
    while (p > rev) {
        Serial.print(*p--);
    }
    Serial.println();
}