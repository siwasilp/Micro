#define IN1  9
#define IN2  8
#define IN3  7
#define IN4  6
#define ENA  11
#define ENB  10

int xx = 1;
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(115200);
}
void loop() {
  if(xx == 1){
    //เดินหน้า 10 วิ
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(10000);
  analogWrite(ENB, 0);
  analogWrite(ENA, 0);
  delay(1000);

  //เลี้ยวขวา
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
  delay(500);
  analogWrite(ENA, 0);
  delay(1000);

  //เดินหน้า 2 วิ
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(2000);
  analogWrite(ENB, 0);
  analogWrite(ENA, 0);
  delay(1000);
  
  //ถอยหลัง 2 วิ
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(2000);
  analogWrite(ENB, 0);
  analogWrite(ENA, 0);
  delay(1000);

  //เลี้ยวซ้าย
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);
  delay(500);
  analogWrite(ENB, 0);
  delay(1000);

  //เดินหน้า 2 วิ
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(2000);
  analogWrite(ENB, 0);
  analogWrite(ENA, 0);
  delay(1000);
  
  //ถอยหลัง 2 วิ
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(2000);
  analogWrite(ENB, 0);
  analogWrite(ENA, 0);
  delay(1000);

  xx=0;
  }
}
