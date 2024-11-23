#include <AFMotor.h>

// Defining pins
#define lefts 10 // Left IR sensor pin
#define rights 11 // Right IR sensor pin
#define trigPin 8 // Ultrasonic sensor trigger pin
#define echoPin 9 // Ultrasonic sensor echo pin

// Defining motors
AF_DCMotor leftMotor(1, MOTOR12_1KHZ); 
AF_DCMotor rightMotor(2, MOTOR12_1KHZ);

// Variables
const int distanceThreshold = 10; // Distance threshold in cm
long duration;
int distance;

void setup() {
  // Setting the motor speed
  leftMotor.setSpeed(180);
  rightMotor.setSpeed(180);
  
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
    // Stop both motors
    leftMotor.run(RELEASE);
    rightMotor.run(RELEASE);
    Serial.println("Obstacle detected! Stopping...");
  } else {
    // Line follower logic
    if (leftSensorValue <= 350 && rightSensorValue <= 350) {
      // Move forward
      leftMotor.run(FORWARD);
      rightMotor.run(FORWARD);
    } else if (leftSensorValue <= 350 && rightSensorValue > 350) {
      // Turn left
      leftMotor.run(RELEASE);  // Stop the left motor
      rightMotor.run(FORWARD); // Move right motor forward
    } else if (leftSensorValue > 350 && rightSensorValue <= 350) {
      // Turn right
      leftMotor.run(FORWARD);  // Move left motor forward
      rightMotor.run(RELEASE); // Stop the right motor
    } else {
      // Stop
      leftMotor.run(RELEASE);
      rightMotor.run(RELEASE);
    }
  }

  delay(100); // Small delay to stabilize readings
}
