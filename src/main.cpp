#include <Arduino.h>
#define LED_PIN 5
#define POT_PIN 7
#define LDR_PIN 9



void setup() {
  Serial.begin(115200);
  Serial.println("--- Ініціалізація GPIO ---");

  pinMode(LED_PIN, OUTPUT);
  analogWrite(LED_PIN, 128);

  pinMode(POT_PIN, INPUT);
  analogSetPinAttenuation(POT_PIN, ADC_11db);

  pinMode(LDR_PIN, INPUT);
  analogReadResolution(12);
  analogSetPinAttenuation(LDR_PIN, ADC_11db);
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int setpoint = potValue;
  int ldrValue = analogRead(LDR_PIN);
  int error = setpoint - ldrValue;

  Serial.print("TARGET: ");
  Serial.print(setpoint);
  Serial.print(" | LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | ERROR: ");
  Serial.println(error);

  delay(500);
}

