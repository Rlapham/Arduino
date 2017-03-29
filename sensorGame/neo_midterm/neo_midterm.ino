#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN A0

#define NUM_LEDS 60

#define BRIGHTNESS 255

int leftValue; 
int redToGreen; 
int divider; 
int neoMap; 
int input;  

//communication 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int gamma[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };



void setup() {
  Serial.begin(9600);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  pinMode(A1, INPUT); 

}

void loop() {

///KEY 
//timer(100, 100); = A1, int input, 100
//red(); = A1, int input, 200
//green();  = A1, int input, 300
//rightW(255, 33);  = A1, int input, 400
//leftW(255, 33);  = A1, int input, 500
//rainbowCycle(.1); = A1, int input, 600

delay(500); 
input = analogRead(A1); 
Serial.println(input); 

///timer 
if (input == 100){
  timer(100, 100);
}

///red
if (input == 200){
  red();
  Erase(1000);
}

///green
if (input == 300){
  green(); 
  Erase(1000);  
}

///right
if (input == 400){
  rightW(255, 33); 
}

///left
if (input == 500){
  leftW(255, 33);  
}

///rainbow
if (input == 600){
  rainbowCycle(.1);
}

}




////////

void timer(uint8_t wait, uint8_t rate){
  strip.clear(); 
  strip.setBrightness(BRIGHTNESS);
  pulseRG();
  leftValue = 60;
  right(strip.Color(0, 0, 0), rate);
  strip.setBrightness(0);
  delay(wait);
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
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


//
void pulseRG() {
  for(int j = 0; j < 256 ; j++){
      for(uint16_t i=60; i > 29; i--) {
          strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels())) & 100));
          int neoMap = map(i, 60, 30, 0, 29); 
          strip.setPixelColor(neoMap, Wheel(((i * 256 / strip.numPixels())) & 100));
        }
        strip.show();
      }
}


// Fill the dots one after the other with a color
void right(uint32_t c, uint8_t wait) {
  for(uint16_t r=0; r< 30; r++) { 
    if (leftValue > 29){ 
      strip.setPixelColor(r, c);
      strip.setPixelColor(leftValue, c);
      strip.show();
      leftValue -= 1; 
      delay(wait);
  }
}
//strip.setPixelColor(30, strip.Color(0,0,0, gamma[0]));
//  strip.clear();
}


////// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}


void greenToRed() {
  uint16_t i, j;
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i= 60; i > 30; i--) {
      if (redToGreen < 31){
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels())) & 100));
      strip.setPixelColor(redToGreen, Wheel(((redToGreen * 256/strip.numPixels())) & 100));
      redToGreen -= 1; 
      strip.show();
      }
    }
  }
}

void rightW (uint16_t bright, uint16_t rate) {
   for(uint16_t i=60; i > 30; i--) {
          strip.setPixelColor(i, strip.Color(bright, bright, bright, gamma[0]));
        }
        strip.show();
        for(uint16_t r= 30; r < 61; r++) { 
            strip.setPixelColor(r, strip.Color(0, 0, 0));
            strip.show();
            delay(rate);
      }
      }

void leftW (uint16_t bright, uint16_t rate) {
   for(uint16_t i=0; i < 30; i++) {
          strip.setPixelColor(i, strip.Color(bright, bright, bright, gamma[0]));
        }
        strip.show();
        for(uint16_t r= 30; r >= 0; r--) { 
            strip.setPixelColor(r, strip.Color(0, 0, 0));
            strip.show();
            delay(rate);
      }}      

void green () {
   for(uint16_t i= 0; i < 60; i++) {
          strip.setPixelColor(i, strip.Color(0, 255, 0, gamma[100]));
        }
        strip.show();
}

void red () {
   for(uint16_t i= 0; i < 60; i++) {
          strip.setPixelColor(i, strip.Color(255, 0, 0, gamma[100]));
        }
        strip.show();
}

void Erase(uint16_t rate){ 
  for(uint16_t i= 0; i < 60; i++) {
          strip.setPixelColor(i, strip.Color(0, 0, 0, gamma[0]));
        }
        delay(rate);
}
/////////
////////


