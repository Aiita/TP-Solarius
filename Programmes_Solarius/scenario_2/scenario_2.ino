#include <Servo.h>

Servo rotationServo;
Servo inclinaisonServo;

#define rotationServoPin 11
#define inclinaisonServoPin 9
#define lumHautGauchePin A2
#define lumHautDroitePin A3
#define lumBasGauchePin A0
#define lumBasDroitePin A1

int rotation = 0;
int inclinaison = 0;
int lumHautGauche = 0;
int lumHautDroite = 0;
int lumBasGauche = 0;
int lumBasDroite = 0;

void setup() {
  
  pinMode(lumHautGauchePin ,INPUT);
  pinMode(lumHautDroitePin ,INPUT);
  pinMode(lumBasGauchePin ,INPUT);
  pinMode(lumBasDroitePin ,INPUT);
  
  rotationServo.attach(rotationServoPin);
  inclinaisonServo.attach(inclinaisonServoPin);
}
void loop() {
  lumHautGauche = analogRead(lumHautGauchePin);
  lumHautDroite = analogRead(lumHautDroitePin);
  lumBasGauche = analogRead(lumBasGauchePin);
  lumBasDroite = analogRead(lumBasDroitePin);

  if (lumHautGauche > lumBasGauche
      || lumHautDroite > lumBasDroite)
    --inclinaison;
  else if (lumHautGauche < lumBasGauche
           || lumHautDroite < lumBasDroite)
    ++inclinaison;


  if (lumHautGauche > lumHautDroite
      || lumBasGauche > lumBasDroite)
    ++rotation;
  else if (lumHautGauche < lumHautDroite
           || lumBasGauche < lumBasDroite)
    --rotation;


  rotationServo.write(rotation);
  inclinaisonServo.write(inclinaison);

  delay(50);
}
