#include <SD.h>
#include <Servo.h>
Servo draw_servo;

int nr = 1, nl = 1;
int pinNum(int num)

{
  int i = 0;
  while (num)
  {
    num = num/ 2;
    i++;
  }
  return i;
}
                                                          //right motor
void right1()
{
  digitalWrite(pinNum(nr),LOW);
  nr = nr * 2;
  if (nr>8) nr = 1;
  digitalWrite(pinNum(nr),HIGH);
}

void left1()
{
  digitalWrite(pinNum(nr),LOW);
  nr = nr / 2;
  if (nr<1) nr = 8;
  digitalWrite(pinNum(nr),HIGH);
}
//left motor
void right2()
{
  digitalWrite(pinNum(nl)+4,LOW);
  nl = nl * 2;
  if (nl>8) nl = 1;
  digitalWrite(pinNum(nl)+4,HIGH);
}

void left2()
{
  digitalWrite(pinNum(nl)+4,LOW);
  nl = nl / 2;
  if (nl<1) nl = 8;
  digitalWrite(pinNum(nl)+4,HIGH);
}
                                                            //movements
void up(float x)
{
   for(int i = 0; i< x*200; i++)
    {
      right1();
      left2();
      delay(6);
    }
}
int down(float x)
{
   for(int i = 0; i< x*200; i++)
    {
      left1();
      right2();
      delay(6);
    }
}
int rightup(float x)
{
   for(int i = 0; i< x*200; i++)
    {
      right1();
      delay(6);
    }
}
int rightdown(float x)
{
   for(int i = 0; i< x*200; i++)
    {
      right2();
      delay(6);
    }
}
int leftup(float x)
{
   for(int i = 0; i< x*200; i++)
    {
      left2();
      delay(6);
    }
}
int leftdown(float x)
{
   for(int i = 0; i< x*200; i++)
    {
      left1();
      delay(6);
    }
}
void right(float x)
{
   for(int i = 0; i< x*100; i++)
    {
      right1();
      right2();
      delay(6);
    }
}
void left(float x)
{
   for(int i = 0; i< x*100; i++)
    {
      left1();
      left2();
      delay(6);
    }
}

void draw()
{
  delay(80);
  up(0.05);
  delay(50);
  down(0.05);
  delay(50);
  up(0.05);
  delay(50);
  down(0.05);
  delay(80);
}
void setup()
{
  //initilazing SD
  SD.begin(10);
  File dataFile = SD.open("pixels.txt");
  //setting servo
  draw_servo.attach(9);
  draw_servo.write(160);
  //setting steppers
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  digitalWrite(pinNum(nr),HIGH);
  digitalWrite(pinNum(nl)+4,HIGH);

  delay(5000);
  // 80 * 60 pic (no servo)
  left(5);
  for(int x = 0; x < 700; x++)
  {
    for(int y = 0; y < 500; y++)
    {
      int num = dataFile.read();
      if(num != 48)
      {
//        delay(20);
//        draw_servo.write(120);
        draw();
      }
//      else 
//      {
//        delay(20);
//        draw_servo.write(160);
//      }
      right(0.02);
    }
//    draw_servo.write(160);
    left(10);
    up(0.01);
  }
}

void loop()
{
}
