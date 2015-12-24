// This program will setup the board attached to the BlinkyTape and display one 
// color all across the LEDs. When you push the button briefly it will change 
// to a new color and wait for you to push the button again. If you hold 
// the button down for 1 second it will turn off the LEDs by setting 
// the brightness to zero.


#include <FastLED.h> 
#define BUTTON_PIN 10
#define PIN_SIGNAL 13
#define LED_COUNT 60 
struct CRGB leds[LED_COUNT];
int colorID = 1;   // counter for track current color
uint8_t lastButtonState = 1; // Tracks the state of the button
                             // start with unpressed
int longPressLength = 10; // How long is a long press?
        // 10 will equal one second when we're done looping 
        // every 100 milliseconds
int BRIGHT_LEVEL = 20; // The starting level for the lights

void setup(){  
  LEDS.addLeds<WS2812B, PIN_SIGNAL, GRB>(leds, LED_COUNT); // BlinkyBoard Config
  LEDS.showColor(CRGB(255, 255, 255)); // White
  LEDS.setBrightness(BRIGHT_LEVEL);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // The mode of pin for the button
}

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

void cycleBrightness(){   
  if (BRIGHT_LEVEL<80){    // Don't go over 90, only add 10 if its less than 80
    BRIGHT_LEVEL+=10;
  } else {
    BRIGHT_LEVEL=20;
  }
  LEDS.setBrightness(BRIGHT_LEVEL);   // Set the new brightness level
  }  
  

void loop() {

  uint8_t buttonState = digitalRead(BUTTON_PIN);  
  
  if((buttonState != lastButtonState) && (buttonState == 0)) {
    int pressLength=0;
    while (digitalRead(BUTTON_PIN) == LOW && pressLength < 10)
      {
        delay(100);
        pressLength++;
      }
      if (pressLength < 10) {
      // Short press action
        cycleBrightness();
      } else {
        // Long Press Action
        changeColor();
        if (colorID < 3){
        colorID++;
        } else {
          colorID = 1;
        } 
        lastButtonState = buttonState;
      }
  } else {
  lastButtonState = buttonState;
  }
}
