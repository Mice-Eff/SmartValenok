// Powered by Mice_Eff https://youtu.be/7z2vXxELKN0
#include <SPI.h> // https://github.com/PaulStoffregen/SPI
#include <ESP8266WiFi.h> // https://github.com/blynkkk/blynk-library/releases/tag/v0.6.1
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial
char auth[] = "mW9r7SVtvADj7lxFqiXnJJaMuRJruk4c"; //токен устройства 2
char ssid[] = "mice_eff";  //название wi-fi
char pass[] = "12345677";  //пароль от wi-fi
SimpleTimer timer;
int a = 0 ;
int M = 13; // пин куда подлючен + от  пк
int motor = 2; // куда подлючен мотор на втором устройстве
int vir = V3; // виртуальный пин виртуальной кнопки

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(M, OUTPUT);
}

WidgetBridge bridge2(V2); // мост на втором виртуальном пине

BLYNK_WRITE(V1) {
  int e = param.asInt();
  if (e == 1) { 
    digitalWrite(M, LOW);
    delay(2000);                       // время сколько будут замкнуты + и -  пк
    digitalWrite(M,HIGH);
  }

}


void loop() {
  Blynk.run();
  timer.run();
}

BLYNK_CONNECTED() {
  bridge2.setAuthToken("GnoMFEVL6YydXU3Lx6ZBqGJjubvNz9-w"); // токен устройства 1
}
