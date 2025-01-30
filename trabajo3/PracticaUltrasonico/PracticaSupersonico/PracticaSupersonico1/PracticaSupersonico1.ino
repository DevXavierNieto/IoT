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
}

void loop() {
  // put your main code here, to run repeatedly:
  // El orden que lleva el ultrasonico es desde Vcc, el orden en Arduino es: 5v, pin digital, pin digital, gnd
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
