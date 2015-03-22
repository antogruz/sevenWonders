#include "cout.h"
#include "couleurs.h"

Cout::Cout(int nbois, int nargile, int npierre, int nminerai, int nverre, int ntissu, int npapyrus, int pieces) {
  ressources[bois] = nbois;
  ressources[argile] = nargile;
  ressources[pierre] = npierre;
  ressources[minerai] = nminerai;
  ressources[verre] = nverre;
  ressources[tissu] = ntissu;
  ressources[papyrus] = npapyrus;
  this->pieces = pieces;
}

void Cout::afficher(std::ostream& Out) const {
  for (std::map<Ressource, int>::const_iterator it = ressources.begin(); it != ressources.end(); it++) {
    for (int i = 0; i < (it->second); i++) {
      Out << it->first;
    }
  }
  if (pieces > 0) {
    Out << jaune << "(" << pieces << ")";
  }  
}

bool Cout::isFree() const {
  for (std::map<Ressource, int>::const_iterator it = ressources.begin(); it != ressources.end(); it++) {
    if (it->second > 0) {
      return false;
    }
  }
  if (pieces > 0) {
    return false;
  }
  return true;
}

void Cout::check(Ressource ressource) {
  ressources[ressource] --;
  if(ressources[ressource] < 0) {
    ressources[ressource] = 0;
  }
}

void Cout::check(int pieces) {
  this->pieces -= pieces;
  if(this->pieces < 0) {
    this->pieces = 0;
  }
}

int Cout::nombreRestant() const {
  int somme = 0;
  for (std::map<Ressource, int>::const_iterator it = ressources.begin(); it != ressources.end(); it++) {
    somme += it->second;
  }
  return somme;
}

std::ostream& operator << (std::ostream& Out, const Cout& cout) {
  cout.afficher(Out);
  return Out;
}
