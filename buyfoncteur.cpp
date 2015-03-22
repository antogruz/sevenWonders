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
  if (joueur.pieces < 2) {
    return false;
  }
  joueur.ressourcesBought.push_back(*it);
  ressources.erase(it);
  joueur.pieces -= 2;
  joueur.piecesToGive[side] += 2;
  return true;
}
