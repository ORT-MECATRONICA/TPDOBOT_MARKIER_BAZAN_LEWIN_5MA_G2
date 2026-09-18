//LDR_5MA_G2_DOBOT_MARKIER_BAZAN_LEWIN

const int LDR_PIN = 32;

void setup() {
  Serial.begin(115200);
  pinMode(LDR_PIN, INPUT);}
  
  Serial.println("--- Prueba de LDR con ESP32 iniciada ---");
}

void loop() {
  int valorLDR = analogRead(LDR_PIN);
  float porcentajeLuz = (valorLDR / 4095.0) * 100.0;

  Serial.print("Valor LDR: ");
  Serial.print(valorLDR);
  Serial.print(" | Luz aproximada: ");
  Serial.print(porcentajeLuz, 1);
  Serial.println("%");

  delay(500);
}