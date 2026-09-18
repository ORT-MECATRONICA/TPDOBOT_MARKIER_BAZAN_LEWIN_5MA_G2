// 5MA G2 - MARKIER, BAZAN Y LEWIN

#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

void setup() {
  Serial.begin(115200);
  Serial.println("--- Prueba de sensor BMP280 con ESP32 ---");

  bool status = bmp.begin(0x76);

  if (!status) {
    status = bmp.begin(0x77);
  }

  if (!status) {
    Serial.println("¡Error! No se encontró el sensor BMP280. Verificá las conexiones.");
    while (1) { delay(10); }
  }

  /* Parámetros por defecto para la medición de presión/temperatura */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Modo de funcionamiento */
                  Adafruit_BMP280::SAMPLING_X2,     /* Muestreo de temp. */
                  Adafruit_BMP280::SAMPLING_X16,    /* Muestreo de presión */
                  Adafruit_BMP280::FILTER_X16,      /* Filtrado de ruido */
                  Adafruit_BMP280::STANDBY_MS_500); /* Tiempo de espera */

  Serial.println("BMP280 detectado correctamente. Iniciando lecturas...");
}

void loop() {
  float temperatura = bmp.readTemperature();

  Serial.print("Temperatura: ");
  Serial.print(temperatura, 1);
  Serial.println(" °C");

  delay(2000);
}