#include <Servo.h>                        // permet de faire appel à la bibliothèque Servo

Servo servorotate;
Servo servoinc;

int capteur_lum = 0; // capteur branché sur le port 0
int analog_lum; // valeur analogique envoyé par le capteur

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // démarrer la liaison série
  servorotate.attach(8);
  servoinc.attach(9);
  pinMode(A0,INPUT_PULLUP); // attache les potentiomètres à la bonne pin
  pinMode(A1,INPUT_PULLUP);
}

void loop() {
  analog_lum = analogRead(capteur_lum); // lecture de la valeur analogique, qu'on enregistre dans analog_lum
  Serial.print("Valeur luminosité = ");
  Serial.print(analog_lum); 
  Serial.println("");
  delay(1000);
  // put your main code here, to run repeatedly:

}
