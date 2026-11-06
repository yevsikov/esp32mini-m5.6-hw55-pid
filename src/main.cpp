#include <Arduino.h>
#define LED_PIN 5



void setup() {
  Serial.begin(115200);
  Serial.println("--- Ініціалізація GPIO ---");
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
      Serial.println("ESP32 is alive!");

  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}

