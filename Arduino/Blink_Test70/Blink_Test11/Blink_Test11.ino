#define SW_BOTTON1 15
#define SW_BOTTON2 2
#define LED_D2 4
void setup() {
  pinMode(LED_D2, OUTPUT);
  pinMode(SW_BOTTON1, INPUT);
  pinMode(SW_BOTTON2, INPUT);
}
void loop() {
  int SW1 = digitalRead(SW_BOTTON1);
  int SW2 = digitalRead(SW_BOTTON2);
  if (SW1 == HIGH) {
    digitalWrite(LED_D2, HIGH);
    delay(200);
    digitalWrite(LED_D2, LOW);
    delay(200);
    digitalWrite(LED_D2, HIGH);
    delay(200);
  } 
  else if(SW2 == HIGH) {
    digitalWrite(LED_D2, HIGH);
  }
  else{
    digitalWrite(LED_D2, LOW);
  }
}
