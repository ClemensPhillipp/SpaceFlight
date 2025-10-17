#include <Servo.h>

Servo servo;

int minpos = 175;
int maxpos = 110;

int pos = minpos;

const int IN1 = 5;
const int IN2 = 6;
const int GSM1 = 10;

int speed = 255;

void setup() {
  servo.attach(9);
  servo.write(pos);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(GSM1, OUTPUT);
}

void loop() {
  delay(5000);
  motor_forward();
  up();
  delay(10000);
  down();
  delay(5000);
  motor_stop();
  delay(5000);
}

void motor_forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  for (int i = 0; i <= speed; i += 1) {
    analogWrite(GSM1, i);
    delay(80);
  }
}

void motor_stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  for (int i = speed; i >= 0; i -= 1) {
    analogWrite(GSM1, i);
    delay(80);
  }
}

void up() {
  for (pos = minpos; pos >= maxpos; pos -= 1) {
    servo.write(pos);
    delay(50);
  }
}

void down() {
  for (pos = maxpos; pos <= minpos; pos += 1) {
    servo.write(pos);
    delay(50);
  }
}
