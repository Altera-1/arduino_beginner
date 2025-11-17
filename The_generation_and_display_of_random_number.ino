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
    pinMode(11,INPUT_PULLUP);
    digitalWrite(a, HIGH); // 初始化为HIGH（熄灭）
  }
  

}
void loop() 
{
  int button=digitalRead(11);
  randomSeed(analogRead(A0));
  int number=random(0,9);//读取11口，按下，数字快速跳动。松手停止跳动显示数字
  if(button==0)
  {
   display(number);
  }
}

void display(int a)
{ 
  delay(50);
  clear();
  switch(a)//数字显示
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

void clear()//清除显示函数
{
  for(int a = 2; a <= 8; a++)
  {
    digitalWrite(a, HIGH);
  }
}
