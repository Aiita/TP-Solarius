#include <Servo.h>

Servo servoRotation;
Servo servoInclinaison;

int rotation = 0;
int inclinaison = 0;

int moyenneLumHaut;
int moyenneLumBas;
int moyenneLumGauche;
int moyenneLumDroite;

unsigned long temps = 0;

void setup()
{
  servoRotation.attach(11);
  servoInclinaison.attach(9);


}
void loop() {
  temps = millis() + 100;
  while (temps > millis())
  {

    moyenneLumBas  = ( analogRead(A0) + analogRead(A1) ) / 2;
    moyenneLumHaut     = ( analogRead(A2) + analogRead(A3) ) / 2;
    moyenneLumGauche    = ( analogRead(A2) + analogRead(A0) ) / 2;
    moyenneLumDroite   = ( analogRead(A3) + analogRead(A1) ) / 2;

    inclinaison = servoInclinaison.read();
    rotation = servoRotation.read();

    if ((moyenneLumHaut > moyenneLumBas))
      if (inclinaison > 0)
        inclinaison = inclinaison - 1;

    if ((moyenneLumBas > moyenneLumHaut))
      if (inclinaison < 180)
        inclinaison = inclinaison + 1;

    if ((moyenneLumDroite < moyenneLumGauche))
      if (rotation > 0)
        rotation = rotation - 1;

    if ((moyenneLumGauche < moyenneLumDroite))
      if (rotation < 180)
        rotation = rotation + 1;
  }
  servoInclinaison.write(inclinaison);
  servoRotation.write(rotation);
}
