#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
const char *ssid = "U_Club_24";  //ENTER YOUR WIFI ssid
const char *password = "metropass";  //ENTER YOUR WIFI password

void setup() {
  delay(1000);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  WiFi.begin(ssid, password);     //Connect to your WiFi router
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
  HTTPClient http;    //Declare object of class HTTPClient
  
  String postData = "test post data";
  
  http.begin("http://10.201.7.120:8080");              //change the ip to your computer ip address
//  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
 
//  int httpCode = http.POST(postData);   //Send the request
  
  int httpCode = http.GET();
  String payload = http.getString();    //Get the response payload

  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
 
  http.end();  //Close connection
  
  delay(5000);  //Post Data at every 5 seconds
}
