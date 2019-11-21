#include <SoftwareSerial.h>
#include <HardwareSerial9bit.h>

#define BAUD 9600

SoftwareSerial mySerial(3, 4); // RX, TX

uint8_t n=0;

void setup() {
  
  // Open serial communications and wait for port to open:
  Serial.begin(BAUD);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  //Open seial communication to recieve 9bit data
  Serial91.begin(9600, SERIAL_9N1);
  // set the data rate for the SoftwareSerial port
  mySerial.begin(BAUD);

  Serial.println("READY!");
}

void loop() {
uint16_t indata=0;
  
  Serial.print("SS TX = ");
  if(n<=15) Serial.print("0x0");
  else Serial.print("0x");
  Serial.print(n,HEX);
  Serial.print(", ");
  
  mySerial.write(n);
  
  delay(500);

  n = (n+1)%256;
  
  Serial.print(Serial91.available());
  Serial.print(", S1 RX = ");
  while(Serial91.available()>0){
    Serial.print((int)Serial91.read(),HEX);   
  }
  Serial.println("");
}
