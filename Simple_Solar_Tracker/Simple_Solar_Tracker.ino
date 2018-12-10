
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 90;    // variable to store the servo position

int LDR0, LDR1;

int limit0 = 15;
int limit1 = 165;
int servoTime = 10;   // 10ms for servo move 1 degree  
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
}

void loop() 
{
  ReadInput();
  AngleCorrect();
}

void ReadInput()
{
  LDR0 = analogRead(A0);
  LDR1 = analogRead(A1);
  delay(30);
  Serial.print(LDR0);Serial.print("         ");Serial.println(LDR1);
}

void AngleCorrect()
{
  int LDRdiff = LDR0-LDR1;
      LDRdiff = abs(LDRdiff);
      
  if(LDRdiff>30)
  {
  if(LDR0>LDR1)
  {
    if(pos<limit1) pos++;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(servoTime);
  }
  else if(LDR0<LDR1)
  {
    if(pos>limit0) pos--;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(servoTime);
  }
  }
}

