#ifndef _DECK_
#define _DECK_

#include "carte.h"
#include "joueur.h"
#include <list>
#include <cstdlib>
#include <algorithm>

class Deck {
  
 private:
  
  std::list<Carte> cartes;
  
 public:
  Deck(int nombreDeJoueurs);
  
  void shuffle();
  void deal(std::vector<Joueur> & joueurs);

};

Carte takeRandomCarte(std::list<Carte> & cartes);
#endif
