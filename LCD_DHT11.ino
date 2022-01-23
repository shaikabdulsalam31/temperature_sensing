#include "DHT.h"
#include "LiquidCrystal.h"

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
dht.begin();
lcd.begin(16,2);
lcd.print("The current temp");
lcd.setCursor(0,1);
lcd.print("is: ");
float f = dht.readTemperature(true);
lcd.setCursor(5,1);
lcd.print(f);
lcd.print(" F");
}

void loop() {
delay(1000*60*5);
// put your main code here, to run repeatedly:
float f = dht.readTemperature(true);
lcd.setCursor(5,1);
lcd.print(f);
lcd.print(" F");
delay(100);
}
