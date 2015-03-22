#ifndef _COUT_
#define _COUT_

#include <list>
#include "ressources.h"
#include <map>

class Cout {
  
 private:
  
  std::map<Ressource, int> ressources;
  int pieces;

 public:
  
  Cout(int nbois = 0, int nargile = 0, int npierre = 0, int nminerai = 0, int nverre = 0, int ntissu = 0, int npapyrus = 0, int npieces = 0);
  void afficher(std::ostream& Out) const;
  bool isFree() const;
  void check(Ressource ressource);
  void check(int pieces);
  int getPieces() const { return pieces; };
  int nombreRestant() const;
};

std::ostream& operator << (std::ostream& Out, const Cout& cout);

#endif
