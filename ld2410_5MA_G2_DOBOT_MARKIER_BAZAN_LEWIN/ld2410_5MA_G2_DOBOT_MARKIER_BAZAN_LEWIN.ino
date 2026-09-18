// 5MA G2 - MARKIER, BAZAN Y LEWIN

#include <ld2410.h>

ld2410 radar;

void setup() {
  Serial.begin(115200); 
  Serial2.begin(256000, SERIAL_8N1, 16, 17);
  Serial.println("\n--- Reiniciando comunicación con HLK-LD2410C ---");

  if (radar.begin(Serial2)) {
    Serial.println("¡Conectado exitosamente al sensor!");
  } else {
    Serial.println("Error: No hay comunicación por UART.");
  }
}

void loop() {
  radar.read();

  if (radar.isConnected()) {
    if (radar.presenceDetected()) {
      Serial.println("Precencia detectada");
    } else {
      Serial.println("No hay presencia detectada");
    }
  } else {
    Serial.println("Esperando datos del radar...");
  }

  delay(300);
}