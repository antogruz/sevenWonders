#ifndef _CARTE_
#define _CARTE_

#include <cstring>
#include "couleurs.h"
#include <iostream>
#include <list>
#include "ressources.h"
#include "cout.h"
#include "symbole.h"
#include "joueur.h"
#include "situationcommerciale.h"

class Joueur;
class Carte {

 private:

  std::string name;
  Couleur couleur;
  Cout cout;
  std::list<Ressource> ressources;
  bool ressourcesChoix;
  int points;
  int boucliers;
  std::list<Symbole> symboles;

 public:
  // Construction des cartes
  Carte(std::string name, Couleur couleur);
  Carte(std::string name, Couleur couleur, Cout cout);
  Carte(std::string name, Couleur couleur, Cout cout, bool ressourcesChoix);
  Carte(std::string name, Couleur couleur, Cout cout, bool ressourcesChoix, int points);
  Carte(std::string name, Couleur couleur, Cout cout, bool ressourcesChoix, int points, int boucliers);
  void addRessource(Ressource ressource);
  void addSymbole(Symbole symbole);

  // Accesseurs
  std::string getName() const;
  Couleur getCouleur() const;
  void afficher(std::ostream& Out) const;
  bool hasProduction() const;
  bool isChoix() const;
  Cout getCout() const;
  Ressource getRandomRessource() const;
  int getRessourcesNumber() const;
  std::list<Ressource>::const_iterator ressourcesBegin() const { return ressources.begin(); }
  std::list<Ressource>::const_iterator ressourcesEnd() const { return ressources.end(); }

  // Actions
  virtual void onPlay(Joueur& joueur) {std::cout << "Aucun effet" << std::endl;};
  virtual void talk() {
    std::cout << "Je suis une carte" << std::endl;
  }
};

std::ostream& operator << (std::ostream& Out, const Carte& carte);

class CarteCommerce : public Carte {
 private:
  SituationCommerciale nouveauxTarifs;
  
 public:
  // Constructeurs
  CarteCommerce(std::string name, Couleur couleur, SituationCommerciale nouveauxTarifs);

  void onPlay(Joueur& joueur);
  void talk() {
    std::cout << "Je suis une carte Commerce" << std::endl;
  }
};


#endif
