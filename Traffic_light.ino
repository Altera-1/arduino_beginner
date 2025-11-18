/*
 * 交通灯控制系统 with 数码管倒计时显示
 * 端口连接说明：
 * 
 * 数码管段控制 (共阳极)：
 * 引脚2 -> a段
 * 引脚3 -> b段  
 * 引脚4 -> c段
 * 引脚5 -> d段
 * 引脚6 -> e段
 * 引脚7 -> f段
 * 引脚8 -> g段
 * 
 * 交通灯控制：
 * 引脚9  -> 红灯
 * 引脚10 -> 黄灯
 * 引脚11 -> 绿灯
 * 接地端 -> GND
 */

void setup() 
{
  Serial.begin(9600); // 初始化串口通信
  
  // 初始化引脚2-11
  for(int a = 2; a <= 11; a++)
  {
    pinMode(a, OUTPUT);    // 设置引脚为输出模式
    
    // 数码管段(2-8引脚)初始化为HIGH(熄灭)
    // 交通灯(9-11引脚)初始化为LOW(熄灭)
    digitalWrite(a, HIGH);
    if(a > 8)
    {
      digitalWrite(a, LOW); // 交通灯初始状态为熄灭
    }
  }
}

void loop() 
{
  green();   // 绿灯阶段
  yellow();  // 黄灯阶段
  red();     // 红灯阶段
}

// 绿灯阶段函数
void green()
{
  digitalWrite(11, HIGH); // 点亮绿灯
  count(5);               // 5秒倒计时
  digitalWrite(11, LOW);  // 熄灭绿灯
}

// 黄灯阶段函数
void yellow()
{ 
  int i = 3; // 倒计时3秒
  
  while (i > 0) 
  { 
    display(i);             // 显示当前倒计时数字
    digitalWrite(10, HIGH); // 黄灯亮
    delay(500);             // 保持500ms
    digitalWrite(10, LOW);  // 黄灯灭
    delay(500);             // 保持500ms
    i--;                    // 倒计时减1
  }
  clear(); // 清除数码管显示
}

// 红灯阶段函数
void red()
{
  digitalWrite(9, HIGH); // 点亮红灯
  count(5);              // 5秒倒计时
  digitalWrite(9, LOW);  // 熄灭红灯
}

// 倒计时函数
void count(int sum)
{
  while(sum > 0)
  {
    display(sum); // 显示当前倒计时数字
    delay(1000);  // 每个数字显示1秒
    sum--;        // 倒计时减1
  }
  clear(); // 倒计时结束后清除显示
}

// 数码管显示函数
void display(int a)
{ 
  clear(); // 先清除显示
  
  // 根据数字点亮对应的段
  switch(a)
  {
    case 0:
      digitalWrite(2, LOW); // a段
      digitalWrite(3, LOW); // b段
      digitalWrite(4, LOW); // c段
      digitalWrite(5, LOW); // d段
      digitalWrite(6, LOW); // e段
      digitalWrite(7, LOW); // f段
      break;
    case 1:
      digitalWrite(3, LOW); // b段
      digitalWrite(4, LOW); // c段
      break;  
    case 2:
      digitalWrite(2, LOW); // a段
      digitalWrite(3, LOW); // b段
      digitalWrite(5, LOW); // d段
      digitalWrite(6, LOW); // e段
      digitalWrite(8, LOW); // g段
      break;
    case 3:
      digitalWrite(2, LOW); // a段
      digitalWrite(3, LOW); // b段
      digitalWrite(4, LOW); // c段
      digitalWrite(5, LOW); // d段
      digitalWrite(8, LOW); // g段
      break;
    case 4:
      digitalWrite(3, LOW); // b段
      digitalWrite(4, LOW); // c段
      digitalWrite(7, LOW); // f段
      digitalWrite(8, LOW); // g段
      break;
    case 5:
      digitalWrite(2, LOW); // a段
      digitalWrite(4, LOW); // c段
      digitalWrite(5, LOW); // d段
      digitalWrite(7, LOW); // f段
      digitalWrite(8, LOW); // g段
      break;
    case 6:
      digitalWrite(2, LOW); // a段
      digitalWrite(4, LOW); // c段
      digitalWrite(5, LOW); // d段
      digitalWrite(6, LOW); // e段
      digitalWrite(7, LOW); // f段
      digitalWrite(8, LOW); // g段
      break;
    case 7:
      digitalWrite(2, LOW); // a段
      digitalWrite(3, LOW); // b段
      digitalWrite(4, LOW); // c段
      break;
    case 8:
      digitalWrite(2, LOW); // a段
      digitalWrite(3, LOW); // b段
      digitalWrite(4, LOW); // c段
      digitalWrite(5, LOW); // d段
      digitalWrite(6, LOW); // e段
      digitalWrite(7, LOW); // f段
      digitalWrite(8, LOW); // g段
      break;
    case 9:
      digitalWrite(2, LOW); // a段
      digitalWrite(3, LOW); // b段
      digitalWrite(4, LOW); // c段
      digitalWrite(5, LOW); // d段
      digitalWrite(7, LOW); // f段
      digitalWrite(8, LOW); // g段
      break;
    default:
      break;
  }  
}

// 清除数码管显示函数
void clear()
{
  // 将所有数码管段引脚设置为HIGH(熄灭)
  for(int a = 2; a <= 8; a++)
  {
    digitalWrite(a, HIGH);
  }
}