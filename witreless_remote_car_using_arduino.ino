#include <SoftwareSerial.h>
SoftwareSerial BT(A1, A0); //TX, RX respetively
String readvoice;
int move_forward=0;
void setup() 
{
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void forward()
{
  move_forward=1;
  digitalWrite(2, HIGH);
  digitalWrite (3, LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}

void back()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5,HIGH); 
}

void right()
{
  digitalWrite (2,HIGH);
  digitalWrite (3,LOW);
  digitalWrite (4,LOW);
  digitalWrite (5,HIGH);
}


void left()
{
  digitalWrite (2, LOW);
  digitalWrite (3, HIGH);
  digitalWrite (4, HIGH);
  digitalWrite (5, LOW);  
}

void mstop()
{
  digitalWrite (2, LOW);
  digitalWrite (3, LOW);
  digitalWrite (4, LOW);
  digitalWrite (5, LOW);
}
//-----------------------------------------------------------------------//  
void loop() 
{
  while (BT.available())
  {  //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable 
    char c = BT.read(); //Conduct a serial read
    readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  }  

  if (readvoice.length() > 0) 
  {
    Serial.println(readvoice); 

    if(readvoice == "forward") 
    {
     forward();;
     delay (5000);
     mstop();
     delay (100);
    }
  
    else if(readvoice == "backward") 
    {
      back();
      delay (3000);
     mstop();
     delay (100);
    }
    else if (readvoice == "right")
    {
      right();
      delay (500);
     mstop();
     delay (100);
    }
    else if ( readvoice == "left")
    {
      left();
      delay (500);
      mstop();
     delay (100);
    }
    else if (readvoice == "stop")
    {
      mstop();
      delay (100);
    }
  }
    readvoice="";
  
}
