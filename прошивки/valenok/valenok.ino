// CREATED BY MICE EFF   https://www.youtube.com/watch?v=Jy7_d9qloM4               
            #include <SPI.h> // https://github.com/PaulStoffregen/SPI
            #include <ESP8266WiFi.h> // https://github.com/blynkkk/blynk-library/releases/tag/v0.6.1
            #include <BlynkSimpleEsp8266.h>
            #include <SimpleTimer.h>  //https://github.com/jfturcot/SimpleTimer  
#define BLYNK_PRINT Serial           
char auth[] = "токен";//токен устройства 1
char ssid[] = "сеть";  //название wi-fi
char pass[] = "пароль";  //пароль от wi-fi
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
  bridge1.setAuthToken("токен"); // токен устройства 2
}
