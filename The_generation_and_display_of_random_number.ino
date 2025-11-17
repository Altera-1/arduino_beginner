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
  int number=random(0,9);
  if(button==0)
  {
   display(number);
  }
}

void display(int a)
{ 
  delay(50);
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