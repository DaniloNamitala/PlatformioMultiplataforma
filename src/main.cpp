#include <Arduino.h>

// exemplo uso ifdef
#ifdef BUILD_ARDUINO
#define LED 13
#elif BUILD_BLUEPILL
#define LED PC13
#endif

// exemplo uso ifdef
#ifdef BUILD_ARDUINO
void config_duino() {
  // essa funcao so vai existir no arduino
}
#elif BUILD_BLUEPILL
void config_stm() {
  // essa funcao so vai existir no stm
}
#endif  

void setup() {
  pinMode(LED, OUTPUT);

  // exemplo uso ifdef
  #ifdef BUILD_ARDUINO
  config_duino();
  #elif BUILD_BLUEPILL
  config_stm();
  #endif
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);

  // exemplo uso ifdef
  #ifdef BUILD_ARDUINO
  analogWrite(A0, 255);
  #elif BUILD_BLUEPILL
  pwmWrite(PA0, 65535);
  #endif
}

