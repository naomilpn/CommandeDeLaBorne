#include <Wire.h>
#include <Arduino.h>
#include "fonctionbarriere.h"

void configurationBarriere(int address)
{
  Wire.beginTransmission(address);
  Wire.write(0x78);
  Wire.endTransmission();
}

void ouverture(int address)
{
  Wire.beginTransmission(address);
  Wire.write(OUVRIR);
  Wire.endTransmission();
  delay(500);
}

void fermeture(int address)
{
  Wire.beginTransmission(address);
  Wire.write(FERMER);
  Wire.endTransmission();
  delay(500);
}

int lectureBoucle(int address)
{
  int c;
  Wire.requestFrom(address, 1);
  while (Wire.available())
  {
    c = Wire.read();
  }
  return c;
}

boolean boucleAmond(int address)
{
  if (lectureBoucle(address) == 64)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

boolean boucleAval(int address)
{
  if (lectureBoucle(address) == 32)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
