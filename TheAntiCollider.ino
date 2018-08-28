 int trigPin = 9;
int echoPin = 10;
int ledRed = 11;
int ledGreen = 12;
int ledYellow = 7;
int motor = 8;



void setup() {
  Serial.begin(9600); 
   pinMode(ledRed, OUTPUT);
   pinMode(ledGreen, OUTPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(motor, OUTPUT);
   pinMode(ledYellow, OUTPUT);
  pinMode(echoPin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);

 
 if((distance<=30)) 
  {
    digitalWrite(ledRed, HIGH);// turn the LED on (HIGH is the voltage level)
   
    digitalWrite(ledGreen, LOW);
    digitalWrite(motor, LOW);
    digitalWrite(ledYellow, LOW);
}
   else if(distance>30 and distance<49)
 {
     digitalWrite(ledRed, LOW);// turn the LED off by making the voltage LOW
    digitalWrite(ledYellow, HIGH);
     digitalWrite(ledGreen, LOW);
     digitalWrite(motor, HIGH);
 }
    else if(distance>50)
    {
 digitalWrite(ledRed, LOW);// turn the LED off by making the voltage LOW
 digitalWrite(ledYellow, LOW);
     digitalWrite(ledGreen, HIGH);
     digitalWrite(motor, HIGH);
  }
}
