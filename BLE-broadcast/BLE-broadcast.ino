#include <CurieBLE.h>

BLEService broadcastService("");
BLEUnsignedShortCharacteristic broadcastChar("1234", BLEBroadcast);

void setup() {
  BLE.begin();
  BLE.setLocalName("Curie");
  broadcastChar.broadcast();
  broadcastService.addCharacteristic(broadcastChar);
  BLE.addService(broadcastService);
}

void loop() {
  static unsigned short i = 0x1301;
  broadcastChar.writeValue(i+=1);
  delay(1000);
}
