#include "couleurs.h"
#include "carte.h"
#include "joueur.h"
#include "deck.h"
#include "jeu.h"
#include <iostream>
#include <time.h>

int main(int argc, char** argv) {
  srand(time(NULL));
  
  clearScreen();
  Jeu jeu(3);
  Deck deck(3);
  deck.shuffle();
  jeu.deal(deck);
  while (!jeu.ageFini()) {
    jeu.draft();
  }
  jeu.show();
}
