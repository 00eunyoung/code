//우노3
#include <SPI.h>//SPI 라이브러리
#include <SoftwareSerial.h>//UART 라이브러리
#include <LiquidCrystal_I2C.h>//I2C LCD 라이브러리

LiquidCrystal_I2C lcd(0x3F, 20, 4);

SoftwareSerial mySerial(2, 3);//UART 우노 1,3통신(핀번호)

byte d=0;

volatile byte command = 0;//SPI 통신 command
volatile byte data = 0;//SPI 통신에서 값

int val = 0;
float cur = 0;
//byte degree[8] = {B00110,B01001,B01001,B00110,B00000,B00000,B00000,B00000};
//byte fan_off[8] = {B00100,B00100,B00100,B11111,B00100,B00100,B00100,B00000};
//byte fan_on[8] = {B00100,B10101,B01110,B11111,B01110,B10101,B00100,B00000};


const int pinTrig1 = 8;
const int pinEcho1 = 9;
const int pinTrig2 = 7;
const int pinEcho2 = 6;
const int pinTrig3 = 5;
const int pinEcho3 = 4;

int rangeMax = 200;
int rangeMin = 0;
long T1,L1,T2,L2,T3,L3;
long TM;
long m3,m4,m5;

int m1, m2, a=0, b=0, c=0;

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
//lcd.createChar(0, degree);
//lcd.createChar(1, fan_off);
//lcd.createChar(2, fan_on);
  
  //lcd.setCursor(0, 0); lcd.print("Impassable");
  //lcd.setCursor(0, 1); lcd.print("Normal");
  //lcd.setCursor(0, 2); lcd.print("Hill");
  lcd.setCursor(0, 3); lcd.print("Weight:"); // 로드셀만 추가
  
  
  pinMode(pinTrig1, OUTPUT);
  pinMode(pinEcho1, INPUT);
  pinMode(pinTrig2, OUTPUT);
  pinMode(pinEcho2, INPUT);
  pinMode(pinTrig3, OUTPUT);
  pinMode(pinEcho3, INPUT);
  
  pinMode(MISO, OUTPUT); //SPI 통신
  SPCR |= _BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR |= _BV(SPIE);

}

ISR(SPI_STC_vect) {
  byte c = SPDR;
  switch (command) {
    case 0:
      command = c;
      SPDR = 0;
      break;
    case 's':
      SPDR = data;
      break;
  }
}

void loop() {
  
  digitalWrite(pinTrig1, LOW); delayMicroseconds(2); //초음파 1 입력
  digitalWrite(pinTrig1, HIGH); delayMicroseconds(10);
  digitalWrite(pinTrig1, LOW);
  T1 = pulseIn(pinEcho1, HIGH);
  L1 = T1/58.82;

  if(a>=1){
    if(m3-L1<=5){
      Serial.println("초음파 1은 현재 정체구간입니다.");
      lcd.setCursor(0, 0); lcd.print("Track 1: ");
      lcd.setCursor(9, 0); lcd.print("Heavy");
    }else if(5<m3-L1<=50){
      Serial.println("초음파 1은 정상구간입니다.");
      lcd.setCursor(0, 0); lcd.print("Track 1: ");
      lcd.setCursor(9, 0); lcd.print("Normal");
    }else{
      Serial.println("초음파 1은 원활한 구간입니다.");
      lcd.setCursor(0, 0); lcd.print("Track 1: ");
      lcd.setCursor(9, 0); lcd.print("smooth");
    }
  }
  m3 = L1; 
  a=1;
  

  digitalWrite(pinTrig2, LOW); delayMicroseconds(2);  //초음파 2 입력
  digitalWrite(pinTrig2, HIGH); delayMicroseconds(10);
  digitalWrite(pinTrig2, LOW);
  T2 = pulseIn(pinEcho2, HIGH);
  L2 = T2/58.82;
  
  if (L2 >= rangeMax || L2 <= rangeMin) Serial.println("-1");
  else{
    data=(byte)L2;//SPI통신을 통해 우노2에게 값을 전달 
    if (digitalRead(SS) == HIGH)
      command = 0;
  }

  if(b>=1){
    if(m4-L2<=5){
      Serial.println("초음파 2는 현재 정체구간입니다.");
      lcd.setCursor(0, 1); lcd.print("Track 2: ");
      lcd.setCursor(9, 1); lcd.print("Heavy");
    }else if(5<m4-L2<=50){
      Serial.println("초음파 2는 정상구간입니다.");
      lcd.setCursor(0, 1); lcd.print("Track 2: ");
      lcd.setCursor(9, 1); lcd.print("Normal");
    }else{
      Serial.println("초음파 2는 원활한 구간입니다.");
      lcd.setCursor(0, 1); lcd.print("Track 2: "); 
      lcd.setCursor(9, 1); lcd.print("smooth"); 
    }
  }
  m4 = L2;
  b=1;


  digitalWrite(pinTrig3, LOW); delayMicroseconds(2);//초음파 2 입력
  digitalWrite(pinTrig3, HIGH); delayMicroseconds(10);
  digitalWrite(pinTrig3, LOW);
  T3 = pulseIn(pinEcho3, HIGH);
  L3 = T3/58.82;

  if(c>=1){
    if(m5-L3<=5){
      Serial.println("초음파 3는 현재 정체구간입니다.");
      lcd.setCursor(0, 2); lcd.print("Track 3: ");
      lcd.setCursor(9, 2); lcd.print("Heavy");
    }else if(5<m5-L3<=50){
      Serial.println("초음파 3은 정상구간입니다.");
      lcd.setCursor(0, 2); lcd.print("Track 3: ");
      lcd.setCursor(9, 2); lcd.print("Normal");
    }else{
      Serial.println("초음파 3은 원활한 구간입니다.");
      lcd.setCursor(0, 2); lcd.print("Track 3: ");
      lcd.setCursor(9, 2); lcd.print("smooth");
    }
  }
  m5 = L3;
  c=1;


  if(mySerial.available()) {   //UART통신, d라는 변수를 통해 우노1에서 로드셀 값을 받아야함
    d = mySerial.read();
    lcd.setCursor(0,3); lcd.print("weight :");

     if(d == (byte)'a'){
        lcd.setCursor(9,3);
        lcd.print("Limit");
     }else if(d == (byte)'b'){
        lcd.setCursor(9,3);
        lcd.print("PASS");
     }else{
        lcd.setCursor(9,3);
        lcd.print("Waiting");
     }
      
    Serial.write((byte)d);
    Serial.println();
   }
   
   delay(600);
   lcd.setCursor(9, 0);
   lcd.print("           ");
   lcd.setCursor(9, 1);
   lcd.print("           ");
   lcd.setCursor(9, 2);
   lcd.print("           ");
   lcd.setCursor(9, 3);
   lcd.print("           ");
  
}
