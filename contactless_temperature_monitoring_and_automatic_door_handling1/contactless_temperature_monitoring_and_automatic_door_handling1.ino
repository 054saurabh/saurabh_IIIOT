#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

long x=0;
long y=0;

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(A3,INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
  
  lcd_1.begin(16, 2); 
  
}

void loop(){
  
  digitalWrite(9,0);
  delayMicroseconds(2);
  digitalWrite(9,1);
  delayMicroseconds(10);
  digitalWrite(9,0);
  y=pulseIn(8,1);
  x=(y/2)*.0343;
  Serial.println("distance");
  Serial.println(x);
  
  
  if(x<=100){
    
    int x=analogRead(A3);
    int temp=map(x,20,358,-40,125);
    Serial.println("temp");
    Serial.println(temp);

    lcd_1.setCursor(0, 0);
    lcd_1.print("body tempr is:");
    lcd_1.setCursor(2, 1);
    lcd_1.print(temp);
    delay(1000);
    
    if(temp>37){
      
      lcd_1.clear(); 
      lcd_1.setCursor(2, 0);
      lcd_1.print("NOT ALLOW");
      digitalWrite(13,1);
      digitalWrite(7,0);
      digitalWrite(6,0);
      digitalWrite(10,0);
      delay(1000);  
    }
    else if(temp<30){
      
      lcd_1.clear(); 
      lcd_1.setCursor(2, 0);
      lcd_1.print("NOT ALLOW");
      digitalWrite(13,1);
      digitalWrite(7,0);
      digitalWrite(6,0);
      digitalWrite(10,0);
      delay(1000);  
      
    }
    else{
    
      lcd_1.clear(); 
      lcd_1.setCursor(2, 0);
      lcd_1.print("WELCOME !!!");
      lcd_1.setCursor(2, 1);
      lcd_1.print(temp);

      digitalWrite(13,0);
      
      digitalWrite(10,0);
      digitalWrite(6,1);
      digitalWrite(7,0);
      delay(1000);

      digitalWrite(6,0);
      digitalWrite(10,0);
      digitalWrite(7,1);
      delay(1000);

      digitalWrite(6,0);
      digitalWrite(7,0);
      digitalWrite(10,1);
      delay(1000);

    }
  }
  else{
    lcd_1.clear();
    digitalWrite(6,0);
    digitalWrite(10,0);
    digitalWrite(7,0);
    digitalWrite(13,0);
    delay(100);
 }
      
}