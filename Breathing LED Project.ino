/*
 * 呼吸灯程序 
 * 使用引脚9（PWM引脚）控制LED亮度
 * 实现呼吸灯效果：渐亮后渐灭
 */ino

void setup() 
{
  // 初始化串口通信，波特率9600
  Serial.begin(9600);
  
  // 设置引脚9为输出模式（PWM引脚）
  pinMode(9, OUTPUT);
}

void loop() 
{
  // 渐亮过程：亮度从0到255逐渐增加
  for (int a = 0; a < 256; a++) 
  {
    analogWrite(9, a);  // 设置PWM输出值（0-255）
    delay(10);          // 延时10ms，控制渐亮速度
  }
  
  // 渐灭过程：亮度从255到1逐渐减少
  for (int a = 255; a > 0; a--) 
  {
    analogWrite(9, a);  // 设置PWM输出值（0-255）
    delay(10);          // 延时10ms，控制渐灭速度
  }  
}
