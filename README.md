# Self-Driving Car

### [YouTube Demonstration](https://youtu.be/Xy_YFjEKqgE) 

<h2>Description</h2>
The goal of this project was to create a vehicle that could detect the walls of a path and autonomously steer to correct its trajectory. For the frame, I 3D modelled in SolidWorks and 3D printed a flat bed with motor alignment clips which allowed me to accurately align motors to prevent stalling and power loss. I used 4 yellow TT motors and the plastic wheels that came with them to drive. The motors were controlled by 2 L298N motor controllers each controlling 2 motors. The motor controllers were each powered by a 6V power supply made from 4 AA batteries, and each received control logic PWM signals from a central Arduino Mega 2560, which was powered by a separate 9V battery. The car navigated using distance measurements from 2 HC-SR04 Ultrasonic Sensor Modules mounted on the left and right sides facing outward. I programmed the Arduino Mega 2560 to autonomously navigate using C/C++ programming. Every line of code was written by me. 

<h2>Navigation</h2>
To navigate, the main loop of the Arduino pulses and reads each sensor one at a time. The ultrasonic sensors return the value of the duration of their pulse, so I use this value to calculate distance by multiplying by the speed of sound in air over two. I then check these distances using if statements to see if the car is less than 30cm on either side. If a sensor reads less than 30cm on one side, the car turns left or right to steer away from the wall using left/right turn functions that I wrote. If neither sensor reads less than 30cm then the car defaults to go straight. Because the car struggled to turn left, I added in a fail-safe "pivot" function at less than 17cm from the wall. The pivot function (rightHard, leftHard) would stop all motors, then turn on only the two closest to the wall on for half a second, then go straight for half a second. This allowed the car to stop and pivot away from the wall if it couldn't gradually turn quick enough. 
<br><br>
<h2>Sensors and Electronics Used</h2>

- <b>Arduino Mega 2560</b> 
- <b>2 L298N motor controllers</b>
- <b>2 HC-SR04 Ultrasonic Sensor Module</b>
- <b>8 AA batteries</b>
- <b>1 9V battery</b>
- <b>4 yellow TT motors</b>

<h2>Challenges and Solutions</h2>
One of the main challenges of this project was the turning. My idea was to program a nice gradual turn, so the car didn't have to stop and pivot every time it had to correct slightly, but because the motors I used were cheap and had low torque at 6V, they struggled to differentially steer. I originally had a long, narrow frame with no alignment system. With this design, the car could turn slowly left, but could not turn right at all. The lack of motor alignment also meant I couldn't go less than ≈60% duty cycle on certain motors without them stalling, which meant I had little PWM room to work with to increase my turn speed. So I redesigned the frame to be wider, and I added a guide clip to fit over the front piece on the motors to ensure motor alignment. With those two improvements, the car could turn easier and the wheels also wouldn't randomly stall anymore, but it still turned faster to one side than the other. My theory was that uneven weight distribution and traction was causing this, so I rearranged the electronics on top to distribute the weight somewhat evenly, and I experimented with removing the rubber treads on the tires to ensure even traction. Experimentation proved that the best tire tread configuration was no treads in the front, and both treads in the back. With this configuration I achieved the best turning so far. However, if the car was pointed at the right wall at more than ≈45 angle of attack, it could not steer left quick enough to avoid it. To solve this, I created a failsafe "pivot" function, that would stop the motors and pivot left before continuing straight. This allowed the car to achieve ≈90% obstacle avoidance success, even at high angles of attack. 
<br>
<p align="center">
Top View: <br>
<img width="450" height="600" alt="top view" src="https://github.com/user-attachments/assets/7d458fb6-489d-4968-beb0-c59ddffeb9ef" /><br>
Side View: <br>
<img width="600" height="450" alt="side view" src="https://github.com/user-attachments/assets/2132d874-540e-4977-9acc-aba075f2ec2d" /><br>
Front View: <br>
<img width="600" height="450" alt="front view" src="https://github.com/user-attachments/assets/300f180d-de6e-457d-8ba4-427485ed7be6" /><br>
Motor alignment clip: <br>
<img width="450" height="600" alt="motor clip" src="https://github.com/user-attachments/assets/296a5f3e-03f7-4030-a8fd-9a082e460702" /> <br>





