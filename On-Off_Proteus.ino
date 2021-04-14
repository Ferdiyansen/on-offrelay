#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);

float set_temperature=0;


void setup() {
  // put your setup code here, to run once:

pinMode(3,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);

digitalWrite(3,LOW);

lcd.begin(16,2);
lcd.display();
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
set_temperature=analogRead(A1);
set_temperature=map(set_temperature,0,1024,0,100);

float T=analogRead(A0);
T=map(T,0,1024,0,100);

//On-Off Control
if(T<set_temperature)
{digitalWrite(3,HIGH);}
else
{digitalWrite(3,LOW);}

//Display message on LCD 
lcd.setCursor(0,0);
lcd.print("Temp    Set_T");

lcd.setCursor(0,1);
lcd.print(T);
lcd.setCursor(10,1);
lcd.print(set_temperature);

}
