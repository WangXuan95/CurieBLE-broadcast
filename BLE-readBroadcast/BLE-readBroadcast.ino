#include <CurieBLE.h>

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("*** CurieBLE central read broadcast service data ***");
  BLE.begin();
  BLE.scan(true);
}

void loop() {
  unsigned short val;
  Serial.print("Scanning Broadcast...");

  if( BLE.getBroadcastValueByUuid(0x1234,val) ){
    Serial.print("    Uuid=1234: ");
    Serial.print(val, HEX);
  }
  
  if( BLE.getBroadcastValueByUuid(0x1235,val) ){
    Serial.print("    Uuid=1235: ");
    Serial.print(val, HEX);
  }
  
  Serial.println();
  delay(1000);
}
