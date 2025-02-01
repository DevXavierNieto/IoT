#include <Servo.h>
Servo servoMotor;
const int trig = 2;
const int echo = 3;
const int led1 = 5;
const int led2 = 6;
const int led3 = 7;
char c = 'b';

int time = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  servoMotor.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly: relevadoor, pila de 9 vots y 2 caimanes y bomba de arduino
  servoMotor.write(0);
  delay(1000);
  servoMotor.write(60);
  delay(1000);
  servoMotor.write(120);
  delay(1000);
  servoMotor.write(180);
  if (Serial.available() > 0) {
    c = Serial.read();
  }

  if (c == 'a') {
    digitalWrite(trig, HIGH);
    delayMicroseconds(20);
    digitalWrite(trig, LOW);
    time = pulseIn(echo, HIGH);
    Serial.println(time);

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);

    if (time <= 400 && time > 0) {
      digitalWrite(led1, LOW);
    } else {
      digitalWrite(led1, HIGH);
    }

    if (time >= 401 && time < 700) {
      digitalWrite(led2, LOW);
    } else {
      digitalWrite(led2, HIGH);
    }

    if (time >= 700) {
      digitalWrite(led3, LOW);
    } else {
      digitalWrite(led3, HIGH);
    }
  } else if (c == 'b') {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
}

/*
  cafe tierra (GND)
  amarillo 5v
  enmedio es pin
*/