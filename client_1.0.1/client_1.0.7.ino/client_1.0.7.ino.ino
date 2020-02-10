//#include <WiFiClient.h> 

#include <ESP8266WiFi.h>

#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <WebSocketClient.h>

//#include <ESP8266mDNS.h>
#include <ArduinoJson.h>
const char *ssid = "U_Club_24";  //ENTER YOUR WIFI ssid
const char *password = "metropass";  //ENTER YOUR WIFI password

boolean handshakeFailed=0;
String data= "";
char path[] = "/";   //identifier of this device
char* host = "";  //replace this ip address with the ip address of your Node.Js server
String hostBackup = "";
const int espport= 3000;
String mac = "";

WiFiClient client;
WebSocketClient webSocketClient;
unsigned long previousMillis = 0;
unsigned long currentMillis;
unsigned long interval=300;


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
  WiFi.softAP("NotYourWiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  auto httpPostCode = -1;
  String payload = "";
  HTTPClient http;  // Declare object of class HTTPClient

  
  
  while (payload == "") {
        
        
        http.begin("http://192.168.4.2:8080"); // change the ip to your computer ip address
        
        //  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
        //  http.POST(postData);
      
        int httpCode = http.GET();
        payload = http.getString();    // Get the response payload
      
      
        
      
        Serial.println(httpCode);   // Print HTTP return code
        Serial.println(payload);    // Print request response payload
        
        
        delay(1000);  //Post Data at every 5 seconds
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

  p = "37049188";
  Serial.println(p);
  Serial.print("ip: ");
  String ip = doc["ip"];
  Serial.println(ip);
  
  hostBackup = ip;
  
  int strLen = ip.length() + 1;
  char charBuf[strLen];
  host = (char*)ip.c_str();
  
  Serial.println("host");
  Serial.println(host);
  
  delay(500);
  
//  httpPostCode = http.POST(postData);   // Send the request
  // connect device to wifi
  WiFi.mode(WIFI_STA);  //This line hides the viewing of ESP as wifi hotspot
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
  Serial.println(s);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

//  if (MDNS.begin("loomx")) { // Start the mDNS responder for loomx.local
//    Serial.println("mDNS responder started");
//  } else {
//    Serial.println("Error setting up MDNS responder!");
//  }
//  http.begin("http://" + ip + ":8080");
  
  http.end();  //Close connection
  delay(1000);
  int code = 0;
  String localip = WiFi.localIP().toString().c_str();
  String postData = "ip=" + localip;
  while (code != 200) {
    http.begin("http://" + ip + ":8080");
    code = http.GET();
    payload = http.getString();
    Serial.println(code);
//    http.POST(ip);
    delay(500);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
    httpPostCode = http.POST(postData);
  }
  http.end();

  
  wsconnect();
  
}


void loop() {
  if (client.connected()) {
    webSocketClient.sendData("");
    
    webSocketClient.getData(data);    
    if (data.length() > 0) {
      Serial.println(data);
      data = "";
    }
  }
  else {
    wsconnect();
  }
  
//  delay(1000);
}


void wsconnect() {

  int strLen = hostBackup.length() + 1;
  char charBuf[strLen];
  host = (char*)hostBackup.c_str();
  mac = WiFi.macAddress();

 
  Serial.println("no");
  // Connect to the websocket server
  Serial.println(host);
  Serial.println(espport);
  if (client.connect(host, espport)) {
    Serial.println("Connected");
  } else {
    Serial.println("Connection failed.");

//    webSocketClient.loop();
      delay(1000);  
   
//   if(handshakeFailed){
//    handshakeFailed=0;
//    ESP.restart();
//    }
//    handshakeFailed=1;
//    wsconnect();
  }
  // Handshake with the server
  webSocketClient.path = path;
  webSocketClient.host = host;
  if (webSocketClient.handshake(client)) {
    Serial.println("Handshake successful");
  } else {
//    webSocketClient.loop();
    Serial.println("Handshake failed.");
    delay(1000);  
//    wsconnect();
//   if(handshakeFailed){
//    handshakeFailed=0;
//    ESP.restart();
//    }
//    handshakeFailed=1;
  }

//  while (1) {
  if (client.connected()) {
    currentMillis=millis(); 
    webSocketClient.getData(data);  
    webSocketClient.sendData(mac);   
    if (data.length() > 0) {
      Serial.println(data);
      webSocketClient.sendData(data);
     }
//      delay(500);
   }
}
