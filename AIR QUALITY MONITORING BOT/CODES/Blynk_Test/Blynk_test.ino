#define BLYNK_TEMPLATE_ID "TMPL39P59o6o4"
#define BLYNK_TEMPLATE_NAME "First project"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "5Mioqf9rSTjEzayg9A9WOwVmhJOXjkYJ"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "iQOO Z5";      // WiFi name
char pass[] = "Likhith1";  // WiFi password

BLYNK_WRITE(V0) {  
  digitalWrite(LED_BUILTIN, param.asInt()); 
}

void setup() {
  Serial.begin(115200); 
  pinMode(LED_BUILTIN, OUTPUT);   
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}
