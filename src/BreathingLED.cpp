#include "BreathingLED.h"

BreathingLED::BreathingLED(int LEDPin) : _LEDPin(LEDPin) {
  pinMode(_LEDPin, OUTPUT);
  analogWrite(_LEDPin, PWMRANGE);
}

void BreathingLED::hold() {
  _currentState = RESTING;
  analogWrite(_LEDPin, PWMRANGE);
}

void BreathingLED::breathe() {
  _currentState = BREATHING;
  analogWrite(_LEDPin, PWMRANGE);
}

void BreathingLED::loop() {
  switch(_currentState) {
    case BREATHING:
      float val = (exp(sin(millis()/INHALE*PI)) - 0.36787944)*PULSE;
      analogWrite(_LEDPin, PWMRANGE-val);
      break;
  }
}
