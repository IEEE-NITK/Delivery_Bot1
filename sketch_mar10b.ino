#define IR1 9

#define S0  2

#define S1  10

#define S2  11

#define S3  12

#define sensorOut 13

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

/*defining outputs*/

#define LM1 4

#define LM2 5

#define RM1 6

#define RM2 7

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

  char ent[10]={1,2};

  /*Red*/

  digitalWrite(S2,LOW);

  digitalWrite(S3,LOW);

  frequency1 = pulseIn(sensorOut,LOW);

  redcolor = map(frequency1,118,126,255,0);       // Check Last programs comment about this

  /*Blue*/

  digitalWrite(S2,LOW);

  digitalWrite(S3,HIGH);

  frequency2 = pulseIn(sensorOut,LOW);

  bluecolor = map(frequency2,139,147,255,0);

  /*Green*/

  digitalWrite(S2,HIGH);

  digitalWrite(S3,HIGH);

  frequency3 = pulseIn(sensorOut,LOW);

  greencolor = map(frequency3,124,133,255,0);



  for(i=0;i<(sizeof(ent)/(sizeof(ent[0])));i++);

  {
  motion=0;
  if(num==1)

  {

    if(redcolor>greencolor && redcolor>bluecolor)

    {

      motion=1; 

    }

  }

  if(num==2)

  {

    if(bluecolor>greencolor && bluecolor>redcolor)

    {

      motion=1;

    }

  }

  while(redcolor>10 && greencolor>10 &&bluecolor>10)

  {

    if(digitalRead(IR1))

    { 

      digitalWrite(LM1,HIGH);

      digitalWrite(LM2,LOW);

      digitalWrite(RM1,HIGH);

      digitalWrite(RM2,LOW);

    }   

    

    else if(!digitalRead(IR1) && motion)

    {

       digitalWrite(LM1,LOW);

      digitalWrite(LM2,LOW);

      digitalWrite(RM1,HIGH);

      digitalWrite(RM2,LOW);
    } 

    

    else if(digitalRead(IR1) && !(motion))

    {

      digitalWrite(LM1,HIGH);

      digitalWrite(LM2,LOW);

      digitalWrite(RM1,LOW);

      digitalWrite(RM2,LOW);

    }

  }

  /*At a junction*/

  if(!(digitalRead(IR1)) && redcolor<10 && bluecolor<10 && greencolor<10)

  {

      startTime=millis();

      while(millis < startTime + 2000)      // Dont use time as it is not very accurate, move forward on the junction as long as both 

      {                                     // Ir and color sensor detects black, and when they dont, exit the loop 

       digitalWrite(LM1,HIGH);

       digitalWrite(LM2,LOW);

       digitalWrite(RM1,HIGH);

       digitalWrite(RM2,LOW);

      }

  }

  while(motion==0)

  {                                          // motion is not made 0 anywhere in the for loop, check this 

      digitalWrite(LM1,HIGH);

      digitalWrite(LM2,LOW);

      digitalWrite(RM1,LOW);

      digitalWrite(RM2,HIGH);

  }

  x++;

  }

  

}
