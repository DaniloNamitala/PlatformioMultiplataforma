#include <Arduino.h>

#ifdef BUILD_ARDUINO
#define LED 13
#elif BUILD_BLUEPILL
#define LED PC13
#endif

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);

  #ifdef BUILD_ARDUINO
  analogWrite(A0, 255);
  #elif BUILD_BLUEPILL
  pwmWrite(PA0, 65535);
  #endif

}

