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
  configurationBarriere(MECA);
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
  if (boucleAmond(MECA) == 0 && boucleAval(MECA) == 1)
  {
    ouverture(MECA);
    do
    {
      if (boucleAmond(MECA) == 1 && boucleAval(MECA) == 0)
      {
        while (boucleAmond(MECA) == 1 || boucleAval(MECA) == 1)
        {
        }
      }
    }
    while (boucleAmond(MECA) == 1 || boucleAval(MECA) == 1);
    fermeture(MECA);
  }
}
