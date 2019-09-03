/*defining inputs*/
#define IR1 9
#define IR2 8
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
/*defining outputs*/
#define LM1 3
#define LM2 5
#define RM1 6
#define RM2 10
void setup() 
{
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);         // include pin s3 also as output
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
  char ent[10];
  printf("Enter the color code:");      // there is no point in using printf and gets on an arduino as there is no standard output 
  gets(ent);                            // device. Read about Serial communication and use that
  printf("%s",ent);
  /*Red*/
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequency1 = pulseIn(sensorOut,LOW);
  redcolor = map(frequency1,0,0,255,0); // both high and low values cannot be 0. let low value be 0, place the colour sensor on 
  /*Blue*/                              // a bright red surface and get the corresponding high value.Same for blue and green
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  frequency2 = pulseIn(sensorOut,LOW);
  bluecolor = map(frequency2,0,0,255,0);
  /*Green*/
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  frequency3 = pulseIn(sensorOut,LOW);
  greencolor = map(frequency3,0,0,255,0);

  abc: num=int(ent[x]);                 // Dont use labels and goto statements in a C or C++ program. They are a bad method of programming
  if(num==1)                            // Use Loops instead of goto
  {
    if(redcolor>greencolor && redcolor>bluecolor)   // This code has logical errors in it, try to figure it out. 
    {                                               // Also, why not use just one IR and one color sensor, and from the path
      motion=1;                                     // one of the side strips that are black can be removed. That would be better.
    }                                               // The logic has been complicated, try to simplify it after correcting logical errors
  }
  if(num==2)
  {
    if(bluecolor>greencolor && bluecolor>redcolor)
    {
      motion=1;
    }
  }
  while(digitalRead(IR1) || digitalRead(IR2))
  {
    if(digitalRead(IR1) && digitalRead(IR2))
    {
      analogWrite(LM1,100);
      analogWrite(LM2,0);
      analogWrite(RM1,100);
      analogWrite(RM2,100);
    }
    
    else if(!digitalRead(IR1) && digitalRead(IR2))
    {
      analogWrite(LM1,0);
      analogWrite(LM2,0);
      analogWrite(RM1,100);
      analogWrite(RM2,0);
      
     }
     else if(!digitalRead(IR2) && digitalRead(IR1))
     {
      analogWrite(LM1,100);
      analogWrite(LM2,0);
      analogWrite(RM1,0);
      analogWrite(RM2,0);
     }
  }
  /*At a junction*/
  if(!(digitalRead(IR1)&&digitalRead(IR2)))
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
  while(motion==0)
  {
      analogWrite(LM1,100);
      analogWrite(LM2,0);
      analogWrite(RM1,0);
      analogWrite(RM2,100);
  }
  x++;
  goto abc;
  
}
