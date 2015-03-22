#ifndef _RESSOURCES_
#define _RESSOURCES_

#include <stdio.h>
#include <iostream>
#include "couleurs.h"

enum Ressource {bois, argile, pierre, minerai, verre, tissu, papyrus}; 

std::ostream& operator << (std::ostream& Out, Ressource ressource);
Couleur getCouleur(Ressource ressource);

#endif
