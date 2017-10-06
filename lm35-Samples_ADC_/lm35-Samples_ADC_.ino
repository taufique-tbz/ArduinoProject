int tempPin=1;

void setup() {
Serial.begin(9600);
pinMode(tempPin,INPUT);
}

void loop() {
float samples=analogRead(tempPin);
Serial.println(samples);
delay(5000);
}
