#include "thingProperties.h"

int ledPin=23;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  delay(200);
  
}


/*
  Since Led is READ_WRITE variable, onLedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedChange()  {
  // Add your code here to act upon Led change
  if(led == 1){
    digitalWrite(ledPin,HIGH);
    Serial.println("ON");
  }else{
    digitalWrite(ledPin,LOW);
    Serial.println("OFF");
  }
}

