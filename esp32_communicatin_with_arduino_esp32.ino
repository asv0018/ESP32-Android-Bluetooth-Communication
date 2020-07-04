#include "BluetoothSerial.h"
 
BluetoothSerial SerialBT;
 
void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param){
  if(event == ESP_SPP_SRV_OPEN_EVT){
    // IF CONNECTED TURN LED GREEN, for example
    Serial.println("Client Connected");
  }
 
  if(event == ESP_SPP_CLOSE_EVT ){
    Serial.println("Client disconnected");
    // IF DISCONNECTED TURN LED RED, for example
  }
}
 
void setup() {
  Serial.begin(115200);
 // interrupt to know weather bluetooth is connected or not
  SerialBT.register_callback(callback);
  
  if(!SerialBT.begin("ESP32")){
    Serial.println("An error occurred initializing Bluetooth");
  }else{
    Serial.println("Bluetooth initialized");
  }
}

void loop() {
  
  if (Serial.available()) {
    // If written from the serial moniter
  SerialBT.write(Serial.read());
}

 if (SerialBT.available()) {
  // if recieved from the bluetooth serial 
  Serial.write(SerialBT.read());
}
}
