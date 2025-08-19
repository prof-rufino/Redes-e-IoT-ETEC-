/*

  REDES & IoT
  Prof. André Rufino

*/



void setup() {
  Serial.begin(9600);   // Comunicação com o PC
  Serial1.begin(9600);  // Comunicação com Nano #1
  Serial2.begin(9600);  // Comunicação com Nano #2
  Serial3.begin(9600);  // Comunicação com UNO

  Serial.println("Mega pronto para gerenciar o chat!");
}

void loop() {
  // --- Recebe do NANO 1 e repassa ---
  if (Serial1.available()) {
    String msg = Serial1.readStringUntil('\n');
    Serial.print("Nano 1 disse: ");
    Serial.println(msg);
    Serial2.println("Nano 1: " + msg);
    Serial3.println("Nano 1: " + msg);
  }

  // --- Recebe do NANO 2 e repassa ---
  if (Serial2.available()) {
    String msg = Serial2.readStringUntil('\n');
    Serial.print("Nano 2 disse: ");
    Serial.println(msg);
    Serial1.println("Nano 2: " + msg);
    Serial3.println("Nano 2: " + msg);
  }

  // --- Recebe do UNO e repassa ---
  if (Serial3.available()) {
    String msg = Serial3.readStringUntil('\n');
    Serial.print("UNO disse: ");
    Serial.println(msg);
    Serial1.println("UNO: " + msg);
    Serial2.println("UNO: " + msg);
  }

  // --- Recebe do PC e envia para todos ---
  if (Serial.available()) {
    String msg = Serial.readStringUntil('\n');
    Serial1.println("PC: " + msg);
    Serial2.println("PC: " + msg);
    Serial3.println("PC: " + msg);
  }
}
