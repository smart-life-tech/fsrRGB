int redPin1 = 3;
int redPin2 = 5;
int redPin3 = 7;
int redPin4 = 9;

int ledPins[4] = {redPin1, redPin2, redPin3, redPin4};
void setup(void)
{
    Serial.begin(9600);
    pinMode(redPin1, OUTPUT);
    pinMode(redPin2, OUTPUT);
    pinMode(redPin3, OUTPUT);
    pinMode(redPin4, OUTPUT);
}

void loop(void)
{

    //====================================
    // blink the red led pin only
    for (size_t i = 0; i < 5; i++)
    {
        digitalWrite(ledPins[i], HIGH);
    }

    delay(1000);
    for (size_t i = 0; i < 5; i++)
    {
        digitalWrite(ledPins[i], LOW);
    }
    delay(1000);
}
