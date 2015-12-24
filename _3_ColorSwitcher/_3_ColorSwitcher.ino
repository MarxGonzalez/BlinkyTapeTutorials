// This program will setup the board attached to the BlinkyTape and display 
// one color all across the LEDs 5 seconds it will display another color, 
// then another, etc., etc. and loop back to be beginning.
// What is different from 2_ColorSwitcher is that we've moved all the code
// from the loop() into a function which we call from inside loop()

// You should get a feel for the loop from this.
// You should get a feel for better code and that you can call functions you 
// declare outside loop() from within loop()
// You should learn about incrementing a counter and using a Case statement to 
// act on different values

#include <FastLED.h>  // The FastLED libraries which talk to the LEDs

#define PIN_SIGNAL 13 // The pin on the board to which the lights are connected
#define LED_COUNT 60 // BlinkyTape has 60 LEDs!

struct CRGB leds[LED_COUNT]; // this struct contains 60 CRGB one for each LED
                            // FAST LED uses this to set the colors

int changeSpeed = 5000; // This how quickly we're going to change the lights.
                        // Time in milliseconds. 1 second is 1000 milliseconds

int colorID = 1; // is an ID we're going to use to pick what color to show. 
                 // IDs are nice because you can do math on them, like 
                 // increment them by one ex: colorID++

// Everything in setup() is run 1 time before loop() runs
void setup()
{  
  LEDS.addLeds<WS2812B, PIN_SIGNAL, GRB>(leds, LED_COUNT); // BlinkyBoard Config
  LEDS.showColor(CRGB(0, 0, 0)); // OFF
                                 // Start with all the lights off
  LEDS.setBrightness(40); // Mid Level 
                          // Set the brightness level one time while we're 
                          // setting up the whole BlinkyTape
}

// This is a function. Notice it is outside the Setup or the loop functions.
// We  can call this from inside the loop or the setup.
// This function changes the color depending on what the value of colorID is.
void changeColor(){
  switch (colorID){
    case 1:
      LEDS.showColor(CRGB(255, 0, 0)); // Red
      break;
    case 2:
      LEDS.showColor(CRGB(0, 0, 255)); // Blue
      break;
    case 3:
      LEDS.showColor(CRGB(0, 255, 0)); // Green
      break;
    }
  
  }


// loop() runs continuously as long as power is supplied.
// This where we make the BlinkyTape do things, where we can call other 
// functions, wait for button presses, etc.

void loop() {
  changeColor();  // Call ChangeColor which will be RED because colorID is 1

// This next part reads like this in English. 
// If colorID is less than 3 then increment colorID by 1.
// Otherwise (else) set colorID to 1.
// There are 3 values for colorID (1, 2, 3), when colorID is 3, set it to 1
  
  if (colorID < 3){ 
    colorID++;                  // here we're incrementing colorID by 1
    } else {
      colorID = 1;
    }
  delay(changeSpeed);  // This is the same delay we used in other samples
}
