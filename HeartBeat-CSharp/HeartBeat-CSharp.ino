byte inputByte_0;
byte inputByte_1;
byte inputByte_2;

double alpha=0.75;
int period=20;
double change=0.0;

void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  analogReference(INTERNAL);
}
void loop() {  
  if (Serial.available()> 2) 
  {
    inputByte_0 = Serial.read();
    delay(10);    
    inputByte_1 = Serial.read();
    delay(10);      
    inputByte_2 = Serial.read();
    delay(10);   
  }
  if(inputByte_0 == 4)
  {       
       switch (inputByte_1) 
       {
          case 8:
             switch (inputByte_2)
            {
              case 16:
                Serial.print("I'M ARDUINO");
                break;
              case 32: 
                  static double oldValue=0;
                  static double oldChange=0;
 
                 int x=analogRead(A0);
                 double value=alpha*oldValue+(1-alpha)*x;
                 change=value-oldValue; 
                 Serial.println(x/10);
                 oldValue=value;
                 oldChange=change;
                 delay(period*10);
                  
                  break;
            }
        } 
        inputByte_0 = 0;
        inputByte_1 = 0;
        inputByte_2 = 0;
  }
}
