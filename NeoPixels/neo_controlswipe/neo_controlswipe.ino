#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#include <NewPing.h>
#endif

#define PIN 13
#define trigPin 3
#define echoPin 2
#define MaxDistance 50 
#define BRIGHTNESS 10
#define NUMPIXELS 60

NewPing sonar(trigPin, echoPin, MaxDistance); 

//pix
int PPoten = A0;
int Pstore = 0;
int Pix;   

//bright
int BPoten = A1;
int Bstore = 0;
int Bri;  

//color
int CPoten = A2;
int Cstore = 0;
int Col;  

//Ultra
int Dist; 
int DistMap;


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  Pstore = analogRead(PPoten);
  Pix = map(Pstore, 0, 1023, 0, 60);
  Bstore = analogRead(BPoten);
  Bri = map(Bstore, 0, 1023, 0, 255);
  Cstore = analogRead(CPoten);
  Col = map(Cstore, 0, 1023, 0, 255);
  Dist = sonar.ping_in();
  DistMap = map(Dist, 0, 50, 0, 255);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  ///ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(1, INPUT); 


  //pixel
  pinMode(A0, INPUT);
  //bright
  pinMode(A1, INPUT); 
  //color
  pinMode(A2, INPUT); 
  //NEO
  pinMode(13, OUTPUT); 
}

void loop() {
  //pixel pot
  Pstore = analogRead(PPoten);
  Pix = map(Pstore, 0, 1023, 0, 60);

  //bright pot 
  Bstore = analogRead(BPoten);
  Bri = map(Bstore, 0, 1023, 0, 255);

  //color
  Cstore = analogRead(CPoten);
  Col = map(Cstore, 0, 1023, 0, 255);

  //Ultra
  Dist = sonar.ping_in();
  DistMap = map(Dist, 0, 50, 0, 255);
  
  //run 
    Ultra();
    Pixel();
    Bright();  
}

  
  
//  choosing pixel/color
void Pixel() {
  uint16_t i;
    for(i=0; i < Pix; i++) {
      strip.setPixelColor(Pix, Wheel(Col));
      strip.show();
      //    }   
//        for(i=Pix; i > 0; i--) {
//        strip.setPixelColor(i, 0);
//        strip.show();   
//    }
    }
    strip.clear();
}
   

// setting brightness 
void Bright(){
  strip.setBrightness(Bri);
}


void Ultra(){ 
  Serial.print(Dist);
  Serial.println("in"); 
}

////Alt Switch// 
//void Switch(){
//    uint16_t i;
//    for(i=0; i< Pix; i++) {
//      strip.setPixelColor(i, Wheel(i));
//      strip.show();
//    }  
//}  





///////OTHER

void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

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

// Slightly different, this makes the rainbow equally distributed throughout
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

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
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
