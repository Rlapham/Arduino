#include <NewPing.h>

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
const int FSR = A3;
int z = 0 ;

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
  int pressure = analogRead(FSR);
  int dist2 = distance2();
  int dist1 = distance1();
  //Serial.println(dist1);
  x = random()%2;
  Serial.println(x);
//  int pp = sonar1.ping_median(10);
//  Serial.print(pp);
  if (x == 1) {
    while (x == 1) {
     if (pressure>0){
     Serial.println(pressure);
      }
    }
    Serial.print("z = ");
    Serial.println(z);
    if (z>0) {
      RightLed();
      Serial.println("hit!");
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
    else {GreenLed();} 
    y = 0 ;
    z = 0;
  }
//  else if (x == 0) {
//   LeftLed();
//   Serial.println(sonar2.ping_median(20));
//   for (int i = 0; i < 11; i++ ){
//     if(sonar2.check_timer()){
//      y += 1;
//     }
//    }
//   if (y > 0) {
//     Serial.print(y);
//     Serial.print(",");
//     Serial.println("Right!");  
//     RedLed();}  
//     else {GreenLed();} 
//   y = 0 ; 
//  }
}
