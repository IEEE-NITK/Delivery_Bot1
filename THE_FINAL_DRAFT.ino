#define s1 10
#define s0 2
#define s2 11
#define s3 12
#define colorOut 13
#define LM1 3
#define LM2 5
#define RM1 6
#define RM2 9
#define IR 9
#define LED 4
#define LED1 8
float r,g,b;
int i=0;
int n;
char input[10];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s0,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(colorOut,INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
  digitalWrite(s0,1);
  digitalWrite(s1,1);

}






                                             //READ
void read2()
{int sumr=0;
  int sumb=0;
  int sumg=0;
  int n=100;
 for(int j=0;j<n;j++)
 {//red
  digitalWrite(s2,0);
  digitalWrite(s3,0);
  r=2*pulseIn(colorOut,LOW);
  //blue
  digitalWrite(s2,0);
  digitalWrite(s3,1);
  b=2*pulseIn(colorOut,LOW);
  //green
  digitalWrite(s2,1);
  digitalWrite(s3,1);
  g=2*pulseIn(colorOut,LOW);
  //mapping
   sumr+=r;
  sumb+=b;
  sumg+=g;}
  r=sumr/n;
 b=sumb/n;
 g=sumg/n;
 }




                                                   //REDCHECK
int redcheck()
{while(1)
{ read2();
  
  if(r<=15&&r>=10&&g>42&&g<=55)
  {
    digitalWrite(LED, HIGH);
    return 1;
   // digitalWrite(LED1, LOW);
  }
  else
  {
        digitalWrite(LED, LOW);
        return 0;
  }
  // printing stuff
  printit();
  
 }}







                                                  //BLUECHECK
int bluecheck()
{while(1)
{ read2();
  
  if(r>50&&r<75)
  {
    digitalWrite(LED, HIGH);
    return 1;
   // digitalWrite(LED1, LOW);
  }
  else
  {
        digitalWrite(LED, LOW);
        return 0;
  }
  // printing stuff
  printit();  
      }
   }









                                                 //GREENCHECK
int greencheck()
{                                
while(1)
{read2();

if(g>28&&g<38&&b>38&&b<47&&r>30&&r<40)
  {
    digitalWrite(LED, HIGH);
    return 1;
   // digitalWrite(LED1, LOW);
  }
  else
  {
        digitalWrite(LED, LOW);
        return 0;
  }
  // printing stuff
  printit();
  
 
      }}






  
                                                   //FORWARD
void forward()
{   analogWrite(LM2,150);
    analogWrite(LM1,0);
    analogWrite(RM2,150);
    analogWrite(RM1,0);  
  }
            






                                                   //LEFT
void left()
{   analogWrite(LM2,0);
    analogWrite(LM1,150);
    analogWrite(RM2,150);
    analogWrite(RM1,0);
  }








                                                   //RIGHT
void right()
{   analogWrite(LM2,150);
    analogWrite(LM1,0);
    analogWrite(RM2,0);
    analogWrite(RM1,150);
  }                  









                                                     //HALT
void halt()
{   analogWrite(LM2,0);
    analogWrite(LM1,0);
    analogWrite(RM2,0);
    analogWrite(RM1,0);

  }








                                                    //PRINT
void printit()
{ Serial.print(r);
  Serial.print(" ");
  Serial.print(g);
  Serial.print(" ");
  Serial.println(b);
  }

                                                 // BLUE FOLLOW
void bluefollow() 
{
  while(1)
  { read2();
 
  if(r>=50&&r<=80)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
        digitalWrite(LED, LOW);
  }
  // printing stuff
  printit();
  
   if(r>=50&&r<=80)
   {forward();}
    
    else if(r<30&&g<30)            
    {left();}

    else if(r>80)              
    {right();}
  
    else if(r<30&&g>=40)
    {halt();
    return;}
    }
    }








                                             // GREEN FOLLOW

void greenfollow()
{while(1)
{ read2();

  if(b>30&&g<40)
  {
    digitalWrite(LED, HIGH);
  }
  else
   {
        digitalWrite(LED, LOW);
  }
  // printing stuff
  printit();
  
 if(b>30&&g<40)
  {forward();}
    
    else if(b<30)
     {left();}
    
    else if(r>45)
    {right();}

    else if(r<45&&g>45)
    {halt();
    return; 
    }}}






                  
                                              //RED FOLLOW

void redfollow()
{while(1)
{ read2();

if(redcheck())
  {
    digitalWrite(LED, HIGH);
   // digitalWrite(LED1, LOW);
  }
  else
  {
        digitalWrite(LED, LOW);
  }
  // printing stuff
  printit();
  
    if(r>=10&&r<20)
    {forward();}
    
    else if(g>52)
    {right();}
    
    else if(g<40)
    {left();}
    
    else if(r>=28)
    {halt();
    return;}
      
      }
   }







                                        // JUNCTION
void junction(){
  while(1){
  read2();
  
  if(r>20&&r<=32)
  {
    digitalWrite(LED1, HIGH);
  }
  else
   {
        digitalWrite(LED1, LOW);
  }
  // printing stuff
  printit();
   
  if(r>20&&r<=32)
    {analogWrite(LM2,100);
    analogWrite(LM1,0);
    analogWrite(RM2,100);
    analogWrite(RM1,0);
  }
    
   else
    {halt();
    return;
    }
}
}







                                                   //FOLLOW
void follow(char colour)
{    
  while(1)
{
  if(colour=='R')
  {
 //   redfollow();
    return;
    }
   else if(colour=='G')
  {greenfollow();
    return;
    }
   else if(colour=='B')
  { bluefollow();  
    return;
    }
printit();
  
}}
                                 
                         
                                                  //ROTATE
void rotate(char colour)
{ 
    forward();
    delay(200);
     halt();
      analogWrite(LM2,0);
    analogWrite(LM1,100);
    analogWrite(RM2,100);
    analogWrite(RM1,0);  
    
  while(1)
{
  if(colour=='R')
  {if(redcheck())
  {halt();  
    return;
    }
   }
   
   else if(colour=='G')
   {if(greencheck())
  {halt();  
    return;
    }
    }
   
   else if(colour=='B')
   {if(bluecheck())
  {halt();  
    return;
    }
  }
   
  
 
 
  // printing stuff
  printit();
  
}
}

                                                      //MAIN LOOP
void loop() {
  if(i==0)
  {
  input[0]={'R'};
  redfollow();
  n=strlen(input);
  for(i=0;i<n;i++)
  { junction();
    Serial.println("*****************************************************************************************************************");
    rotate('R');
    Serial.println("*****************************************************************************************************************");
    follow(input[i]);
  }
  }
  }
  
