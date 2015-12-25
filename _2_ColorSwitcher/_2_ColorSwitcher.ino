// This program will setup the board attached to the BlinkyTape and display 
// one color all across the LEDs. 5 later seconds it will display another 
// color, then another, etc., etc. and loop back to be beginning.

// You should get a feel for the loop from this.
// You will see use a different way to set the colors by setting values
// for every member of the array of LEDs

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
  LEDS.setBrightness(40); // Mid Level 
                          // Notice I only set the brightness level once. 
                          // If you don't change it, it stays the same.

  for( int k=0; k<LED_COUNT; k++) {
    leds[k] = CRGB( 255, 0, 0);
    } // Fill the LEDs with color, RED in this case
      // This creates an array of 60 CRGBs each 255,0,0 so that each LED 
      // will be RED      
  LEDS.show(); // Send all that to the lights

  delay(changeSpeed); // delay (wait) for "changeSpeed" (5000) milliseconds
  
  for( int k=0; k<LED_COUNT; k++) {
  leds[k] = CRGB( 0, 255, 0);
  } // Fill the LEDs with color, GREEN in this case
  LEDS.show(); // Send all that to the lights
  delay(changeSpeed);

  for( int k=0; k<LED_COUNT; k++) {
  leds[k] = CRGB( 0, 0, 255);
  } // Fill the LEDs with color, BLUE in this case
  LEDS.show(); // Send all that to the lights
  delay(changeSpeed);

  for( int k=0; k<LED_COUNT; k++) {
  leds[k] = CRGB( 255, 255, 255);
  } // Fill the LEDs with color, WHITE in this case
  LEDS.show(); // Send all that to the lights
  delay(changeSpeed);

  for( int k=0; k<LED_COUNT; k++) {
  leds[k] = CRGB( 80, 40, 10);
  }   // Fill the LEDs with color
      // On the web it looks like Brown to me. 
      // On the BlinkyTape it looks more like a light rose color.
  LEDS.show(); // Send all that to the lights
  delay(changeSpeed);
  
}
