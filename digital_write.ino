const int writeStepperOnPin = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(writeStepperOnPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(writeStepperOnPin, 1);
  delay(10);
  digitalWrite(writeStepperOnPin, 0);
  delay(10);
}