#ifndef _JEU_
#define _JEU_

#include "joueur.h"
#include "deck.h"
#include <cstdlib>
#include <vector>
#include "side.h"

class Jeu {
  
 private:
  std::vector<Joueur> joueurs;
  
 public:
  Jeu(int nombreDeJoueurs);

  void deal(Deck deck);
  bool ageFini() const;
  Joueur & getHumain();
  Joueur getHumain() const;
  void nouveauTour();
  void draft();
  bool buyTo(Side side);
  void show() const;

};

#endif
