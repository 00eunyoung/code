const int red_pwm = 11;
const int green_pwm = 10;
const int yellow_pwm = 9;
unsigned long l3, l4;
unsigned long interval = 40;
int fDir = 0;
int fade = 0;
int i=0;

void setup() {
  l3 = 0;
}

void loop() {
  l4 = millis();
  if (l4 - l3 >= interval) {
    l3 = l4;
    if (!fDir) {
      fade += 5;
      if (fade >= 255) {
        fade = 255; fDir = 1;
       }
      } else {
        fade -= 5;
        if (fade <= 0) {
          fade = 0; fDir = 0;
          i= (i+1)%4;}
      }
      if(i==0){
        analogWrite(green_pwm, 0);
        analogWrite(yellow_pwm, 0);
        analogWrite(red_pwm, fade);
    }else if(i==1){
      analogWrite(green_pwm, fade);
      analogWrite(red_pwm, 0);
      analogWrite(yellow_pwm, 0);
    }else if(i==2){
      analogWrite(yellow_pwm, fade);
      analogWrite(red_pwm, 0);
      analogWrite(green_pwm, 0);
    }else if(i==3){
      analogWrite(green_pwm, fade);
      analogWrite(red_pwm, 0);
      analogWrite(yellow_pwm, 0);
    }else{
      i=0;
    }
 }}
