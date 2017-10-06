#include <IRremote.h>

int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;



void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(13, OUTPUT);


}
void loop()

{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value); // Print the Serial 'results.value'
    delay(10);
    if (results.value==0xFF6897) {
      digitalWrite(13, HIGH);
    }
    else
      digitalWrite(13, LOW);
    irrecv.resume();   // Receive the next value
  }
}
