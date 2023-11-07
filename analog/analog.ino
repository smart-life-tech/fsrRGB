
int sensor_pin = A0;
int sensor_pin2 = A1;
int sensor_pin3 = A2;
int sensor_pin4 = A3;
int sensor_pin5 = A4;

int sensor_value;
int sensor_value2;
int sensor_value3;
int sensor_value4;
int sensor_value5;

void setup(void)
{
    Serial.begin(9600);
    Serial.print("sensor1 (A0)     \t");
    Serial.print("sensor2 (A1)     \t");
    Serial.print("sensor3 (A2)     \t");
    Serial.print("sensor4 (A3)     \t");
    Serial.println("sensor5 (A4)   \t");
}

void loop(void)
{
    sensor_value = analogRead(sensor_pin);
    sensor_value2 = analogRead(sensor_pin2);
    sensor_value3 = analogRead(sensor_pin3);
    sensor_value4 = analogRead(sensor_pin4);
    sensor_value5 = analogRead(sensor_pin5);

    Serial.print(sensor_value);
    Serial.print("                 \t");
    Serial.print(sensor_value2);
    Serial.print("                 \t");
    Serial.print(sensor_value3);
    Serial.print("                 \t");
    Serial.print(sensor_value4);
    Serial.print("                 \t");
    Serial.println(sensor_value5);

    //============================================================
}
