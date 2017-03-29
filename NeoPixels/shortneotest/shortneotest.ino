#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define BRIGHTNESS 255
#define NUMPIXELS 72
 
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(72, A0, NEO_GRB + NEO_KHZ800);

void setup() {
   Serial.begin(9600);
   pinMode(A0, OUTPUT);
   strip1.begin();
   strip1.show(); // Initialize all pixels to 'off'
   strip1.setBrightness(25);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0; i < 72; i++) {
      strip1.setPixelColor(i, 255, 0, 255);
      strip1.show();
      delay(1);
          }  

}
