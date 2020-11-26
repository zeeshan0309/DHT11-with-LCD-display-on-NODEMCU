#include <DHT.h>
#include <DHT_U.h>

#include<Wire.h>
#include<LiquidCrystal_I2C.h>

#define Type DHT11
int sensePin = 6;


DHT obj(sensePin, Type);
float temp;
float humidity;
int setupTime = 500;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  obj.begin();
  delay(setupTime);
  Serial.begin(115200);
}

void loop() {
  humidity = obj.readHumidity();
  temp = obj.readTemperature();
  Serial.print("temp = ");
  Serial.print(temp);
  Serial.print(" humidity = ");
  Serial.println(humidity);
  delay(2*setupTime);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("temp = ");
  lcd.print(temp);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("humidity = ");
  lcd.print(humidity);
  lcd.print("%");
 
  
  delay(setupTime);
}
