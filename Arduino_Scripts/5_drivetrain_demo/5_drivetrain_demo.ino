#define motor1A 11 
#define motor1B 10 
#define motor2A 6 
#define motor2B 5 

int Speed = 150;            // choose speed variable in range [0, 255]

int turn_subtract = 25;     // experiment with different values here
int turn_add = 25;

void setup(){
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop(){
  driveForward(Speed);
  delay(2000);
  driveBackward(Speed);
  delay(2000);
  turnRight(Speed);
  delay(2000);
  turnLeft(Speed);
  delay(2000);
  driveStop();
  delay(2000);
}

void driveForward(int Spd){
  analogWrite(motor1A, Spd);   
  analogWrite(motor1B, LOW);
  analogWrite(motor2A, Spd);
  analogWrite(motor2B, LOW);
}

void driveBackward(int Spd){
  analogWrite(motor1A, LOW);   
  analogWrite(motor1B, Spd);
  analogWrite(motor2A, LOW);
  analogWrite(motor2B, Spd);
}

void driveStop(){
  analogWrite(motor1A, LOW);
  analogWrite(motor1B, LOW);
  analogWrite(motor2A, LOW);
  analogWrite(motor2B, LOW);
}

void turnLeft(int Spd){
  analogWrite(motor1A, Spd+turn_add);
  analogWrite(motor1B, LOW);
  analogWrite(motor2A, LOW);
  analogWrite(motor2B, Spd-turn_subtract);
}

void turnRight(int Spd){
  analogWrite(motor1A, LOW);
  analogWrite(motor1B, Spd-turn_subtract);
  analogWrite(motor2A, Spd+turn_add);
  analogWrite(motor2B, LOW);
}
