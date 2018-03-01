void setup() {

Serial.begin(9600); // Initializing serial input (9600 is the standard)

//Motor #1:
pinMode(12, OUTPUT); // Direction of Motor #1
pinMode(3, OUTPUT); // PWM pin for Motor #1
pinMode(9, OUTPUT); // Brake for Motor #1

//Motor #2:
pinMode(13, OUTPUT); // Direction of Motor #2
pinMode(11, OUTPUT); // PWM pin for Motor #2
pinMode(8, OUTPUT); // Brake for Motor #2

Serial.println("Please enter a value for speed (has to be between 40 & 155)"); // (Range from 40 - 150)
}

void loop() {

if(Serial.available() > 0) { // only run the program if there inputs are entered
int input = Serial.readString().toInt();

//Motor #1:
digitalWrite(12, HIGH); // Direction of Motor#1
digitalWrite(9, LOW); // Brake for Motor#1 -> LOW means off/HIGH means on
analogWrite(3, input); // Speed that Motor#1 runs at

//Motor#2:
digitalWrite(13, LOW); // Direction opposite of Motor#1
digitalWrite(8, LOW); // Brake for Motor#2 -> LOW means off/HIGH means on
analogWrite(11, input); // Speed that Motor#2 runs at (has to be same as Motor#1)

delay(6900); // Delay for 6.9s -> value doesn't matter

//Activation of Brakes after Motor Activation:
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
  }
}
