#include <Servo.h>                        // permet de faire appel à la bibliothèque Servo

Servo servorotate;
Servo servoinc;

int capteur_lum1 = 0; // capteur branché sur le port A0
int analog_lum1; // valeur analogique envoyé par le capteur

int capteur_lum2 = 1; // capteur branché sur le port A1
int analog_lum2; // valeur analogique envoyé par le capteur

int capteur_lum3 = 2; // capteur branché sur le port A2
int analog_lum3; // valeur analogique envoyé par le capteur

int capteur_lum4 = 3; // capteur branché sur le port A3
int analog_lum4; // valeur analogique envoyé par le capteur

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // démarrer la liaison série
  servorotate.attach(8);
  servoinc.attach(9);
  pinMode(A0,INPUT_PULLUP); // attache les capteur de luminosité à la bonne pin
  pinMode(A1,INPUT_PULLUP);
}

void loop() {
  analog_lum1 = analogRead(capteur_lum1); // lecture de la valeur analogique, qu'on enregistre dans analog_lum
  Serial.print("Valeur luminosité1 = ");
  
  analog_lum2 = analogRead(capteur_lum2);
  Serial.print("Valeur luminosité2 = ");
  
  analog_lum3 = analogRead(capteur_lum3);
  Serial.print("Valeur luminosité3 = ");
  
  analog_lum4 = analogRead(capteur_lum4);
  Serial.print("Valeur luminosité4 = ");
  
  // put your main code here, to run repeatedly:

}
