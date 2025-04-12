#include <Arduino.h>
#include "BluetoothSerial.h"
#include "esp_bt_device.h"
#define BTN_1 4
#define BTN_1 12
#define BTN_1 13
#define BTN_1 14
#define BTN_1 27
#define BTN_1 32
#define BTN_1 33
BluetoothSerial SerialBT;
#define threshold 40

volatile u_int64_t time = 0;


volatile uint32_t button_time1 = 0;
volatile uint32_t button_time2 = 0;
volatile uint32_t button_time3 = 0;
volatile uint32_t button_time4 = 0;
volatile uint32_t button_time5 = 0;
volatile uint32_t button_time6 = 0;
volatile uint32_t button_time7 = 0;

void printDeviceAddress();
void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);
void getTouch1();
void getTouch2();
void getTouch3();
void getTouch4();
void getTouch5();
void getTouch6();
void getTouch7();
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

touchAttachInterrupt(BTN_1, getTouch1, threshold);
touchAttachInterrupt(BTN_2, getTouch2, threshold);
touchAttachInterrupt(BTN_3, getTouch3, threshold);
touchAttachInterrupt(BTN_4, getTouch4, threshold);
touchAttachInterrupt(BTN_5, getTouch5, threshold);
touchAttachInterrupt(BTN_6, getTouch6, threshold);
touchAttachInterrupt(BTN_7, getTouch7, threshold);
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

