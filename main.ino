int led[32] = { 13, 12, 10, 9, 8, 6, 5, 4, 2, 7, 3, 14, 16, 17, 18, 20, 21, 22, 25, 26, 29, 30, 33, 34,37, 38, 41, 42, 45, 46, 49, 50 };
int buzzer[3]={ 52, 51, 53}; // 탈출구 위치를 알리는 부저 센서
int GasPin[6] ={A0,A1,A2,A3,A4,A5}; // 가스 감지 센서
int GasValue[6] = {0,0,0,0,0,0}; // 각 가스 감지 센서가 감지하는 수치 변수
int f=0, g = 0; // f는 화재인식변수, g는 화재발생위치를 가르키는 변수

void setup(){

 for(int i=0;i<6;i++)
 {
   pinMode(GasPin[i], INPUT);
 }
 for (int i=0;i<3;i++)
 {
  pinMode(buzzer[i],OUTPUT);
 }
 for(int i=0;i<32;i++)
 {
   pinMode(led[i], OUTPUT);
 }
  Serial.begin(9600);
}

void loop()
{
  if(f==0)//화재발생 x
  {
    for(int i=0;i<6;i++)
    {
      GasValue[i]=analogRead(GasPin[i]);
      if(GasValue[i]>200) // 해당 위치에 있는 가스감지센서에서 일정 가스 수치가 넘어가면 
      { 
        f=1, g= i+1;// f=1일 때, 화재인식 / g는 해당 가스감지센서 위치(화재 발생 위치)를 알려줌
        break;
      }
    }
  }

if(f==1)//화재발생 o
{
  if(g==4)
  {
    for(int i=0;i<3;i++)
     {  
      tone(buzzer[i], 500,300); 
      delay(500);
    }
      for(int j=12, i=13;j>=0, i<=31; j--, i++) 
      {
        digitalWrite(led[i],HIGH);
        digitalWrite(led[j],HIGH);
        delay(500);
        digitalWrite(led[i],LOW);
        digitalWrite(led[j],LOW);
      }
  }
  else if(g==5)
  {
    for(int i=0;i<3;i++)
     {  
      tone(buzzer[i], 500,300); 
      delay(500);
    }
   
    for(int i=6, j=7;i>=0, j<=31; i--, j++)
      {
        digitalWrite(led[i],HIGH);
        digitalWrite(led[j],HIGH);
        delay(500);
        digitalWrite(led[i],LOW);
        digitalWrite(led[j],LOW);
      }
  }
  else if(g==6)
  {
    for(int i=0;i<2;i++)
    {  
      tone(buzzer[i], 500,300); 
      delay(500);
    }
    for(int i=0;i<=34;i++)
      {
        digitalWrite(led[i],HIGH);
        delay(500);
        digitalWrite(led[i],LOW);
      }
  }
  else if(g==1)
  {
    for(int i=1;i<3;i++)
    {  
      tone(buzzer[i], 500,300); 
      delay(500);
    }
    for(int i=31;i>=0;i--)
      {
        tone(buzzer[0], 500,500);
        digitalWrite(led[i],HIGH);
        delay(500);
        digitalWrite(led[i],LOW);
      }
  }
  else if(g==2)
  {
    for(int i=0;i<3;i++)
     {
      tone(buzzer[i],500,300);
      delay(500);
     }
   for(int i=23, j=24;i>=0, j<=31 ;i--,j++)
      {
        digitalWrite(led[i],HIGH);
        digitalWrite(led[j],HIGH);
        delay(500);
        digitalWrite(led[i],LOW);
        digitalWrite(led[j],LOW);
      }
  }
  else if(g==3)
  {
     for(int i=0;i<3;i++)
     {
      tone(buzzer[i],500,300);
      delay(500);
     }
     for(int i=16,j=17;i>=0,j<=32;i--,j++)
      {
        digitalWrite(led[i],HIGH);
        digitalWrite(led[j],HIGH);
        delay(100);
        digitalWrite(led[i],LOW);
        digitalWrite(led[j],LOW);
      }

      
  }
}
}