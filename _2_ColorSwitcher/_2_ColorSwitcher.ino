// This program will setup the board attached to the BlinkyTape and display 
// one color all across the LEDs. 5 later seconds it will display another 
// color, then another, etc., etc. and loop back to be beginning.

// You should get a feel for the loop from this.

#include <FastLED.h>  // The FastLED libraries which talk to the LEDs

#define PIN_SIGNAL 13 // The pin on the board to which the lights are connected


#define LED_COUNT 60 // BlinkyTape has 60 LEDs!
struct CRGB leds[LED_COUNT]; // this struct contains 60 CRGB one for each LEB 
                            // FAST LED uses this to set the colors

int changeSpeed = 5000; // This how quickly we're going to change the lights.
                            // Arduinos base unit of time is milliseconds. 
                            // 1 second is 1000 milliseconds.


// Everything in setup() is run 1 time before loop() runs
void setup()
{  
  LEDS.addLeds<WS2812B, PIN_SIGNAL, GRB>(leds, LED_COUNT); // BlinkyBoard Config
}


// loop() runs continuously as long as power is supplied.
// This where we make the BlinkyTape do things, where we can call other 
// functions, wait for button presses, etc.

void loop() {
  LEDS.showColor(CRGB(255, 0, 0)); // Red
  LEDS.setBrightness(40); // Mid Level 
                          // Notice I only set the brightness level once. 
                          // If you don't change it, it stays the same.

  delay(changeSpeed); // delay (wait) for "changeSpeed" (5000) milliseconds
  
  LEDS.showColor(CRGB(0, 255, 0)); // Green
  delay(changeSpeed);

  LEDS.showColor(CRGB(0, 0, 255)); // Blue
  delay(changeSpeed);

  LEDS.showColor(CRGB(255, 255, 255)); // White
  delay(changeSpeed);

  LEDS.showColor(CRGB(80, 40, 10)); // I made this up. 
        // On the web it looks like Brown to me. 
        // On the BlinkyTape it looks more like a light rose color.
  delay(changeSpeed);
  
}
