#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define MaxDistance 50 
#define BRIGHTNESS 10
#define NUMPIXELS 60

//bright1
int BPoten1 = A1;
int Bstore1 = 0;
int Bri1;  

//color1
int CPoten1 = A2;
int Cstore1 = 0;
int Col1;  

//bright2
int BPoten2 = A3;
int Bstore2 = 0;
int Bri2;  

//color2
int CPoten2 = A4;
int Cstore2 = 0;
int Col2;  



// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, A0, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  Bstore1 = analogRead(BPoten1);
  Bri1 = map(Bstore1, 0, 1023, 0, 255);
  Cstore1 = analogRead(CPoten1);
  Col1 = map(Cstore1, 0, 1023, 0, 255);
  Bstore2 = analogRead(BPoten1);
  Bri2 = map(Bstore1, 0, 1023, 0, 255);
  Cstore2 = analogRead(CPoten1);
  Col2 = map(Cstore1, 0, 1023, 0, 255);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'


  //NEO
  pinMode(A0, OUTPUT);
  //bright
  pinMode(A1, INPUT); 
  //color
  pinMode(A2, INPUT); 
  //bright
  pinMode(A3, INPUT); 
  //color
  pinMode(A4, INPUT); 

}

void loop() {

  //1
  //bright pot 
  Bstore1 = analogRead(BPoten1);
  Bri1 = map(Bstore1, 0, 1023, 0, 255);

  //color
  Cstore1 = analogRead(CPoten1);
  Col1 = map(Cstore1, 0, 1023, 0, 255);

  //2
  //bright pot 
  Bstore2 = analogRead(BPoten2);
  Bri2 = map(Bstore2, 0, 1023, 0, 255);

  //color
  Cstore2 = analogRead(CPoten2);
  Col2 = map(Cstore2, 0, 1023, 0, 255);
  
//run 
  //1
  Color1();
  Bright1();  

  //2
  Color2();
//  Bright2();  
}

  



  
////  choosing pixel/color
void Color1() {
  uint16_t i;
    for(i=0; i < 15; i++) {
      strip.setPixelColor(i, Wheel(Col1));
      strip.show();
          }  
}


////// setting brightness 
void Bright1(){
  strip.setBrightness(Bri1);
}

////  choosing pixel/color
void Color2() {
  uint16_t i;
    for(i=15; i < 30; i++) {
      strip.setPixelColor(i, Wheel(Col2));
      strip.show();
          }  
}


////// setting brightness 
void Bright2(){
  strip.setBrightness(Bri2);
}

//
//
//////Alt Switch// 
////void Switch(){
////    uint16_t i;
////    for(i=0; i< Pix; i++) {
////      strip.setPixelColor(i, Wheel(i));
////      strip.show();
////    }  
////}  
//
//
//
//
//
/////////OTHER
//
//void theaterChaseRainbow(uint8_t wait) {
//  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
//    for (int q=0; q < 3; q++) {
//      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
//        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
//      }
//      strip.show();
//
//      delay(wait);
//
//      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
//        strip.setPixelColor(i+q, 0);        //turn every third pixel off
//      }
//    }
//  }
//}
//
//
//// Fill the dots one after the other with a color
//void colorWipe(uint32_t c, uint8_t wait) {
//  for(uint16_t i=0; i<strip.numPixels(); i++) {
//    strip.setPixelColor(i, c);
//    strip.show();
//    delay(wait);
//  }
//}
//
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
//
//// Slightly different, this makes the rainbow equally distributed throughout
//void rainbowCycle(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
//    for(i=0; i< strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
//    }
//    strip.show();
//    delay(wait);
//  }
//}
//
////Theatre-style crawling lights.
//void theaterChase(uint32_t c, uint8_t wait) {
//  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
//    for (int q=0; q < 3; q++) {
//      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
//        strip.setPixelColor(i+q, c);    //turn every third pixel on
//      }
//      strip.show();
//
//      delay(wait);
//
//      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
//        strip.setPixelColor(i+q, 0);        //turn every third pixel off
//      }
//    }
//  }
//}
//
//
//// Input a value 0 to 255 to get a color value.
//// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}  
