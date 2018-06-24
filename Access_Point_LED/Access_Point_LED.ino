#include<ESP8266WiFi.h>
int ledPin=D7;
WiFiServer server(80);   //Initialize the server on Port 80

void setup() 
{
pinMode(ledPin,OUTPUT);
WiFi.mode(WIFI_AP);                   //Our ESP8266-12E is an AccessPoint [Accesspoint means make wifi a server.]
WiFi.softAP("Hello_IoT", "12345678"); // Provide the (SSID, password); [Passward and name of server]
server.begin();                       // Start the HTTP Server

Serial.begin(115200);                         //Start communication between the ESP8266-12E and the monitor window
IPAddress HTTPS_ServerIP= WiFi.softAPIP();    // Obtain the IP of the Server
Serial.println("Server IP is: ");             // Print the IP to the monitor window
Serial.println(HTTPS_ServerIP);
}

void loop() { 
   // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");
 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
