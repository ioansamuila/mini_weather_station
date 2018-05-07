#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  DHT.read11(A2);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Hmdt.: ");
  lcd.print((float)DHT.humidity, 1);
  lcd.print(" %");
  lcd.setCursor(1, 1);
  lcd.print("Temp.: ");
  lcd.print((float)DHT.temperature, 1);
  lcd.write(0b11011111);
  lcd.print("C");
  delay(4000);
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  delay(4000);
  for (int positionCounter = 0; positionCounter < 15; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  for (int positionCounter = 0; positionCounter < 15; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
}

