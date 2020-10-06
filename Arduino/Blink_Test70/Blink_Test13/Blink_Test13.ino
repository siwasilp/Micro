#define SW_BOTTON 15
#define LED_PIP 4
int ch = 1;
int SW = 0;
void setup() {
  pinMode(LED_PIP, OUTPUT);
  pinMode(SW_BOTTON, INPUT);
}
void loop() {
  SW = digitalRead(SW_BOTTON);
  if (SW == LOW && ch == HIGH) {
    while (true) {
      SW = digitalRead(SW_BOTTON);
      digitalWrite(LED_PIP, HIGH);
      if (SW == HIGH) {
        ch = LOW;
        break;
      }
    }
    delay(500);
  } else if (SW == LOW && ch == LOW) {
    while (true) {
      SW = digitalRead(SW_BOTTON);
      digitalWrite(LED_PIP, HIGH);
      delay(200);
      digitalWrite(LED_PIP, LOW);
      delay(200);
      if (SW == HIGH) {
        ch = HIGH;
        break;
      }
    }
    delay(500);
  } else {
    digitalWrite(LED_PIP, LOW);
  }
}
