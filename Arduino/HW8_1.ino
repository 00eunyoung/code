volatile byte command = 0;
volatile byte data = 0;
const int pinLM35 = 1;


void setup () {
  pinMode(MISO, OUTPUT);
  //pinMode(pinLM35, INPUT);
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
  data = (byte)(analogRead(pinLM35) * 5 * 100 / 1024.0);

  if (digitalRead(SS) == HIGH)
    command = 0;
}
