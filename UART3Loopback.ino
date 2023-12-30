// UART3Loopback


int LED = 13;
boolean LEDst = true;

void setup() {
  Serial.begin(115200);
  Serial3.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LEDst);
}

void loop() {
  while (Serial.available() > 0) {
    char a = Serial.read();
    Serial3.write(a);
  }
  
}

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
