void setup() 
{
  Serial.begin(9600);
  for (int a=2; a<10; a++) 
  {
   pinMode(a,OUTPUT);
   digitalWrite(a, HIGH);
  }
  Serial.println("系统准备就绪，请输入");
}

void loop() 
{
  if(Serial.available()>0)
  {
    String a=Serial.readStringUntil('\n');
    if(a=="s")
    { 
      Serial.println("开始启动");
      delay(500);
      for(int a=2 ;a<10;a++)
      { int b=a-1;int c=b-1;

        digitalWrite(a,LOW );
        delay(50);
        digitalWrite(b,LOW);
        delay(50);
        digitalWrite(c, HIGH);
        if (a==9) 
        {
         digitalWrite(a, HIGH);
         digitalWrite(b, HIGH);
        }
      } 
    }  
  }
}