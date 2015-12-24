// This program will setup the board attached to the BlinkyTape and display 
// one color all across the LEDs
// When you push the button, it will change to a new color and wait for you 
// to push the button again  before changing to a new color.

// This will show you how you can use the button

#include <FastLED.h>  // The FastLED libraries which talk to the LEDs

#define BUTTON_PIN 10 // The pin on the board to which the button is connected
#define PIN_SIGNAL 13 // The pin on the board to which the lights are connected
#define LED_COUNT 60 // BlinkyTape has 60 LEDs!

struct CRGB leds[LED_COUNT]; // this struct contains 60 CRGB one for each LED
                            // FAST LED uses this to set the colors

int brightLevel = 10; // The starting level for the lights
int colorID = 1; // is an ID we're going to use to pick what color to show.

uint8_t lastButtonState = 1; 
    // This will track what the state of the button was when we last checked it.
    // Our button is LOW or 0 for pressed and HIGH or 1 for not pressed.
    // We'll start with saying the button was NOT pressed.

// Everything in setup() is run 1 time before loop() runs
void setup()
{  
  LEDS.addLeds<WS2812B, PIN_SIGNAL, GRB>(leds, LED_COUNT); // BlinkyBoard Config
  LEDS.setBrightness(brightLevel); // Set initial brightness  level
  LEDS.showColor(CRGB(255, 255, 255)); // start with WHITE Lights
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
    // The mode of pin to which the button is connected
}

void cycleBrightness(){
    if (brightLevel < 80){
      brightLevel += 10;
      LEDS.setBrightness(brightLevel);
      LEDS.show();
    } else {
      brightLevel = 20;
      LEDS.setBrightness(brightLevel);
      LEDS.show();
    }
  }

// loop() runs continuously as long as power is supplied.
// This where we make the BlinkyTape do things, where we can call other 
// functions, wait for button presses, etc.

void loop() {
// Our LEDs will be OFF when we start. Push the button and they change colors.

    // Let's see what the state of the button is and store that in buttonState
  uint8_t buttonState = digitalRead(BUTTON_PIN);  
  
  // Here's how this next part reads in English:
  // If the button state is not the same as the last time we checked and the 
  // button state is pressed (low or 0), change the color and store the current 
  // button state as the last state AND 
  // if the colorID is less than 3 increment colorID by 1 else set colorID to 1. 
  // In all other cases, store the current button state in the last button state
  // and keep going.
  
  // For us humans, this can also be interpreted to mean:
  // If the button state was NOT Pressed or if the ButtonState is the Same as 
  // the last time then store the state again and keep going.
  
  // Load this on your BlinkyTape and push the button!
  // Notice that the flickering is gone and the color changes 
  // are precisely one per button press


  if ((buttonState != lastButtonState) && (buttonState == 0)){
    cycleBrightness();
    lastButtonState = buttonState;
  }
  else {
    lastButtonState = buttonState;
    }
}
