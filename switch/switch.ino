//int buzzer = 13; //buzzer on 13
//int prPin = 7; //Input for HC-S501
int statIn=21,
    statOut=20,
    
    in1=2,
    in2=3,
    in3=4,

    l1=13,
    l2=12,
    l3=11;

void setup() {
  //pinMode(buzzer,OUTPUT);
  //pinMode(pirPin,INPUT);
  //pinMode(statIn,INPUT);
  //pinMode(statOut,OUTPUT);
  pinMode(in1,INPUT);
  pinMode(in2,INPUT);
  pinMode(in3,INPUT);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
}

void loop() {
  /*if(digitalRead(pirPin)==HIGH){
    digitalWrite(buzzer,HIGH);
    delay(1000);
  }else{
    digitalWrite(buzzer,LOW);
  }*/
  
  if(digitalRead(in1)==HIGH) digitalWrite(l1,HIGH);
  else digitalWrite(l1,LOW);

  if(digitalRead(in2)==HIGH) digitalWrite(l2,HIGH);
  else digitalWrite(l2,LOW);

  if(digitalRead(in3)==HIGH) digitalWrite(l3,HIGH);
  else digitalWrite(l3,LOW);
}
