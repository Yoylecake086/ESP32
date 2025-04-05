#include <Arduino.h>
#include "BluetoothSerial.h"
#include "esp_bt_device.h"
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
}




void printDeviceAddress() {
  const uint8_t* address = esp_bt_dev_get_address();
  for(int i = 0; i < 6; i++){
    char str[3];
    sprintf(str, "%02X", (int) address[i]);
    Serial.print(str);
    if(i < 5){
      Serial.print(":");
    }else{
      Serial.print("\n");
    }
    }
  }
  /*
  char addrStr[18];
  sprintf(addrStr, "%02X:%02X:%02X:%02X:%02X:%02X",)
  */
