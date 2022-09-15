const int led_red = 13;
const int led_green = 12;
const int led_yellow = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_red,OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_yellow,LOW);
  digitalWrite(led_red,HIGH);
  delay(1000);
  
  digitalWrite(led_red,LOW);
  digitalWrite(led_green,HIGH);
  delay(1000);
  
  digitalWrite(led_green,LOW);
  digitalWrite(led_yellow,HIGH);
  delay(1000);
}
