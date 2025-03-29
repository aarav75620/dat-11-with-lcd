#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Define DHT11 Sensor
#define DHTPIN 2      // Pin connected to DHT11 data pin
#define DHTTYPE DHT11 // Using DHT11 sensor

DHT dht(DHTPIN, DHTTYPE);

// Initialize LCD (0x27 is the common I2C address, some LCDs use 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    // Start LCD and DHT sensor
lcd.begin(16, 2);
    lcd.backlight();
    dht.begin();
    
    // Display startup message
    lcd.setCursor(0, 0);
    lcd.print("DHT11 with LCD");
    delay(2000);
    lcd.clear();
}

void loop() {
    // Read temperature and humidity
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // Check if readings are valid
    if (isnan(h) || isnan(t)) {
        lcd.setCursor(0, 0);
        lcd.print("Sensor Error!");
        return;
    }

    // Display Humidity
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.print("% ");

    // Display Temperature
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print("C ");

    // Wait before next reading
    delay(2000);
}
