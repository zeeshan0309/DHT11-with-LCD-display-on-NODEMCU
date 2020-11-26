#include <LiquidCrystal_I2C.h>

#include <dummy.h>

#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>

#define Type DHT11
int sensePin = 0;

DHT obj(sensePin, Type);
float temp;
float humidity;
int setupTime = 500;

LiquidCrystal_I2C lcd(0x27);

void setup() { 
  lcd.begin(16, 2);
  
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.write("Hello");
  Serial.begin(115200);
  obj.begin();
  delay(setupTime);
}

void loop() {
  humidity = obj.readHumidity();
  temp = obj.readTemperature();
  Serial.print("temp = ");
  Serial.print(temp);
  Serial.print(" humidity = ");
  Serial.println(humidity);
  delay(2*setupTime);
}
