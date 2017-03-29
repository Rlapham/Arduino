void setup() {
  // tell micro what pin is out
  pinMode(2, OUTPUT); 
}

void loop() {
  digitalWrite(2, HIGH); 
  delay(500); 
  digitalWrite(2, LOW); 
  delay(500); 
 
}
