#ifndef _CARTE_
#define _CARTE_

#include <cstring>
#include "couleurs.h"
#include <iostream>
#include <list>
#include "ressources.h"
#include "cout.h"

class Carte {

 private:

  std::string name;
  Couleur couleur;
  Cout cout;
  std::list<Ressource> ressources;
  bool ressourcesChoix;
  int points;
  int boucliers;
 public:

  Carte(std::string name, Couleur couleur);
  Carte(std::string name, Couleur couleur, Cout cout);
  Carte(std::string name, Couleur couleur, Cout cout, bool ressourcesChoix);
  Carte(std::string name, Couleur couleur, Cout cout, bool ressourcesChoix, int points);
  Carte(std::string name, Couleur couleur, Cout cout, bool ressourcesChoix, int points, int boucliers);
  
  std::string getName() const;
  Couleur getCouleur() const;
  void afficher(std::ostream& Out) const;
  void addRessource(Ressource ressource);
  bool hasProduction() const;
  bool isChoix() const;
  Cout getCout() const;
  Ressource getRandomRessource() const;
  int getRessourcesNumber() const;
  std::list<Ressource>::const_iterator ressourcesBegin() const { return ressources.begin(); }
  std::list<Ressource>::const_iterator ressourcesEnd() const { return ressources.end(); }
};

std::ostream& operator << (std::ostream& Out, const Carte& carte);

#endif
