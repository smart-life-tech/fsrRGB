
int sensor_pin = A0;
int sensor_pin2 = A1;
int sensor_pin3 = A2;
int sensor_pin4 = A3;

int sensor_value;
int sensor_value2;
int sensor_value3;
int sensor_value4;
// values at which leds blink
int blueVal = 300;
int greenVal = 1000;

int redVal2 = 300;
int redVal3 = 300;
int redVal4 = 300;
bool op2;

char prev_color = ' ';

int redPin = 3;
int greenPin = 2;
int bluePin = 4;

int redPin2 = 5;
int redPin3 = 7;
int redPin4 = 9;

int greenPin2 = 6;
int greenPin3 = 8;
int greenPin4 = 10;


bool blue, red, green = true;
bool blue2, red2, green2 = true;
bool blue3, red3, green3 = true;
bool blue4, red4, green4 = true;

void setup(void) {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);

  pinMode(redPin3, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(redPin4, OUTPUT);
  pinMode(greenPin4, OUTPUT);

  blue = true;
}

void loop(void) {
  sensor_value = analogRead(sensor_pin);
  sensor_value2 = analogRead(sensor_pin2);
  sensor_value3 = analogRead(sensor_pin3);
  sensor_value4 = analogRead(sensor_pin4);

  Serial.print("Analog reading1 = ");
  Serial.println(sensor_value);
  Serial.print("Analog reading2 = ");
  Serial.println(sensor_value2);
  Serial.print("Analog reading3 = ");
  Serial.println(sensor_value3);
  Serial.print("Analog reading4 = ");
  Serial.println(sensor_value4);

  if (sensor_value < blueVal) {
    Serial.println(": Light touch value below set");
    digitalWrite(redPin, LOW);
    green = true;
    if (blue) {
      allLedsOff();
      flashBlue(3);

      blue = false;
    }
  }
  else {
    op2 = true;
  }

  if (sensor_value > greenVal) {
    Serial.println(": heavy  squeeze value greater");
    blue = true;
    digitalWrite(redPin, LOW);
    if (green) {
      flashGreen(3);
      green = false;
    }
  }
  if (sensor_value > blueVal && sensor_value < greenVal) {
    Serial.println(": Medium squeeze value in between");
    blue = true;
    green = true;

    flashRed(3);
  }
  delay(100);
  //==========================================================
  if (sensor_value2 < redVal2 && op2 == true) {
    Serial.println(": Light touch value below set");
    digitalWrite(redPin2, HIGH);
    green2 = true;
  }

  else if (sensor_value2 > redVal2 && op2 == true) {
    digitalWrite(redPin2, LOW);
    if (green2) {
      Serial.println(":GREEN 2 BLINK");
      flashGreen2(3);
      green2 = false;
    }
  }
  //============================================================

  //==========================================================
  if (sensor_value3 < redVal3  && op2 == true) {
    Serial.println(": Light touch value below set");
    digitalWrite(redPin3, HIGH);
    green3 = true;
  }

  else if (sensor_value3 > redVal3  && op2 == true) {
    digitalWrite(redPin3, LOW);
    if (green3) {
      Serial.println(":GREEN 3 BLINK");
      flashGreen3(3);
      green3 = false;
    }
  }
  //============================================================

  //==========================================================
  if (sensor_value4 < redVal4  && op2 == true) {
    Serial.println(": Light touch value below set");
    digitalWrite(redPin4, HIGH);
    green4 = true;
  }

  else if (sensor_value4 > redVal4  && op2 == true) {
    digitalWrite(redPin4, LOW);
    if (green4) {
      Serial.println(":GREEN 4 BLINK");
      flashGreen4(3);
      green4 = false;
    }
  }
  //============================================================
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


void flashGreen2(int times) {
  for (int i = 0; i <= times; i++) {
    digitalWrite(greenPin2, HIGH);
    delay(500);
    digitalWrite(greenPin2, LOW);
    delay(500);
  }
}


void flashGreen3(int times) {
  for (int i = 0; i <= times; i++) {
    digitalWrite(greenPin3, HIGH);
    delay(500);
    digitalWrite(greenPin3, LOW);
    delay(500);
  }
}


void flashGreen4(int times) {
  for (int i = 0; i <= times; i++) {
    digitalWrite(greenPin4, HIGH);
    delay(500);
    digitalWrite(greenPin4, LOW);
    delay(500);
  }
}
void allLedsOff() {
  for (int i = 4; i < 11; i++) {
    digitalWrite(i, LOW);
  }
  op2 = false;
}
