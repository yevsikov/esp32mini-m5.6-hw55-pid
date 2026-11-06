#include <Arduino.h>
#define LED_PIN 5
#define POT_PIN 7



void setup() {
  Serial.begin(115200);
  Serial.println("--- Ініціалізація GPIO ---");

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  pinMode(POT_PIN, INPUT);
  analogSetPinAttenuation(POT_PIN, ADC_11db);
}

void loop() {
  Serial.println("ESP32 is alive!");

  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);


  int potValue = analogRead(POT_PIN);
  Serial.print("Potentiometer value: ");
  Serial.println(potValue);

}

