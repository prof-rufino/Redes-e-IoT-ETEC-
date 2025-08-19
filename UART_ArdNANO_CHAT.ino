/*

REDES & IoT - Aula Prática 1
Prof. André Rufino

*/

#include <SoftwareSerial.h>

// UART nos mesmos pinos para consistência
SoftwareSerial chatSerial(2, 3); // RX = 2, TX = 3

String msg = "";

void setup() {
  Serial.begin(9600);       // Comunicação com PC
  chatSerial.begin(9600);   // Comunicação com Arduino UNO
  Serial.println("NANO pronto para chat!");
}

void loop() {
  // Recebe do UNO e mostra no Monitor Serial
  if (chatSerial.available()) {
    msg = chatSerial.readStringUntil('\n');
    Serial.print("UNO disse: ");
    Serial.println(msg);
  }

  // Envia para o UNO o que foi digitado no Monitor Serial
  if (Serial.available()) {
    msg = Serial.readStringUntil('\n');
    chatSerial.println(msg);
  }
}
