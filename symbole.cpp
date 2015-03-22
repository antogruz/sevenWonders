#include "symbole.h"
#include <cstring>
#include <cstdlib>

std::string getName(Symbole symbole) {
  switch (symbole) {
  case compas:
    return "(compas)";
    break;
  case tablette:
    return "(tablette)";
    break;
  case roue:
    return "(roue)";
    break;
  default:
    return "(symbole inconnu)";
    break;
  }
}

std::ostream& operator << (std::ostream& Out, Symbole symbole) {
  Out << getName(symbole);
  return Out;
}
