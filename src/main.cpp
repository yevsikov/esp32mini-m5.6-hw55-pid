#include <Arduino.h>
#define LED_PIN 5
#define POT_PIN 7
#define LDR_PIN 9

const int PWM_BASE = 0;
const float PID_KP = 0.01;
const float PID_KI = 0.001;

float iCorrection = 0.0;
unsigned long previousTime = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("--- Ініціалізація GPIO ---");
  Serial.println("PID_KP: ");
  Serial.print(PID_KP);


  pinMode(LED_PIN, OUTPUT);
  analogWrite(LED_PIN, 128);

  pinMode(POT_PIN, INPUT);
  analogSetPinAttenuation(POT_PIN, ADC_11db);

  pinMode(LDR_PIN, INPUT);
  analogReadResolution(12);
  analogSetPinAttenuation(LDR_PIN, ADC_11db);

  previousTime = millis();
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int setpoint = potValue;
  int ldrValue = analogRead(LDR_PIN);
  int error = setpoint - ldrValue;

  Serial.print("TIME: ");
  Serial.print(millis());
  Serial.print(" | TARGET: ");
  Serial.print(setpoint);
  Serial.print(" | LDR: ");
  Serial.print(ldrValue);


  unsigned long currentTime = millis();
  float dtSeconds = (currentTime - previousTime) / 1000.0;
  previousTime = currentTime;

  iCorrection += PID_KI * error * dtSeconds;

  if (iCorrection > 30.0) {
    iCorrection = 30.0;
  }
  if (iCorrection < -30.0) {
    iCorrection = -30.0;
  }

  float pwmValue = PWM_BASE + PID_KP * error + iCorrection;

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
  Serial.print(" | I: ");
  Serial.print(iCorrection, 2);
  Serial.print(" | PWM: ");
  Serial.println(pwmOutput);

  delay(500);
}

