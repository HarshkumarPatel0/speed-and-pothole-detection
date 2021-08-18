# Speed-and-Pothole-Detection
In this project, we describe the combination of two different sensors to be able to measure the speed, if the car is over speeding and if there is a pothole on the road. For this we make use of an ultrasonic sensor to detect potholes, two infrared sensors to be able to detect the speed, a piezoelectric buzzer to alert the over speeding, and an Arduino UNO to be able to control de whole system.

![alt text](https://github.com/bihy1234/speed-and-pothole-detection/blob/main/images/IMG_3368.jpg)

![alt text](https://github.com/bihy1234/speed-and-pothole-detection/blob/main/images/IMG_3369.jpg)

# Materials 
The following specific materials are required for the project:

•	Arduino UNO

•	HC-SR04 Ultrasonic Sensor

Additional general materials required:

•	Piezoelectric Buzzer

•	2x IR collision sensors

•	Breadboard

•	Jumper and wires

# Schematic
Schematic for the Speed and Pothole Detector
![alt text](https://github.com/bihy1234/speed-and-pothole-detection/blob/main/Schematic/ARDUINO-Speed-pothole_2020-12-07_14-17-56.png)

Schematic for the Pothile Detector
![alt text](https://github.com/bihy1234/speed-and-pothole-detection/blob/main/Schematic/ARDUINO-pothole_2020-12-07_14-26-16.png)

Schematic for the Speed Detector
![alt text](https://github.com/bihy1234/speed-and-pothole-detection/blob/main/Schematic/ARDUINO-speed_2020-12-07_14-23-06.png)

# Usage
Preliminary setup:

Install all the hardware according the schematics listed above.

Install Arduino IDE.

Compile the code 

Open the Serial Monitor

The code is structured so the Serial Monitor can output the speed when a car passes through the IR sensors, and it will show if there is a pothole ahead. There isn’t anything else to do than make the code run while testing its functionality with a remote controlled car.
It is worth noting how the speed calculation and the pothole detection works, in the case of the speed calculation, the Arduino will get time that the car needed to pass from one IR sensor to another, having the time, and the known distance between the two IR sensors, we are able to calculate the speed with a simple speed formula:

V=m/s

Where V is the speed of the car, m is the distance between the both IR sensors and s is the time that the car took to pass from one IR sensor to another. Have in mind that in case of the car accelerating or deaccelerating between the IR sensors, the Arduino will output the speed as an average of the change of speed. 
As for the pothole detecting, we use the ultrasonic sensor, which sends an ultrasonic wave that will echo or “bounce” back to the sensor, depending on the time taken by the ultrasonic wave to go, and bounce back, the Arduino is able to calculate the distance between the sensor and the object or surface on which the ultrasonic wave bounced back. The formula used to do the calculation is:

m = s*0.34/2

Where m is the distance between an object or surface, and the sensor, and s is the time taken by the ultrasonic wave to go and come back.



# Credits
Muhammad Ansar: for the Car Speed Detector project

Trevor Tomesh: Professor 

Alex Clarke: Lab Co-ordinator
