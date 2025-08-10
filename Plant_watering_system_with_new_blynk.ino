



/*Plant watering system with new blynk update
   Home Page
*/
//Include the library files
#define BLYNK_TEMPLATE_ID //"TMPL3l5sJza4x"
#define BLYNK_TEMPLATE_NAME //"smart plant watering system using nodemcu"
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID //"TMPL3l5sJza4x"
#define BLYNK_TEMPLATE_NAME //"smart plant watering system using nodemcu"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Initialize the LCD display


char auth[] = "A5ITzY-aF1vBpgGkUbBlllsFsh0O4c_p";//Enter your Auth token
char ssid[] = "moto";//Enter your WIFI name
char pass[] = "12345678";//Enter your WIFI password

BlynkTimer timer;
bool Relay = 0;

//Define component pins
#define sensor A0
#define waterPump D3

void setup() {
  Serial.begin(9600);
  pinMode(waterPump, OUTPUT);
  digitalWrite(waterPump, HIGH);

 

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

 
  for (int a = 0; a <= 15; a++) {
  
    delay(500);
  }
 

  //Call the function
  timer.setInterval(100L, soilMoistureSensor);
}

//Get the button value
BLYNK_WRITE(V1) {
  Relay = param.asInt();

  if (Relay == 1) {
    digitalWrite(waterPump, LOW);
 
  } else {
    digitalWrite(waterPump, HIGH);
  
  }
}

//Get the soil moisture values
void soilMoistureSensor() {
  int value = analogRead(sensor);
  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1;

  Blynk.virtualWrite(V0, value);
 

}

void loop() {
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}
