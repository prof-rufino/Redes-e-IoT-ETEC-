*/  

REDES e IoT Aula 1

/*


#include <SoftwareSerial.h>

// Cria uma UART em pinos digitais
SoftwareSerial chatSerial(2, 3); // RX = 2, TX = 3

String msg = "";

void setup() {
  Serial.begin(9600);       // Comunicação com PC
  chatSerial.begin(9600);   // Comunicação com Arduino Nano
  Serial.println("UNO pronto para chat!");
}

void loop() {
  // Recebe do NANO e mostra no Monitor Serial
  if (chatSerial.available()) {
    msg = chatSerial.readStringUntil('\n');
    Serial.print("NANO disse: ");
    Serial.println(msg);
  }

  // Envia para o NANO o que foi digitado no Monitor Serial
  if (Serial.available()) {
    msg = Serial.readStringUntil('\n');
    chatSerial.println(msg);
  }
}
