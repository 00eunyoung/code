const int pinButton[8] = {5,6,7,8,9,10,11,12};
const int pinBuzzer = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinButton[0], INPUT);
  pinMode(pinButton[1], INPUT);
  pinMode(pinButton[2], INPUT);
  pinMode(pinButton[3], INPUT);
  pinMode(pinButton[4], INPUT);
  pinMode(pinButton[5], INPUT);
  pinMode(pinButton[6], INPUT);
  pinMode(pinButton[7], INPUT);
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pinButton[0])==HIGH){
    tone(pinBuzzer, 523);
  }else if(digitalRead(pinButton[1])==HIGH){
    tone(pinBuzzer, 494);
  }else if(digitalRead(pinButton[2])==HIGH){
    tone(pinBuzzer, 440);
  }else if(digitalRead(pinButton[3])==HIGH){
    tone(pinBuzzer, 392);
  }else if(digitalRead(pinButton[4])==HIGH){
    tone(pinBuzzer, 349);
  }else if(digitalRead(pinButton[5])==HIGH){
    tone(pinBuzzer, 330);
  }else if(digitalRead(pinButton[6])==HIGH){
    tone(pinBuzzer, 294);
  }else if(digitalRead(pinButton[7])==HIGH){
    tone(pinBuzzer, 262);
  }else{
    noTone(pinBuzzer);
  }
}
