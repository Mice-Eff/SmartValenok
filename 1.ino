// Powered by Mice_Eff https://youtu.be/7z2vXxELKN0                   
            #include <SPI.h> // https://github.com/PaulStoffregen/SPI
            #include <ESP8266WiFi.h> // https://github.com/blynkkk/blynk-library/releases/tag/v0.6.1
            #include <BlynkSimpleEsp8266.h>
            #include <SimpleTimer.h>    
#define BLYNK_PRINT Serial           
char auth[] = "GnoMFEVL6YydXU3Lx6ZBqGJjubvNz9-w";//токен устройства 1
char ssid[] = "mice_eff";  //название wi-fi
char pass[] = "12345677";  //пароль от wi-fi
SimpleTimer timer; 
int motor = 2; // пин куда подлючен мотор
int vir = V1; // виртуальный пин виртуальной кнопки
int but = 12; // пин куда подключена кнопка
int a = 0;
WidgetBridge bridge1(V0);


BLYNK_WRITE(V3) {
  int e = param.asInt();
if (e == 1) { 
  digitalWrite(motor,LOW);
   delay(2500);            
   digitalWrite(motor,HIGH);
}
}
void setup(){
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, pass);
 
    while (Blynk.connect() == false) {
  }
 pinMode(motor,OUTPUT);
 pinMode(but,INPUT);
 digitalWrite(motor,LOW);
 delay(1500);              // время вибрации при подлючении к blynk
 digitalWrite(motor,HIGH);
        
}


void loop(){
   
  Blynk.run(); 
  timer.run(); 
 if( digitalRead(but)==HIGH){
  a=1;
   digitalWrite(motor,LOW);
   delay(500);             // время вибрации после нажатия на кпопку 
   digitalWrite(motor,HIGH);

   if(a==1){
       bridge1.virtualWrite(vir,HIGH);   
       delay(5000);
          bridge1.virtualWrite(vir,LOW);   
          a=0;
   }
 }
}

BLYNK_CONNECTED() {
  bridge1.setAuthToken("mW9r7SVtvADj7lxFqiXnJJaMuRJruk4c"); // токен устройства 2
}

