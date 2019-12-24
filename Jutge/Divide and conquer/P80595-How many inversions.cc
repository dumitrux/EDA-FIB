#include <ESP8266WiFi.h>

////////////////////
#define LED_BUILTIN 0
#define MAX_PWR 1023
#define MIN_PWR 0

//Digital
#define light1 4
#define light2 5
#define light3 9
#define light4 10

#define front_right_1  1
#define front_right_2  3
#define front_left_1   15
#define front_left_2   13
#define back_right_1   12
#define back_right_2   14
#define back_left_1    2
#define back_left_2    0
  
#define camera A0
#define prox_sensor_1 A1
#define prox_sensor_1 A2


const char* ssid = "PAPA1";
const char* pasw = "LEMD";
WiFiServer server(80);

//////////////////////

void setup() {
  //setup ports 
  bool wifi = false;
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);
  pinMode(light4, OUTPUT);
  pinMode(front_right_1, OUTPUT);
  pinMode(front_right_2, OUTPUT);
  pinMode(front_left_1, OUTPUT);
  pinMode(front_left_2, OUTPUT);
  pinMode(back_right_1, OUTPUT);
  pinMode(back_right_2, OUTPUT);
  pinMode(back_left_1, OUTPUT);
  pinMode(back_left_2, OUTPUT);
  
  //Test board
  for(int i = 0; i < 2; i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }

  //Connect wifi
  int tries = 0;
  
  Serial.begin(115200);
  WiFi.begin(ssid, pasw);
  Serial.printf("\nConectando: ",WiFi.SSID().c_str(), "\n");
  while(WiFi.status() != WL_CONNECTED && tries < 15){
    delay(500);
    Serial.print(".");
    tries++;
  }
  
  if(tries >= 15){
    Serial.println("No se ha podido conectar");
  }
  else {
    Serial.println("Conectado con exito");
    server.begin();
    Serial.printf("Servidor inicializado en: ", WiFi.localIP().toString().c_str(), "\n");
    wifi = true;
  }

  light_show_1();
  delay(1000);
  systems_test();
  if(wifi)digitalWrite(LED_BUILTIN, HIGH);

}

void loop() {
  WiFiClient client = server.available();
  if(!client) return;
  
}


//////////////////////

void light_show_1(){
  analogWrite(light1, PWMRANGE);
  delay(250);
  analogWrite(light1, PWMRANGE);
  analogWrite(light2, PWMRANGE);
  delay(250);
  analogWrite(light2, PWMRANGE);
  analogWrite(light3, PWMRANGE);
  delay(250);
  analogWrite(light3, PWMRANGE);
  analogWrite(light4, PWMRANGE);
  delay(250);
  analogWrite(light4, PWMRANGE);
}

void systems_test() {  
  go_front();
  delay(500);
  
  go_back(); 
  delay(500);
  
  turn_left();
  delay(500);
  
  turn_right();
  delay(1000);

  turn_left();
  delay(500);

  stop_eng();
}

void go_front(){
  digitalWrite(front_right_1, HIGH);
  digitalWrite(front_right_2, LOW);
  
  digitalWrite(front_left_1, HIGH);
  digitalWrite(front_left_2, LOW);
  
  digitalWrite(back_right_1, HIGH);
  digitalWrite(back_right_2, LOW);

  digitalWrite(back_left_1, HIGH);
  digitalWrite(back_left_2, LOW);
}

void go_back(){
  digitalWrite(front_right_1, LOW);
  digitalWrite(front_right_2, HIGH);
  
  digitalWrite(front_left_1, LOW);
  digitalWrite(front_left_2, HIGH);
  
  digitalWrite(back_right_1, LOW);
  digitalWrite(back_right_2, HIGH);

  digitalWrite(back_left_1, LOW);
  digitalWrite(back_left_2, HIGH); 
}

void turn_right(){
  digitalWrite(front_right_1, LOW);
  digitalWrite(front_right_2, HIGH);
  
  digitalWrite(front_left_1, HIGH);
  digitalWrite(front_left_2, LOW);
  
  digitalWrite(back_right_1, LOW);
  digitalWrite(back_right_2, HIGH);

  digitalWrite(back_left_1, HIGH);
  digitalWrite(back_left_2, LOW); 
}


void turn_left(){
  digitalWrite(front_right_1, HIGH);
  digitalWrite(front_right_2, LOW);
  
  digitalWrite(front_left_1, LOW);
  digitalWrite(front_left_2, HIGH);
  
  digitalWrite(back_right_1, HIGH);
  digitalWrite(back_right_2, LOW);

  digitalWrite(back_left_1, LOW);
  digitalWrite(back_left_2, HIGH); 
}

void stop_eng(){
  digitalWrite(front_right_1, LOW);
  digitalWrite(front_right_2, LOW);
  digitalWrite(front_left_1, LOW);
  digitalWrite(front_left_2, LOW);  
  digitalWrite(back_right_1, LOW);
  digitalWrite(back_right_2, LOW);
  digitalWrite(back_left_1, LOW);
  digitalWrite(back_left_2, LOW);
}
