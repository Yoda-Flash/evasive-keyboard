 // Define pin connections & motor's steps per revolution
const int dirPin1 = D9;
const int stepPin1 = D10;
const int dirPin2 = D7;
const int stepPin2 = D8;
const int enablePin = D1;
const int stepsPerRevolution = 3200;

void setup() {
  // Declare pins as Outputs
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Set motor direction clockwise
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);

  // Spin motor slowly
  for (int x = 0; x < stepsPerRevolution; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(25);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(25);

  }
  delay(1000);  // Wait a second

  // Set motor direction counterclockwise
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);

  // Spin motor quickly
  for (int x = 0; x < stepsPerRevolution; x++) {
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(25);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(25);
  }
  delay(1000);  // Wait a second
}