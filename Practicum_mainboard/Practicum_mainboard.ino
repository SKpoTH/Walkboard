#include <Servo.h>
 
Servo myservo;

int SwitchRight = HIGH;
int SwitchLeft = HIGH;
int SwitchStart = HIGH;

int Is_Start = 0;

void setup() {
  pinMode(PIN_PC2, OUTPUT);
  pinMode(PIN_PC3, OUTPUT);
  pinMode(PIN_PC4, OUTPUT);
  pinMode(PIN_PC5, OUTPUT);

  pinMode(PIN_PD0, INPUT_PULLUP);
  
  pinMode(PIN_PD1, INPUT_PULLUP);
  pinMode(PIN_PD6, INPUT_PULLUP);

  myservo.attach(PIN_PD5);
}

void loop() {
  SwitchStart = digitalRead(PIN_PD0);

  if(Is_Start == 0)
  {
    digitalWrite(PIN_PC2, 0);
    digitalWrite(PIN_PC3, 0);
    digitalWrite(PIN_PC4, 0);
    digitalWrite(PIN_PC5, 0);
    
    if(SwitchStart == LOW)
    {
      Is_Start = 1;
      delay(500);
    }
  }
  else if(Is_Start == 1)
  {
    SwitchLeft = digitalRead(PIN_PD1);
    SwitchRight = digitalRead(PIN_PD6);
    if(SwitchLeft == LOW)
    {
      myservo.write(135);
    }
    else if(SwitchRight == LOW)
    {
      myservo.write(45);
    }
    else
    {
      myservo.write(90);
    }
    digitalWrite(PIN_PC2, 0);
    digitalWrite(PIN_PC3, 1);
    digitalWrite(PIN_PC4, 1);
    digitalWrite(PIN_PC5, 0);

    if(SwitchStart == LOW)
    {
      Is_Start = 0;
      delay(500);
    }
  }
}
