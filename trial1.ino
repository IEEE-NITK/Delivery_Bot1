#define s1 10
#define s0 2
#define s2 11
#define s3 12
#define colorOut 13

float r,g,b;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(4,1);
    pinMode(5,1);
  pinMode(6,1);
  pinMode(7,1);

  pinMode(s1,OUTPUT);
  pinMode(s0,OUTPUT);

  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);

  pinMode(colorOut,INPUT_PULLUP);

  digitalWrite(s0,1);
  digitalWrite(s1,1);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(s2,0);
  digitalWrite(s3,0);

  r=2*pulseIn(colorOut,LOW);

  digitalWrite(s2,0);
  digitalWrite(s3,1);

  b=2*pulseIn(colorOut,LOW);

  digitalWrite(s2,1);
  digitalWrite(s3,1);

  g=2*pulseIn(colorOut,LOW);

//  Serial.print("Time Period:   ");
//  Serial.print(r);
//  Serial.print(" ");
//  Serial.print(g);
//  Serial.print(" ");
//  Serial.println(b);
//
//  Serial.println("***********************");
//  Serial.print("Frequency:   ");
//  Serial.print(1/r);
//  Serial.print(" ");
//  Serial.print(1/g);
//  Serial.print(" ");
//  Serial.println(1/b);

  delay(2000);

  r=map(r,15,30,255,0);
  g=map(g,15,30,255,0);
  b=map(b,15,30,255,0);

  Serial.print(r);
  Serial.print(" ");
  Serial.print(g);
  Serial.print(" ");
  Serial.println(b);
//
//  if(b>r && b>g)
//  {
//    digitalWrite(4,0);
//    digitalWrite(5,100);
//    digitalWrite(6,0);
//    digitalWrite(7,100);
//  }
//  else
//  {
//    
//    digitalWrite(5,0);
//    digitalWrite(7,0);
//  }
  
}
