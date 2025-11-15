void setup() 
{
  Serial.begin(9600);
  for (int a = 2; a < 10; a++) 
  {
    pinMode(a, OUTPUT);
    digitalWrite(a, HIGH);
  }
  Serial.println("系统准备就绪，请输入 s 开始");
}

void loop() 
{
  if (Serial.available() > 0)
  {
    String a = Serial.readStringUntil('\n');
    if (a == "s")
    { 
      Serial.println("开始启动");
      delay(500);
      
      // 持续循环直到有新命令
      while (Serial.available() == 0) 
      {
        for (int a = 2; a < 10; a++)
        { 
          int b = a - 1;
          int c = b - 1;

          digitalWrite(a, LOW);
          delay(40);  // 快速点亮
          digitalWrite(b, LOW);
          delay(40);  // 快速点亮第二个
          digitalWrite(c, HIGH);
          delay(20);  // 快速熄灭第三个
          
          // 循环结束重置（你的原始逻辑）
          if (a == 9) 
          {
            digitalWrite(a, HIGH);
            digitalWrite(b, HIGH);
            delay(100);  // 循环结束稍作停顿
          }
          
          // 检查新命令
          if (Serial.available() > 0) break;
        }
      }
    }  
  }
}
