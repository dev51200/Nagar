#include <Servo.h>
Servo myservo;

int pos = 0;

//========== defining inputs ==========//
#define L_S 2  //frontleft sensor
#define R_S 3  //frontright sensor
#define F_S 4  //front sensor
#define RI_S 5 //right side sensor
#define LI_S 6 //left side sensor
#define B_S 7  //back sensor

//========== defining outputs ==========//
#define LM1 8 //left motor pin 1
#define LM2 9 //left moror pin 2
#define RM1 10 //right motor pin 1 
#define RM2 11 //right motor pin 2
#define pump 12 //pump

void setup()
{
  pinMode(L_S, INPUT);
  pinMode(R_S, INPUT);
  pinMode(F_S, INPUT);
  pinMode(RI_S, INPUT);
  pinMode(LI_S, INPUT);
  pinMode(B_S, INPUT);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);
  myservo.attach(13);
  myservo.write(90);
}

void put_off_fire()
{
  digitalWrite(pump, HIGH);
  for (pos = 50; pos <= 130; pos += 1)
  {
    myservo.write(pos);
    delay(10);
  }
  for (pos = 130; pos >= 50; pos -= 1)
  {
    myservo.write(pos);
    delay(10);
  }
  delay(500);
  digitalWrite(pump, LOW);
  myservo.write(90);
}

void FireIsInFront()
{
  if (digitalRead(F_S) == 0) //If Fire is straight ahead
  {
    //Move the robot forward
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    delay(500);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    put_off_fire();
  }
}

void FireIsOnFrontLeft()
{
  if (digitalRead(L_S) == 0) //If Fire is to the left
  {
    //Move the robot left
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    delay(5000);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    put_off_fire();
  }
}

void FireIsOnFrontRight()
{
  if (digitalRead(R_S) == 0) //If Fire is to the right
  {
    //Move the robot right
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    delay(5000);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}

void FireIsOnVeryRight()
{
  if (digitalRead(RI_S) == 0) //IF THE FIRE IN THE Right side
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    delay(5000);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}
void FireIsOnVeryLeft()
{
  if (digitalRead(LI_S) == 0) //if the fire in left side
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    delay(5000);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}

void FireIsOnBack()
{
  if (digitalRead(B_S) == 0) //if the fire is in  backside
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    delay(5000);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}
void NoFireDetected()
{
  if (digitalRead(L_S) == 1 && digitalRead(R_S) == 1 && digitalRead(F_S) == 1 && digitalRead(RI_S) == 1 && digitalRead(LI_S) == 1 && digitalRead(B_S) == 1) //If Fire not detected all sensors are zero
  {
    myservo.write(90);
    //move the robot
    digitalWrite(LM1, HIGH);// BY SETTING PIN TO HIGH MOTOR STOPS
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
}

void loop()
{
  NoFireDetected();
  FireIsInFront();
  FireIsOnFrontLeft();
  FireIsOnFrontRight();
  FireIsOnVeryRight();
  FireIsOnVeryLeft();
  FireIsOnBack();
  delay(100);// new update
}
