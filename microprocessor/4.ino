#define LDR_PIN 13
void setup() {
  // put your setup code here, to run once:
  pinMode(LDR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Room: ");
  if (digitalRead(LDR_PIN) == LOW){
    Serial.println("light");
  }
  else{
    Serial.println("dark");
  }
  delay(100);
}