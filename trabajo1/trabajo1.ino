const int led1=10;
const int led2=8;
const int led3=5;
const int led4=2;
int cont=1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(cont%10==0) digitalWrite(led1,HIGH);
  else digitalWrite(led1,LOW);
  if(cont%8==0) digitalWrite(led2,HIGH);
  else digitalWrite(led2,LOW);
  if(cont%5==0) digitalWrite(led3,HIGH);
  else digitalWrite(led3,LOW);
  if(cont%2==0) digitalWrite(led4,HIGH);
  else digitalWrite(led4,LOW);
  delay(2000);
  cont++;
}