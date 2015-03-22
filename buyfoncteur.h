#ifndef __BUYFONCTEUR__
#define __BUYFONCTEUR__

#include <map>
#include "side.h"

class Joueur;
class BuyFoncteur {
 
 private:
  std::map<Side,int> prixRessource;
  std::map<Side,int> prixProduit;

 public:
  BuyFoncteur();
  bool operator ( ) (Joueur& joueur, Side side, int numero);
  
};

#endif
