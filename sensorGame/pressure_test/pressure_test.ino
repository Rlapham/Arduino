int FSR = A3;
unsigned long startTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(3,OUTPUT);
  unsigned long loopTime = 1;

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long loopTime = millis() - startTime;
  if (loopTime<=5000) {
    int val = analogRead(FSR);
    Serial.println(loopTime);
    if (val > 1) {
    Serial.println(val);
    digitalWrite(8,HIGH);
    delay(1000);
    digitalWrite(8,LOW);
    startTime = millis();
    }
  }else {
    Serial.println("MISS!");
    digitalWrite(3,HIGH);
    delay(1000);
    digitalWrite(3,LOW); 
    startTime = millis();
  }
  delay(150);
}
