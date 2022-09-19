int flexSensor = A2;
int buzzer = 6;
int lights = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(flexSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(lights, OUTPUT);
}

void loop()
{
  bool door = checkDoor(); // true if door is open
  doorAction(door);
}

bool checkDoor()
{
  if(map(analogRead(flexSensor),100,1000,0,1000)>500)
  {
    // door closed
    return(false);
  }
  else
  {
    return(true);
  }
}

void doorAction(bool door)
{
  if(door)
  {
    // if door is opened, buzzer rings for 1 sec and lights are turned on for a total of 5 secs
    digitalWrite(buzzer,HIGH);
    digitalWrite(lights,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    delay(4000);
    digitalWrite(lights,LOW);
  }
}
