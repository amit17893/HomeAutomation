#include<SoftwareSerial.h>
#define TxD 3
#define RxD 2
#define LED_PIN 12
#define L 11
SoftwareSerial bluetoothSerial(TxD,RxD);

char c;

void setup() {
  // put your setup code here, to run once:
bluetoothSerial.begin(9600);
Serial.begin(9600);
pinMode(LED_PIN,OUTPUT);
pinMode(L,OUTPUT);
pinMode(7,OUTPUT);
digitalWrite(7,HIGH);
digitalWrite(LED_PIN,HIGH);
digitalWrite(L,HIGH);
}

void loop() {
  digitalWrite(7,HIGH);
  // put your main code here, to run repeatedly:
if(bluetoothSerial.available()){
  c=bluetoothSerial.read();
  Serial.println(c);
  if(c=='1')
  digitalWrite(LED_PIN,HIGH);
  if(c=='0')
  digitalWrite(LED_PIN,LOW);
  if(c=='3')
  digitalWrite(L,HIGH);
  if(c=='4')
  digitalWrite(L,LOW);
}
}
