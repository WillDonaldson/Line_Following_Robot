#define motorPinA 11                // can alternatively use digital pins 5 & 6 instead of 10 & 11
#define motorPinB 10          

int Speed = 150;                    // choose speed variable in range [0, 255]

void setup(){
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
}

void loop(){
  driveForward(Speed);              
  delay(2000);
  driveBackward(Speed);
  delay(2000);
}

void driveForward(int Spd){      
  // creating functions, like driveForward(), store blocks of code  
  // functions make code modular, and easier to scale without needing to repeat lines of code  
  analogWrite(motorPinA, Spd);
  analogWrite(motorPinB, LOW);
}

void driveBackward(int Spd){
  analogWrite(motorPinA, Spd);
  analogWrite(motorPinB, LOW);
}
