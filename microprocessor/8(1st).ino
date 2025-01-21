#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define I2C_ADDR 0x27
#define LCD_COLUMNS  20
#define LCD_LINES 4
#define LDR_PIN 13

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
DHT dht(DHTPIN, DHTTYPE);

void setup(){
  lcd.init();
  lcd.backlight();

  //lcd.begin(9600);
  lcd.setCursor(1,0);
  lcd.print("dht22 sensor logging");
  dht.begin();

  pinMode(LDR_PIN, INPUT);
}

void loop(){

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)){
    lcd.println(F("Failed to read from DHT sensor"));
    return;
  }
  lcd.setCursor(2,3);
  lcd.print(F("Humidity: "));
  lcd.print(humidity);
  lcd.setCursor(3,2);
  lcd.print(F("% Temperature: "));
  lcd.print(temperature);
  lcd.setCursor(1,1);
  lcd.print(F(".C"));

  lcd.print("Room: ");
  if (digitalRead(LDR_PIN) == LOW){
    lcd.println("light");
  }
  else{
    lcd.println("dark");
  }
}