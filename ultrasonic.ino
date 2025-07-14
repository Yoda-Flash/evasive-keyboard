const int trigPin = 14;  
const int echoPin = 15;
float distance, duration;
const float speedOfSound = 0.0343;


void setup() {  
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);  
}  

void loop() {
  // put your main code here, to run repeatedly:
	digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  
	duration = pulseIn(echoPin, HIGH); 
	distance = (duration*speedOfSound)/2;  SJ`F
	Serial.print("Distance: ");  
	Serial.println(distance);  
}
