byte fsr1; 
byte fsr2;

void setup() {
  Serial.begin(9600);

}

void loop() {
    fsr1 = analogRead(A0) / 4;
    delay(1);  
    fsr2 = analogRead(A1) /4; 


  
    Serial.print(fsr1);  
    Serial.print(',');
    Serial.println(fsr2);  
    delay(1000); 
}


