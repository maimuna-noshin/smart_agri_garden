#define BLYNK_TEMPLATE_ID "TMPL6jd9nW7z0"
#define BLYNK_TEMPLATE_NAME "pump"
#define BLYNK_AUTH_TOKEN "YaBqb909sEAi4lqLkm0fK_Ony_fXqssw"

#include <BlynkSimpleEsp8266.h>

char auth[] = "YaBqb909sEAi4lqLkm0fK_Ony_fXqssw";  // Paste the authentication token from Blynk app here
char ssid[] = "sadman";   // Your WiFi SSID
char pass[] = "eee4518project"; // Your WiFi password

#define RELAY_PIN D1  // Define the GPIO pin to which the relay module is connected

void setup()
{
  Blynk.begin(auth, ssid, pass);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Ensure the relay is initially off
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1)  // Virtual pin V1 in the Blynk app
{
  int value = param.asInt();
  if (value == 1) {
    digitalWrite(RELAY_PIN, HIGH);  // Turn on the water pump
  } else {
    digitalWrite(RELAY_PIN, LOW);   // Turn off the water pump
  }
}
