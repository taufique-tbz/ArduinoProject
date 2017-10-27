#include <Servo.h>

#include <IRremote.h>
 
int RECV_PIN = 2; // the pin where you connect the output pin of TSOP4838
int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int led6 = 8;
int led7 = 9;
int led8 = 10;
int led9 = 11;
int itsONled[] = {0,0,0,0,0,0,0,0,0,0};
/* the initial state of LEDs is OFF (zero) 
the first zero must remain zero but you can 
change the others to 1's if you want a certain
led to light when the board is powered */
#define code1  2295 // code received from button 1
#define code2  34935 // code received from button 2
#define code3  18615 // code received from button 3
#define code4  10455 // code received from button 4
#define code5  43095 // code received from button 5
#define code6  26775 // code received from button 6
#define code7  6375 // code received from button 7
#define code8  39015 // code received from button 8
#define code9  22695 // code received from button 9
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;

Servo servoMain; // Define our Servo

void setup()
{
  servoMain.attach(12); // servo on digital pin 10
  Serial.begin(9600);   // you can comment this line
  irrecv.enableIRIn();  // Start the receiver
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);  
}
 
void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
       case code1:
         if(itsONled[1] == 1) {        // if first led is on then
            digitalWrite(led1, LOW);   // turn it off when button is pressed
            servoMain.write(45);  // Turn Servo Left to 45 degrees 
           itsONled[1] = 0;           // and set its state as off
         } else {                      // else if first led is off
             digitalWrite(led1, HIGH); // turn it on when the button is pressed
            servoMain.write(90);  // Turn Servo Left to 45 degrees  
           itsONled[1] = 1;          // and set its state as on
         }
          break; 
       case code2:
         if(itsONled[2] == 1) {
            digitalWrite(led2, LOW);
            itsONled[2] = 0;
         } else {
             digitalWrite(led2, HIGH);
                          itsONled[2] = 1;
         }
          break;
       case code3:
         if(itsONled[3] == 1) {
            digitalWrite(led3, LOW);
            itsONled[3] = 0;
         } else {
             digitalWrite(led3, HIGH);
             itsONled[3] = 1;
         }
          break;
       case code4:
         if(itsONled[4] == 1) {
            digitalWrite(led4, LOW);
            itsONled[4] = 0;
         } else {
             digitalWrite(led4, HIGH);
             itsONled[4] = 1;
         }
          break;  
     case code5:
         if(itsONled[5] == 1) {
            digitalWrite(led5, LOW);
            itsONled[5] = 0;
         } else {
             digitalWrite(led5, HIGH);
             itsONled[5] = 1;
         }
          break;   
     case code6:
         if(itsONled[6] == 1) {
            digitalWrite(led6, LOW);
            itsONled[6] = 0;
         } else {
             digitalWrite(led6, HIGH);
             itsONled[6] = 1;
         }
          break;        
       case code7:
         if(itsONled[7] == 1) {
            digitalWrite(led7, LOW);
            itsONled[7] = 0;
         } else {
             digitalWrite(led7, HIGH);
             itsONled[7] = 1;
         }
          break;  
     case code8:
         if(itsONled[8] == 1) {
            digitalWrite(led8, LOW);
            itsONled[8] = 0;
         } else {
             digitalWrite(led8, HIGH);
             itsONled[8] = 1;
         }
          break;   
     case code9:
         if(itsONled[9] == 1) {
            digitalWrite(led9, LOW);
            itsONled[9] = 0;
         } else {
             digitalWrite(led9, HIGH);
             itsONled[9] = 1;
         }
          break;        

      }
    Serial.println(value); // you can comment this line
    irrecv.resume(); // Receive the next value
  }
}
