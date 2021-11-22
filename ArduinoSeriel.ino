void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("O");
  char c = Serial.read();

  if(c == 'N')
  {
    Serial.println("OK");
  }
    String sSeriel = Serial.readStringUntil('\n');
    if(sSeriel == "SOS")
    {
      Serial.println("NON");
    }
  delay(1000);
}