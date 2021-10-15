#define IRsensor A0
int IRvalue = 0;                      // variable to store the reading from the sensor

void setup(){
  Serial.begin(9600);                 // set speed at which Arduino board will comminucate with computer
  pinMode(IRsensor, INPUT);           // setup infrared sensor as an input 
}

void loop(){
  IRvalue = digitalRead(IRsensor);    // measure and record input signal
  Serial.println(IRvalue);            // print out the measured value
  delay(100);                         // delay 0.1 seconds 
}
