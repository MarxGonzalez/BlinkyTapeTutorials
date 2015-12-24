// This program will setup the board attached to the BlinkyTape and display 
// one color all across the LEDs. Pushing the button, will change to a new color

// This will show you how you can use the button

#include <FastLED.h>  // The FastLED libraries which talk to the LEDs

#define BUTTON_PIN 10 // The pin on the board to which the button is connected
#define PIN_SIGNAL 13 // The pin on the board to which the lights are connected
#define LED_COUNT 60 // BlinkyTape has 60 LEDs!

struct CRGB leds[LED_COUNT]; // this struct contains 60 CRGB one for each LED
                            // FAST LED uses this to set the colors

int colorID = 1; // is an ID we're going to use to pick what color to show. 

// Everything in setup() is run 1 time before loop() runs
void setup()
{  
  LEDS.addLeds<WS2812B, PIN_SIGNAL, GRB>(leds, LED_COUNT); // BlinkyBoard config
  LEDS.showColor(CRGB(0, 0, 0)); // OFF
                                 // Start with all the lights off
  LEDS.setBrightness(40); // Mid Level 

  pinMode(BUTTON_PIN, INPUT_PULLUP); // The mode of pin for the button's pin
}

// This is a function. Notice it is outside the Setup or the loop functions
// We can call this inside those functions.
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
// LEDs will be OFF when we start. Push the button & change to the next color

// NOTE: The BlinkyTape button is in a LOW state when it is pushed. 
// Other buttons in the world are HIGH, You need to know that about your button

// Here's how this reads in English:
// Read the status of the pin assigned at BUTTON_PIN. If is is low (pushed), 
// change the color. If the Color id is less than 3 increment colorID by 1 
// else set colorID to 1.
// Load this on your BlinkyTape and push the button!

if (digitalRead(BUTTON_PIN) == LOW){  
  changeColor();
  if (colorID < 3){ 
    colorID++;
    } else {
      colorID = 1;
    }
}

}
