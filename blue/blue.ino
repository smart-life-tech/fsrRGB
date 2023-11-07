int bluePin = 4;

void setup(void)
{
    Serial.begin(9600);

    pinMode(bluePin, OUTPUT);
}

void loop(void)
{

    //====================================
    // blink the blue led pin only
    digitalWrite(bluePin, HIGH);
    delay(1000);
    digitalWrite(bluePin, LOW);
    delay(1000);
}
