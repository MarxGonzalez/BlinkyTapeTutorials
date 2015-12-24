// This program will setup the board attached to the BlinkyTape and display one 
// color all across the LEDs

#include <FastLED.h>  // This is how we include the FastLED libraries 
                      // which talk to the LEDs

#define PIN_SIGNAL 13 // The pin on the board to which the lights are connected

#define LED_COUNT 60 // BlinkyTape has 60 LEDs

struct CRGB leds[LED_COUNT]; // this struct contains 60 CRGB one for each 
                            // LEB bulb. FAST LED uses this to set the colors

// Everything in setup() is run 1 time before loop() runs
void setup()
{  
  LEDS.addLeds<WS2812B, PIN_SIGNAL, GRB>(leds, LED_COUNT); // BlinkyBoard Config
}


// loop() runs continuously as long as power is supplied.
// This where we make the BlinkyTape do things, where we can call other 
// functions, wait for button presses, etc.

void loop() {
  LEDS.showColor(CRGB(255, 0, 0)); 
        // RGB = Red, Green, & Blue. Combining these colors lets you make 
        // other colors. 

  LEDS.setBrightness(40); // Mid Level Brightness
      // BlinkinLabs says at 93 you will be drawing 1Amp. You should be aware 
      // that most USB wall plugs and computer USB ports are rated at .5 amps. 
      // So be careful to check the output rating of your power source.
}
