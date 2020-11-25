#include "ButtonController.h"
#include "IRReader.h"

int IRPin = D7; //IR pin
int RPin = D3; //Relay pin
int BPin = D2; //Button pin

int state = LOW;

void onUpdate();

IRReader reader(IRPin, 500, onUpdate);
ButtonController bController(BPin, 500, onUpdate);

void setup() // процедура setup
{
    Serial.begin(9600); // подключаем монитор порта

    //PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, FUNC_GPIO15);

    pinMode(LED_BUILTIN, OUTPUT);

    pinMode(RPin, OUTPUT);

    reader.setup();
    bController.setup();

    digitalWrite(LED_BUILTIN, HIGH);
    delay(400);
    Serial.println("started"); 
}

void onUpdate() {
    state = state == LOW ? HIGH : LOW;
    digitalWrite(RPin, state);
}

void loop() // процедура loop
{
    reader.update();
    bController.update();
}