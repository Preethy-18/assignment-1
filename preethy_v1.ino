// C++ code
float temp;
float vout;
float vout1;
int led1=13;
int gasSensor;
int piezo=7;
//
void setup()
{
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(piezo,OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  vout=analogRead(A1);
  vout1=(vout/1023)*5000;
  temp=(vout-500)*10;
  
  gasSensor=analogRead(A0);
  
  if (temp>80)
  {
    digitalWrite(led1,HIGH);
    Serial.println("it's hot");
  }
  else if(temp<30)
  {
    digitalWrite(led1,LOW);
    Serial.println("it's cold");
  }
  if (gasSensor>=100)
  {
    digitalWrite(piezo,HIGH);
  }
  else
  {
    digitalWrite(piezo,LOW);
  }
  Serial.print("in degreeC=");
  Serial.print("");
  Serial.print(temp);
  Serial.print("/t");
  Serial.print("gasSensor=");
  Serial.print(" ");
  Serial.print(gasSensor);
  Serial.println();
  delay(1000);
}
  