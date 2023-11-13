# AutoSync-ACCwithOTA
"AutoSync: Adaptive Cruise Control with FOTA" combines the benefits of Adaptive Cruise Control (ACC) and Flash Over the Air (FOTA) technology. It involves developing a cruise control system that can adjust the vehicle's speed and maintain a safe distance from the vehicle ahead (ACC) while incorporating wireless updates for the car system (FOTA).

There are 3 modes of operation for Cruise Control: the Cruise Control is off, Normal Cruise Control, and Adaptive Cruise Control.

If the Cruise Control is off, the car is at a constant speed.
In Normal Cruise Control mode, the driver gets to choose a speed to stay on. Using the FOTA feature we update the car system to add the Collision Avoidance feature with the Normal Cruise Control.
As for the Adaptive Cruise Control, the car uses an ultrasonic sensor that constantly measures the distance between it and the car ahead. According to this distance, the car speed is controlled (by changing the PWM of the STM timer) so it avoids colliding with the car ahead.

For the FOTA feature, we created a simple website where we can upload our .hex file which is the firmware we want to update.
![image](https://github.com/nadinfromc137/AutoSync-ACCwithFOTA/assets/44551861/2ba8d7a9-1dc1-47da-8c2f-0bdfcca8a001)

After the user clicks upload, the hex file is uploaded to a server, which is detected by the Raspberry Pi microcontroller and fetched to be uploaded.
