#include <servo.h>

const int writeStepperOnPin = 10;

const int leftTrigPin = 14;
const int leftEchoPin = 15;
const int rightTrigPin = 12;
const int rightEchoPin = 13;

float leftDuration, rightDuration, leftDistance, rightDistance;
const float speedOfSound = 0.0343;
const int upperDistanceThreshold = 17;
const int lowerDistanceThreshold = 25;

const int leftServoPin = 19;
const int rightServoPin = 18;
Servo leftServo;
Servo rightServo;
const int maxLeftServo = 180;
const int minLeftServo = 100;
const int maxRightServo = 180;
const int minRightServo = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(writeStepperOnPin, OUTPUT);

  pinMode(leftTrigPin, OUTPUT);
  pinMode(leftEchoPin, INPUT);
  pinMode(rightTrigPin, OUTPUT);
  pinMode(rightEchoPin, INPUT);

  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);

  Serial.begin(9600);
}

void loop() {
  readLeftDistance();
  readRightDistance();
  // put your main code here, to run repeatedly:
  if (leftDistance <= lowerDistanceThreshold || rightDistance <= lowerDistanceThreshold) {
    digitalWrite(writeStepperOnPin, 1);
  } else digitalWrite(writeStepperOnPin, 0);

f
}

void readLeftDistance() {
  digitalWrite(leftTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(leftTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(leftTrigPin, LOW);
  leftDuration = pulseIn(leftEchoPin, HIGH);
  leftDistance = (leftDuration*speedOfSound)/2;
  Serial.print("left distance: ");
  Serial.println(leftDistance);
}

void readRightDistance() {
  digitalWrite(rightTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(rightTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(rightTrigPin, LOW);
  rightDuration = pulseIn(rightEchoPin, HIGH);
  rightDistance = (rightDuration*speedOfSound)/2;
  Serial.print("right distance: ");
  Serial.println(rightDistance);
}
'
  // void moveLeftServo() {
  //   leftServo.write(minLeftServo, maxLeftServo);
  // }

  // void generateRandomServoTarget(int min, int max) {
  //   return random(min, max);
  // }

  // void generateRandomServoDelay() {
  //     H
  // }'