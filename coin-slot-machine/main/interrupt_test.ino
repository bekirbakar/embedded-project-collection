/**
 * 2018
 * Coin Slot Machine
 */

const byte ledPin = 13;
const byte interruptPin = 3;
volatile byte state = 0;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(1), blink, CHANGE);
}

void loop()
{
    digitalWrite(ledPin, HIGH);

    if (state == 1)
    {
        Serial.println("okay");
    }
}

void blink()
{
    state = 1;
}
