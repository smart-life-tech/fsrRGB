#include "LowPower.h"
int sensor_pin = A0;
int sensor_value;
// values at which leds blink
int greenVal = 300;
int blueVal = 1000;

char prev_color = ' ';

int redPin = 3;
int greenPin = 2;
int bluePin = 4;

bool blue, red, green = true;
void setup(void) {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop(void) {
  sensor_value = analogRead(sensor_pin);

  Serial.print("Analog reading = ");
  Serial.print(sensor_value);

  if (sensor_value < greenVal) {
    Serial.println(": Light touch value below set");
    blue = true;
    digitalWrite(redPin, LOW);
    if (green) {
      prev_color = 'g';
      flashGreen(3);
      green = false;
    }
    if (prev_color == 'r' || prev_color == 'b') {
      Serial.println("going to sleep");
      delay(1000);
      LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
      Serial.println("done");
    }

  }  if (sensor_value > blueVal) {
    Serial.println(": heavy  squeeze value greater");
    green = true;
    digitalWrite(redPin, LOW);
    if (blue) {
      prev_color = 'b';
      flashBlue(3);
      blue = false;
    }
    if (prev_color == 'r' || prev_color == 'g') {
      Serial.println("going to sleep");
      delay(1000);
      LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
      Serial.println("done");
    }
  }
  if (sensor_value > greenVal && sensor_value < blueVal) {
    Serial.println(": Medium squeeze value in between");
    blue = true;
    green = true;
    prev_color = 'r';
    flashRed(3);
  }
  delay(100);
}

void flashBlue(int times) {
  for (int i = 0; i <= times; i++) {
    digitalWrite(bluePin, HIGH);
    delay(500);
    digitalWrite(bluePin, LOW);
    delay(500);
  }
}

void flashRed(int times) {
  digitalWrite(redPin, HIGH);
}


void flashGreen(int times) {
  for (int i = 0; i <= times; i++) {
    digitalWrite(greenPin, HIGH);
    delay(500);
    digitalWrite(greenPin, LOW);
    delay(500);
  }
}
