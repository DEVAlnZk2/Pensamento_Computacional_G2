// C++ code
//
#include <Servo.h>

int angulo = 0;

int distancia = 0;

Servo servo_9;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

int counter;

int counter2;

int counter3;

int counter4;

void setup()
{
  servo_9.attach(9, 500, 2500);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);

  angulo = 0;
  servo_9.write(0);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
}

void loop()
{
  if (distancia > 334) {
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    for (counter = 0; counter < 60; ++counter) {
      distancia = 0.01723 * readUltrasonicDistance(8, 7);
      Serial.println("Nenhum objeto detectado");
      Serial.println(distancia);
      servo_9.write(angulo);
      angulo = (angulo + 3);
      delay(100); // Wait for 100 millisecond(s)
    }
    for (counter2 = 0; counter2 < 60; ++counter2) {
      distancia = 0.01723 * readUltrasonicDistance(8, 7);
      Serial.println("Nenhum objeto detectado");
      Serial.println(distancia);
      servo_9.write(angulo);
      angulo = (angulo - 3);
      delay(100); // Wait for 100 millisecond(s)
    }
  }
  if (distancia >= 1 || distancia <= 334) {
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    for (counter3 = 0; counter3 < 60; ++counter3) {
      distancia = 0.01723 * readUltrasonicDistance(8, 7);
      Serial.println(" objeto detectado");
      Serial.println(distancia);
      servo_9.write(angulo);
      angulo = (angulo + 3);
      delay(100); // Wait for 100 millisecond(s)
    }
    for (counter4 = 0; counter4 < 60; ++counter4) {
      distancia = 0.01723 * readUltrasonicDistance(8, 7);
      Serial.println(" objeto detectado");
      Serial.println(distancia);
      servo_9.write(angulo);
      angulo = (angulo - 3);
      delay(100); // Wait for 100 millisecond(s)
    }
  }
}
