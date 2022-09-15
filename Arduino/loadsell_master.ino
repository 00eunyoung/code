//우노2(I2C, SPI 통신)
#include <Wire.h>//I2C 라이브러리
#include <IRremote.h>
#include <Servo.h> //서보모터 라이브러리
#include <SPI.h>//SPI 라이브러리

#define sv 8
const int pinServo = A3;
Servo servo;

int i=0, num=0;

const int pinLED1 = 2;
const int pinLED2 = A1; 
const int pinLED3 = 6; 
const int pinLED4 = 3; 
const int pinLED5 = 8;


long val;

IRrecv irrecv(5);
decode_results results;

void setup() {
  Wire.begin();
  servo.attach(pinServo);
  servo.write(0);
  Serial.begin(9600);
  pinMode(SS, OUTPUT);
  digitalWrite(SS, HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16);

  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
  pinMode(pinLED4, OUTPUT);
  pinMode(pinLED5, OUTPUT);
  irrecv.enableIRIn();
}
  
byte transferAndWait(const byte what){
  byte a = SPI.transfer(what);
  delayMicroseconds(20);
  return a;
}

void loop() {

  byte s, data, L1, L2, L3;
  
  digitalWrite(SS, LOW);//SPI통신
  transferAndWait('s');
  transferAndWait(0);
  s = transferAndWait(0);
  digitalWrite(SS, HIGH);

//I2C통신
  /*Wire.requestFrom(sv, 1);//I2C통신, 값을 받아야함
  while (Wire.available()) {
    byte c = Wire.read();
    Serial.write(c);
    Serial.println();
    servo.write(0);
    if(c==(byte)'a'){
     servo.write(90);
    }else{
      servo.write(0);
    }
    */

    /*switch (c) {//I2C통신을 통해 우노1에서 값을 받아오면 서보모터가 돌아감
      case '0': servo.write(0);
        Serial.println("Go 0 degree"); break;
      case '1': servo.write(45);
        Serial.println("Go 45 degree"); break;
      case '2': servo.write(86);
        Serial.println("Go 90 degree"); break;
      case '3': servo.write(135);
        Serial.println("Go 135 degree"); break;
      case '4': servo.write(180);
        Serial.println("Go 180 degree"); break;
      default: ;
    }*/
   if(irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value == 0xFD28D7) { //2번 누르면 작동합니다
      //서브모터 돌려주는 코드 
      //delay();
      servo.write(0);
      delay(7000); 
      servo.write(94);

    delay(100);
    digitalWrite(pinLED1, HIGH);
    digitalWrite(pinLED2, HIGH);
    digitalWrite(pinLED3, HIGH);
    digitalWrite(pinLED4, HIGH);
    digitalWrite(pinLED5, HIGH);
    delay(5000);
    digitalWrite(pinLED1, LOW);
    digitalWrite(pinLED2, LOW);
    digitalWrite(pinLED3, LOW);
    digitalWrite(pinLED4, LOW);
    digitalWrite(pinLED5, LOW);
    }
    irrecv.resume();  
  }
}
  /*if(s<45 && s>=25){
    digitalWrite(pinLED1, HIGH);
    digitalWrite(pinLED2, HIGH);
    digitalWrite(pinLED3, HIGH);
    digitalWrite(pinLED4, HIGH);
    digitalWrite(pinLED5, HIGH);
  }else if(s<25 || s>=45){
    digitalWrite(pinLED1, LOW);
    digitalWrite(pinLED2, LOW);
    digitalWrite(pinLED3, LOW);
    digitalWrite(pinLED4, LOW);
    digitalWrite(pinLED5, LOW);
  }*/

  /*
  if( 60<=s ){//val 조건문 수정 필요
    digitalWrite(pinLED1, HIGH);
    //analogWrite(pinLED2,0);
    digitalWrite(pinLED2, LOW);
    digitalWrite(pinLED3, LOW);
    digitalWrite(pinLED4, LOW);
    digitalWrite(pinLED5, LOW);
    //delay(100);
  }else if( 57<s && s<60) {
    digitalWrite(pinLED1, LOW);
    digitalWrite(pinLED2, HIGH);
    digitalWrite(pinLED3, LOW);
    digitalWrite(pinLED4, LOW);
    digitalWrite(pinLED5, LOW);
   }else if( 48<s && s<=57) {
    digitalWrite(pinLED1, LOW);
    digitalWrite(pinLED2, LOW);
    //analogWrite(pinLED2,0);
    digitalWrite(pinLED3, HIGH);
    digitalWrite(pinLED4, LOW);
    digitalWrite(pinLED5, LOW);
  }else if( 46<s && s<=48 ){
    digitalWrite(pinLED1, LOW);
    digitalWrite(pinLED2, LOW);
   // analogWrite(pinLED2,0);
    digitalWrite(pinLED3, LOW);
    digitalWrite(pinLED4, HIGH);
    digitalWrite(pinLED5, LOW);
  }else if( s<20 && s<=46){
    digitalWrite(pinLED1, LOW);
    //analogWrite(pinLED2,0);
    digitalWrite(pinLED2, LOW);
    digitalWrite(pinLED3, LOW);
    digitalWrite(pinLED4, LOW);
    digitalWrite(pinLED5, HIGH);
  }else{
    digitalWrite(pinLED1, LOW);
    //analogWrite(pinLED2,0);
    digitalWrite(pinLED2, LOW);
    digitalWrite(pinLED3, LOW);
    digitalWrite(pinLED4, LOW);
    digitalWrite(pinLED5, LOW);
  }*/
