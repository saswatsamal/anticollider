/* The code of Anti Collider of Saswat Samal (PIYSOCIAL)
 *  for more visit: www.piysocial.weebly.com/theanticollider.html
 */

//pins define
int trigPin = 5;
int echoPin = 6;
int ledRed = 13;
int ledYellow = 4;
int ledGreen = 3;
int ledred = 2;
int pwmA = 9;
int M0 = 7;
int M1 = 8;
int M2 = 11;
int M3 = 12;
int pwmB = 10;
int i = 225;
int j = 225;


void setup() 
{
  Serial.begin(9600); 
  /////////INDICATORS//////////
   pinMode(ledRed, OUTPUT);
   pinMode(ledYellow, OUTPUT);
   pinMode(ledGreen, OUTPUT);
   pinMode(ledred, OUTPUT);
   
  ///////MOTORS///////////
  
   pinMode(M0, OUTPUT);
   pinMode(M1, OUTPUT);
   pinMode(M2, OUTPUT);
   pinMode(M3, OUTPUT);

  //////////SENSOR/////////
  
   pinMode(echoPin, INPUT);
   pinMode(trigPin, OUTPUT);
  
  //////SPEED OF MOTOR//////

   analogWrite(pwmA,i);
   analogWrite(pwmB,j);
  
}

//////////INDICATORS(BUZZERS)///////////

void buzzer()
{
  digitalWrite(ledRed, HIGH);  
  delay(100);                       
  digitalWrite(ledRed, LOW);    
  delay(100);                       
}

void buzzer1()
{
  digitalWrite(ledRed, HIGH);  
  delay(300);                       
  digitalWrite(ledRed, LOW);    
  delay(300);                    
}

void buzzer2()
{
  digitalWrite(ledRed, HIGH);   
  delay(50);                       
  digitalWrite(ledRed, LOW);  
  delay(50);   
}

////////////MOTOR MOTION////////////

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

////////////LOOP////////////

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
 delay(100);
}
else if((distance>25 && distance<=40))
 {
  digitalWrite(ledred, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed,LOW);
  buzzer2();
  motorForward();
  analogWrite(pwmA,i-100);
  analogWrite(pwmB,j-100);
  Serial.println("STOP, Else you'll get collided with the front vehicle");
 }
else if((distance>40 && distance<=69))
 {
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledred,LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed,LOW);
  buzzer();
  motorForward();
  analogWrite(pwmA,i-50);
  analogWrite(pwmB,j-50);
  Serial.println("SLOW DOWN YOUR VEHICLE!!!!!!");
 }
else if((distance>70 && distance<100))
 {
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledred,LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed,LOW);
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
  digitalWrite(ledRed,LOW);
}
}

/*
 * For code, visit https://github.com/saswatsamal/anticollider
 */

/*
 * Siksha 'O' Anusandhan (Deemed to be) University
 */
