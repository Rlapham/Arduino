#include <Adafruit_NeoPixel.h>
#include <Servo.h> 
#ifdef __AVR__
#include <avr/power.h>
#endif

#define BRIGHTNESS 10
#define NUMPIXELS 60
//neo pins
#define PIN2 2
#define PIN3 3
#define PIN4 4
//#define PIN5 8

///servo
#define pot1 A5
//#define pot2 A9
//#define pot3 A10
//#define pot4 A11
#define servoPin2 6
//#define servoPin3 7
//#define servoPin4 8
//#define servoPin5 9

Servo servo2;
//Servo servo3;
//Servo servo4;
//Servo servo5;


//bright1
int BPoten1 = A0;
int Bstore1 = 0;
int Bri1;  

//color1
int CPoten1 = A1;
int Cstore1 = 0;
int Col1;  

//bright2
int BPoten2 = A2;
int Bstore2 = 0;
int Bri2;  

//color2
int CPoten2 = A3;
int Cstore2 = 0;
int Col2;  

//bright3
int BPoten3 = A4;
int Bstore3 = 0;
int Bri3;  

//color3
int CPoten3 = A5;
int Cstore3 = 0;
int Col3;

//bright4
int BPoten4 = A6;
int Bstore4 = 0;
int Bri4;  

//color4
int CPoten4 = A7;
int Cstore4 = 0;
int Col4;    



// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(72, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(72, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(72, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(72, PIN5, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  //1
  Bstore1 = analogRead(BPoten1);
  Bri1 = map(Bstore1, 0, 1023, 0, 255);
  Cstore1 = analogRead(CPoten1);
  Col1 = map(Cstore1, 0, 1023, 0, 255);
  strip1.begin();
  strip1.show(); // Initialize all pixels to 'off'

  //2
  Bstore2 = analogRead(BPoten2);
  Bri2 = map(Bstore2, 0, 1023, 0, 255);
  Cstore2 = analogRead(CPoten2);
  Col2 = map(Cstore2, 0, 1023, 0, 255);
  strip2.begin();
  strip2.show(); // Initialize all pixels to 'off'

  //3
  Bstore3 = analogRead(BPoten3);
  Bri3 = map(Bstore3, 0, 1023, 0, 255);
  Cstore3 = analogRead(CPoten3);
  Col3 = map(Cstore3, 0, 1023, 0, 255);
  strip3.begin();
  strip3.show(); // Initialize all pixels to 'off'

  //4
  Bstore4 = analogRead(BPoten4);
  Bri4 = map(Bstore4, 0, 1023, 0, 255);
  Cstore4 = analogRead(CPoten4);
  Col4 = map(Cstore4, 0, 1023, 0, 255);
  strip4.begin();
  strip4.show(); // Initialize all pixels to 'off'


  //NEO OUTPUT
  pinMode(PIN2, OUTPUT);
  pinMode(PIN3, OUTPUT);
  pinMode(PIN4, OUTPUT);
  pinMode(PIN5, OUTPUT);
  
  //1
  pinMode(BPoten1, INPUT); 
  pinMode(CPoten1, INPUT); 
  
  //2
  pinMode(BPoten2, INPUT); 
  pinMode(CPoten2, INPUT); 

  //3
  pinMode(BPoten3, INPUT); 
  pinMode(CPoten3, INPUT); 
  
  //4
  pinMode(BPoten4, INPUT); 
  pinMode(CPoten4, INPUT); 

  ///servo 
  pinMode(pot1, INPUT);
//  pinMode(pot2, INPUT);
//  pinMode(pot3, INPUT);
//  pinMode(pot4, INPUT);
 
  pinMode(6, OUTPUT); 
//  pinMode(7, OUTPUT); 
//  pinMode(8, OUTPUT); 
//  pinMode(9, OUTPUT);

  servo2.attach(servoPin2);
//  servo3.attach(servoPin3);
//  servo4.attach(servoPin4);
//  servo5.attach(servoPin5);

}

void loop() {

  //1
  Bstore1 = analogRead(BPoten1);
  Bri1 = map(Bstore1, 0, 1023, 0, 255);
  Cstore1 = analogRead(CPoten1);
  Col1 = map(Cstore1, 0, 1023, 0, 255);

  //2
  Bstore2 = analogRead(BPoten2);
  Bri2 = map(Bstore2, 0, 1023, 0, 255);
  Cstore2 = analogRead(CPoten2);
  Col2 = map(Cstore2, 0, 1023, 0, 255);

  //3
  Bstore3 = analogRead(BPoten3);
  Bri3 = map(Bstore3, 0, 1023, 0, 255);
  Cstore3 = analogRead(CPoten3);
  Col3 = map(Cstore3, 0, 1023, 0, 255);

  //4
  Bstore4 = analogRead(BPoten4);
  Bri4 = map(Bstore4, 0, 1023, 0, 255);
  Cstore4 = analogRead(CPoten4);
  Col4 = map(Cstore4, 0, 1023, 0, 255);
  
//run 

  //1
  Color1();
  Bright1();  

  //2
  Color2();
  Bright2();  

  //3
  Color3();
  Bright3();  

  //4
  Color4();
  Bright4();  

  ///servo 1 
  int potval1 = analogRead(pot1);
  int angle1 = map(potval1, 1008, 1023, 180, 90); 

//  ///servo2
//  int potval2 = analogRead(pot2);
//  int angle2 = map(potval2, 0, 1023, 180, 90); 
//
//  ///servo3
//  int potval3 = analogRead(pot3);
//  int angle3 = map(potval3, 0, 1023, 180, 90); 
//
//  ///servo4
//  int potval4 = analogRead(pot4);
//  int angle4 = map(potval4, 0, 1023, 180, 90); 

  
  servo2.write(angle1); 
  Serial.println(CPoten1);
  Serial.println(BPoten1);
//  servo3.write(angle2); 
//  servo4.write(angle3); 
//  servo5.write(angle4); 
}

  



  
////  choosing pixel/color
void Color1() {
  uint16_t i;
    for(i=0; i < 72; i++) {
      strip1.setPixelColor(i, Wheel1(Col1));
      strip1.show();
          }  
}


////// setting brightness 
void Bright1(){
  strip1.setBrightness(Bri1);
}

////  choosing pixel/color
void Color2() {
  uint16_t i;
    for(i=0; i < 72; i++) {
      strip2.setPixelColor(i, Wheel2(Col2));
      strip2.show();
          }  
}


////// setting brightness 
void Bright2(){
  strip2.setBrightness(Bri2);
}

////  choosing pixel/color
void Color3() {
  uint16_t i;
    for(i=0; i < 72; i++) {
      strip3.setPixelColor(i, Wheel3(Col3));
      strip3.show();
          }  
}


////// setting brightness 
void Bright3(){
  strip3.setBrightness(Bri3);
}


////  choosing pixel/color
void Color4() {
  uint16_t i;
    for(i=0; i < 72; i++) {
      strip4.setPixelColor(i, Wheel4(Col4));
      strip4.show();
          }  
}


////// setting brightness 
void Bright4(){
  strip4.setBrightness(Bri4);
}


/////OLD CODE 

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
//void rainbow(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=0; j<256; j++) {
//    for(i=0; i<strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel((i+j) & 255));
//    }
//    strip.show();
//    delay(wait);
//  }
//}
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


///Wheel 1
uint32_t Wheel1(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}  

///Wheel 2
uint32_t Wheel2(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip2.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip2.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip2.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


///Wheel 3
uint32_t Wheel3(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip3.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip3.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip3.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}  

///Wheel 4
uint32_t Wheel4(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip4.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip4.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip4.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}  
