int in1=2,
    in2=3,
    in3=4;

void setup() {
  Serial.begin(9600);
  pinMode(in1,INPUT);
  pinMode(in2,INPUT);
  pinMode(in3,INPUT);
}

void loop() {
  if(digitalRead(in1)==HIGH) Serial.println("port1:True");
  else Serial.println("port1:False");

  if(digitalRead(in2)==HIGH) Serial.println("port2:True");
  else Serial.println("port2:False");

  if(digitalRead(in3)==HIGH) Serial.println("port3:True");
  else Serial.println("port3:False");
  delay(500);
}
