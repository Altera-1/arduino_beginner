/*这是一个arduino随机数字生成的代码，使用的是共阳极数码管，对应连接方式如下
  2    →     a     
  3    →     b      
  4    →     c     
  5    →     d     
  6    →     e     
  7    →     f     
  8    →     g
  11 → 按钮一脚
按钮另一脚   → GND
Arduino 5V  → 数码管共阳极(COM)
Arduino GND → 面包板GND*/
void setup() 
{
  Serial.begin(9600);
  
  for(int a = 2; a <= 8; a++)
  {
    pinMode(a, OUTPUT);
    pinMode(11, INPUT_PULLUP);
    digitalWrite(a, HIGH); // 初始化为HIGH（熄灭）
  }
}

void loop() 
{
  int button = digitalRead(11);
  
  if(button == 0)
  {
    // 按钮防抖
    delay(50);
    if(digitalRead(11) == 0) {
      // 显示5个随机数字，最后一个停留
      displayRandomSequence();
    }
    
    // 等待按钮释放
    while(digitalRead(11) == 0) {
      delay(10);
    }
  }
}

void displayRandomSequence()
{
  int lastNumber = 0;
  
  for(int i = 0; i < 5; i++)
  {
    // 每次生成随机数种子
    randomSeed(analogRead(A0) + millis());
    lastNumber = random(0, 10);
    
    // 显示当前数字
    display(lastNumber);
    
    // 如果不是最后一个数字，短暂显示后清除
    if(i < 4) {
      delay(100); // 每个数字显示300ms
      clear();
      delay(50); // 数字间的间隔100ms
    }
  }
  // 最后一个数字将保持显示
}

void display(int a)
{ 
  clear();
  switch(a)
    {
      case 0:
        digitalWrite(2, LOW); // a
        digitalWrite(3, LOW); // b
        digitalWrite(4, LOW); // c
        digitalWrite(5, LOW); // d
        digitalWrite(6, LOW); // e
        digitalWrite(7, LOW); // f
        break;
      case 1:
        digitalWrite(3, LOW); // b
        digitalWrite(4, LOW); // c
        break;  
      case 2:
        digitalWrite(2, LOW); // a
        digitalWrite(3, LOW); // b
        digitalWrite(5, LOW); // d
        digitalWrite(6, LOW); // e
        digitalWrite(8, LOW); // g
        break;
      case 3:
        digitalWrite(2, LOW); // a
        digitalWrite(3, LOW); // b
        digitalWrite(4, LOW); // c
        digitalWrite(5, LOW); // d
        digitalWrite(8, LOW); // g
        break;
      case 4:
        digitalWrite(3, LOW); // b
        digitalWrite(4, LOW); // c
        digitalWrite(7, LOW); // f
        digitalWrite(8, LOW); // g
        break;
      case 5:
        digitalWrite(2, LOW); // a
        digitalWrite(4, LOW); // c
        digitalWrite(5, LOW); // d
        digitalWrite(7, LOW); // f
        digitalWrite(8, LOW); // g
        break;
      case 6:
        digitalWrite(2, LOW); // a
        digitalWrite(4, LOW); // c
        digitalWrite(5, LOW); // d
        digitalWrite(6, LOW); // e
        digitalWrite(7, LOW); // f
        digitalWrite(8, LOW); // g
        break;
      case 7:
        digitalWrite(2, LOW); // a
        digitalWrite(3, LOW); // b
        digitalWrite(4, LOW); // c
        break;
      case 8:
        digitalWrite(2, LOW); // a
        digitalWrite(3, LOW); // b
        digitalWrite(4, LOW); // c
        digitalWrite(5, LOW); // d
        digitalWrite(6, LOW); // e
        digitalWrite(7, LOW); // f
        digitalWrite(8, LOW); // g
        break;
      case 9:
        digitalWrite(2, LOW); // a
        digitalWrite(3, LOW); // b
        digitalWrite(4, LOW); // c
        digitalWrite(5, LOW); // d
        digitalWrite(7, LOW); // f
        digitalWrite(8, LOW); // g
        break;
      default:
        break;
    }
}

void clear()
{
  // 清除所有使用的引脚 (2-8)
  for(int a = 2; a <= 8; a++)
  {
    digitalWrite(a, HIGH);
  }
}
