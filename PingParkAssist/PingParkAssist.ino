
#define IN4  4
const int trigPin = 2;


long duration;
int distance = 0;
void setup() {
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if ((distance < 50) && (distance > 0))
  {
    digitalWrite(IN4, HIGH);
  }
  else if ((distance > 51) && (distance < 150))
  {
    digitalWrite(IN4, HIGH);
    delay(10 * (distance - 50));
    digitalWrite(IN4, LOW);
    delay(10 * (distance - 50));
  }
  else if ((distance > 151) && (distance < 200)) {
    digitalWrite(IN4, HIGH);
    delay(1000);
    digitalWrite(IN4, LOW);
    delay(1000);
  }
  else if (distance > 200) {
    digitalWrite(IN4, LOW);
  }
  delayMicroseconds(10);

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  pinMode(trigPin, INPUT);
  duration = pulseIn(trigPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
}
