int tempPin=1;

void setup() {
Serial.begin(9600);
pinMode(tempPin,INPUT);
}

void loop() {
float samples=analogRead(tempPin);
float analogVoltage=(samples*5)/1024;

float tempC=analogVoltage/0.01;
float tempF=(tempC * 9)/5 + 32; 

Serial.print(tempC);
delay(5000);
}
