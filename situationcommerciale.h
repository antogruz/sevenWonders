#ifndef __SITUATIONCOMMERCIALE__
#define __SITUATIONCOMMERCIALE__

#include <map>
#include "side.h"
#include "couleurs.h"

class SituationCommerciale {

 private:
  std::map<Side,int> prixRessource;
  std::map<Side,int> prixProduit;

 public:
  SituationCommerciale();
  SituationCommerciale(std::map<Side,int> prixRessource, std::map<Side,int> prixProduit);

  void appliquerReduction(SituationCommerciale nouveauxTarifs);

  // getters & setters
  void setPrixRessource(Side side, int prix);
  void setPrixProduit(Side side, int prix);
  int getPrixRessource(Side side) const;
  int getPrixProduit(Side side) const;
  int getPrix(Side side, Couleur couleur) const;

};

#endif
