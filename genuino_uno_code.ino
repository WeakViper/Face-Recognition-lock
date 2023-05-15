


#include "Ultrasonic.h"
Ultrasonic ultrasonic(7);
long RangeInCentimeters;

int smokeA0 = A5;
// Your threshold value
int sensorThres = 400;

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


void setup() {
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
 digitalWrite(8,LOW);
   pinMode(2, OUTPUT);
 digitalWrite(2,HIGH);


}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
   digitalWrite(8,HIGH);
    delay(2000);
    digitalWrite(8 ,LOW);
  }

  RangeInCentimeters= ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print(RangeInCentimeters);//0~400cm
  Serial.println(" cm");
  
  

  if(4 > RangeInCentimeters){
    digitalWrite(8,HIGH);
    Serial.println(" high");
    delay(2000);
    digitalWrite(8, LOW);
    Serial.println("low");
     
  }

}
  
