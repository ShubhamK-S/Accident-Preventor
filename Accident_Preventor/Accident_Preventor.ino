#include <LiquidCrystal.h>

#define SENSE_eyeblink A5 

#define buzzer 6
#define relay A0

#define sensorDigital_al 7
#define sensorAnalog_al A4

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup()
{
pinMode(SENSE_eyeblink, INPUT);
pinMode(sensorDigital_al, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(relay, OUTPUT);
Serial.begin(9600);
lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Driver safe.");


}
void loop()
{
bool digital = digitalRead(sensorDigital_al);
  int analog = analogRead(sensorAnalog_al);
  
  digitalWrite(relay, LOW);
  //delay(500);

  Serial.print("Analog value : ");
  Serial.print(analog);
  Serial.print("t");
  Serial.print("Digital value :");
  Serial.println(digital);

if(digitalRead(SENSE_eyeblink) || digital==1)
{
 //digitalWrite(buzzer, LOW);
// digitalWrite(LED, HIGH);
 digitalWrite(buzzer, HIGH);
digitalWrite(relay, HIGH);
  delay(100);
  lcd.clear();
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("WARNING! Stopped.");
 
}
else
{
 // digitalWrite(buzzer, HIGH);  
  // digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW);
  digitalWrite(relay, LOW);
  // delay(3000);
  lcd.clear();
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Driver safe.");
  }
}