/**
 * 2018
 * Coin Slot Machine
 */

#define MONEY 2

int coinPin = 0;
int relayPin = 12;
int qu = 0;
void setup()
{
    pinMode(coinPin, INPUT);
    pinMode(relayPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int val = digitalRead(coinPin);
    if (val == 0)
    {
        delay(100);
        Serial.println("Coin inserted!");
        qu = qu + 1;

        if (qu == MONEY)
        {
            Serial.println("Product released!.");
            digitalWrite(relayPin, LOW);
            delay(2000);
            qu = 0;
        }
    }

    digitalWrite(relayPin, HIGH);
}
