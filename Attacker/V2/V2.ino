#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

// Right Motor
int enableRightMotor=5; 
int rightMotorPin1=7;
int rightMotorPin2=8;

// Left Motor
int enableLeftMotor=6;
int leftMotorPin1=9;
int leftMotorPin2=10;


// Current State (Forward or Reverse Mode)
char currentState = 'F';

void setup()
{
  pinMode(enableRightMotor,OUTPUT);
  pinMode(rightMotorPin1,OUTPUT);
  pinMode(rightMotorPin2,OUTPUT);
  
  pinMode(enableLeftMotor,OUTPUT);
  pinMode(leftMotorPin1,OUTPUT);
  pinMode(leftMotorPin2,OUTPUT);
  rotateMotor(0,0);   
    
  Dabble.begin(9600, 2, 3);
}



void loop()
{
  int rightMotorSpeed=0;
  int leftMotorSpeed=0;
  Dabble.processInput();
    if (GamePad.isSelectPressed())
    {
      if (currentState == 'F') {
        currentState = 'R';
      } else if (currentState == 'R') {
        currentState = 'F';
      } else {}
    }

  if (currentState == 'F') {
      if (GamePad.isUpPressed())
      {
        rightMotorSpeed = 255;
        leftMotorSpeed = 255;
      }
    
      if (GamePad.isDownPressed())
      {
        rightMotorSpeed = -255;
        leftMotorSpeed = -255;
      }
    
      if (GamePad.isLeftPressed())
      {
        rightMotorSpeed = 255;
        leftMotorSpeed = 0;
      }
    
      if (GamePad.isRightPressed())
      {
        rightMotorSpeed = 0;
        leftMotorSpeed = 255;
      }
    
      rotateMotor(rightMotorSpeed, leftMotorSpeed);
  } else if (currentState == 'R') {
      if (GamePad.isUpPressed())
      {
        rightMotorSpeed = -255;
        leftMotorSpeed = -255;
      }
    
      if (GamePad.isDownPressed())
      {
        rightMotorSpeed = 255;
        leftMotorSpeed = 255;
      }
    
      if (GamePad.isLeftPressed())
      {
        rightMotorSpeed = 0;
        leftMotorSpeed = -255;
      }
    
      if (GamePad.isRightPressed())
      {
        rightMotorSpeed = -255;
        leftMotorSpeed = 0;
      }
    
      rotateMotor(rightMotorSpeed, leftMotorSpeed);
  }
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed >= 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed >= 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }

  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}
