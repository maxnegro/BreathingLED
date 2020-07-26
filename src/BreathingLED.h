#ifndef BreathingLED_h
#define BreathingLED_h

#include <math.h>

// If you want to support Arduino versions older than 1.0 you need to do this if
#if ARDUINO >= 100
// If you just want to support Arduino 1.0 or newer you just need to #include "Arduino.h"
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define INHALE    3000    //Inhalation time in milliseconds.
#define PULSE     PWMRANGE/(M_E-1/M_E)

class BreathingLED {
public:
  BreathingLED(int LEDPin);
  void loop();
  void hold();
  void breathe();

private:
  int _LEDPin;
  unsigned long _sStart = 0;
  enum STATES {
    BREATHING,
    RESTING
  } _currentState = BREATHING;
};

#endif
