#include "deck.h"

Deck::Deck(int nombreDeJoueurs) {
  if (nombreDeJoueurs != 3) {
    std::cerr << "Il ne peut y avoir que trois joueurs pour l'instant" << std::endl;
    exit(-1);
  }
  // Ressources 
  Carte chantier("Chantier", marron);
  chantier.addRessource(bois);
  cartes.push_back(chantier);
  Carte cavite("Cavité", marron);
  cavite.addRessource(pierre);
  cartes.push_back(cavite);
  Carte filon("Filon", marron);
  filon.addRessource(minerai);
  cartes.push_back(filon);
  Carte bassin("Bassin Argileux", marron);
  bassin.addRessource(argile);
  cartes.push_back(bassin);
  Carte foret("Exploitation Forestière", marron, Cout(0,0,0,0,0,0,0,1), true);
  foret.addRessource(bois);
  foret.addRessource(pierre);
  cartes.push_back(foret);
  Carte fosse("Fosse Argileuse", marron, Cout(0,0,0,0,0,0,0,1), true);
  fosse.addRessource(argile);
  fosse.addRessource(minerai);
  cartes.push_back(fosse);
  
  // Produits manufacturés
  Carte metierATisser("Métier à tisser", gris);
  metierATisser.addRessource(tissu);
  cartes.push_back(metierATisser);
  Carte presse("Presse", gris);
  presse.addRessource(papyrus);
  cartes.push_back(presse);
  Carte verrerie("Verrerie", gris);
  verrerie.addRessource(verre);
  cartes.push_back(verrerie);
		  
  // Batiments civils
  cartes.push_back(Carte("Autel", bleu, Cout(), false, 2));
  cartes.push_back(Carte("Théâtre", bleu, Cout(), false, 2));
  cartes.push_back(Carte("Bains", bleu, Cout(0,0,1), false, 3));
  
  // Batiments commerciaux
  cartes.push_back(Carte("Comptoir Ouest", jaune));
  cartes.push_back(Carte("Comptoir Est", jaune));
  cartes.push_back(Carte("Marché", jaune));
  
  // Batiments militaires
  cartes.push_back(Carte("Tour de Garde", rouge, Cout(0,0,0,1), false, 0, 1));
  cartes.push_back(Carte("Caserne", rouge, Cout(0,1), false, 0, 1));
  cartes.push_back(Carte("Palissade", rouge, Cout(1), false, 0, 1));

  // Batiments scientifiques
  cartes.push_back(Carte("Atelier", vert, Cout(0,0,0,0,0,1)));
  cartes.push_back(Carte("Officine", vert, Cout(0,0,0,0,1)));
  cartes.push_back(Carte("Scriptorium", vert, Cout(0,0,0,0,0,0,1)));
  
}

void Deck::shuffle() {
  std::list<Carte> nouvellePile;
  while (cartes.size() > 0) {
    nouvellePile.push_back(takeRandomCarte(cartes));
  }
  cartes = nouvellePile;
}

void Deck::deal(std::vector<Joueur> & joueurs) {
  std::vector<Joueur>::iterator itJoueurs = joueurs.begin();
  std::list<Carte>::iterator itCartes = cartes.begin();
  
  while (itCartes != cartes.end()) {
    for (itJoueurs = joueurs.begin(); itJoueurs != joueurs.end(); itJoueurs++) {
      itJoueurs->addCarte(*itCartes);
      itCartes++;
    }
  }
}

Carte takeRandomCarte(std::list<Carte> & cartes) {
  int random = rand() % cartes.size();
  std::list<Carte>::iterator it = cartes.begin();
  for (int i = 0; i < random; i++) {
    it++;
  }
  Carte carteChoisie = *it;
  cartes.erase(it);
  return carteChoisie;
}
  
