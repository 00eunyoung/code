const int pinLEDR = 9;
const int pinLEDG = 10;
const int pinLEDB = 11;
byte c;
void setup() {
Serial.begin(9600);
  pinMode(pinLEDR, OUTPUT);
  pinMode(pinLEDG, OUTPUT);
  pinMode(pinLEDB, OUTPUT);
}
void loop() {
  if (Serial.available()) {
    c = Serial.read();

    if(digitalRead(pinLEDR)==HIGH){
      if (c == 'r') {
        digitalWrite(pinLEDR, LOW);
        Serial.write(c);
        Serial.println();
      }
    }else{
      if (c == 'r') {
      digitalWrite(pinLEDR, HIGH);
      Serial.write(c);
      Serial.println();
      }
    }
    
    if(digitalRead(pinLEDG)==HIGH){
      if (c == 'g') {
        digitalWrite(pinLEDG, LOW);
        Serial.write(c);
        Serial.println();
      }
    }else{
      if (c == 'g') {
      digitalWrite(pinLEDG, HIGH);
      Serial.write(c);
      Serial.println();
      }
    }
    if(digitalRead(pinLEDB)==HIGH){
      if (c == 'b') {
        digitalWrite(pinLEDB, LOW);
        Serial.write(c);
        Serial.println();
      }
    }else{
      if (c == 'b') {
      digitalWrite(pinLEDB, HIGH);
      Serial.write(c);
      Serial.println();
      }
    }
   }
}
