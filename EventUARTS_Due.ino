// UART3Loopback
// Inspired by code here: https://arduino-er.blogspot.com/2015/04/arduino-due-muilt-serial-and-serialevent.html
// Type stuff in the Serial Monitor (UART0) and it is forwared to UART1
// All other UART input is forwared out the Serial Monitor (UART0)

#define COMPANY_NAME "pubinv.org "
#define PROG_NAME "UART3Loopback"
#define VERSION ":V0.1"
#define DEVICE_UNDER_TEST "Hardware:_Control_V1.1_Firmware:_"  //A model number
#define LICENSE "GNU Affero General Public License, version 3 "


int LED = 13;
boolean LEDst = true;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  Serial.begin(115200);
  Serial1.begin(4800);
  Serial2.begin(4800);
  Serial3.begin(9600);
  digitalWrite(LED, LOW);
}

void loop() {

//  while (Serial.available() > 0) {
//    char a = Serial.read();
//    Serial1.write(a); // First power supply
//    Serial2.write(a); // Second power supply
//    //Serial3.write(a);
//  }

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
