/*

REDES & IoT
Prof. André Rufino

*/
  

String msg = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Dispositivo pronto para o chat!");
}

void loop() {
  // Mostra mensagens recebidas do Mega
  if (Serial.available()) {
    msg = Serial.readStringUntil('\n');
    Serial.println(msg);
  }

  // Envia mensagens digitadas no Monitor Serial para o Mega
  if (Serial.availableForWrite() && Serial.available()) {
    msg = Serial.readStringUntil('\n');
    Serial.println("Enviado: " + msg); // confirma localmente
  }
}
