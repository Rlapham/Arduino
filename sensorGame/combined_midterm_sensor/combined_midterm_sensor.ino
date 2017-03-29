#include <NewPing.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

///NEO 
#define PIN A0
#define NUM_LEDS 60
#define BRIGHTNESS 15

#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define MaxDistance 200
int RedLED = 7;
int GreenLED = 8;
int LeftLED = 9;
int RightLED = 10;
long x ;
int tempCheckTimer; 
int y = 0 ;
int z = 0 ;
long clue = false; 
long start = true; 
int w = 0; 

//fsr
int FSR = A3;
unsigned long startTime = 0;

///NEO
int leftValue; 
int redToGreen; 
int divider; 
int neoMap; 

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


NewPing sonar1(trigPin1, echoPin1, MaxDistance);
NewPing sonar2(trigPin2, echoPin2, MaxDistance);

void echoCheck() { // If ping echo, set distance to array.
  if (sonar1.check_timer()) {
    Serial.println("Yes");}
  if (tempCheckTimer = 0){
    Serial.println("NOO");}
}
  
void setup() {
  ///game
  Serial.begin(9600);
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(LeftLED, OUTPUT);
  pinMode(RightLED, OUTPUT);
  pinMode(FSR,INPUT);
  randomSeed(analogRead(0));

  ///neo
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  ///fsr
  unsigned long loopTime = 1;

}


int distance1() {
  int dist = sonar1.ping_cm();
  if (dist != 0) {
    return dist;
  }
}

int distance2() {
  int dist = sonar2.ping_cm();
  if (dist != 0) {
    return dist;
  }
}

int compare1(int before) {
  int dist = sonar1.ping_cm();
  int diff = abs(dist - before);
  while (diff < 30) {
    int dist = sonar1.ping_cm();
    diff = abs(dist - before);
    Serial.print(before);
    Serial.print(",");
    Serial.print(dist);
    Serial.print(",");
    Serial.println(diff);
    delay(300);
  }
  return 1;
}

int compare2(int before) {
  int dist = sonar2.ping_cm();
  int diff = abs(dist - before);
  while (diff < 30) {
    int dist = sonar2.ping_cm();
    diff = abs(dist - before);
    Serial.print(before);
    Serial.print(",");
    Serial.print(dist);
    Serial.print(",");
    Serial.println(diff);
    delay(500);
  }
  return 1;
}

void RedLed() {
  digitalWrite(RedLED,HIGH);
  delay(1000);
  digitalWrite(RedLED,LOW);
}

void GreenLed() {
  digitalWrite(GreenLED,HIGH);
  delay(1000);
  digitalWrite(GreenLED,LOW);
}

void LeftLed() {
  digitalWrite(LeftLED,HIGH);
  delay(2000);
  digitalWrite(LeftLED,LOW);
}

void RightLed() {
  digitalWrite(RightLED,HIGH);
  delay(2000);
  digitalWrite(RightLED,LOW);

}

void loop() {

if (start == true){
  int pressure = analogRead(FSR);
  int dist2 = distance2();
  int dist1 = distance1();
  x = random()%2;
  Serial.println(x);
  clue = false; 

//
  
  ////1
  
  if (x == 1) {
    pressureSensor(); 
    if (clue == true){
      leftW(255, 33); 
    }
    Serial.println(sonar1.ping_median(20));
    for (int i = 0; i < 11; i++ ){
     if(sonar1.check_timer()){
      y += 1;
     }
    }
   if (y > 5) {
     Serial.print(y);
     Serial.print(",");
     Serial.println("Left!");  
     RedLed();}  
    else {
      GreenLed();
    } 
    y = 0 ;
    delay(2000);
    start = true;  
  }

  ////0 
  
  else if (x == 0) {
    pressureSensor(); 
    if (clue == true){
      rightW(255, 33); 
    }
   Serial.println(sonar2.ping_median(20));
   for (int i = 0; i < 11; i++ ){
     if(sonar2.check_timer()){
      y += 1;
     }
    }
   if (y > 0) {
     Serial.print(y);
     Serial.print(",");
     Serial.println("Right!");  
     
     RedLed();}  
     else {
     GreenLed();
     } 
     y = 0 ; 
     delay(2000);
     start = true; 
}
//if (w >= 3){
//  start = false; 
//  while (start == false){
//    rainbowCycle(.1);
//  }
//} 
} 
}
///GAME FUNCTIONS 

///sensor 
void pressureSensor(){  
//  timer(100, 255); 
  unsigned long loopTime = millis() - startTime;
  if (loopTime<=5000) {
    int val = analogRead(FSR);
    if (val > 1) {
    green(); 
    startTime = millis();
    val = 0; 
    clue = true; 
    start = false; 
    }
  }else {
    Serial.println("MISS!");
    red(); 
    startTime = millis();
    clue = false; 
    start = false; 
  }
  delay(150);
}





//// NEO FUNCTIONS

///NEO
//  red(); 
//  Erase(1000); 
//
//  green(); 
//  Erase(1000); 
//
//  rightW(255, 33); 
//  leftW(255, 33); 
//  timer(100, 255);  
//  strip.clear();
//  delay(500);
//  rainbowCycle(.1);

///END NEO 

void timer(uint8_t wait, uint8_t rate){
  while (clue == false){
  strip.clear(); 
  strip.setBrightness(BRIGHTNESS);
  pulseRG();
  leftValue = 60;
  right(strip.Color(0, 0, 0), rate);
  strip.setBrightness(0);
  delay(wait);
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
}

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
        for(uint16_t r= 30; r > 0; r--) { 
            strip.setPixelColor(r, strip.Color(0, 0, 0));
            strip.setPixelColor(0, strip.Color(0, 0, 0));
            strip.show();
            delay(rate);
      }
}      

void green () {
   for(uint16_t i= 0; i < 60; i++) {
          strip.setPixelColor(i, strip.Color(0, 255, 0, gamma[100]));
        }
        strip.show();
        delay(500); 
}      

void red () {
   for(uint16_t i= 0; i < 60; i++) {
          strip.setPixelColor(i, strip.Color(255, 0, 0, gamma[100]));
        }
        strip.show();
        delay(500); 
}

void Erase(uint16_t rate){ 
  for(uint16_t i= 0; i < 60; i++) {
          strip.setPixelColor(i, strip.Color(0, 0, 0, gamma[0]));
        }
        delay(rate);
}

