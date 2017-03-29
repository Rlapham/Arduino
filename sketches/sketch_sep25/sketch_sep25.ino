void setup() {
 pinMode(4, INPUT);
 pinMode(13, OUTPUT);
}
 
void loop() {
//digitalWrite(13, LOW);
//delay(1000);
//digitalWrite(13,HIGH);
//delay(1000); 

  
if (digitalRead(4) == 1) {
   digitalWrite(13, HIGH);
}
  else {
   digitalWrite(13, LOW);
 }  
}


