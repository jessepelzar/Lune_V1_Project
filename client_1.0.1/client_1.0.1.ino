#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
//#include <ESP8266HTTPClient.h>
//#include <ESP8266WiFiMulti.h>
//#include <WiFi.h>

//ESP8266WiFiMulti WiFiMulti;
#include <WiFiManager.h>

//const char* ssid     = "WifiName";
//const char* password = "YourPassword";

//const char* host = "IP";
//  
//
//const char* ssid     = "hello";
//const char* password = "123456789";

String g_state = "";

//ESP8266WebServer server(80);
//WiFiServer server(8080);

void setup() {
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.resetSettings();
  wifiManager.autoConnect("loomx");
//  WiFi.mode(WIFI_AP);
//  WiFi.softAP(ssid, password);
//
//  IPAddress IP = WiFi.softAPIP();
//  Serial.print("AP IP address: ");
//  Serial.println(IP);
//  server.on("/setSTATE",handle_OnConnect);
//  
//  server.begin();
}




void loop() {
//   server.handleClient();
//   WiFiClient client;
//   char c = client.read();             // read a byte, then
//   Serial.println(c);
//  if (client) {                             // If a new client connects,
//    Serial.println("New Client.");          // print a message out in the serial port
//    String currentLine = "";                // make a String to hold incoming data from the client
//    while (client.connected()) {            // loop while the client's connected
//      if (client.available()) {             // if there's bytes to read from the client,
//        char c = client.read();             // read a byte, then
//        Serial.println(c);
//        Serial.write(c);// print it out the serial monitor
//      }
//    }
//    client.stop();
//    Serial.println("Client disconnected.");
//    Serial.println("");
//  }
}


//
//void handle_OnConnect() {
//  Serial.println("onconnect");
//  g_state = server.arg("STATEstate");
//  Serial.println(g_state);
//  server.send(200,"text/plain", g_state); 
//}

//String httpGETRequest(const char* serverName) {
//  WiFiClient client;
//  HTTPClient http;
//    
//  // Your IP address with path or Domain name with URL path 
//  http.begin(client, serverName);
//  
//  // Send HTTP POST request
//  int httpResponseCode = http.GET();
//  
//  String payload = "--"; 
//  
//  if (httpResponseCode>0) {
//    Serial.print("HTTP Response code: ");
//    Serial.println(httpResponseCode);
//    payload = http.getString();
//  }
//  else {
//    Serial.print("Error code: ");
//    Serial.println(httpResponseCode);
//  }
//  // Free resources
//  http.end();
//
//  return payload;
//}
