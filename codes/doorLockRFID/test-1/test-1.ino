#define buzzer 14 //d5
#define relay 12 //d6

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(buzzer, HIGH);
  digitalWrite(relay, LOW);
  delay(2000);
  digitalWrite(buzzer, LOW);
  digitalWrite(relay, HIGH);
  delay(2000);
}
