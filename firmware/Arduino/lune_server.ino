#include <WiFi.h>

// Application helper functions
void display_help(void);
int first_free_client(void);
void print_clients(void);
void send_message_to_clients(void);
int get_total_clients(void);
void send_message_to_client(int client_number);
void send_broadcast_to_clients(void);


// Application Functions
void task_check_disconnected_clients(void);
void task_check_for_new_clients(void);
void task_check_user_input(void);

// Application Data
#define MAX_CLIENTS 10
#define MAX_RESPONSE_LENGTH 50
#define FOR_EACH_CLIENT for(int i = 0; i < MAX_CLIENTS; ++i)

const char* ssid = "Lune Controller";
const char* password = "password";

WiFiServer server(80, MAX_CLIENTS);

WiFiClient *clients[MAX_CLIENTS] = { NULL };
char client_responses[MAX_CLIENTS][MAX_RESPONSE_LENGTH] = {0};

void setup() 
{
  Serial.begin(115200);
  Serial.println("\n");
  Serial.print("Creating: "); Serial.println(ssid);
  
  WiFi.disconnect(true);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  Serial.print("WiFi Created AP IP: "); Serial.println(WiFi.softAPIP());
  
  server.begin();
  Serial.println("Server started");
  display_help();
}

void loop() 
{
  task_check_disconnected_clients();
  task_check_for_new_clients();
  task_check_user_input();
}

//Task Definitions
void task_check_disconnected_clients(void)
{
  if (WiFi.softAPgetStationNum() < get_total_clients())
  {
    Serial.println("A Client has disconnected");
    FOR_EACH_CLIENT
    {
      if (clients[i] != NULL && !clients[i]->connected())
      {
        Serial.print("Client "); Serial.print(i); Serial.println(" Disconnected");
        clients[i]->flush();
        clients[i]->stop();
        delete clients[i];
        clients[i] = NULL;
      }
    }
  }
}

void task_check_for_new_clients(void)
{
  WiFiClient newClient = server.available();
  if (newClient) 
  {
    bool known = false;
    IPAddress new_ip = newClient.remoteIP();
    FOR_EACH_CLIENT
    {
      if ((clients[i] != NULL) && (clients[i]->remoteIP() == new_ip))
      {
        Serial.print("This IP is already known by the server: ");
        Serial.println(new_ip);
        known = true;
      }
    }
    
    if (!known)
    {
      int first_free_client_index = first_free_client();
      if (first_free_client_index != -1)
      {
        clients[first_free_client_index] = new WiFiClient(newClient);
        Serial.println("Client Added");
        Serial.print("IP: "); Serial.println(clients[first_free_client_index]->remoteIP());
      }
      else
      {
        Serial.println("Max Number of Clients filled");
      }
    }
  }
}

void task_check_user_input(void)
{
  if(Serial.available())
  {
    char user_in = Serial.read();
    Serial.print(user_in);
    if (user_in == 'h')
    {
      display_help();
    }
    else if (user_in == 'p')
    {
      Serial.println("");
      print_clients();
    }
    else if (user_in == 'b')
    {
      Serial.println("");
      send_broadcast_to_clients();
    }
    else if (user_in == 'm')
    {
      if(Serial.available() > 1)
      {
        char client_to_send = Serial.read();
        Serial.println(client_to_send);
        if(client_to_send >= '0' || client_to_send <= '9')
          send_message_to_client( client_to_send - '0' );
        else
          Serial.println("Invalid client to send");
      }
      else
      {
        Serial.println("Usage: m[n] -> n [0:9]");
      }
    }
    else
    {
      Serial.println("Invalid Selection");
    }
    Serial.println("");
    Serial.flush();
  }
}

// Helper function Definitions

void display_help(void)
{
  Serial.println("Help: ");
  Serial.println("'h'    - help menu");
  Serial.println("'p'    - display current connections");
  Serial.println("'b'    - broadcast test message to all connections");
  Serial.println("'m[n]' - directly send message to a client");
  Serial.println("         Ex: m0 -> send to client 0, m1 -> send to client 1... etc");
}

int first_free_client(void) 
{
    FOR_EACH_CLIENT
    {
        if(clients[i] == NULL || !clients[i]->connected()) return i;
    }
    return -1;
}

void print_clients(void)
{
  Serial.println("Clients: ");
  FOR_EACH_CLIENT
  {
    if(clients[i] != NULL)
    {
      Serial.print("\tClient "); Serial.print(i); Serial.println(": ");
      Serial.print("\tIP: "); Serial.println(clients[i]->remoteIP());
      Serial.print("\tConnected "); Serial.println(clients[i]->connected());
    }
  }
  Serial.println("\n");
}

int get_total_clients(void)
{
  int total_clients = 0;
  FOR_EACH_CLIENT
  {
    if (clients[i] != NULL)
      total_clients++;
  }
  return total_clients;
}

void send_message_to_client(int client_number)
{
  if(client_number >=0 || client_number <= 9)
  {
    if (clients[client_number] != NULL && clients[client_number]->connected())
    {
      Serial.println("\tSending: 'test message' to ");
      Serial.print("\tClient ");Serial.print(client_number);Serial.print(" IP: ");
      Serial.println(clients[client_number]->remoteIP());
      
      String check = clients[client_number]->readStringUntil('\n');
      Serial.println(check);
      
      clients[client_number]->print("test message\n");
      clients[client_number]->flush();
    }
  }
  else
  {
    Serial.println("Invalid Client");
  }
  Serial.println("");
}

void send_broadcast_to_clients(void)
{
  Serial.println("Broadcast Test: ");
  FOR_EACH_CLIENT
    send_message_to_client(i);
}
