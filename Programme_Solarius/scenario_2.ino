#include <Servo.h>

Servo rotationServo;
Servo inclinaisonServo;

#define rotationServoPin 9
#define inclinaisonServoPin 10
#define lumHautGauchePin A0
#define lumHautDroitePin A1
#define lumBasGauchePin A2
#define lumBasDroitePin A3

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
  lumHautGauche = analogRead(lumHautGauche);
  lumHautDroite = analogRead(lumHautDroite);
  lumBasGauche = analogRead(lumBasGauche);
  lumBasDroite = analogRead(lumBasDroite);

  if (lumHautGauche > lumBasGauche
      || lumHautDroite > lumBasDroite)
    ++inclinaison;
  else if (lumHautGauche < lumBasGauche
           || lumHautDroite < lumBasDroite)
    --inclinaison;


  if (lumHautGauche > lumHautDroite
      || lumBasGauche > lumBasDroite)
    ++rotation;
  else if (lumHautGauche < lumHautDroite
           || lumBasGauche < lumBasDroite)
    --rotation;


  rotationServo.write(rotation);
  inclinaisonServo.write(inclinaison);

  delay(500);
}
