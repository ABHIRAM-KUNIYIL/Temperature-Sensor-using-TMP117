#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
#include <SoftwareWire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

SoftwareWire bus1(7, 8);
SoftwareWire bus2(6, 8);
SoftwareWire bus3(5, 8);
SoftwareWire bus4(4, 8);
SoftwareWire bus5(3, 8);

unsigned long previousMillis = 0;
const unsigned long RECORDING_INTERVAL = 250; 

int lastPage = -1; 

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight(); 
  lcd.print("System Booting..");

  bus1.begin();
  bus2.begin();
  bus3.begin();
  bus4.begin();
  bus5.begin();

  // ---> Time removed from headers
  Serial.println("Temp1,Temp2,Temp3,Temp4,Temp5");
  delay(2000); 
}

float readTemp(SoftwareWire &bus) {
  float tempC = 0.0;
  bus.beginTransmission(0x48); 
  bus.write(0x00); 
  bus.endTransmission();
  
  bus.requestFrom(0x48, 2); 
  
  if (bus.available() == 2) {
    int16_t rawTemp = (bus.read() << 8) | bus.read();
    tempC = rawTemp * 0.0078125; 
  }
  return tempC;
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= RECORDING_INTERVAL) {
    previousMillis = currentMillis;

    float t1 = readTemp(bus1);
    float t2 = readTemp(bus2);
    float t3 = readTemp(bus3);
    float t4 = readTemp(bus4);
    float t5 = readTemp(bus5);

    // ---> Time removed from Excel stream
    Serial.print(t1); Serial.print(",");
    Serial.print(t2); Serial.print(",");
    Serial.print(t3); Serial.print(",");
    Serial.print(t4); Serial.print(",");
    Serial.println(t5);

    // --- SMART LCD UPDATING ---
    int currentPage = (currentMillis / 3000) % 2; 

    if (currentPage != lastPage) {
      lcd.clear();
      lastPage = currentPage;
    }

    if (currentPage == 0) {
      lcd.setCursor(0, 0); lcd.print("1:"); lcd.print(t1, 1); lcd.print(" ");
      lcd.setCursor(8, 0); lcd.print("2:"); lcd.print(t2, 1); lcd.print(" ");
      lcd.setCursor(0, 1); lcd.print("3:"); lcd.print(t3, 1); lcd.print(" ");
      lcd.setCursor(8, 1); lcd.print("4:"); lcd.print(t4, 1); lcd.print(" ");
    } else {
      lcd.setCursor(0, 0); lcd.print("5:"); lcd.print(t5, 1); lcd.print(" C  ");
    }
  }
}