void setup() {
  Serial.begin(115200);
}

void loop() {
  for(int i=0;i<6;i++){
    Serial.println("B6004804 นายภูวนาท ต่อชีวี");
  }
  Serial.println("My grade is A");
}
