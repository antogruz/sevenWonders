#ifndef _JOUEUR_
#define _JOUEUR_

#include "carte.h"
#include <list>
#include <vector>
#include <map>
#include "side.h"
#include "buyfoncteur.h"

class Joueur {

  friend class BuyFoncteur;
 
 private:
  
  std::list<Carte> constructions;
  std::vector<Carte> hand;
  std::map< Side, std::list<Carte> > ressourcesToBuy;
  std::list<Carte> ressourcesBought;
  int pieces;
  std::map<Side,int> piecesToGive;
  bool humain;

  void constructRessourcesToBuy(Side side, Joueur joueur);
  
 public:

  Joueur() {pieces = 3; humain = false;};
  Joueur(bool humain) { pieces = 3; this->humain = humain; };
  
  void showConstructions() const;
  void showHand() const;
  void showRessourcesBought() const;
  std::vector<Carte> getHand() const;
  void setHand(std::vector<Carte> hand);
  int sizeHand() const;
  void addCarte(Carte carte);
  void addConstruction(Carte carte);
  void show() const;
  bool construire(unsigned int numero);
  bool vendre(unsigned int numero);
  bool ageFini() const;
  bool canAfford(Cout cout) const;
  bool isHumain() const;
  std::list<Carte> getRessourcesToBuy(Side side) const;
  BuyFoncteur buy; // buy(Joueur, Side, numero)
  void nouveauTour(Joueur& gauche, Joueur& droit);
  int getPieces() const {return pieces;};
};

bool canCoutBeSatisfied(Cout & cout, std::list<Carte> & cartes);

#endif

  
