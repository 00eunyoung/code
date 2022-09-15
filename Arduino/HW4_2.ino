const int pinTilt=2;
const int pinLEDR=8;
const int pinLEDG=9;
const int pinLEDB=10;
int val=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinLEDR, OUTPUT);
  pinMode(pinLEDG, OUTPUT);
  pinMode(pinLEDB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val= analogRead(pinTilt);
  Serial.println(val);
 

    digitalWrite(pinLEDB, LOW);
    digitalWrite(pinLEDG, LOW);
    digitalWrite(pinLEDR, LOW);
  if(val==0){
    digitalWrite(pinLEDB, HIGH);
    digitalWrite(pinLEDG, HIGH);
    digitalWrite(pinLEDR, HIGH);
  }

  if(val>1010){
    digitalWrite(pinLEDB, HIGH);
    digitalWrite(pinLEDG, HIGH);
    digitalWrite(pinLEDR, HIGH);
  }
}
