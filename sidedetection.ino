int tr1=12;
int te1=13;
int tr2=10;
int te2=9;
int led1=3;
int led2=4;
void setup() {
  // put your setup code here, to run once:
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
pinMode(12,OUTPUT);
pinMode(10,OUTPUT);//trigger
pinMode(13,INPUT);//echopin
pinMode(9,INPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
 long duration, distance;
  digitalWrite(tr1,HIGH);
  delayMicroseconds(1000);
  digitalWrite(tr1, LOW);
  duration=pulseIn(te1, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
  long duration1, distance1;
  digitalWrite(tr2,HIGH);
  delayMicroseconds(1000);
  digitalWrite(tr2, LOW);
  duration1=pulseIn(te2, HIGH);
  distance1 =(duration1/2)/29.1;
  Serial.print(distance1);
  Serial.println("CM");
  delay(10);
  if (distance<=25)
  {
    digitalWrite(led1,HIGH);
    delay(1000);
    digitalWrite(led1,LOW);
    delay(100);
    
  }
  if (distance1<=25)
  {
    digitalWrite(led2,HIGH);
    delay(1000);
    digitalWrite(led2,LOW);
    delay(100);
  }
  
  
}
