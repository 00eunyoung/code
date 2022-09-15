const int red=13;
const int green=12;
const int yellow=8;
unsigned long l1, l2, l3, l4, l5, l6;
unsigned long interval1=2000;
unsigned long interval2=4000;
unsigned long interval3=6000;
int fON1=0;
int fON2=0;
int fON3=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  l1=0;
  l3=0;
  l4=0;
}

void loop() {
  // put your main code here, to run repeatedly:

  l2= millis();
  l5= millis();
  l6= millis();
  if(l2-l1>=interval1){
    l1=l2;

    if(!fON1){
      fON1=HIGH;
    }else{
      fON1=LOW;
    }
    digitalWrite(red,fON1);
  }

  if(l5-l3>=interval2){
    l3=l5;

    if(!fON2){
      fON2=HIGH;
    }else{
      fON2=LOW;
    }
    digitalWrite(green,fON2);
  }

  if(l6-l4>=interval3){
    l4=l6;

    if(!fON3){
      fON3=HIGH;
    }else{
      fON3=LOW;
    }
    digitalWrite(yellow,fON3);
  }
}
