#ifndef FONCTIONBARRIERE_H
#define FONCTIONBARRIERE_H

#define MECA 0x20
#define OUVRIR 0x7D
#define FERMER 0x7E

void ouverture(int address);
void fermeture(int address);
int lectureBoucle(int address);
void configurationBarriere(int address);
boolean boucleAval(int address);
boolean boucleAmond(int address);

#endif
