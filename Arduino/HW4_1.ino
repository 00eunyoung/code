const int pinLM35=1;
const int pinLEDR=8;
const int pinLEDG=9;
const int pinLEDB=10;
int val=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinLEDR, OUTPUT);
  pinMode(pinLEDG, OUTPUT);
  pinMode(pinLEDB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val= analogRead(pinLM35);
  float temp=(5.0*val*100)/1024;

  Serial.println(temp);

   digitalWrite(pinLEDB, HIGH);
   digitalWrite(pinLEDG, LOW);
   digitalWrite(pinLEDR, LOW);

  if(temp>28){
    digitalWrite(pinLEDB, LOW);
    digitalWrite(pinLEDG, LOW);
    digitalWrite(pinLEDR, HIGH);
  }
  
}
