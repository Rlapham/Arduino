#define pot1 A5
//#define pot2 A9
//#define pot3 A10
//#define pot4 A11
#define servoPin2 6
//#define servoPin3 7
//#define servoPin4 8
//#define servoPin5 9

#include <Servo.h> 
Servo servo2;
//Servo servo3;
//Servo servo4;
//Servo servo5;

///////
void setup() {
  Serial.begin(9600);
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
  ///servo 1 
  int potval1 = analogRead(pot1);
  int angle1 = map(potval1, 0, 1023, 180, 90); 
  

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
//  servo2.write(180); 
//  delay(50);
//    servo2.write(90); 
//    delay(500); 
//  servo3.write(angle2); 
//  servo4.write(angle3); 
//  servo5.write(angle4); 

}
