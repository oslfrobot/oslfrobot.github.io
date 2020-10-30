#include <EEPROM.h>
#include <Servo.h>
Servo s1;
Servo s2;

#define sensor A0
#define IR 3

int x = 100; //count of measurements
String color;

void setup() {
  s1.attach(9);
  s2.attach(10);
  pinMode(sensor, INPUT);
  pinMode(IR, INPUT);

  delay(200);
  if (digitalRead(4) == HIGH)
    calibration();
}

void loop() {
  if (map(analogRead(sensor), 0, 1023, 0, 255) > (EEPROM.read(2) + 20)) {
    color = "black";
  }

  else if (map(analogRead(sensor), 0, 1023, 0, 255) < (EEPROM.read(2) + 20)) {
    color = "white";
  }

  if (color == "black") {
    right();
  }

  if (color == "white") {
    left();
  }

  if (digitalRead(IR) == LOW) {
    getAround();
  }
}

void forward () {
  s1.write(0); // forward
  s2.write(180); // forward
}

void right () {
  s1.write(90); // forward
  s2.write(180); // stop
}

void left () {
  s1.write(0); // stop
  s2.write(90); // forward
}

void backward () {
  s1.write(180); // backward
  s2.write(0); // backward
}

void stop () {
  s1.write(90); // stop
  s2.write(90); // stop
}

void calibration() {
  int blackMeasured = 0;
  int whiteMeasured = 0;
  for (int k = 0; k < x; k++) {
    blackMeasured += analogRead(sensor);
    delay(10);
  }
  EEPROM.write(0, 0);
  EEPROM.write(0, map((blackMeasured / x), 0, 1023, 0, 255)); //black
  right();
  delay(500);
  stop();
  for (int j = 0; j < x; j++) {
    whiteMeasured += analogRead(sensor);
    delay(10);
  }
  EEPROM.write(1, 0);
  EEPROM.write(1, map((whiteMeasured / x), 0, 1023, 0, 255)); //white
  Serial.println(EEPROM.read(1));
  Serial.println(EEPROM.read(0));

  EEPROM.write(2, (EEPROM.read(1) + EEPROM.read(0)) / 2);
  Serial.println(EEPROM.read(2));
  delay(1000);
}

void getAround() {
  backward();
  delay(100);
  right();
  delay(500);
  forward();
  delay(1000);
  left();
  delay(1000);
  forward();
  delay(800);
}
