#include <IRremote.h>
int RECV_PIN = 2; 
int led1 = 13;
int itsONled[] = {0,1};
#define code1  19125
 
IRrecv irrecv(RECV_PIN); 
decode_results results;

void setup()
{
  Serial.begin(9600);   
  irrecv.enableIRIn();  
  pinMode(led1, OUTPUT);
}
 
void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
       case code1:
         if(itsONled[1] == 1) {        // if first led is on then
            digitalWrite(led1, LOW);   // turn it off when button is pressed
           itsONled[1] = 0;           // and set its state as off
         } else {                      // else if first led is off
             digitalWrite(led1, HIGH); // turn it on when the button is pressed
           itsONled[1] = 1;          // and set its state as on
         }
          break; 
      }
    Serial.println(value); 
    irrecv.resume(); 
  }
}
