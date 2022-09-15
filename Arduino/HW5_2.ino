const int pinTrig = 2;
const int pinEcho = 4;
int rangeMax = 30;
int rangeMin = 0;
long T, L;
int RED = 9;
int GREEN = 10;
int BLUE = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(RED, OUTPUT); 
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinTrig, LOW); delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH); delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  
  T = pulseIn(pinEcho, HIGH);
  
  L = T/58.82;
  
  if(0<L && L<10){
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    Serial.println(L);
  }else if(10<=L && L<15){
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
    Serial.println(L);
  }else if(15<=L && L<30){
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
    Serial.println(L);
  }
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
    Serial.println(L);
  

}
