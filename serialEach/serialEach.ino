// this code uses all the pins to test from 2 to 13, observe the working pattern please
void setup(void)
{
    Serial.begin(9600);
    for (size_t i = 2; i < 14; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop(void)
{

    //====================================
    // blink the n led pin only
    for (size_t i = 2; i < 14; i++)
    {
        Serial.println("now on  pin ," + String(i));
        delay(1800);
        digitalWrite(i, HIGH);
        Serial.println("done with pin ," + String(i));
        digitalWrite(i, LOW);
        delay(1000);
    }
}
