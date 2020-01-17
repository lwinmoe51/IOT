const int coin = 2;
boolean insert = false;
volatile int pulse = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), coinInterrupt, RISING);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (insert) {
    insert = false;
    Serial.println("coin detected!");
    delay(1000);
  }
}

//interrupt
void coinInterrupt() {
  pulse++ ;
  insert = true;
}
