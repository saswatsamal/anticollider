#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd( 0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int trigPin = 6;
int echoPin = 5;
int ledRed = 13;
int ledYellow = 4;
int ledGreen = 3;
int ledred = 2;
int pwmA = 9;
int M0 = 8;
int M1 = 7;
int M2 = 12;
int M3 = 11;
int pwmB = 10;
int i = 225;
int j = 225;


void setup() 
{
  Serial.begin(9600); 
  lcd.begin(16, 2); 
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
  lcd.print("Distance:");
  lcd.print(distance);
  lcd.print("CM");
  lcd.setCursor(0, 1); 
  delay(100);

if ((distance<=25))
{
  motorStop();
  digitalWrite(ledRed,HIGH);
  digitalWrite(ledred, HIGH);
 delay(100);
 lcd.print("STOP");
 lcd.setCursor(0, 0); 
 delay(500);
 lcd.clear();
}
else if((distance>25 && distance<=40))
 {
  digitalWrite(ledred, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed,LOW);
  buzzer2();
  motorForward();
  analogWrite(pwmA,100); // speed on the left wheel
  analogWrite(pwmB,100); // speen on the right wheel
  // the speed will be calculated from the odometer...
  Serial.println("STOP, Else you'll get collided with the front vehicle");
lcd.print("SLOW DOWN");
lcd.setCursor(0, 0); 
delay(1000);
lcd.clear();
 }
else if((distance>40 && distance<=69))
 {
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledred,LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed,LOW);
  buzzer();
  motorForward();
  analogWrite(pwmA,150);
  analogWrite(pwmB,150);
  Serial.println("SLOW DOWN YOUR VEHICLE!!!!!!");
  lcd.print("SLOW DOWN NOW");
  lcd.setCursor(0, 0); 
 delay(1000);
  lcd.clear();
 }
else if((distance>70 && distance<100))
 {
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledred,LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed,LOW);
  buzzer1();
  analogWrite(pwmA,220);
  analogWrite(pwmB,220);
  motorForward();
  Serial.println("Vehicle Ahead, Move Slowly");
  lcd.print("MOVE SLOWLY");
  lcd.setCursor(0, 0); 
 delay(1000);
  lcd.clear();
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
  lcd.print("DRIVE SAFE");
  lcd.setCursor(0, 1); 
  delay(1000);
  lcd.print("OBEY TRAFFIC");
  lcd.setCursor(0, 0); 
  delay(1000);
  lcd.clear();

}
}
