#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

int count = 0;

String number = "";

//ボタンのピン番号
int in1=2,
    in2=3,
    in3=4;

//[構文]LCD(rs,e,d0,d1,d2,d3,d4,d5,d6,d7)
LiquidCrystal lcd(53,52,51,50,49,48,47,46,45,44);
//キーパッド配列
char keys[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[4] = {43,42,41,40};  //ピン番号
byte colPins[4] = {39,38,37,36};
Keypad matKeypad = Keypad(makeKeymap(keys),rowPins,colPins,4,4);
//.getKey()で押されたキーを検出

int stat = 0;

void setup() {
  Serial.begin(9600);
  pinMode(in1,INPUT);
  pinMode(in2,INPUT);
  pinMode(in3,INPUT);

  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Smart Umbrella");
  lcd.setCursor(0,1);
  lcd.print("Stand");
}

void loop() {
  if(count%50==0){
    if(digitalRead(in1)==HIGH) Serial.println("port1:True");
    else Serial.println("port1:False");

    if(digitalRead(in2)==HIGH) Serial.println("port2:True");
    else Serial.println("port2:False");

    if(digitalRead(in3)==HIGH) Serial.println("port3:True");
    else Serial.println("port3:False");
  }

  if(Serial.available()>0 && Serial.readString().compareTo("request")==0){
    stat = 1;
  }
  
  if(stat==1){
    char matKey = matKeypad.getKey();
    if(matKey){
      switch(matKey){
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': 
          number = String(number + matKey);break;
        case 'A':
          Serial.println(String("mat:"+number));
          number = "";
          stat = 0;
          break;
        case 'B':
          number.setCharAt(number.length()-1,'\0');
          break;
        case 'C':
          number = "";
          stat = 0;
          break;
      }
      lcd.clear();
      lcd.print("Please enter a number...");
      lcd.setCursor(0,1);
      lcd.print(number);
    }
  }

  delay(10);
}
