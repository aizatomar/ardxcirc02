/*
  * CIRC-02
  * 8 LED Fun
  * Multiple LEDs
  * http://ardx.org/CIRC02
*/

// LED pin variables
int ledPins[] = {2,3,4,5,6,7,8,9};

void setup() {
  // Set each pin connected to an LED to output mode
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  oneAfterAnother();
  //oneAtATime();
}

void oneAfterAnother() {
  int delayTime = 100;
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
  }
  
  for (int i = 7; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(delayTime);
  }
}

void oneAtATime() {
  int delayTime = 100;
  
  for (int i = 0; i < 8; i++) {
    int onPin = ledPins[i];
    int offPin = ledPins[i-1];
    if (i == 0) {
      offPin = ledPins[7];
    }
    digitalWrite(onPin, HIGH);
    digitalWrite(offPin, LOW);
    delay(delayTime);
  }
}

