#define LM1 4
#define LM2 5
#define RM1 6
#define RM2 7
#define IR1 9
#define IR2 8

int a=HIGH;
void setup() {
    pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  Serial.begin(9600);


}

void loop() {
      digitalWrite(LM2,HIGH);
      digitalWrite(LM1,LOW);
      digitalWrite(RM2,HIGH);
      digitalWrite(RM1,LOW);
      /*delay(3000);
      digitalWrite(LM2,HIGH);
      digitalWrite(LM1,LOW);
      digitalWrite(RM2,LOW);
      digitalWrite(RM1,LOW);
      delay(3500);
      digitalWrite(LM2,HIGH);
      digitalWrite(LM1,LOW);
      digitalWrite(RM2,HIGH);
      digitalWrite(RM1,LOW);
      delay(2000);
      digitalWrite(LM1,HIGH);
      digitalWrite(LM2,LOW);
      digitalWrite(RM1,LOW);
      digitalWrite(RM2,HIGH);
      delay(1250);
      digitalWrite(LM1,HIGH);
      digitalWrite(LM2,LOW);
      digitalWrite(RM1,HIGH);
      digitalWrite(RM2,LOW);
      delay(2000);*/
   while(digitalRead(IR1)|| digitalRead(IR2))
   {digitalWrite(LM2,LOW);
      digitalWrite(LM1,LOW);
      digitalWrite(RM2,LOW);
      digitalWrite(RM1,LOW);
    if(!(digitalRead(IR1)&& digitalRead(IR2))){
      while(digitalRead(IR1)&&!(digitalRead(IR2)))
      {
      digitalWrite(LM2,HIGH);
      digitalWrite(LM1,LOW);
      digitalWrite(RM2,LOW);
      digitalWrite(RM1,HIGH);
      }
     while(digitalRead(IR2)&&!(digitalRead(IR1)))
      {
      digitalWrite(LM2,LOW);
      digitalWrite(LM1,HIGH);
      digitalWrite(RM2,HIGH);
      digitalWrite(RM1,LOW );
      }
      }
      else
      {while(digitalRead(IR1)|| digitalRead(IR2))
      {
      digitalWrite(LM2,HIGH);
      digitalWrite(LM1,LOW);
      digitalWrite(RM2,LOW);
      digitalWrite(RM1,HIGH);
      }
      while(digitalRead(IR2))
      {
      digitalWrite(LM2,LOW);
      digitalWrite(LM1,HIGH);
      digitalWrite(RM2,HIGH);
      digitalWrite(RM1,LOW );
      }}
   }
  
      
}
