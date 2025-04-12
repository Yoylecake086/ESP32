#include <Arduino.h>
#include "BluetoothSerial.h"
#include "esp_bt_device.h"

BluetoothSerial SerialBT;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
if(SerialBT.begin("sclugabungus")){
  Serial.println("uhmm an oopsie occured while starting :p");
}else{
  Serial.println("Blututh started :)");
}
printDeviceAddress();
SerialBT.register_callback(callback);
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


  void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
    if(event == ESP_SPP_SRV_OPEN_EVT){
      Serial.println("the blututh divice wwas connected sucesfuly :)");
    }
  }
  /*
  char addrStr[18];
  sprintf(addrStr, "%02X:%02X:%02X:%02X:%02X:%02X",)
  */
