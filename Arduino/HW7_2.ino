#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 5);
byte c;
byte b;
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
}
void loop() {
  
  if (mySerial.available()) {
  c = mySerial.read();
  Serial.write(c);
  }
  
  if(Serial.available()){
    b= Serial.read();
    mySerial.write(b);
    Serial.write(b);
  }
}
