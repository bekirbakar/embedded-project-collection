/**
 * 2018
 * Coin Slot Machine
 */

#include <stdlib.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

// Define the symbols on the buttons of the keypads.
char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {3, 4, 5, 6};
byte colPins[COLS] = {7, 8, 9, 10};

// Initialize an instance of class NewKeypad.
Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

const byte coinInterruptPin = 2;

// Volatile byte coin;
unsigned int coin = 0;

byte keyInputCounter = 0;
byte eventNumber = 0;

const byte CELL = 6;
const byte PRICE = 2;

unsigned int product[CELL][PRICE] = {
    {1, 100},
    {2, 200},
    {3, 200},
    {4, 100},
    {5, 100},
    {6, 100}};

void setup()
{
    pinMode(coinInterruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(coinInterruptPin), coinInput,
                    CHANGE);

    // Add an event listener for this keypad.
    keypad.addEventListener(keypadEvent);
    Serial.begin(9600);
}

void loop()
{
    Serial.println("Waiting!!!");
    keypad.waitForKey();
}

void keypadEvent(KeypadEvent key)
{
    switch (keypad.getState())
    {
    case PRESSED:
        if (key == '#')
        {
            eventNumber = 3;
        }
        else if (key == '*')
        {
            eventNumber = 2;
        }
        else
        {
            eventNumber = 1;
        }
        break;
    case RELEASED:
        eventHandler(eventNumber, key);
        break;
    case HOLD:
        // Buzzer;
        break;
    case IDLE:
        // TODO
        break;
    }
}

short int keyInput = -100;
// short int keyInput[2] = {-10, -10}
byte keyCounter = 0;

void led()
{
    // Blink led port (red green blue).
}

int relayOnOff(short int no)
{
    // no = 1;
    // Set output high.
    // Wait for a while.
    // Set output low.

    Serial.println("Ürün seçildi:");
    Serial.println(100);
    Serial.println("\n");

    return no;
}

void startEvent()
{
    keyCounter = 0;
    keyInput = 0;

    led();
}

void coinControl();
void diyezEvent()
{
    keyInput = 0;
    coinControl();
    if (keyInput <= 8)
    {
        // relayOnOff(keyInput);
        led();
    }
    else
    {
        startEvent();
        led();
    }
}

void keypadEvent(KeypadEvent key)
{
    switch (keypad.getState())
    {
    case PRESSED:
        if (key == '#')
        {
            Serial.println(key);
            // digitalWrite(ledPin,!digitalRead(ledPin));
            // ledPin_state = digitalRead(ledPin);
            // Remember LED state, lit or unlit.
        }
        break;

    case RELEASED:
        if (key == '*')
        {
            Serial.println(key);
            // digitalWrite(ledPin,ledPin_state);
            // Restore LED state from before it started blinking.
            blink = false;
        }
        break;

    case HOLD:
        if (key == '*')
        {
            Serial.println("hold");
            // blink = true;
            // Blink the LED when holding the * key.
        }
        break;
    case IDLE:
        if (key == '*')
        {
            Serial.println("idle");
            // blink = true;
            // Blink the LED when holding the * key.
        }
        break;
    }
}

void eventHandler(byte e, char k)
{
    eventNumber = 0;
    if (e == 1)
    {
        if (k == 'A' || k == 'B' || k == 'C' || k == 'D')
        {
            coin = coin + 100;
            Serial.println(coin);
        }
        else
        {
            // Number entered.
            keyCounter = keyCounter + 1;
            if (keyCounter == 1)
            {
                keyInput = k - '0';
            }
            else if (keyCounter == 2)
            {
                keyInput = (10 * keyInput) + (k - '0');
            }
            else
            {
                startEvent();
            }
        }
    }
    else if (e == 2)
    {
        startEvent();
    }
    else if (e == 3)
    {
        diyezEvent();
    }
    else
    {
        startEvent();
    }

    Serial.println(keyInput);
}

void coinControl()
{
    if (coin == product[keyInput - 1][1])
    {
        relayOnOff(keyInput);
        coin = 0;
    }
    else if (coin <= product[keyInput - 1][1])
    {
        startEvent();
        led();
    }
    else if (coin >= product[keyInput - 1][1])
    {
        relayOnOff(keyInput);

        // Pay back here (refund 8th cell).
        relayOnOff(8);
        startEvent();
        led();
        coin = 0;
    }
}

void coinInput()
{
    // coin = coin + 100;
    int val = digitalRead(coinPin);
    if (val == 0)
    {
        delay(100);
        Serial.println("Coin inserted!");
        qu = qu + 100;
    }
}
