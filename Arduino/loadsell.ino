//우노 1
#include "HX711.h" //HX711로드셀 엠프 관련함수 호출
#include <IRremote.h>
#include <Wire.h>//I2C 라이브러리
#include <Servo.h> //서보모터 라이브러리
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);//UART 우노 1,3통신(핀번호)
byte c=0;

#define sv 8
#define calibration_factor -7050.0 // 로드셀 스케일 값 선언
#define DOUT  7 //엠프 데이터 아웃 핀 넘버 선언
#define CLK  6  //엠프 클락 핀 넘버 
HX711 scale(DOUT, CLK); //엠프 핀 선언 

byte data, num=0;

IRrecv irrecv(A3);
decode_results results;

const int pinServo = 5;
Servo servo;

// duagh
Servo servo2;
const int pinRain = 12;
const int pinRainAnl = A0;
const int pin = 10;
const int pinServo2 = 9; // 살포기 서보모터
const int pinRe = 11;

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);  // 시리얼 통신 개방
  servo.attach(pinServo);   // -------> 따로 해줘야할
  Wire.begin(sv);
  Wire.onRequest(requestEvent);
  Serial.println("HX711 scale TEST");  
  scale.set_scale(calibration_factor);  //스케일 지정 
  scale.tare();  //스케일 설정
  irrecv.enableIRIn();
  Serial.println("Readings:");

  //duaghk
  servo2.attach(pinServo2);
  pinMode(pinRain, OUTPUT);
  pinMode(pin, OUTPUT);
  pinMode(pinServo2, OUTPUT);
  pinMode(pinRe, OUTPUT);

}

void loop() {

  Serial.print(scale.get_units(), 1);  //로드셀값 출력 
 

  if( scale.get_units() >= 0.0){
    if(scale.get_units()>15){
    data= (byte)scale.get_units();
    //delay(500);
    mySerial.write((byte)'a');
  }else if(0<scale.get_units()<=15){
    data= (byte)scale.get_units();
    //delay(500);
    mySerial.write((byte)'b');
  }else{
    data= (byte)'0';
    //delay(500);
    mySerial.write((byte)'c');
  }
  }
 
  //mySerial.write(num);
  
  //mySerial.print(data);
  
  if(irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value == 0xFD8877) { //2번 누르면 작동합니다
      //서브모터 돌려주는 코드 
      servo.write(90);
      delay(3000); 
      servo.write(0);
    }
    irrecv.resume();
  }  
  //servo.write(0);

  Serial.println(analogRead(pinRainAnl));
  Serial.println(digitalRead(pinRain));

  if(analogRead(pinRainAnl) > 400) {
    servo2.attach(pinServo2);
    Serial.println("No Rain Detected"); 
    digitalWrite(pinRe, HIGH);
    servo2.write(0);
    delay(1000);
    digitalWrite(pinRe, LOW);
    digitalWrite(pin, HIGH);
    Serial.println("Move 45 and Start");
    delay(1000);
    digitalWrite(pin, LOW);
    servo2.detach();

  }
  else {
    servo2.attach(pinServo2);
    Serial.println("Rain Detected");
    digitalWrite(pinRe, HIGH);
    servo2.write(180);
    delay(1000);
    digitalWrite(pin, HIGH);
    digitalWrite(pinRe, LOW);
    Serial.println("Move 135 and Start");
    delay(1000);
    digitalWrite(pin, LOW);
    servo2.detach();
  }
  
  Serial.println(); 
  
}

void requestEvent() {
  Wire.write(data);
}
