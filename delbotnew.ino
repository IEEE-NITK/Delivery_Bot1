/*defining inputs*/
#define IR1 9
#define S0  4
#define S1  5
#define S2  6
#define S3  7
#define sensorOut 8
int frequency1 = 0;
int frequency2 = 0;
int frequency3 = 0;
int redcolor=0;
int bluecolor=0;
int greencolor=0;
int f1;
int f2;
int f3;
int startTime=0;
int x=0;
int motion=0;
int num;
int i=0;
int ent[10];
/*defining outputs*/
#define LM1 3
#define LM2 5
#define RM1 6
#define RM2 10
void setup() 
{
  pinMode(IR1,INPUT);
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(sensorOut,INPUT);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);

  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);

  
}

void loop() 
{
  for(i=0;i<10;i++)
  {
  if(Serial.available()>0)
  {
   ent[i]=Serial.read();
  }
  }
  /*Red*/
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequency1 = pulseIn(sensorOut,LOW);
  redcolor = map(frequency1,0,0,255,0);
  /*Blue*/
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  frequency2 = pulseIn(sensorOut,LOW);
  bluecolor = map(frequency2,0,0,255,0);
  /*Green*/
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  frequency3 = pulseIn(sensorOut,LOW);
  greencolor = map(frequency3,0,0,255,0);

  for(i=0;i<(sizeof(ent)/(sizeof(ent[0])));i++);
  {
  while(motion==0)
  {
    while(IR1)
    {
      analogWrite(LM1,100);
      analogWrite(LM2,0);
      analogWrite(RM1,0);
      analogWrite(RM2,100);
    }
  if(i==1)
  {
    if(redcolor>greencolor && redcolor>bluecolor)
    {
      motion=1; 
    }
  }
  if(i==2)
  {
    if(bluecolor>greencolor && bluecolor>redcolor)
    {
      motion=1;
    }
  }
  }
  while(redcolor>10 && greencolor>10 &&bluecolor>10)
  {
    if(digitalRead(IR1) && motion)
    { 
      analogWrite(LM1,100);
      analogWrite(LM2,0);
      analogWrite(RM1,100);
      analogWrite(RM2,0);
    }   
    
    else if(!digitalRead(IR1) && motion)
    {
      analogWrite(LM1,0);
      analogWrite(LM2,0);
      analogWrite(RM1,100);
      analogWrite(RM2,0);
    } 
    
    else if(digitalRead(IR1) && !(motion))
    {
      analogWrite(LM1,100);
      analogWrite(LM2,0);
      analogWrite(RM1,0);
      analogWrite(RM2,0);
    }
  }
  /*At a junction/delivery point*/
  if(!(digitalRead(IR1)) && redcolor<10 && bluecolor<10 && greencolor<10)
  {
      startTime=millis();
      while(millis < startTime + 2000)
      {    
       analogWrite(LM1,100);
       analogWrite(LM2,0);
       analogWrite(RM1,100);
       analogWrite(RM2,0);
      }
  }
  }
  
}
