#include <Psx.h>   
#define dataPin 10
#define cmndPin 11
#define attPin 12
#define clockPin 13
int b=4;
int a=5;
int c=6;
int d=7;
int enA=3;
int enB=9;
Psx Psx;                                                 
unsigned int data = 0;                                   
void setup()
{
  Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10); 
  pinMode(enA,OUTPUT);      
  pinMode(enB,OUTPUT);                       
  pinMode(a, OUTPUT);  
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT); 
  pinMode(d, OUTPUT);
  Serial.begin(9600);
 }
void loop()
{
  data = Psx.read();                                                                                               
  Serial.println(data);    
 if (data & psxUp) 
 {                                                                                
    digitalWrite(b, HIGH);  
    digitalWrite(a, LOW);  
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    analogWrite(enA,255);
    analogWrite(enB,255);
    Serial.println("up");                   
  }
 else if (data & psxLeft)                                    
  {  
    digitalWrite(b, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    analogWrite(enA,255);
    analogWrite(enB,255);
    Serial.println("left");
  }
else if (data & psxRight)                                    
{
    digitalWrite(b, HIGH); 
    digitalWrite(a, LOW);  
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    analogWrite(enA,255);
    analogWrite(enB,255);
    Serial.println("right");
  }
  else if (data & psxDown)                                     
  {
    digitalWrite(b,LOW);  
    digitalWrite(a, HIGH);  
    digitalWrite(c,HIGH);
    digitalWrite(d, LOW);
    analogWrite(enA,255);
    analogWrite(enB,255);
    Serial.println("down");   
  }
  else
  {
    digitalWrite(c, LOW);
    digitalWrite(b, LOW);  
    digitalWrite(a, LOW);  
    digitalWrite(d, LOW);
  }
  delay(20);
  Serial.println(data);   
}
