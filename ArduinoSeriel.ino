void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("O");
  char c = Serial.read();

  if(c == 'N')
  {
    Serial.print("OK");
  }
    String sSeriel = Serial.readStringUntil('\n');
    if(sSeriel == "SOS")
    {
      Serial.print("NON");
    }
  delay(1000);
}