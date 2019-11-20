#include <Wire.h>
#include "I2C.h"
#include "fonctionbarriere.h"

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  initI2C(200);
}

void loop()
{
  /*if (boucleAmond(MECA)== 1 && boucleAval(MECA) == 0)
    {
    do
    {
      if ()
      {
        while ()
        {

        }
      }
    }
    while ();
      fermeture(MECA);
    }*/
  if (boucleAmond() == 0 && boucleAval() == 1)
  {
    ouverture(MECA);
    do
    {
      if (boucleAmond() == 1 && boucleAval() == 0)
      {
        while (boucleAmond() == 1 || boucleAval() == 1)
        {
        }
      }
    }
    while (boucleAmond() == 1 || boucleAval() == 1);
    fermeture(MECA);
  }
}
