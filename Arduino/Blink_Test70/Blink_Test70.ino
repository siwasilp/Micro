#define LED_RD  15
#define LED_YW  2
#define LED_GRN 4
#define LED_BL 5

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BL, OUTPUT);
  pinMode(LED_RD, OUTPUT);
  pinMode(LED_YW, OUTPUT);
  pinMode(LED_GRN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_RD, HIGH);   
  delay(200);                       
  digitalWrite(LED_RD, LOW);    
  delay(200);
  
  digitalWrite(LED_YW, HIGH);   
  delay(200);                       
  digitalWrite(LED_YW, LOW);    
  delay(200);
  
  digitalWrite(LED_GRN, HIGH);   
  delay(200);                       
  digitalWrite(LED_GRN, LOW);    
  delay(200);
  
  digitalWrite(LED_BL, HIGH);   
  delay(200);                       
  digitalWrite(LED_BL, LOW);    
  delay(200);
}















