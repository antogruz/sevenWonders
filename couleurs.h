#ifndef COULEURS
#define COULEURS

#include <stdio.h>
#include <iostream>

#define clearScreen() printf("\033[H\033[2J")

enum Couleur {bleu, rouge, jaune, vert, marron, gris, violet, blanc};

std::ostream& operator << (std::ostream& Out, Couleur couleur);

#endif
