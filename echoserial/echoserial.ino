void setup() {
  Serial.begin(9600); 
  
}

void loop() {
//  echoSerial(); 
  checkSerialInput();
  delay(20); 
}

void echoSerial(){
//  while(Serial.available() > 0){
//    Serial.write(Serial.read());  
//  }
//  if (Serial.available() > 0) {
//    String inComing = Serial.readStringUntil('\n'); 
//    Serial.print("Arduino got string: "); 
//    Serial.println(inComing); 
//  }
  }

void checkSerialInput(){
  if (Serial.available() >0){
    String inComing = Serial.readStringUntil('\n'); 
//    inComing.toUpperCase();
    if (inComing.charAt(0) == 'L'){    // || inComing.charAt(0) == 'l'
      Serial.println("L"); 
      String data = inComing.substring(2, 99);
      Serial.print("this is the light data: ");
      Serial.println(data); 
      int commaPosition = data.indexOf(",");  
      String red = data.substring(0, commaPosition); 
      String green = data.substring(commaPosition + 1, 99); 
      Serial.print("Red data is: "); 
      Serial.println(red); 
      Serial.print("Green data is: "); 
      Serial.println(green); 
      ///
      // analogWrite(redLED, red.toInt()); // converts string to int, so led can red it // 

    } else if (inComing.charAt(0) == 'T'){ 
      Serial.println("T"); 
    } else {
      Serial.println("nope");  
    }
  }
}
   
  

