#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("Hello_IoT","12345678",true);

  Serial.print("Connecting");
  while (WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
           if(WiFi.status()==WL_NO_SSID_AVAIL)
          {
             Serial.println("ssid not found");
          }
           if(WiFi.status()==WL_CONNECT_FAILED)
            {
             Serial.println("pswd not found");
            }
  }

  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {}
