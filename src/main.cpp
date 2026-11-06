#include <Arduino.h>
#define LED_PIN 5
#define POT_PIN 7
#define LDR_PIN 9



void setup() {
  Serial.begin(115200);
  Serial.println("--- Ініціалізація GPIO ---");

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  pinMode(POT_PIN, INPUT);
  analogSetPinAttenuation(POT_PIN, ADC_11db);

  pinMode(LDR_PIN, INPUT);
  analogReadResolution(12);
  analogSetPinAttenuation(LDR_PIN, ADC_11db);
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

    int ldrValue = analogRead(LDR_PIN); // Read the value from the LDR sensor
    Serial.print("LDR value: ");
    Serial.println(ldrValue);

}

