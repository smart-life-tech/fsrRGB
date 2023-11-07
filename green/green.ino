int greenPin1 = 2;
int greenPin2 = 6;
int greenPin3 = 8;
int greenPin4 = 10;

int ledPins[4] = {greenPin1, greenPin2, greenPin3, greenPin4};
void setup(void)
{
    Serial.begin(9600);
    pinMode(greenPin1, OUTPUT);
    pinMode(greenPin2, OUTPUT);
    pinMode(greenPin3, OUTPUT);
    pinMode(greenPin4, OUTPUT);
}

void loop(void)
{

    //====================================
    // blink the green led pin only
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
