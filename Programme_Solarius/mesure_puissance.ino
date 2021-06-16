float voltage = 0;
float power = 0;
float resistance = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
  resistance = 12,5;
}

void loop() {
  // put your main code here, to run repeatedly:
  voltage = analogRead(A0);
  voltage = (voltage * 5) / 1023;
  power = (voltage * voltage) / resistance;
  Serial.println(voltage);
}
