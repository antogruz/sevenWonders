#include "carte.h"
#include <cstdlib>

Carte::Carte(std::string name, Couleur couleur) {
  this->name = name;
  this->couleur = couleur;
  this->ressourcesChoix = false;
  this->cout = Cout();
  this->points = 0;
  this->boucliers = 0;
}

Carte::Carte(std::string name, Couleur couleur, Cout cout) {
  this->name = name;
  this->couleur = couleur;
  this->ressourcesChoix = false;
  this->cout = cout;
  this->points = 0;
  this->boucliers = 0;
}

Carte::Carte(std::string name, Couleur couleur, Cout cout, bool ressourcesChoix) {
  this->name = name;
  this->couleur = couleur;
  this->cout = cout;
  this->ressourcesChoix = ressourcesChoix;
  this->points = 0;
  this->boucliers = 0;
}

Carte::Carte(std::string name, Couleur couleur, Cout cout, bool ressourcesChoix, int points) {
  this->name = name;
  this->couleur = couleur;
  this->cout = cout;
  this->ressourcesChoix = ressourcesChoix;
  this->points = points;
  this->boucliers = 0;
}

Carte::Carte(std::string name, Couleur couleur, Cout cout, bool ressourcesChoix, int points, int boucliers) {
  this->name = name;
  this->couleur = couleur;
  this->cout = cout;
  this->ressourcesChoix = ressourcesChoix;
  this->points = points;
  this->boucliers = boucliers;
}

void Carte::addRessource(Ressource ressource) {
  ressources.push_back(ressource);
}

void Carte::addSymbole(Symbole symbole) {
  symboles.push_back(symbole);
}

std::string Carte::getName() const {
  return name;
}

Couleur Carte::getCouleur() const {
  return couleur;
}

void Carte::afficher(std::ostream& Out) const {  
  Out << cout;
  Out << couleur;
  Out << name;
  for (std::list<Ressource>::const_iterator it = ressources.begin(); it != ressources.end(); it++) {
    if (ressourcesChoix and !(it == ressources.begin())) {
      Out << "/" << *it;
    } else {
      Out << " " << *it;
    }
  }
  if (points > 0) {
    Out << bleu << " (/" << points << " points\\)" << couleur;
  }
  for (int i = 0; i < boucliers; i++) {
    Out << rouge << " (X)" << couleur;
  }
  for (std::list<Symbole>::const_iterator it = symboles.begin(); it != symboles.end(); it++) {
    Out << " " << *it;
  }
  Out << "\n";
  Out << blanc;
}

bool Carte::hasProduction() const {
  return ressources.size() > 0;
}

bool Carte::isChoix() const {
  return ressourcesChoix;
}

Cout Carte::getCout() const {
  return cout;
}

Ressource Carte::getRandomRessource() const {
  if (ressources.size() == 0) {
    std::cerr << "On essaie de récupérer une random ressource d'un carte qui n'en n'a pas\n";
    exit(-1);
  }

  int random = rand() % ressources.size();
  std::list<Ressource>::const_iterator it = ressourcesBegin();
  for (int i = 0; i < random; i++) {
    it++;
  }
  return *it;
}

int Carte::getRessourcesNumber() const {
  return ressources.size();
}

std::ostream& operator << (std::ostream& Out, const Carte& carte)
{
  carte.afficher(Out);
  return Out;
}
