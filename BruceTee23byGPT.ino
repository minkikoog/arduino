#include <AFMotor.h>

// Defining pins and variables
#define lefts A0 
#define rights A2

// Defining motors
AF_DCMotor motor2(2, MOTOR12_8KHZ); 
AF_DCMotor motor3(3, MOTOR12_8KHZ);

void setup() {
  // Setting the speed of motors
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  
  // Declaring pin types
  pinMode(lefts, INPUT);
  pinMode(rights, INPUT);
}

void loop(){
  // Reading sensor values
  int leftValue = analogRead(lefts);
  int rightValue = analogRead(rights);
  
  // Decision-making based on sensor values
  if(leftValue <= 400 && rightValue <= 400){
    motor2.run(FORWARD);
    motor3.run(FORWARD);
  }
  else if(leftValue > 400 && rightValue <= 400){
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
  }
  else if(leftValue <= 400 && rightValue > 400){
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
  }
  else if(leftValue > 400 && rightValue > 400){
    motor2.run(RELEASE);
    motor3.run(RELEASE);
  }
}
