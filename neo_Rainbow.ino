#include <Adafruit_NeoPixel.h>

#define PIN 12
#define LEDCount 120

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDCount, PIN, NEO_GRB + NEO_KHZ800,6); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(128); // set overall brightness to half
}
void loop() {
  int p=1000;
  colorWipe(255, 0, 0, p); // Red
  colorWipe(0, 255, 0, p); // Green
  colorWipe(0, 0, 255, p); // Blue
}
void colorWipe(int r, int g, int b, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(r,g,b));
  }
  strip.show();
  delay(wait);  
}
