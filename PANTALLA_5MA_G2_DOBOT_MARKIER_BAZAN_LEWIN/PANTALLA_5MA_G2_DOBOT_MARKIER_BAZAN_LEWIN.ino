//PANTALLA_5MA_G2_DOBOT_MARKIER_BAZAN_LEWIN

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int contador = 0;

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Prueba ESP32");
 
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Hika Mirko!");

  lcd.setCursor(contador, 1);
  lcd.print("<3");

  contador++;
  if (contador > 15) {
    contador = 0;
  }
  delay(1000);

  lcd.setCursor(0, 1);
  lcd.print("                ");
}