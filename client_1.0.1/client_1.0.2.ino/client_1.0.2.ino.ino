//#include "Arduino.h"
#include <ESP8266WiFi.h>
//#include "WiFi.h"
#include <WiFiClient.h> 

WiFiClient client;
const IPAddress server(0,0,0,0);
const int httpPort = 3000;
const char* ssid = "test";
const char* password =  "12345678";

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booted");
  Serial.println("Connecting to Wi-Fi");
  WiFi.begin ("SCL Guest");
  WiFi.mode(WIFI_STA);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    yield();
  }
//
//  WiFi.mode(WIFI_AP);
//  WiFi.softAP(ssid, password);
//
//  IPAddress IP = WiFi.softAPIP();
//  Serial.print("AP IP address: ");
//  Serial.println(IP);
  Serial.println("WiFi connected");
  if (client.connect(server,httpPort )) {
    Serial.println("Client Connected");
  } else {
    Serial.println("No Connection");
  }
}
void loop() {
//  if (client.connect(server,httpPort )) {
//    Serial.println("Client Connected");
//  } else {
//    Serial.println("No Connection");
//  }
}
