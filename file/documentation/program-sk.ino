#include <EEPROM.h>
#include <Servo.h>
Servo s1;
Servo s2;

#define senzor A0
#define IR 3

int x = 100; //pocet merani
String farba;

void setup() {
  s1.attach(9);
  s2.attach(10);
  pinMode(senzor, INPUT);
  pinMode(IR, INPUT);

  delay(200);
  if (digitalRead(4) == HIGH)
    kalibracia();
}

void loop() {
  if (map(analogRead(senzor), 0, 1023, 0, 255) > (EEPROM.read(2) + 20)) {
    farba = "cierna";
  }

  else if (map(analogRead(senzor), 0, 1023, 0, 255) < (EEPROM.read(2) + 20)) {
    farba = "biela";
  }

  if (farba == "cierna") {
    doprava();
  }

  if (farba == "biela") {
    dolava();
  }

  if (digitalRead(IR) == LOW) {
    naokolo();
  }
}

void dopredu () {
  s1.write(0); // dopredu
  s2.write(180); // dopredu
}

void doprava () {
  s1.write(90); // dopredu
  s2.write(180); // stoji
}

void dolava () {
  s1.write(0); // stoji
  s2.write(90); // dopredu
}

void dozadu () {
  s1.write(180); // dozadu
  s2.write(0); // dozadu
}

void zastav () {
  s1.write(90); // stoji
  s2.write(90); // stoji
}

void kalibracia() {
  int ciernaNamerana = 0;
  int bielaNamerana = 0;
  for (int k = 0; k < x; k++) {
    ciernaNamerana += analogRead(senzor);
    delay(10);
  }
  EEPROM.write(0, 0);
  EEPROM.write(0, map((ciernaNamerana / x), 0, 1023, 0, 255)); //cierna
  doprava();
  delay(500);
  zastav();
  for (int j = 0; j < x; j++) {
    bielaNamerana += analogRead(senzor);
    delay(10);
  }
  EEPROM.write(1, 0);
  EEPROM.write(1, map((bielaNamerana / x), 0, 1023, 0, 255)); //biela
  Serial.println(EEPROM.read(1));
  Serial.println(EEPROM.read(0));

  EEPROM.write(2, (EEPROM.read(1) + EEPROM.read(0)) / 2);
  Serial.println(EEPROM.read(2));
  delay(1000);
}

void naokolo() {
  dozadu();
  delay(100);
  doprava();
  delay(500);
  dopredu();
  delay(1000);
  dolava();
  delay(1000);
  dopredu();
  delay(800);
}