# **LineFollower_ObstacleDetection(PathGuard)**

The **Line Follower with Obstacle Detection** is a robotic system designed to autonomously follow a pre-defined path (line) and detect obstacles in its path using sensors. The robot halts upon detecting an obstacle and resumes operation once the path is clear. This project integrates line-following capabilities and obstacle avoidance to create a versatile and efficient robotic system suitable for automation tasks, logistics, and smart industrial applications.

---

## **Features**
- Autonomous line-following capability.
- Real-time obstacle detection and avoidance.
- Efficient motor control for precise movement.
- Compact and modular design suitable for small-scale applications.

---

## **Prerequisites**

### **Software**
- Arduino IDE (version 1.8.13 or later)

### **Libraries or Dependencies**
- IR Sensor Library (if applicable, for line detection).
- Ultrasonic Sensor Library (e.g., NewPing, for obstacle detection).

### **Hardware Requirements**
- Arduino Uno  
- IR sensors (at least 2 for line tracking)  
- Ultrasonic sensor (e.g., HC-SR05 for obstacle detection)  
- Motor Shield  
- DC motors (2 motors)  
- Robot chassis with wheels  
- Power supply (6V-12V battery pack)  
- Jumper wires and breadboard (for connections)  

---

## **Getting Started**

### **Installation**
1. **Clone the Repository**  
   ```bash
   git clone https://github.com/ShashwatGohel/Line_Follower_Obstacle_Detection.git
   cd ARDUINO_LINE_FOLLOWING_CAR

### **How to Run The Code**

   - Connect the hardware components as per the provided circuit diagram.
   - Open the Arduino IDE and upload the provided code to the Arduino Uno board:
   -Open the .ino file in the Arduino IDE.
   - Select the correct Board and Port under the Tools menu.
   - Click on the Upload button.
   - Once uploaded, power the Arduino and observe the system in action:
   - The robot follows the path marked by the line using IR sensors.
   - If an obstacle is detected, the robot stops and resumes movement once the path is clear.
