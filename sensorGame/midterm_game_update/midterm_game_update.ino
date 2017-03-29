#include <NewPing.h>

#define PIN A0
#define outputPin A1

#define NUM_LEDS 60
#define BRIGHTNESS 15

#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5

///
#define MaxDistance 200

int outport = 12;
int RedLED = 7;
int GreenLED = 8;
int LeftLED = 9;
int RightLED = 10;
long x ;
int tempCheckTimer; 
int y = 0 ;
int z = 0 ;
boolean clue = false; 
boolean way = false; 
boolean step1 = false; 
boolean next = true;
long start = true; 
int w = 0; 

//fsr
int FSR = A3;
unsigned long startTime = 0;




NewPing sonar1(trigPin1, echoPin1, MaxDistance);
NewPing sonar2(trigPin2, echoPin2, MaxDistance);

void echoCheck() { // If ping echo, set distance to array.
  if (sonar1.check_timer()) {
    Serial.println("Yes");}
  if (tempCheckTimer = 0){
    Serial.println("NOO");}
}
  
void setup() {
  Serial.begin(9600);
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(LeftLED, OUTPUT);
  pinMode(RightLED, OUTPUT);
  pinMode(FSR,INPUT);
  randomSeed(analogRead(0));
  unsigned long loopTime = 1;

  ///
  pinMode(outputPin, OUTPUT); 

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
  while (diff < 20) {
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

int pressuretest() {
  unsigned long loopTime = millis() - startTime;
  if (loopTime<=5000) {
    int val = analogRead(FSR);
    Serial.println(loopTime);
    if (val > 1) {
    //analogWrite(outport,HIGH);
    Serial.println(val);
    startTime = millis();
    }
  }else {
    Serial.println("MISS!");
    //analogWrite(outport,HIGH);
    startTime = millis();
  }
  delay(150);
}


void loop() {
  ///outputs
  analogWrite(outputPin, 100); 
  Serial.println(outputPin); 
  
  clue = false;
  way = false;
  next = true;
  unsigned long loopTime = 50;
  int pressure = analogRead(FSR);
  int dist2 = distance2();
  int dist1 = distance1();
  x = random()%2;
  Serial.print("x = ");
  Serial.println(x);
  int pp = sonar1.ping_median(10);

  
  if (x == 1) {
    while (loopTime<=5000 && clue == false) {
    //Serial.print("The clue is ");
    //Serial.print(clue);  
    loopTime = millis() - startTime;
    int val = analogRead(FSR);
    //Serial.print("loop time is ");
    Serial.println(loopTime);
      if (val > 1) {
      Serial.println("HIT!!");
      //analogWrite(outport,HIGH);
      startTime = millis();
      delay(200);
      clue = true;
      }
    }
    if (loopTime > 5000 && clue == false) {
      Serial.println("MISS!");
    }
    delay(100);
    //Serial.print("sonar = ");
    Serial.println(sonar1.ping_median(20));
    
//    for (int i = 0; i < 11; i++ ){
//     if(sonar1.check_timer()){
//      y += 1;
//        }
//      }
    if (sonar1.ping_median() > 0) {
     //Serial.print("need to move");
     //Serial.print(y);
     //Serial.print(",");
     //Serial.println("Wrong Way!");  
     //RedLed();}
     startTime = millis();
     loopTime = 0;
     while (loopTime<=4000 &&  way == false) {
      Serial.print("loopcheck = ");
      Serial.println(loopTime);
      loopTime = millis() - startTime;
      int asdf = sonar2.ping_median(10);
      if (sonar2.ping_median(8) > 0){
        way = true;
        next = false;
        Serial.println("NEXT!");
          } 
        }
     if (loopTime > 4000 && way == false) {
      Serial.println("Wrong Way!");
      next = false;
      }
    }
    if (sonar2.ping_median() > 0 && next == true) {
     //Serial.print(y);
     //Serial.print(",");
     //Serial.println("Wrong Way!");  
     //RedLed();}
     startTime = millis();
     loopTime = 0;
     way = false;
     int before2 = sonar2.ping_cm();
     while (loopTime<=6000 &&  way == false) {
      int distnow2 = sonar2.ping_cm();
      Serial.print("loopcheck = ");
      Serial.println(loopTime);
      loopTime = millis() - startTime;
      int diff = abs(distnow2 - before2);
      Serial.print("The difference is ");
      Serial.println(diff);
      if (diff > 30){
        way = true;
        Serial.println("NEXT!");
          } 
        }
     if (loopTime > 6000 && way == false) {
      Serial.println("Wrong Way!");
      }
    }  
  startTime = millis();
  }

delay(250);
clue = false;
loopTime = 0;
// when go left  


  if (x == 0) {
    while (loopTime<=5000 && clue == false) { 
    loopTime = millis() - startTime;
    int val = analogRead(FSR);
    Serial.print("loop time is111111 ");
    Serial.println(loopTime);
      if (val > 1) {
      Serial.println("HIT!!");
      //analogWrite(outport,HIGH);
      startTime = millis();
      delay(200);
      clue = true;
      }
    }
    if (loopTime > 5000 && clue == false) {
      Serial.println("MISS!");
    }
    delay(100);
    //Serial.print("sonar = ");
    Serial.println(sonar2.ping_median(20));
    
//    for (int i = 0; i < 11; i++ ){
//     if(sonar1.check_timer()){
//      y += 1;
//        }
//      }
    if (sonar2.ping_median(20) > 0) {
     //Serial.print("need to move");
     //Serial.print(y);
     //Serial.print(",");
     //Serial.println("Wrong Way!");  
     //RedLed();}
     startTime = millis();
     loopTime = 0;
     while (loopTime<=4000 &&  way == false) {
      Serial.print("loopcheck = ");
      Serial.println(loopTime);
      loopTime = millis() - startTime;
      int asdf = sonar1.ping_median(10);
      if (sonar1.ping_median(8) > 0){
        way = true;
        next = false;
        Serial.println("NEXT!");
          } 
        }
     if (loopTime > 4000 && way == false) {
      Serial.println("Wrong Way!");
      next = false;
      }
    }

    if (sonar1.ping_median() > 0 && next == true) {
     //Serial.print(y);
     //Serial.print(",");
     //Serial.println("Wrong Way!");  
     //RedLed();}
     startTime = millis();
     loopTime = 0;
     way = false;
     int before1 = sonar1.ping_cm();
     while (loopTime<=6000 &&  way == false) {
      int distnow1 = sonar1.ping_cm();
      Serial.print("loopcheck = ");
      Serial.println(loopTime);
      loopTime = millis() - startTime;
      int diff = abs(distnow1 - before1);
      Serial.print("The difference is ");
      Serial.println(diff);
      if (diff > 30){
        way = true;
        Serial.println("NEXT!");
          } 
        }
     if (loopTime > 6000 && way == false) {
      Serial.println("Wrong Way!");
      }
    }  
  }
  startTime = millis();

  if (sonar1.ping_median() < 2){
  //send rainbow signal
  }
  
  if (sonar2.ping_median() < 2){
  //send rainbow signal
  }



}

