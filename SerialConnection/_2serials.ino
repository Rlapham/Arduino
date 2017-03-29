byte fsr1; 
byte fsr2;

void setup() {
  Serial.begin(9600);

}

void loop() {
    fsr1 = analogRead(A0);
    delay(50);  
    fsr2 = analogRead(A1); 
    delay(50); 


  
    Serial.print(fsr1);  
    delay(200);
    Serial.print(',');
    delay(20); 
    Serial.println(fsr2);  
    delay(100); 
}


