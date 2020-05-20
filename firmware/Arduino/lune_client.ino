#include <WiFi.h>
const char *ssid = "Lune Controller";
const char *password = "password";
WiFiClient client;
#define PORT 80
IPAddress local_ip;
IPAddress gateway_ip;
void attempt_reconnect(void);

void setup()
{
  Serial.begin(115200);
  WiFi.disconnect(true);
  WiFi.begin(ssid, password);
  WiFi.mode(WIFI_STA);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  local_ip = WiFi.localIP();
  gateway_ip = WiFi.gatewayIP();
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.print(local_ip);
  Serial.print(" Gateway IP: ");
  Serial.println(gateway_ip);
  if (client.connect(gateway_ip, PORT))
  {
    Serial.println("Client Connected");
  }
}

void loop()
{
  if (client.connected())
  {
    client.print("ok\n");
    
    String master_request = client.readStringUntil('\n');
    if (master_request.length() > 0)
    {
      Serial.println(master_request);
    }
    client.flush();
  }
  else 
  {
    attempt_reconnect();
  }

}
void attempt_reconnect(void)
{
  static uint8_t reconnect_attempts = 0;
  if (reconnect_attempts < 5)
  {
      Serial.print("Reconnect attempt: "); Serial.print(reconnect_attempts); Serial.print("...");
      if (client.connect(gateway_ip, PORT) )
      {
        Serial.println("Success");
        reconnect_attempts = 0;
      }
      else
      {
        Serial.println("Failed");
        reconnect_attempts++;
      }
  }
  else
  {
    Serial.println("Disconnected");
  }
}
