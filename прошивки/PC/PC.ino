// CREATED BY MICE EFF https://www.youtube.com/watch?v=Jy7_d9qloM4
#include <SPI.h> // https://github.com/PaulStoffregen/SPI
#include <ESP8266WiFi.h> // https://github.com/blynkkk/blynk-library/releases/tag/v0.6.1
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h> // https://github.com/jfturcot/SimpleTimer
#define BLYNK_PRINT Serial
char auth[] = "токен"; //токен устройства 2
char ssid[] = "сеть";  //название wi-fi
char pass[] = "пароль";  //пароль от wi-fi
SimpleTimer timer;
int a = 0 ;
int M = 13; // пин куда подлючен + от  пк
int motor = 2; // куда подлючен мотор на втором устройстве
int vir = V3; // виртуальный пин виртуальной кнопки

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(M, OUTPUT);
  digitalWrite(13,HIGH);  // 5 вольт для реле 
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
  bridge2.setAuthToken("токен"); // токен устройства 1
}
