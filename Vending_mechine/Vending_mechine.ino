#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);// rs,en,d4,d5,d6,d7,rw-gnd,
const int buttonPin = 5; 
int buttonState;
const int led =  6;

const int coin = 2;
boolean insert = false;
volatile int pulse = 0;
unsigned long balance =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(buttonPin,INPUT);
  lcd.begin(16, 2);
  attachInterrupt(digitalPinToInterrupt(2), coinInterrupt, RISING);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Please  insert");
  lcd.setCursor(5,1);
  lcd.print("COIN");
  delay(50);
  
  
  if (insert) {
    
    //Serial.println("coin detected!");
    balance = 1000;
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("COIN ACCEPTED");
    lcd.setCursor(1,1);
    lcd.print("Balance :"+(String)balance);
    delay(2000);

    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Please put cup");
    lcd.setCursor(2,1);
    lcd.print("under pipe");
    delay(2000);

    while(buttonState==LOW){
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("READY?");
      lcd.setCursor(1,1);
      lcd.print("Press START");
      buttonState = digitalRead(buttonPin);
      Serial.println("LOW");
      delay(50);
    }
    
    if(buttonState == HIGH){
      Serial.println("HIGH");
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("Adding cola");
        digitalWrite(led,HIGH);
        delay(3000); //time for full cup
        digitalWrite(led,LOW);
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("ENJOY");
        lcd.setCursor(2,1);
        lcd.print("YOUR COLA");
        delay(4000);
        buttonState = LOW;
        Serial.println("LOW");
      }
      insert = false;
      balance = 0;
    }
}

//interrupt
void coinInterrupt() {
  pulse++ ;
  insert = true;
}
