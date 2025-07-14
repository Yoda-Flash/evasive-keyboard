const int leftStepperDirPin = D9;
const int leftStepperStepPin = D10;
const int rightStepperDirPin = D7;
const int rightStepperStepPin = D8;
const int blotEnablePin = D1;

const int stepsPerRevolution = 3200;
const int maxStepperPose = 4800;
int stepperPos;

const int maxStepperDelay = 150;
const int minStepperDelay = 25;
int stepperDelay;

const int readStepperOnPin = D0;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftStepperDirPin, OUTPUT);
  pinMode(leftStepperStepPin, OUTPUT);
  pinMode(rightStepperDirPin, OUTPUT);
  pinMode(rightStepperStepPin, OUTPUT);
  pinMode(blotEnablePin, OUTPUT);

  pinMode(readStepperOnPin, INPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(readStepperOnPin) == 1 && stepperPos <= maxStepperPose) {
    stepperOut();
  } 
  else if (digitalRead(readStepperOnPin) == 1 && stepperPos > maxStepperPose) {
    stepperIn();
  }
  // stepperOut();
  // delay(1000);
  Serial.print("Digital read: ");
  Serial.println(digitalRead(readStepperOnPin));

  // stepperIn();
  // delay(1000);
  // delay(5);
}

void stepperOut() {
  digitalWrite(leftStepperDirPin, HIGH);
  digitalWrite(rightStepperDirPin, HIGH);
  Serial.println("Moving stepper out");
  
  stepperDelay = generateRandomStepperDelay();

  for (int x = 0; x < stepsPerRevolution; x++) {
    stepperPos += x;
    digitalWrite(leftStepperStepPin, HIGH);
    digitalWrite(rightStepperStepPin, HIGH);
    delayMicroseconds(stepperDelay);
    digitalWrite(leftStepperStepPin, LOW);
    digitalWrite(rightStepperStepPin, LOW);
    delayMicroseconds(stepperDelay);
  }
}

void stepperIn() {
  digitalWrite(leftStepperDirPin, LOW);
  digitalWrite(rightStepperDirPin, LOW);
  
  stepperDelay = generateRandomStepperDelay();

  for (int x = 0; x < stepsPerRevolution; x++) {
    stepperPos -= x;
    digitalWrite(leftStepperStepPin, HIGH);
    digitalWrite(rightStepperStepPin, HIGH);
    delayMicroseconds(stepperDelay);
    digitalWrite(leftStepperStepPin, LOW);
    digitalWrite(rightStepperStepPin, LOW);
    delayMicroseconds(stepperDelay);
  }
}

long generateRandomStepperDelay() {
  return random(minStepperDelay, maxStepperDelay);
}