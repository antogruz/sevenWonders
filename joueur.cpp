#include "joueur.h"

#define superAdmin false

void Joueur::showConstructions() const {
  for (std::list<Carte>::const_iterator it = constructions.begin(); it != constructions.end(); it++) {
    std::cout << *it;
  }
}

void Joueur::addConstruction(Carte carte) {
  constructions.push_back(carte);
}

void Joueur::showHand() const {
  int numero = 1;
  for (std::vector<Carte>::const_iterator it = hand.begin(); it != hand.end(); it++) {
    if (canAfford(it->getCout())) {
      std::cout << numero << " " << *it;
    } else {
      std::cout << rouge << numero << " * " << *it;
    }
    numero++;
  }
}

void Joueur::showRessourcesBought() const {
  for (std::list<Carte>::const_iterator it = ressourcesBought.begin(); it != ressourcesBought.end(); it++) {
    std::cout << *it;
  }
}

std::vector<Carte> Joueur::getHand() const {
  return hand;
}

void Joueur::setHand(std::vector<Carte> hand) {
  this->hand = hand;
}

int Joueur::sizeHand() const {
  return hand.size();
}

void Joueur::addCarte(Carte carte) {
  hand.push_back(carte);
}

void Joueur::show() const {
  std::cout << "Vous avez " << jaune << pieces << " piece(s)" << blanc << std::endl;
  if (ressourcesBought.size() > 0) {
    std::cout << "Vous avez acheté :\n";
    showRessourcesBought();
  }
  std::cout << "Voici vos constructions :" << std::endl << std::endl ;
  showConstructions();
  std::cout << std::endl;
  if(!ageFini()) {
    std::cout << "Voici votre main" << std::endl << std::endl;
    showHand();
    std::cout << std::endl;
    std::cout << "Que voulez-vous construire ?" << std::endl;
  } else {
    std::cout << "L'age est fini !" << std::endl;
  }
}

bool Joueur::construire(unsigned int numero) {
  if (numero < 1 or numero > hand.size()) {
    return false;
  }
  if (!canAfford(hand[numero-1].getCout())) {
      return false;
  }
  pieces -= hand[numero-1].getCout().getPieces();
  constructions.push_back(hand[numero-1]);
  hand.erase(hand.begin()+numero-1);
  return true;
}

bool Joueur::vendre(unsigned int numero) {
  if (numero < 1 or numero > hand.size()) {
    return false;
  }
  pieces += 3;
  hand.erase(hand.begin()+numero-1);
  return true;
}

bool Joueur::ageFini() const {
  return hand.size() < 2;
}

bool Joueur::canAfford(Cout cout) const {
  
  if (superAdmin and humain) {
    return true;
  }

  // Pièces
  cout.check(pieces);
  if (cout.getPieces() > 0) {
    return false;
  }

  // Ressources de base
  std::list<Carte> cartes = constructions;
  cartes.insert(cartes.end(), ressourcesBought.begin(), ressourcesBought.end());
  std::list<Carte>::iterator itCarte = cartes.begin();
  while (itCarte != cartes.end()) {
    if (!(itCarte->hasProduction())) {
      itCarte = cartes.erase(itCarte);
    } else if (!(itCarte->isChoix())) {
      std::list<Ressource>::const_iterator itRessource;
      for (itRessource = itCarte->ressourcesBegin(); itRessource != itCarte->ressourcesEnd(); itRessource++) {
	cout.check(*itRessource);
      }
      itCarte = cartes.erase(itCarte);
    } else {
      itCarte++;
    }
  }
  
  // Ressources à choix
  return canCoutBeSatisfied(cout, cartes);
}

std::list<Carte> Joueur::getRessourcesToBuy(Side side) const {
  return ressourcesToBuy.at(side);
}

void Joueur::nouveauTour(Joueur& gauche, Joueur& droit) {
  gauche.pieces += piecesToGive[left];
  droit.pieces += piecesToGive[right];
  constructRessourcesToBuy(left, gauche);
  constructRessourcesToBuy(right, droit);
  ressourcesBought.clear();
  piecesToGive.clear();
}

void Joueur::constructRessourcesToBuy(Side side, Joueur joueur) {
  ressourcesToBuy[side].clear();
  std::list<Carte>::const_iterator it;
  for (it = joueur.constructions.begin(); it != joueur.constructions.end(); it++) {
    if (it->hasProduction()) {
      if (it->isChoix() or it->getRessourcesNumber() == 1) {
	ressourcesToBuy[side].push_back(*it);
      } else {
	// Carte de double ressource
	std::list<Ressource>::const_iterator itRessource;
	for (itRessource = it->ressourcesBegin(); itRessource != it->ressourcesEnd(); itRessource++) {
	  Carte carte("Ressource", getCouleur(*itRessource));
	  carte.addRessource(*itRessource);
	}
      }
    }
  }
}
	

bool canCoutBeSatisfied(Cout & cout, std::list<Carte> & cartes) {
  
  Cout copieCout = cout;
  if (cout.isFree()) {
    return true;
  } else if (cout.nombreRestant() > cartes.size()) {
    return false;
  } else {
    Carte carte = cartes.front();
    cartes.pop_front();
    std::list<Ressource>::const_iterator itRessource;
    for (itRessource = carte.ressourcesBegin(); itRessource != carte.ressourcesEnd(); itRessource++) {
      cout = copieCout;
      cout.check(*itRessource);
      if (canCoutBeSatisfied(cout, cartes)) {
	return true;
      }
    }
    return false;
  }
}
// Getters and Setters
const SituationCommerciale& Joueur::getSituationCommerciale() const {
  return buy.getSituationCommerciale();
}

SituationCommerciale & Joueur::getSituationCommerciale() {
  return buy.getSituationCommerciale();
}

