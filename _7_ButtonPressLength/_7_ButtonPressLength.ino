// This program will setup the board attached to the BlinkyTape and display one 
// color all across the LEDs. When you push the button briefly it will change 
// to a new color and wait for you to push the button again. If you hold 
// the button down for 1 second it will turn off the LEDs by setting 
// the brightness to zero.

// This will show you how you can use the button
// How to trigger an action after holding the button for a given length of time

#include <FastLED.h>  // The FastLED libraries which talk to the LEDs

#define BUTTON_PIN 10 // The pin on the board to which the button is connected
#define PIN_SIGNAL 13 // The pin on the board to which the lights are connected
#define LED_COUNT 60 // BlinkyTape has 60 LEDs!

struct CRGB leds[LED_COUNT]; // this struct contains 60 CRGB one for each LED
                            // FAST LED uses this to set the colors

int colorID = 1; // is an ID we're going to use to pick what color to show. 
                 // IDs are nice because you can do math on them, like 
                 // increment them by one colorID++

uint8_t lastButtonState = 1; // This will track what the state of the button 
                             // was when we last saw it. Our button is LOW or 0 
                             // for pressed and HIGH or 1 for not pressed. We'll 
                             // start with saying the button was NOT pressed.

int longPressLength = 10; // 10 will equal one second when we're done 
                          // looping with a delay of 100 milliseconds
                          // Remember: 10 * 100 = 1000 milliseconds or 1 seconds


// Everything in setup() is run 1 time before loop() runs
void setup(){  
  LEDS.addLeds<WS2812B, PIN_SIGNAL, GRB>(leds, LED_COUNT); // BlinkyBoard Config
  LEDS.showColor(CRGB(0, 0, 0)); // OFF
                                 // Start with all the lights off
  LEDS.setBrightness(40); // Mid Level Brightness
  pinMode(BUTTON_PIN, INPUT_PULLUP); // The mode of pin for the button
}

// This is a function. Notice it is outside the Setup or the loop functions.
// We can call this inside those functions.
// This is the function that increments the colorID and changes the color
void changeColor(){
  if (colorID < 3){  // This part increments the colorID
    colorID++;
    } else {
      colorID = 1;
    }
  switch (colorID){
    case 1:
        // Red
      for( int k=0; k<LED_COUNT; k++) {
        leds[k] = CRGB( 255, 0, 0);
        }
      break;
    case 2:
      // Blue
      for( int k=0; k<LED_COUNT; k++) {
        leds[k] = CRGB( 0, 0, 25);
        }
      break;
    case 3:
      // Green
      for( int k=0; k<LED_COUNT; k++) {
        leds[k] = CRGB( 0, 255, 0);
        }
      break;
    }
  LEDS.show(); // Send the current color to the BlinkyTape
  }


// loop() runs continuously as long as power is supplied.
// This where we make the BlinkyTape do things, where we can call other 
// functions, wait for button presses, etc.

void loop() {
// Our LEDs will be OFF when we start. When we push the button, 
// they will change to the next color.

    // Get the state of the button and  store that in buttonState
  uint8_t buttonState = digitalRead(BUTTON_PIN);  
  
  // Here's how this reads in English:
  // If the button state is not the same as the last time we checked and the 
  // button state is pressed (low / 0) Start counting and every 100 
  // milliseconds check again. If that happens 10 times,  (if pressLength) 
  // reaches 10 (1 second), turn off the LEDS. If the button is not pressed 
  // and it was pressed,  change the color and  increment colorID by 1 else 
  // set colorID to 1. In all other cases, just store the current button 
  // state in the last button state
  
  
  // Load this on your BlinkyTape and push the button!    

  if((buttonState != lastButtonState) && (buttonState == 0)) {
    int pressLength=0;
    while (digitalRead(BUTTON_PIN) == LOW && pressLength < 10)
      {
        delay(100);
        pressLength++;
      }
      if (pressLength < 10) {
        changeColor(); 
      } else {
        LEDS.showColor(CRGB(0, 0, 0)); // Lights OFF
        lastButtonState = buttonState;
      }
  } else {
  lastButtonState = buttonState;
  }
}
