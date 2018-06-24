#include<ESP8266WiFi.h>

WiFiServer server(80);   //Initialize the server on Port 80

void setup() 
{

WiFi.mode(WIFI_AP);                   //Our ESP8266-12E is an AccessPoint [Accesspoint means make wifi a server.]
WiFi.softAP("Hello_IoT", "12345678"); // Provide the (SSID, password); [Passward and name of server]
server.begin();                       // Start the HTTP Server

Serial.begin(115200);                         //Start communication between the ESP8266-12E and the monitor window
IPAddress HTTPS_ServerIP= WiFi.softAPIP();    // Obtain the IP of the Server
Serial.println("Server IP is: ");             // Print the IP to the monitor window
Serial.println(HTTPS_ServerIP);
}

void loop() { 
  WiFiClient client = server.available();
    if (!client) 
    {
       return;
    }
//Looking under the hood
Serial.println("Somebody has connected :)");
}
