#include <Servo.h>

int pir = A1;
int servoPin = 9;

Servo myservo;

void setup()
{
  Serial.begin(9600);
  myservo.attach(servoPin);
  myservo.write(0);
  pinMode(pir, INPUT);
}

void loop()
{
  if(motionDetected())
  {
    myservo.write(90);
    delay(5000);
    myservo.write(0);
  }
  delay(1000);
}

bool motionDetected()
{
  Serial.println(analogRead(pir));
  if(analogRead(pir)>100)
    return(true);
  else
    return(false);
}
