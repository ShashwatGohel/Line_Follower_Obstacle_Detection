#include <AFMotor.h>

// Defining pins
#define lefts A0
#define rights A1
#define trigPin A3 // Ultrasonic sensor trigger pin
#define echoPin A2 // Ultrasonic sensor echo pin

// Defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

// Variables
const int distanceThreshold = 10; // Distance threshold in cm
long duration;
int distance;

void setup() {
  // Setting the motor speed
  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor4.setSpeed(180);
  
  // Declaring PIN input types
  pinMode(lefts, INPUT);
  pinMode(rights, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Begin serial communication
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int leftSensorValue = analogRead(lefts);
  int rightSensorValue = analogRead(rights);

  // Ultrasonic sensor distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Print sensor values to the serial monitor
  Serial.print("Left Sensor: ");
  Serial.print(leftSensorValue);
  Serial.print("\tRight Sensor: ");
  Serial.print(rightSensorValue);
  Serial.print("\tDistance: ");
  Serial.println(distance);

  // Obstacle detection Logic
  if (distance <= distanceThreshold) {
    // Stop all motors
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    Serial.println("Obstacle detected! Stopping...");
  } else {
    // Line follower logic
    if (leftSensorValue <= 350 && rightSensorValue <= 350) {
      // Move forward
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    } else if (leftSensorValue <= 350 && rightSensorValue > 350) {
      // Turn left
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
    } else if (leftSensorValue > 350 && rightSensorValue <= 350) {
      // Turn right
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    } else {
      // Stop
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    }
  }

  delay(100); // Small delay to stabilize readings
}