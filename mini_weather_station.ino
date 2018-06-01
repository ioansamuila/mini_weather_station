#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Celsius to Fahrenheit conversion
double Fahrenheit(double celsius)
{
        return 1.8 * celsius + 32;
}

//Celsius to Kelvin conversion
double Kelvin(double celsius)
{
        return celsius + 273.15;
}

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor:");
  delay(1000);//Wait before accessing Sensor
}

void loop() {
  DHT.read11(A2);
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  and ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature);
  Serial.print("C / ");
  Serial.print(Fahrenheit(DHT.temperature));
  Serial.print("F / ");
  Serial.print(Kelvin(DHT.temperature));
  Serial.println("K.");
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

