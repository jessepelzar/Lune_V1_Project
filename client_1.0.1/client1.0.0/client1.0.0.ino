#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;
//#include <WiFiManager.h>

//const char* ssid     = "WifiName";
//const char* password = "YourPassword";

const char* host = "IP";
  

const char* ssid     = "youdonwanttoconnect";
const char* password = "123456789";

ESP8266WebServer server(80);

const char* testServer = "http://192.168.4.1/";

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.softAP(ssid, password);
//  while((WiFiMulti.run() == WL_CONNECTED)) { 
//    delay(500);
//    Serial.print(".");
//  }
  Serial.println("");
  Serial.println("Connected to WiFi");
//  WiFi.softAP(ssid, password);
//
//  IPAddress IP = WiFi.softAPIP();
//  server.on("/", handle_OnConnect);
//  
//  server.begin();
//  Serial.print("AP IP address: ");
//  Serial.println(IP);
  
//  WiFiManager wifiManager;
//  wifiManager.autoConnect("loomx");
  
  
}


void handle_OnConnect() {
  Serial.println("onconnect");
  server.send(200, "text/html", "test"); 
}


unsigned long previousMillis = 0;
const long interval = 10000;
String testServ;

//void loop() {
//  unsigned long currentMillis = millis();
  
//  if(currentMillis - previousMillis >= interval) {
     // Check WiFi connection status
//    if ((WiFiMulti.run() == WL_CONNECTED)) {
//      testServ = httpGETRequest(testServer);
//      
//      Serial.println("Temperature: " + testServ);
//      previousMillis = currentMillis;
//    }
//    else {
////      Serial.println("WiFi Disconnected");
//    }
//  }
//}
void loop() {
//   server.handleClient();
//   Serial.print("connecting to ");
//   Serial.println(host);
//  
//   // Use WiFiClient class to create TCP connections
   WiFiClient client;
//   const int httpPort = 80;
//   if (!client.connect(host, httpPort)) {
//    Serial.println("connection failed");
//    return;
//   }
//  
//   // We now create a URI for the request
//   String url = "/";
//  
//   Serial.print("Requesting URL: ");
//   Serial.println(url);
//   String data = "data test";
//
//   Serial.print("Requesting POST: ");
//   // Send request to the server:
//   client.println("POST / HTTP/1.1");
//   client.println("Host: server_name");
//   client.println("Accept: */*");
//   client.println("Content-Type: application/x-www-form-urlencoded");
//   client.print("Content-Length: ");
//   client.println(data.length());
//   client.println();
//   client.print(data);
// 
//  while (client.connected() || client.available())
//{
//  if (client.available())
//  {
//    String line = client.readStringUntil('\n');
//    Serial.println(line);
//  }
//}  
//  String line = client.readString();
//  Serial.println(line);
//  if (client.available() > 0) {
//    Serial.print("incoming :");
//    int size;
//    while ((size = client.available()) > 0) {
//            unsigned long * msg = (unsigned long *)malloc(size);
//            size = client.read((uint8_t *)msg, size);
//            String str = String("Value = ") + (*msg);
//            Serial.println(str);
//            free(msg);
//    }
//  }


 // This will send the request to the server
 /*this is a get method working
  * client.print(String("GET ") + url + " HTTP/1.1\r\n" +
           "Connection: close\r\n\r\n");*/
// unsigned long timeout = millis();
// while (client.available() == 0) {
// if (millis() - timeout > 5000) {
//  Serial.println(">>> Client Timeout !");
//  client.stop();
//  return;
// }
//}

 // Read all the lines of the reply from server and print them to Serial
 while(client.available()){
  String line = client.readStringUntil('\r');
  Serial.print(line);
 }
//
// Serial.println();
// Serial.println("closing connection");
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
