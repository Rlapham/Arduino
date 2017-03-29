#define pot A0
#define servoPin2 2
#define servoPin3 3
#define servoPin4 4
#define servoPin5 5
#define servoPin6 6
#define servoPin7 7
#define servoPin8 8
#define servoPin9 9
#define servoPin10 10

#include <Servo.h> 
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo10;





///////
void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(10, OUTPUT); 
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
  servo6.attach(servoPin6);
  servo7.attach(servoPin7);
  servo8.attach(servoPin8);
  servo9.attach(servoPin9);
  servo10.attach(servoPin10);
}

void loop() {
  int val = analogRead(pot);
  Serial.println(val);
  int angle = map(val, 0, 1023, 180, 90); 
  Serial.print("angle:");
  Serial.println(angle);
//  servo10.write(angle); 
  servo2.write(180); 
  delay(200);
    servo2.write(90);
      delay(50);
          servo2.write(0);
      delay(100);
//  servo3.write(angle); 
//  servo4.write(angle); 
//  servo5.write(angle); 
//  servo6.write(angle); 
//  servo7.write(angle); 
//  servo8.write(angle); 
//  servo9.write(angle); 

}
