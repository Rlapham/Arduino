#define pot A0
//#define servoPin 9
//#define speaker 6
//
//#include <Servo.h> 
//Servo servo;


///////
void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
//  pinMode(9, OUTPUT); 
//  servo.attach(servoPin);
}

void loop() {
  int val = analogRead(pot);
  Serial.println(val);
//  int angle = map(val, 0, 1023, 0, 180); 
//  servo.write(angle); 
//  int pitch = map(val, 0, 1023, 400, 2000); 
//  tone(speaker, pitch); 
  
}
