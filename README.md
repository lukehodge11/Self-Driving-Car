# Self-Driving Car

### [YouTube Demonstration](https://youtu.be/Xy_YFjEKqgE) 

<h2>Description</h2>
The goal of this project was to create a vehicle that could detect the walls of a path and autonomously steer to correct its trajectory. For the frame, I 3D modelled in SolidWorks and 3D printed a flat bed with motor alignment clips which allowed me to accurately align motors to prevent stalling and power loss. I used 4 yellow TT motors and the plastic wheels that came with them to drive. The motors were controlled by 2 L298N motor controllers each controlling 2 motors. The motor controllers were each powered by a 6V power supply made from 4 AA batteries, and each received control logic PWM signals from a central Arduino Mega 2560, which was powered by a separate 9V battery. The car navigated using distance measurements from 2 HC-SR04 Ultrasonic Sensor Modules mounted on the left and right sides facing outward. I programmed the Arduino Mega 2560 to autonomously navigate using C/C++ programming. Every line of code was written by me. 

<h2>Navigation</h2>
To navigate, the main loop of the Arduino pulses and reads each sensor one at a time. The ultrasonic sensors return the value of the duration of their pulse, so I use this value to calculate distance by multiplying by the speed of sound in air over two. I then check these distances using if statements to see if the car is less than 30cm on either side. If a sensor reads less than 30cm on one side, then the car turns left or right to steer away from the wall using left/right turn functions that I wrote. If neither sensor reads less than 30 then the car defaults to go straight. Because the car struggled to turn left, I added in a fail-safe "pivot" function at less than 17cm from the wall. The pivot function (rightHard, leftHard) would stop all motors, then turn on only the two closest to the wall for half a second, then go straight for half a second. This allowed the car to stop and pivot away from the wall if the gradual turn functions weren't enough. 
<br><br>
<h2>Sensors and Electronics Used</h2>

- <b>Arduino Mega 2560</b> 
- <b>2 L298N motor controllers</b>
- <b>2 HC-SR04 Ultrasonic Sensor Module</b>
- <b>8 AA batteries</b>
- <b>1 9V battery</b>
- <b>4 yellow TT motors</b>

<h2>Challenges and Solutions</h2>
One of the main challenges of this project was the turning. Because the motors I used were cheap and had low torque at 6V, they struggled to differentially steer on certain sides. I originally had a longer, narrower frame with no alignment system. With this design, I could turn the car left very slowly turn left very slowly, but I could not get it to turn right at all except by fully stopping the right side motors. On a slightly uneven floor, the lack of motor alignment meant I couldn't go less than ≈60% duty cycle without the motors stalling. 



