byte redLEDpin = 7;
byte switchPin = 2; 
int fsrValue; 

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); 
  pinMode(switchPin, INPUT);
  pinMode(A0, INPUT); //FSR
  Serial.begin(9600); 
  Serial.println("funtions setup finished");
}

void loop() {
  // put your main code here, to run repeatedly:
  fsrValue = analogRead(A0);
  Serial.println(fsrValue); 

  }