//void greenToRedRight(uint8_t wait) {
//  uint16_t i, j;
//  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
//    for(i=0; i< 30; i++) {
//      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels())) & 100));
//    }
//    strip.show();
//  }
//}
//  for(int j = 255; j >= 0 ; j--){
//      for(uint16_t i=0; i<strip.numPixels(); i++) {
//          strip.setPixelColor(i, strip.Color(0,0,0, gamma[j] ) );
//        }
//        delay(wait);
//        strip.show();
//      }
//}
//
//
//void rainbowFade2White(uint8_t wait, int rainbowLoops, int whiteLoops) {
//  float fadeMax = 100.0;
//  int fadeVal = 0;
//  uint32_t wheelVal;
//  int redVal, greenVal, blueVal;
//
//  for(int k = 0 ; k < rainbowLoops ; k ++){
//    
//    for(int j=0; j<256; j++) { // 5 cycles of all colors on wheel
//
//      for(int i=0; i< strip.numPixels(); i++) {
//
//        wheelVal = Wheel(((i * 256 / strip.numPixels()) + j) & 255);
//
//        redVal = red(wheelVal) * float(fadeVal/fadeMax);
//        greenVal = green(wheelVal) * float(fadeVal/fadeMax);
//        blueVal = blue(wheelVal) * float(fadeVal/fadeMax);
//
//        strip.setPixelColor( i, strip.Color( redVal, greenVal, blueVal ) );
//
//      }
//
//      //First loop, fade in!
//      if(k == 0 && fadeVal < fadeMax-1) {
//          fadeVal++;
//      }
//
//      //Last loop, fade out!
//      else if(k == rainbowLoops - 1 && j > 255 - fadeMax ){
//          fadeVal--;
//      }
//
//        strip.show();
//        delay(wait);
//    }
//  
//  }
//
//
//
//  delay(500);
//
//
//  for(int k = 0 ; k < whiteLoops ; k ++){
//
//    for(int j = 0; j < 256 ; j++){
//
//        for(uint16_t i=0; i < strip.numPixels(); i++) {
//            strip.setPixelColor(i, strip.Color(0,0,0, gamma[j] ) );
//          }
//          strip.show();
//        }
//
//        delay(2000);
//    for(int j = 255; j >= 0 ; j--){
//
//        for(uint16_t i=0; i < strip.numPixels(); i++) {
//            strip.setPixelColor(i, strip.Color(0,0,0, gamma[j] ) );
//          }
//          strip.show();
//        }
//  }
//
//  delay(500);
//
//
//}
//
//void whiteOverRainbow(uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength ) {
//  
//  if(whiteLength >= strip.numPixels()) whiteLength = strip.numPixels() - 1;
//
//  int head = whiteLength - 1;
//  int tail = 0;
//
//  int loops = 3;
//  int loopNum = 0;
//
//  static unsigned long lastTime = 0;
//
//
//  while(true){
//    for(int j=0; j<256; j++) {
//      for(uint16_t i=0; i<strip.numPixels(); i++) {
//        if((i >= tail && i <= head) || (tail > head && i >= tail) || (tail > head && i <= head) ){
//          strip.setPixelColor(i, strip.Color(0,0,0, 255 ) );
//        }
//        else{
//          strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
//        }
//        
//      }
//
//      if(millis() - lastTime > whiteSpeed) {
//        head++;
//        tail++;
//        if(head == strip.numPixels()){
//          loopNum++;
//        }
//        lastTime = millis();
//      }
//
//      if(loopNum == loops) return;
//    
//      head%=strip.numPixels();
//      tail%=strip.numPixels();
//        strip.show();
//        delay(wait);
//    }
//  }
//  
//}
//void fullWhite() {
//  
//    for(uint16_t i=0; i<strip.numPixels(); i++) {
//        strip.setPixelColor(i, strip.Color(0,0,0, 255 ) );
//    }
//      strip.show();
//}
//
//
//// Slightly different, this makes the rainbow equally distributed throughout
//void rainbowCycle(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=0; j<256 * 5; j++) { // 5 cycles of all colors on wheel
//    for(i=0; i< strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
//    }
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
//// Input a value 0 to 255 to get a color value.
//// The colours are a transition r - g - b - back to r.
//uint32_t Wheel(byte WheelPos) {
//  WheelPos = 255 - WheelPos;
//  if(WheelPos < 85) {
//    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3,0);
//  }
//  if(WheelPos < 170) {
//    WheelPos -= 85;
//    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3,0);
//  }
//  WheelPos -= 170;
//  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0,0);
//}
//
//uint8_t red(uint32_t c) {
//  return (c >> 8);
//}
//uint8_t green(uint32_t c) {
//  return (c >> 16);
//}
//uint8_t blue(uint32_t c) {
//  return (c);
//}
//
//
//
//
//
//
//
//  
