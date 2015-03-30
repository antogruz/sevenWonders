#ifndef __BUYFONCTEUR__
#define __BUYFONCTEUR__

#include <map>
#include "side.h"
#include "situationcommerciale.h"

class Joueur;
class BuyFoncteur {
 
 private:
  SituationCommerciale situationCommerciale;

 public:
  BuyFoncteur();
  bool operator ( ) (Joueur& joueur, Side side, int numero);
  
  // getters & setters
  const SituationCommerciale& getSituationCommerciale() const;
  SituationCommerciale& getSituationCommerciale();
};

#endif
