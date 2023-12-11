#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);  // RX, TX

const int button = 4;
const int led = 5;


void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() 
{
  if(digitalRead(button) == 0)
  {
    mySerial.write('1');
    // Serial.println("Sent '1' !");
    delay(10);
    
  }
  else
  {
    mySerial.write('0');
    // Serial.println("Sent '0' !");
    delay(10);
    
  }
  
  if(mySerial.available() > 0)
  {
    char receivedChar = mySerial.read();
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
