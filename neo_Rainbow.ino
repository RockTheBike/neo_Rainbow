#include <WS2812.h> // light_ws2812 from github

#define outputPin 7
#define LEDCount 17

WS2812 LED(LEDCount);
cRGB value;

byte intensity = 0;
byte sign = 1;

void setup() {
  LED.setOutput(outputPin); // Digital Pin 7
  LED.setColorOrderRGB();
}

void loop() {
  int p=1000;
  colorWipe(255, 0, 0, p); // Red
  colorWipe(0, 255, 0, p); // Green
  colorWipe(0, 0, 255, p); // Blue
}

void colorWipe(int r, int g, int b, int wait) {
  for(int i=0; i<LEDCount; i++) {
    value.b = b;
    value.g = g;
    value.r = r;
    LED.set_crgb_at(i, value); // Set value at LED found at index 0
  }
  LED.sync(); // Sends the data to the LEDs
  delay(wait);  
}


