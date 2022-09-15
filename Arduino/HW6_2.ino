#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
float set = 28.0, cur;
const int pinLM35 = 1;
int val=0;
const int led=13;
byte degree[8]={
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000,
};
byte fan_off[8]={
  B00100,
  B00100,
  B00100,
  B11111,
  B00100,
  B00100,
  B00100,
  B00000,
};
byte fan_on[8]={
  B00100,
  B10101,
  B01110,
  B11111,
  B01110,
  B10101,
  B00100,
  B00000,
};
void setup() {
  pinMode(led, OUTPUT);
  lcd.begin(16, 2);
  lcd.createChar(0, degree);
  lcd.createChar(1, fan_off);
  lcd.createChar(2, fan_on);
  lcd.setCursor(0, 0); lcd.print("Set:");
  lcd.setCursor(10, 0); lcd.write((byte)0);
  lcd.setCursor(11, 0); lcd.print("C");
  lcd.setCursor(0, 1); lcd.print("Cur:");
  lcd.setCursor(10, 1); lcd.write((byte)0);
  lcd.setCursor(11, 1); lcd.print("C");
}

void loop() {
  val =  analogRead(pinLM35);
  cur= val * 5 * 100 / 1024.0;
  lcd.setCursor(6, 0); lcd.print(set, 1);
  lcd.setCursor(6, 1); lcd.print(cur, 1);
  lcd.setCursor(15,1);
  if (cur > set) {
    digitalWrite(led, HIGH); 
    lcd.write(2);}
  else {
    digitalWrite(led, LOW);
    lcd.write(1);
    }
    delay(500);
}
