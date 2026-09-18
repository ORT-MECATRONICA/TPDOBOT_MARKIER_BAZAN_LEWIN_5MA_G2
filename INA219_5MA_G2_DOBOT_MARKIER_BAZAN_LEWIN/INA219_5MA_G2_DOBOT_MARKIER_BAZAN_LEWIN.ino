// 5MA G2 - MARKIER, BAZAN Y LEWIN

#include <Wire.h>
#include <Adafruit_INA219.h>

const int SDA_PIN = 21;
const int SCL_PIN = 22 ;
const int ALERT_PIN = 27;

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(115200);
  pinMode(ALERT_PIN, INPUT);
  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("\n--- Monitoreo de Corriente con INA219 ---");

  if (!ina219.begin()) {
    Serial.println("Error: No se encontró el módulo INA219. Verificá conexiones.");
    while (1) { delay(10); }
  }

  Serial.println("Sensor INA219 listo.");
}

void loop() {
  float corriente_mA = ina219.getCurrent_mA();

  Serial.print("Corriente: ");
  Serial.print(corriente_mA, 1);
  Serial.println(" mA");

  delay(500);
}