#define motorPinA 11                // can alternatively use digital pins 5 & 6 instead of 10 & 11
#define motorPinB 10          

int Speed = 150;                    // choose speed variable in range [0, 255]

void setup(){
    pinMode(motorPinA, OUTPUT);
    pinMode(motorPinA, OUTPUT);
}

void loop(){
    analogWrite(motorPinA, Speed);  // set one side of the motor to a HIGH PWM signal
    analogWrite(motorPinB, LOW);    // set other side of the motor to LOW (ground) signal
    delay(2000);                    // rotate forward for 2 seconds

    analogWrite(motorPinA, LOW);
    analogWrite(motorPinB, Speed);
    delay(2000);                    // rotate backwards for 2 seconds
}
