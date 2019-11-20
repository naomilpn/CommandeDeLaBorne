/*Programme de Lecture de Carte
   Version 1.0 date : 20/11/2019
   Lépinay 
   Le programme à l'heure actuelle permet de détecter ou non une carte insérer dans le boitier
   Suit l'algorithme du TD 1
*/
#include <Wire.h>                         //Définition et inclusion de la bibliothèque Wire
#include "I2C.h"                          //Définition et inclusion de la bibliothèque I2C
#include "arduino.h"                      //Définition et inclusion de la bibliothèque Arduino
#define CARTE 0x50                        //Définition de l'adresse CARTE
#define AUXI 0x21                         //Définition de l'adresse AUXI

void setup()
{
  Wire.begin();                           //Initialisation de la bibliothèque Wire
  Serial.begin(9600);                     //Définition du débit en bitspar seconde
  initI2C(200);                           //Initialisation de la bibiliothèque I2C avec comme vitesse 200
}

void loop()
{
  Wire.beginTransmission(CARTE);          //Commencement de la transmission CARTE
  Wire.write(0x78);                       //Ecriture des données vers 0x78 (120)
  Wire.endTransmission();                 //Fin de ma transmission
  delay(1000);                            //Pause
  Wire.requestFrom(CARTE, 4);             //Récupération des 4 octets de CARTE

  while (Wire.available())
  {
    char c = Wire.read();                 //Lecture
    Serial.println(c, DEC);               //Affichage au moniteur série
  }

  Wire.beginTransmission(AUXI);           //Commencement de la transmission AUXI
  Wire.write(0x01);                       //Ecriture des données vers 0x01 (1)
  Wire.endTransmission();                 //Fin de ma transmission
  delay(1000);                            //Pause
  Wire.requestFrom(AUXI, 4);              //Récupération des 4 octets de AUXI

  char c = Wire.read();                   //Lecture
  if (c == 0x01)                          //Si c= 0x01 alors
  {
    Serial.println("Carte non insérée"); //Affichage sur le moniteur série
  }
  else                                    //Sinon
  {
    Serial.println("Carte insérée");     //Affichage sur le moniteur série
  }

  Wire.beginTransmission(AUXI);          //Commencement de la transmission AUXI
  Wire.write(0x02);                      //Ecriture des données vers 0x02(2)
  Wire.endTransmission();                //Fin de ma transmission
  delay(1000);                           //Pause
  Wire.requestFrom(AUXI, 4);             //Récupération des 4 octets de AUXI

  while (Wire.available())
  {
    char c = Wire.read();                 //Lecture
    Serial.println(c, DEC);               //Affichage au moniteur série
  }
}
