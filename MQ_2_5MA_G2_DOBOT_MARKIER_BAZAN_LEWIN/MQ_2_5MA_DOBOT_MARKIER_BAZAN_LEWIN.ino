// 5MA G2 - MARKIER, BAZAN Y LEWIN

const int MQ2_PIN = 33;

void setup() {
  Serial.begin(115200); 
  pinMode(MQ2_PIN, INPUT);
  Serial.println("--- Prueba del sensor MQ-2 con ESP32 ---");
 
  delay(3000);
}

void loop() {
  int valorGAS = analogRead(MQ2_PIN); 
  float porcentajeGAS = (valorGAS / 4095.0) * 100.0;

  Serial.print("Lectura GAS: ");
  Serial.print(valorGAS);
  Serial.print(" | Nivel relativo: ");
  Serial.println(porcentajeGAS, 1);

  delay(1000);
}