#include <Arduino.h>
#define LED_PIN 5
#define POT_PIN 7
#define LDR_PIN 9

const int PWM_BASE = 128;
const float PID_KP = 0.03;

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


  float pwmValue = PWM_BASE + PID_KP * error;

  if (pwmValue < 0) {
    pwmValue = 0;
  }
  if (pwmValue > 255) {
    pwmValue = 255;
  }

  int pwmOutput = (int)pwmValue;
  analogWrite(LED_PIN, pwmOutput);

  
  Serial.print(" | ERROR: ");
  Serial.print(error);
  Serial.print(" | PWM: ");
  Serial.println(pwmOutput);

  delay(500);
}

