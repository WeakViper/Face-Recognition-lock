# Face-Recognition-lock
A project developed for the BITS Dubai 2022 challenege using arduinos to create a door lock system based on facial recognition and a mobile application.   
This project used the following componenets: arduino uno, genuino uno, esp32camera, esp8266 wifi-microchip, MQ-2 module, HC-SR04, Microservo, Gyro buzzer.   
A microservo was used to simulate the door here.     
Used the Esp32 camera for facial recognition, if a registered face is recognised, the door is unlocked. With the IP address, it can also be used as a surveillance camera.  
The esp8266 was used in combination with thingspead and an MIT app inventor based application to unlock the door remotely via the MIT application on a mobile device.   
The genuino uno was used to program a doorbell and a gas leak detector. The doorbell was implemented used the HC-SR04 ultrasonic sensor in a non-touch fasion to help reduce the spread of covid. The gas sensor sounds an alarm if it detects a gas leak.   
The arduino uno was the centerpiece for linking both the ESP modules to the rest of the circuit and processing their outputs to have the appropriate affects. It was also used to upload the code and initialize both modules.   

