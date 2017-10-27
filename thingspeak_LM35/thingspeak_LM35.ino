#include <ESP8266WiFi.h>

const char* ssid = "Goku"; // your wireless network name (SSID)
const char* password = "Pafkiet7443"; // your Wi-Fi network password


float tempC;



WiFiClient client;

const int channelID = 261853;
String writeAPIKey = "98EZTWV8DSRU4Q5T"; // write API key for your ThingSpeak Channel
const char* server = "api.thingspeak.com";
const int postingInterval = 5 * 1000; // post data every 5 seconds

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  if (client.connect(server, 80)) {

    int valueA0 = analogRead(A0);
    tempC = valueA0 / 9.31;

    String body = "field1=";
           body += String(tempC);
    
 
    
    Serial.print("Temp: ");
    Serial.println(tempC); 

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + writeAPIKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(body.length());
    client.print("\n\n");
    client.print(body);
    client.print("\n\n");

  }
  client.stop();

  delay(postingInterval);
}

