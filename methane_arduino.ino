#include <SoftwareSerial.h>

SoftwareSerial nodemcu(8, 9);

int pinRedLed = 12;
int pinGreenLed = 11;
int pinSensor = A0; // Use A0 as the analog pin for the MQ4 sensor
int THRESHOLD = 480;
int buzzer = 10;

int rdata = 0;
String mystring;

void setup() {
  Serial.begin(9600);
  nodemcu.begin(9600);

  pinMode(buzzer, OUTPUT);
  pinMode(pinRedLed, OUTPUT);
  pinMode(pinGreenLed, OUTPUT);
  pinMode(pinSensor, INPUT);
}

void loop() {
  int rdata = analogRead(pinSensor);

  Serial.print("Methane Range: ");
  Serial.println(rdata);

  if (rdata >= THRESHOLD) {
    digitalWrite(pinRedLed, HIGH);
    digitalWrite(pinGreenLed, LOW);
    digitalWrite(buzzer, HIGH);
    delay(50);
  } else {
    digitalWrite(pinRedLed, LOW);
    digitalWrite(pinGreenLed, HIGH);
    digitalWrite(buzzer, LOW);
  }

  if (nodemcu.available() > 0) {
    char data;
    data = nodemcu.read();
    Serial.println(data);
  }

  if (rdata < 250) {
    mystring = "Methane Range: " + String(rdata);
    nodemcu.println(mystring);
    Serial.println(mystring);
  } else {
    mystring = "Food Spoiled";
    nodemcu.println(mystring);
    Serial.println(mystring);
  }

  mystring = "";
  delay(1000);
}
