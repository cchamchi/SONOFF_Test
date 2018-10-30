/*
This example shows how to connect to Cayenne using an ESP8266 and send/receive sample data.

The CayenneMQTT Library is required to run this sketch. If you have not already done so you can install it from the Arduino IDE Library Manager.

Steps:
1. If you have not already installed the ESP8266 Board Package install it using the instructions here: https://github.com/esp8266/Arduino#installing-with-boards-manager.
2. Select your ESP8266 board from the Tools menu.
3. Set the Cayenne authentication info to match the authentication info from the Dashboard.
4. Set the network name and password.
5. Compile and upload the sketch.
6. A temporary widget will be automatically generated in the Cayenne Dashboard. To make the widget permanent click the plus sign on the widget.
*/

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>

// WiFi network info.
char ssid[] = "PSTORM_C";
char wifiPassword[] = "1234asdf";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "****";
char password[] = "****";
char clientID[] = "****";
#define LED_PIN    13
#define RELAY_PIN  12

void setup() {
	Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(RELAY_PIN,OUTPUT);
	Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() {
	Cayenne.loop();
}

// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.

// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.


CAYENNE_IN(0)
{
  digitalWrite(LED_PIN, !getValue.asInt());
  digitalWrite(RELAY_PIN, getValue.asInt());
}
