#include "situationcommerciale.h"

SituationCommerciale::SituationCommerciale() {
  prixRessource[left] = 2;
  prixRessource[right] = 2;
  prixProduit[left] = 2;
  prixProduit[right] = 2;
}

SituationCommerciale::SituationCommerciale(std::map<Side,int> prixRessource, std::map<Side,int> prixProduit) {
  this->prixRessource = prixRessource;
  this->prixProduit = prixProduit;
}

void SituationCommerciale::appliquerReduction(SituationCommerciale nouveauxTarifs) {
  Side sides[2];
  sides[0] = left;
  sides[1] = right;
  for (int i = 0; i < 2; i++) {
    if (prixRessource[sides[i]] > nouveauxTarifs.prixRessource[sides[i]]) {
      prixRessource[sides[i]] = nouveauxTarifs.prixRessource[sides[i]];
    }
    if (prixProduit[sides[i]] > nouveauxTarifs.prixProduit[sides[i]]) {
      prixProduit[sides[i]] = nouveauxTarifs.prixProduit[sides[i]];
    }
  }
}

// -----------------
// getters & setters
// -----------------
void SituationCommerciale::setPrixRessource(Side side, int prix) {
  prixRessource[side] = prix;
}

void SituationCommerciale::setPrixProduit(Side side, int prix) {
  prixProduit[side] = prix;
}

int SituationCommerciale::getPrixRessource(Side side) const {
  return prixRessource.at(side);
}

int SituationCommerciale::getPrixProduit(Side side) const{
  return prixProduit.at(side);
}

int SituationCommerciale::getPrix(Side side, Couleur couleur) const{
  switch (couleur) {
  case marron:
    return getPrixRessource(side);
    break;
  case gris:
    return getPrixProduit(side);
    break;
  default:
    return 10000;
    break;
  }
}
