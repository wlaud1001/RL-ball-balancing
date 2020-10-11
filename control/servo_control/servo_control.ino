#include <Servo.h> 
#include <ArduinoJson.h>

int servoPin1 = 9;
int servoPin2 = 10;
int servoPin3 = 11;

Servo servo1; 
Servo servo2;
Servo serco3;

int angle1 = 0; // servo position in degrees 
int angle2 = 0;
int angle3 = 0;

void setup() 
{ 
  Serial.begin(9600);
  servo1.attach(servoPin1);
//    servo2.attach(servoPin2);
//    servo3.attach(sercoPin3);
} 


void loop() 
{
  int     size_ = 0;
  String  payload;
  char    buffer[100];
  while (!Serial.available()){
//    Serial.println(Serial.available());
    }
  if (Serial.available())
  {
    payload = Serial.readStringUntil('\n');
    Serial.println(payload);
  }
  StaticJsonDocument<1024> doc;

  DeserializationError error = deserializeJson(doc, payload);
  if (error) {
    Serial.println(error.c_str()); 
    Serial.println("error");
    return;
  }

  JsonObject root = doc.as<JsonObject>();
  const char* action1 = root["servo1"];
  const char* action2 = root["servo2"];
  const char* action3 = root["servo3"];

  int ser1 = atoi(action1);
  int ser2 = atoi(action2);
  int ser3 = atoi(action3);

  Serial.print(ser1);
  Serial.print(" ");
  Serial.print(ser2);
  Serial.print(" ");
  Serial.print(ser3);

  servo1.write(ser1);
  delay(20);
} 
