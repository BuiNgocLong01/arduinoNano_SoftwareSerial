#include <Arduino.h>

const int button = 4;
const int led = 5;


void setup() 
{
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() 
{
  if(digitalRead(button) == 0)
  {
    Serial.write('1');
    delay(100);
  }
  else
  {
    Serial.write('0');
    delay(100);
  }
  
  if(Serial.available() > 0)
  {
    char receivedChar = Serial.read();
    if(receivedChar == '1')
    {
      digitalWrite(led, HIGH);
    }
    else
    {
      digitalWrite(led, LOW);
    }
  }
}
