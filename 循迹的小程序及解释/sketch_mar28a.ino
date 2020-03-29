//循迹的小算法和相关解释.cpp

//需要明晰的是，基础的Arduino项目由setup和loop组成
//setup里面一般是存放一些参数的初始化
//loop里面就是想要循环的给车辆发送的命令了
//算法一般不会写在其中
//让我们开始吧

#include <Servo.h>

#define STOP 0
#define FORWARD 1
#define BACKWARD 2
#define TURNLEFT 3
#define TURNRIGHT 4

int leftMotor1 = 16;
int leftMotor2 = 17;
int rightMotor1 = 18;
int rightMotor2 = 19;

int trac1 = 10; //从车头方向的最右边开始排序
int trac2 = 11;
int trac3 = 12;
int trac4 = 13;

int leftPWM = 5;
int rightPWM = 6;

Servo myServo; //初始化舵机

int inputPin = 7;  // 定义超声波信号接收接口
int outputPin = 8; // 定义超声波信号发出接口

//****上面这些都是在确认一些端口，这些具体需要到实体机构上进行调整****//

//****参数初始化****//
void setup()
{
  // put your setup code here, to run once:
  //串口初始化
  Serial.begin(9600);
  //舵机引脚初始化
  myServo.attach(9);
  //测速引脚初始化
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(leftPWM, OUTPUT);
  pinMode(rightPWM, OUTPUT);
  //寻迹模块D0引脚初始化
  pinMode(trac1, INPUT);
  pinMode(trac2, INPUT);
  pinMode(trac3, INPUT);
  pinMode(trac4, INPUT);
}

//****循环发出指令****//
void loop()
{
  // put your main code here, to run repeatedly:
  tracing();
}

//****算法部分****//

void motorRun(int cmd, int value)
{
  analogWrite(leftPWM, value); //设置PWM输出，即设置速度
  analogWrite(rightPWM, value);
  //设置一些高低电平（数电基础）
  switch (cmd)
  {
    case FORWARD:
      Serial.println("FORWARD"); //输出状态
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      break;
    case BACKWARD:
      Serial.println("BACKWARD"); //输出状态
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      break;
    case TURNLEFT:
      Serial.println("TURN  LEFT"); //输出状态
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      break;
    case TURNRIGHT:
      Serial.println("TURN  RIGHT"); //输出状态
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      break;
    default:
      Serial.println("STOP"); //输出状态
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, LOW);
  }
}

//循迹算法主体
void tracing()
{
  int data[4];
  data[0] = digitalRead(10);
  data[1] = digitalRead(11);
  data[2] = digitalRead(12);
  data[3] = digitalRead(13);
  //猜测0123这些红外探头的规定是右前开始顺时针排位

  if (!data[0] && !data[1] && !data[2] && !data[3]) //左右都没有检测到黑线
  {
    motorRun(FORWARD, 200);
  }

  if (data[0] || data[1]) //右边检测到黑线
  {
    motorRun(TURNRIGHT, 150);
  }

  if (data[2] || data[3]) //左边检测到黑线
  {
    motorRun(TURNLEFT, 150);
  }

  if (data[0] && data[3]) //左右都检测到黑线是停止
  {
    motorRun(STOP, 0);
    while (1)
      ;
  }

  Serial.print(data[0]);
  Serial.print("---");
  Serial.print(data[1]);
  Serial.print("---");
  Serial.print(data[2]);
  Serial.print("---");
  Serial.println(data[3]);
}
