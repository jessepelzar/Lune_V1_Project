#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
const char *ssid = "U_Club_24";  //ENTER YOUR WIFI ssid
const char *password = "metropass";  //ENTER YOUR WIFI password

void setup() {
  delay(1000);
  Serial.begin(115200);
//  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
//  delay(1000);
//  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
//  WiFi.begin(ssid, password);     //Connect to your WiFi router
//  Serial.println("");
//  Serial.print("Connecting");if
//  // Wait for connection
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//  //If connection successful show IP address in serial monitor 
//  Serial.print("Connected to ");
//
//  
//  Serial.println(ssid);
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());

  WiFi.mode(WIFI_AP);
  WiFi.softAP("FBI VAN 42069");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  auto httpPostCode = -1;
  String payload = "";
  while (payload == "") {
        HTTPClient http;  // Declare object of class HTTPClient
        
        String postData = "test=postData";
        
        http.begin("http://192.168.4.2:8080"); // change the ip to your computer ip address
        
        //  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
        //  http.POST(postData);
      
        int httpCode = http.GET();
        payload = http.getString();    // Get the response payload
      
      
        httpPostCode = http.POST(postData);   // Send the request
      
        Serial.println(httpCode);   // Print HTTP return code
        Serial.println(payload);    // Print request response payload
        http.end();  //Close connection
        
        delay(5000);  //Post Data at every 5 seconds
  }

  // Json part
  //  StaticJsonDocument<3000> jsonBuffer;

  DynamicJsonDocument doc(1024);
  auto root = deserializeJson(doc, payload);
  // Test if parsing succeeds.
  //  if (root) {
  //    Serial.println("parseObject() failed");
  //    return;
  //  }
  Serial.print("ssid: ");
  String s = doc["ssid"];
  Serial.println(s);
  Serial.print("password: ");
  String p = doc["password"];
  Serial.println(p);
  Serial.print("ip: ");
  String ip = doc["ip"];
  Serial.println(ip);
  


  delay(1000);
  // connect device to wifi
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  WiFi.begin(s, p);     //Connect to your WiFi router
  Serial.println("");
  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //If connection successful show IP address in serial monitor 
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
}


void loop() {
  
}
