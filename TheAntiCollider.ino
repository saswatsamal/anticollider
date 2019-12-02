/* The code of Anti Collider of Saswat Samal (PIYSOCIAL)
 *  for more visit: www.piysocial.weebly.com/theanticollider.html
 */

int trigPin = 5;
int echoPin = 6;
int ledRed = 2;
int ledYellow = 4;
int ledGreen = 3;
int ledred = 13;
int pwmA = 9;
int M0 = 7;
int M1 = 8;
int M2 = 11;
int M3 = 12;
int pwmB = 10;
int i = 225;
int j = 225;


void setup() {
  Serial.begin(9600); 
   pinMode(ledRed, OUTPUT);
   pinMode(ledYellow, OUTPUT);
   pinMode(ledGreen, OUTPUT);
   pinMode(ledred, OUTPUT);
  
   pinMode(M0, OUTPUT);
   pinMode(M1, OUTPUT);
   pinMode(M2, OUTPUT);
   pinMode(M3, OUTPUT);
  
   pinMode(echoPin, INPUT);
   pinMode(trigPin, OUTPUT);

   analogWrite(pwmA,i);
   analogWrite(pwmB,j);
  // put your setup code here, to run once:
}

void buzzer()
{
  digitalWrite(ledRed, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledRed, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
}

void buzzer1()
{
  digitalWrite(ledRed, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);                       // wait for a second
  digitalWrite(ledRed, LOW);    // turn the LED off by making the voltage LOW
  delay(300);                       // wait for a second
}

void buzzer2()
{
  digitalWrite(ledRed, HIGH);   
  delay(50);                       
  digitalWrite(ledRed, LOW);  
  delay(50);   
}

void motorForward()
{
  digitalWrite(M0,HIGH);
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  digitalWrite(M3,LOW);
}

void motorStop()
{
  digitalWrite(M0,LOW);
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
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

if ((distance<=25))
{
  motorStop();
  digitalWrite(ledRed,HIGH);
  digitalWrite(ledred, HIGH);
}
else if((distance>25 && distance<=30))
 {
  digitalWrite(ledred, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);
  buzzer2();
  motorForward();
  analogWrite(pwmA,i-100);
  analogWrite(pwmB,j-100);
  Serial.println("STOP, Else you'll get collided with the front vehicle");
 }
else if((distance>30 && distance<=49))
 {
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledred,LOW);
  digitalWrite(ledGreen, LOW);
  buzzer();
  motorForward();
  analogWrite(pwmA,i-50);
  analogWrite(pwmB,j-50);
  Serial.println("SLOW DOWN YOUR VEHICLE!!!!!!");
 }
else if((distance>50 && distance<100))
 {
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledred,LOW);
  digitalWrite(ledYellow, LOW);
  buzzer1();
  motorForward();
  analogWrite(pwmA,i-25);
  analogWrite(pwmB,j-25);
  Serial.println("Vehicle Ahead, Move Slowly");
 }
else if ((distance>100))
{
  motorForward();
  analogWrite(pwmA,i);
  analogWrite(pwmB,j);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledred,LOW);
  digitalWrite(ledYellow, LOW);
}
}
