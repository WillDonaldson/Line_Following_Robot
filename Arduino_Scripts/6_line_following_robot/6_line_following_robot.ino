#define motor1A 11 
#define motor1B 10 
#define motor2A 6 
#define motor2B 5 

#define IRright A1
#define IRleft A3
int IRright_val = 0;
int IRleft_val = 0;

int Speed = 150;            // choose speed variable in range [0, 255]

int turn_subtract = 25;     // experiment with different values here
int turn_add = 25;

void setup(){
  Serial.begin(9600);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(IRright, INPUT);
  pinMode(IRleft, INPUT);
}

void loop(){
  IRright_val = digitalRead(IRright);
  IRleft_val = digitalRead(IRleft);

  if(IRright_val == HIGH and IRleft_val == HIGH){
    // both sensors over white
    driveForward(Speed);
  }
  if(IRright_val == HIGH and IRleft_val == LOW){
    // left sensor over black
    turnLeft(Speed);
  }
  if(IRright_val == LOW and IRleft_val == HIGH){
    // right sensor over black
    turnRight(Speed);
  }
  if(IRright_val == LOW and IRleft_val == LOW){
    // both sensors over black
    driveStop();
  }
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

void turnRight(int Spd){
  analogWrite(motor1A, Spd+turn_add);
  analogWrite(motor1B, LOW);
  analogWrite(motor2A, LOW);
  analogWrite(motor2B, Spd-turn_subtract);
}

void turnLeft(int Spd){
  analogWrite(motor1A, LOW);
  analogWrite(motor1B, Spd-turn_subtract);
  analogWrite(motor2A, Spd+turn_add);
  analogWrite(motor2B, LOW);
}
