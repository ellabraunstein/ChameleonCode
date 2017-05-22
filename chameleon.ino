                            /*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservoleft;  // create servo object to control a servo
Servo myservoright;  // create servo object to control a servo


int potpinleft = 0;  //A0YELLOW analog pin used to connect the potentiometer
int potpinright = 1;  // A1GREEN analog pin used to connect the potentiometer
int valleft;    // variable to read the value from the analog pin
int valright;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(9600);
  myservoleft.attach(9);  // BLUEattaches the servo on pin 9 to the servo object
  myservoright.attach(10);  // WHITEattaches the servo on pin 10 to the servo object
}

void loop() {
  valleft = analogRead(potpinleft);            // reads the value of the potentiometer (value between 0 and 1023)
  valright = analogRead(potpinright);            // reads the value of the potentiometer (value between 0 and 1023)
  valleft = map(valleft, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  valright = map(valright, 0, 1023, 0 , 180);     // scale it to use it with the servo (value between 0 and 180)
  Serial.print(valleft);
  Serial.print("_");
  Serial.println(valright);
  myservoleft.write(valleft);                  // sets the servo position according to the scaled value
  myservoright.write(valright);                  // sets the servo position according to the scaled value
// delay(15);                           // waits for the servo to get there
}

