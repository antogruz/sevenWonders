#include "buyfoncteur.h"
#include "joueur.h"

BuyFoncteur::BuyFoncteur(){}

bool BuyFoncteur::operator()(Joueur& joueur, Side side, int numero)
{
  std::list<Carte>& ressources(joueur.ressourcesToBuy[side]);
  std::list<Carte>::iterator it = ressources.begin();
  for (int i = 1; i < numero; i++) {
    it++;
  }
  // *it est la carte que le joueur veut acheter
  int prix = situationCommerciale.getPrix(side, it->getCouleur());
  if (joueur.pieces < prix) {
    return false;
  }
  joueur.ressourcesBought.push_back(*it);
  ressources.erase(it);
  joueur.pieces -= prix;
  joueur.piecesToGive[side] += prix;
  return true;
}

// -----------------
// getters & setters
// -----------------

const SituationCommerciale& BuyFoncteur::getSituationCommerciale() const {
  return situationCommerciale;
}

SituationCommerciale& BuyFoncteur::getSituationCommerciale() {
  return situationCommerciale;
}
