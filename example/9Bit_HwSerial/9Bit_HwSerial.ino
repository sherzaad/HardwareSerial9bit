#include <HardwareSerial9bit.h>

void setup() {
  
  // Open serial communications and wait for port to open. (COM Port for PC Serial Monitor)
  Serial90.begin(115200);
  while (!Serial90) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  //Open seial communication to recieve 9bit data (using Serial1 COM port for 9 bit Serial communication) 
  Serial91.begin(9600, SERIAL_9N1);

  Serial90.println("READY!");
}

void loop() {
uint16_t indata;
  
  if(Serial91.available()){
    indata = (int)Serial91.read(); //read 9bit Serial Data
    Serial90.print("S1 RX = ");
    Serial90.print(indata,HEX); //print 9bit Serial Data to Serial Monitor
  }
  Serial90.println("");
  
  delay(500); //arbitrary delay
}
