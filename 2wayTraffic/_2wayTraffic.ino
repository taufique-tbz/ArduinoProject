// light one
int r1 = 2;
int y1 = 3;
int g1 = 4;

// light two
int r2 = 5;
int y2 = 6;
int g2 = 7;

void setup(){
    // light one
    pinMode(r1, OUTPUT);
    pinMode(y1, OUTPUT);
    pinMode(g1, OUTPUT);

    // light two
    pinMode(r2, OUTPUT);
    pinMode(y2, OUTPUT);
    pinMode(g2, OUTPUT);
}
void loop(){
    changeLights();
    delay(15000);
}
void changeLights(){
    // turn both yellows on
    digitalWrite(g1, LOW);
    digitalWrite(y1, HIGH);
    digitalWrite(y2, HIGH);
    delay(5000);

    // turn both yellows off, and opposite green and red
    digitalWrite(y1, LOW);
    digitalWrite(r1, HIGH);
    digitalWrite(y2, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(g2, HIGH);
    delay(5000);

    // both yellows on again
    digitalWrite(y1, HIGH);
    digitalWrite(y2, HIGH);
    digitalWrite(g2, LOW);
    delay(3000);

    // turn both yellows off, and opposite green and red
    digitalWrite(g1, HIGH);
    digitalWrite(y1, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(y2, LOW);
    digitalWrite(r2, HIGH);
    delay(5000);

}
