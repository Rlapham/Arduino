int store; 

void setup() {
  // put your setup code here, to run once:
  pinMode(A1, INPUT);
  pinMode(A0, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  store == digitalRead(A1); 
  digitalWrite(A0, store); 
}
