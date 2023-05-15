#include <Servo.h>
#include <Keypad.h>
int flag=0;
Servo ServoMotor;
char* password = "427";  // change the password here, just pick any 3 numbers
int position = 0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//face recognition

int a = 0;
int facepin = 10;

int b =0;
int c= 0;

void setup()
{

ServoMotor.attach(11);
LockedPosition(true);
pinMode(facepin, INPUT);
Serial.begin(9600);

}

void loop()
{
 
  //face 
char key = keypad.getKey();
if (key == '*' || key == '#')
{
  Serial.println("# keypad locked");
position = 0;
LockedPosition(true);
}
if (key == password[position])
{
position ++;
}
if (position == 3)
{
  Serial.println("keypad unlocked");
LockedPosition(false);

}
delay(100);

a = digitalRead(A0);
b = digitalRead(A5);


if (a==1){
  ServoMotor.write(90);
  Serial.println("face unlocked");
  
  delay(8000);
  
  ServoMotor.write(0);
  
}
//esp8266
if(b==1){
  
  ServoMotor.write(0);
  Serial.println("locked by app");
  

}


}



void LockedPosition(int locked)
{
if (locked)
{
ServoMotor.write(0);
}
else
{
ServoMotor.write(90);
}
}
