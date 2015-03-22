 #include "ressources.h"
 #include <cstring>
 #include <cstdlib>

#define symbole false

 std::string getSymbole(Ressource ressource) {
   switch (ressource) {
   case bois:
     if (symbole) {
       return "(ooo)";
     } else {
       return "(bois)";
     }
     break;

   case argile:
     if (symbole) {
       return "(▄█▄)";
     } else {
       return "(argile)";
     }
     break;

   case pierre:
     if (symbole) {
       return "(██)";
     } else {
       return "(pierre)";
     }
     break;

   case minerai:
     if (symbole) {
       return "(▲)";
     } else {
       return "(minerai)";
     }
     break;
   case verre:
     if (symbole) {
       return "(Ü)";
     } else {
       return "(verre)";
     }
     break;

   case tissu:
     if (symbole) {
       return "(/-/)";
     } else {
       return "(tissu)";
     }
     break;

   case papyrus:
     if (symbole) {
       return "(/_/)";
     } else {
       return "(papyrus)";
     }
     break;

   default:
     std::cerr << "Cette ressource n'existe pas\n";
     exit(-1);
     break;
   }
 }

 Couleur getCouleur(Ressource ressource) {
   if (!symbole) {
     return marron;
   }
   switch (ressource) {
   case bois:
     return marron;
     break;
   case argile:
     return rouge;
     break;
   case pierre:
     return blanc;
     break;
   case minerai:
     return blanc;
     break;
   case verre:
     return gris;
     break;
   case tissu:
     return violet;
     break;
   case papyrus:
     return marron;
     break;
   default:
     std::cerr << "Cette ressource n'existe pas\n";
     exit(-1);
     break;
  }
}

std::ostream& operator << (std::ostream& Out, Ressource ressource) { 
  Out << getCouleur(ressource) << getSymbole(ressource);
  return Out;
}

