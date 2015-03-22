#include "couleurs.h"
#include <cstring>
#include <cstdlib>

std::string getCodeCouleur(Couleur couleur) {
  switch (couleur) {
    
  case bleu:
    return "\033[01;34m";
    break;

  case jaune:
    return "\033[01;33m";
    break;

  case rouge:
    return "\033[01;31m";
    break;

  case vert:
    return "\033[01;32m";
    break;

  case marron:
    return "\033[00;33m";
    break;

  case gris:
    return "\033[01;36m";
    break;

  case violet:
    return "\033[01;35m";
    break;

  case blanc:
    return "\033[0m";
    break;

  default:
    std::cerr << "Cette couleur n'existe pas encore\n";
    exit(-1);
    break;
      
  }
}

std::ostream& operator << (std::ostream& Out, Couleur couleur) {
  
  Out << getCodeCouleur(couleur);
  return Out;
}
