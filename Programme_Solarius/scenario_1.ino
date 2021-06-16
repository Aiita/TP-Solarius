#include <Servo.h>

Servo rotationServo;
Servo inclinaisonServo;

#define rotationServoPin 9
#define inclinaisonServoPin 10

float rotation = 0;
float inclinaison = 0;

void setup() {
  rotationServo.attach(rotationServoPin);
  inclinaisonServo.attach(inclinaisonServoPin);
}
void loop() {
  
  for (rotation = 0; rotation <= 180; ++rotation)
  {
    rotationServo.write(rotation);
    
    inclinaison = (float)sin(rotation*DEG_TO_RAD);
    inclinaisonServo.write((int)inclinaison);
    
    delay(500);
  }

  for (rotation = 180; rotation >= 0; --rotation)
  {
    rotationServo.write(rotation);
    
    inclinaison = (float)sin(rotation*DEG_TO_RAD);
    inclinaisonServo.write((int)inclinaison);
    
    delay(500);
  }
}
