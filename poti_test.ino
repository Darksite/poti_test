#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

int sensorPin = A0;
int sensorValue = 0;
int sensorValueMem = 0;
int inByte = 0;         // incoming serial byte
int zaehler = 0;

void setup() {
  strip.begin();
  strip.setBrightness(0);
  strip.show(); // Initialize all pixels to 'off'
}

void loop(){
  sensorValue = analogRead(sensorPin);
      // if we get a valid byte, read analog ins:

  noInterrupts();
  strip.setBrightness(sensorValue/8);
  strip.setPixelColor(2, strip.Color(255,0,0));
  strip.show();
  interrupts();
  
}
