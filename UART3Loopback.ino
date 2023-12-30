// UART3Loopback
// Inspired by code here: https://arduino-er.blogspot.com/2015/04/arduino-due-muilt-serial-and-serialevent.html



int LED = 13;
boolean LEDst = true;

void setup() {
  Serial.begin(115200);
  Serial1.begin(4800);
  Serial2.begin(4800);
  Serial3.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LEDst);
}

void loop() {

//  while (Serial.available() > 0) {
//    char a = Serial.read();
//    Serial1.write(a); // First power supply
//    Serial2.write(a); // Second power supply
//    //Serial3.write(a);
//  }
//  
}

//UART0
void serialEvent() {
  while (Serial.available() > 0) {
    char a = Serial.read();
    Serial1.write(a);
    ToggleLED();
  }
}

//UART1
void serialEvent1() {
  while (Serial1.available() > 0) {
    char a = Serial1.read();
    Serial.write(a);
    ToggleLED();
  }
}

//UART2
void serialEvent2() {
  while (Serial1.available() > 0) {
    char a = Serial1.read();
    Serial.write(a);
    ToggleLED();
  }
}

//UART3
void serialEvent3() {
  while (Serial3.available() > 0) {
    char a = Serial3.read();
    Serial.write(a);
    ToggleLED();
  }
}

void ToggleLED(){
  digitalWrite(LED, LEDst = !LEDst);
}
