const int pinVibM = 3;
byte count = 0;
int RED = 11;
int GREEN = 10;
int BLUE = 9;

void setup() {
  pinMode(pinVibM, INPUT);
  pinMode(RED, OUTPUT); 
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(1, countVib, FALLING);
}

void loop() {
  if (count != 0) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);
    count = 0;
    Serial.println(1);
  } else {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    Serial.println(0);
  }
}
void countVib() {
  count++;
}
