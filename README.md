# AutoSync-ACCwithOTA
"AutoSync: Adaptive Cruise Control with FOTA" combines the benefits of Adaptive Cruise Control (ACC) and Flash Over the Air (FOTA) technology. It involves developing a cruise control system that can adjust the vehicle's speed and maintain a safe distance from the vehicle ahead (ACC) while incorporating wireless updates for the car system (FOTA).

There are 3 modes of operation for Cruise Control: the Cruise Control is off, Normal Cruise Control, and Adaptive Cruise Control.

If the Cruise Control is off, the car is at a constant speed.
In Normal Cruise Control mode, the driver gets to choose a speed to stay on. Using the FOTA feature we update the car system to add the Collision Avoidance feature with the Normal Cruise Control.
As for the Adaptive Cruise Control, the car uses an ultrasonic sensor that constantly measures the distance between it and the car ahead. According to this distance, the car speed is controlled (by changing the PWM of the STM timer) so it avoids colliding with the car ahead.
