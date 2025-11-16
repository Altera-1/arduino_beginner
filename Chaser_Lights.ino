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
          int d = c - 1;

          digitalWrite(a, LOW);
          delay(40);  // 点亮第一个
          digitalWrite(b, LOW);
          delay(40);  // 点亮第二个
          digitalWrite(c, LOW);
          delay(40);  // 点亮第三个
          digitalWrite(d,HIGH);
          delay(20);  // 熄灭第四个
          
          
          if (a == 9) 
          {
            digitalWrite(a, HIGH);
            digitalWrite(b, HIGH);
            digitalWrite(c, HIGH);
            delay(100);  // 循环结束稍作停顿
          }
          
          if (Serial.available() > 0) break;//有新输入退出循环
        }
      }
      for(int a=2;a<10;a++)//退出循环熄灭所有led
      {
       digitalWrite(a,HIGH);
      }  
    }  
  }
}
