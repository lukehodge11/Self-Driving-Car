int in1 = 39; //motor controller pins
int in2 = 37; //motor controller pins
int in3 = 35; //motor controller pins
int in4 = 33; //motor controller pins
int rmf = 6; //right front motor pwm
int lmf = 5; // left front motor pwm
int in01 = 53; //motor controller pins
int in02 = 51; //motor controller pins
int in03 = 49; //motor controller pins
int in04 = 47; //motor controller pins
int lmb = 2; // left back motor pwm
int rmb = 3; // right back motor pwm
int trigl = 26; //left ultrasonic sensor
int echol = 27; //left ultrasonic sensor
int trigr = 24; //right ultrasonic sensor
int echor = 25; //right ultrasonic sensor
long durationl, durationr;  //variables for duration
int distancel, distancer; // variables for distance

void straight(void); //function prototypes
void left(void); //function prototypes
void right(void); //function prototypes
void stop(void); //function prototypes
void leftHard(void); //function prototypes
void rightHard(void); //function prototypes

void setup() {
  pinMode(rmf, OUTPUT); //set motor controller pins as outputs
  pinMode(in1, OUTPUT); //set motor controller pins as outputs
  pinMode(in2, OUTPUT); //set motor controller pins as outputs
  pinMode(lmf, OUTPUT); //set motor controller pins as outputs
  pinMode(in3, OUTPUT); //set motor controller pins as outputs
  pinMode(in4, OUTPUT); //set motor controller pins as outputs
  pinMode(lmb, OUTPUT); //set motor controller pins as outputs
  pinMode(in01, OUTPUT); //set motor controller pins as outputs
  pinMode(in02, OUTPUT); //set motor controller pins as outputs
  pinMode(rmb, OUTPUT); //set motor controller pins as outputs
  pinMode(in03, OUTPUT); //set motor controller pins as outputs
  pinMode(in04, OUTPUT); //set motor controller pins as outputs
  pinMode(trigl, OUTPUT); //ultrasonic sensor trig as output
  pinMode(echol, INPUT); // echo as input
  pinMode(trigr, OUTPUT); //ultrasonic sensor trig as output
  pinMode(echor, INPUT); // echo as input

  digitalWrite(in1, LOW); // set motor directions
  digitalWrite(in2, HIGH); // set motor directions
  digitalWrite(in3, LOW); // set motor directions
  digitalWrite(in4, HIGH); // set motor directions

  digitalWrite(in01, HIGH); // set motor directions
  digitalWrite(in02, LOW); // set motor directions
  digitalWrite(in03, LOW); // set motor directions
  digitalWrite(in04, HIGH); // set motor directions

  stop(); //start with all motors at low

 
}

void loop() {
  digitalWrite(trigl, LOW); //set trig to low
  delayMicroseconds(2); // for 2 microseconds
  digitalWrite(trigl, HIGH);//set to high 
  delayMicroseconds(10); //for 10 microseconds
  durationl = pulseIn(echol, HIGH); //read duration
  distancel = (durationl * .034) / 2; // calculate the distance by multiplying duration by speed of sound in air over 2
  delay(50); //delay 50 ms

  digitalWrite(trigr, LOW);//set trig to low
  delayMicroseconds(2);// for 2 microseconds
  digitalWrite(trigr, HIGH);//set to high
  delayMicroseconds(10);//for 10 microseconds
  durationr = pulseIn(echor, HIGH); // read the duration and assign it to duration variable
  distancer = (durationr * .034) / 2;// calculate the distance by multiplying duration by speed of sound in air over 2


  if(distancel < 30) // if the distance from the wall on the left is less than 25 centimeres
    right(); // go right
  else if(distancer < 30) // if the distance from the wall on the right is less than 25 centimeters
    left(); // go left
  else straight(); // else go straight

  if(distancer < 17 && distancer != 0) //if the distance is less than 15 cm (excluding 0 for startup values)
    leftHard(); // pivot hard left
  if(distancel < 17 && distancel != 0)//if the distance is less than 15 cm (excluding 0 for startup values)
    rightHard(); // pivot hard right
}


void straight(void) // go straight
{
  analogWrite(lmf, 127); //all motors at half duty cycle
  analogWrite(rmf, 127);//all motors at half duty cycle
  
  analogWrite(lmb, 127);//all motors at half duty cycle
  analogWrite(rmb, 127);  //all motors at half duty cycle
  delay(300); // for half a second
}

void left(void) // go left
{
  analogWrite(lmf, 100); //left motors at 100 pwm
  analogWrite(rmf, 255); // right motors at max pwm
  
  analogWrite(lmb, 100);  // left motors at 100 pwm
  analogWrite(rmb, 255);  // right motors at max pwm
  delay(300); // for half a second
}

void right(void) // go right
{
  analogWrite(lmf, 255); // left motors at max pwm
  analogWrite(rmf, 100); // right motors at 100 pwm
  
  analogWrite(lmb, 255); // left motors at max pwm
  analogWrite(rmb, 100); // right motors at 100 pwm
  delay(300); // for half a second
}

void stop(void) // stop
{
  analogWrite(lmf, 0); // all motors stop
  analogWrite(rmf, 0); // all motors stop
  
  analogWrite(lmb, 0); // all motors stop
  analogWrite(rmb, 0); // all motors stop
  delay(300); // for half a second
}

void leftHard(void) // turn hard left
{
  stop(); // stop for half a second

  analogWrite(lmf, 0); // left motor off
  analogWrite(rmf, 127); // right motor half
  
  analogWrite(lmb, 0); // left motor off
  analogWrite(rmb, 127);   // right motor half
  delay(500); // for half a second

  straight(); // go straight
  delay(500); // for half a second
}

void rightHard(void) //turn hard right
{
  stop(); // stop for half a second

  analogWrite(lmf, 127); // left motor half
  analogWrite(rmf, 0); // right motor off
  
  analogWrite(lmb, 127); // left motor half
  analogWrite(rmb, 0);   // right motor off
  delay(500); // for half a second

  straight(); // go straight
  delay(500); // for half a second
}


