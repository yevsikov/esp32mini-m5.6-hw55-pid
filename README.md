# ESP32 - Learning Project

This is a small educational project for the [Embedded Development course](https://beetroot.academy/courses/online/kurs-embedded-development)

## Circuit Diagram

```
ESP32-S2-mini

                    +----------------------+
3.3V ---------------|                      |
                    |    ESP32-S2-mini     |
GPIO5 --------------|                      |
GPIO7 --------------|                      |
GPIO9 --------------|                      |
                    |                      |
                    |                      |
                    |                      |
GND ----------------|                      |
                    +----------------------+


LDR

3.3V ---[ LDR ]---+--- GPIO9 (ADC)
                  |
              [ 10kΩ ]
                  |
                 GND



Potentiometer

+-------+
|       |--- 3.3V
|   O   |--- GPIO 7
|       |--- GND
+-------+


WHITE LED

GPIO5 ───[220Ω]───|>|────────────── GND
                  LED

```

## Result

![Result](./result.gif)

If GIF preview is not displayed in your viewer, open it directly: [result.gif](./result.gif)

