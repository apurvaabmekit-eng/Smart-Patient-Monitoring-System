#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


const int ALARM   = 12; //three columns
const int HEARTBEAT =A0;
const int SWET = 11;
float HBVAL=0;

void setup()
{
   pinMode(ALARM, OUTPUT);
   pinMode(HEARTBEAT, INPUT);
   pinMode(SWET, INPUT_PULLUP);
   digitalWrite(ALARM,LOW); 
      Serial.begin(9600);                 // the GPRS baud rate 
      lcd.begin(16, 2);
      lcd.setCursor(0, 0);
      lcd.print("  SMART PATIENT ");
      lcd.setCursor(0, 1);
      lcd.print("MONITRING SYSTEM"); 
      delay(3000);
      lcd.clear();
}

void loop()
{  
  
      HBVAL=analogRead(HEARTBEAT);
     
      if(HBVAL>100 )
      {
        lcd.setCursor(0, 0);
      lcd.print("ALERT HIGH HEART");
      lcd.setCursor(0, 1);
      lcd.print(" RATE DETECTED  ");
        digitalWrite(ALARM,HIGH);
        
      }
      else if(HBVAL<50 )
      {
        lcd.setCursor(0, 0);
      lcd.print("ALERT LOW HEART ");
      lcd.setCursor(0, 1);
      lcd.print(" RATE DETECTED  ");
        digitalWrite(ALARM,HIGH);
         
      }
      else if(digitalRead(SWET)==LOW)
      {
        lcd.setCursor(0, 0);
      lcd.print("ALERT HIGH SWET ");
      lcd.setCursor(0, 1);
      lcd.print("  DETECTED!!!   ");
        digitalWrite(ALARM,HIGH);
         
      }
      else
      {
        digitalWrite(ALARM,LOW);
         lcd.setCursor(0, 0);
      lcd.print("   HEART BEAT   ");
      lcd.setCursor(0, 1);
      lcd.print("    ");
      lcd.print(HBVAL,0);
      lcd.print(" BPM    ");
      }
  
}
