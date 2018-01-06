#include <Adafruit_NeoPixel.h>

#define PIN 13
#define LEDCount 48

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDCount, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(32);
}
void loop() {
  int p=300;
  colorWipe(255, 0, 0, p); // Red
  colorWipe(0, 255, 0, p); // Green
  colorWipe(0, 0, 255, p); // Blue
  colorWipe(255, 255, 255, p); // white
}
void colorWipe(int r, int g, int b, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(r,g,b));
  }
  strip.show();
  delay(wait);  
}
