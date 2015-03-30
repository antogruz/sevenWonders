#include "deck.h"

Deck::Deck(int nombreDeJoueurs) {
  if (nombreDeJoueurs != 3) {
    std::cerr << "Il ne peut y avoir que trois joueurs pour l'instant" << std::endl;
    exit(-1);
  }
  // Ressources 
  Carte* chantier= new Carte("Chantier", marron);
  chantier->addRessource(bois);
  cartes.push_back(chantier);
  Carte* cavite = new Carte("Cavité", marron);
  cavite->addRessource(pierre);
  cartes.push_back(cavite);
  Carte* filon = new Carte("Filon", marron);
  filon->addRessource(minerai);
  cartes.push_back(filon);
  Carte* bassin = new Carte("Bassin Argileux", marron);
  bassin->addRessource(argile);
  cartes.push_back(bassin);
  Carte* foret = new Carte("Exploitation Forestière", marron, Cout(0,0,0,0,0,0,0,1), true);
  foret->addRessource(bois);
  foret->addRessource(pierre);
  cartes.push_back(foret);
  Carte* fosse = new Carte("Fosse Argileuse", marron, Cout(0,0,0,0,0,0,0,1), true);
  fosse->addRessource(argile);
  fosse->addRessource(minerai);
  cartes.push_back(fosse);
  
  // Produits manufacturés
  Carte* metierATisser = new Carte("Métier à tisser", gris);
  metierATisser->addRessource(tissu);
  cartes.push_back(metierATisser);
  Carte* presse = new Carte("Presse", gris);
  presse->addRessource(papyrus);
  cartes.push_back(presse);
  Carte* verrerie = new Carte("Verrerie", gris);
  verrerie->addRessource(verre);
  cartes.push_back(verrerie);
		  
  // Batiments civils
  Carte* autel = new Carte("Autel", bleu, Cout(), false, 2);
  cartes.push_back(autel);
  Carte* theatre = new Carte("Théâtre", bleu, Cout(), false, 2);
  cartes.push_back(theatre);
  Carte* bains = new Carte("Bains", bleu, Cout(0,0,1), false, 3);
  cartes.push_back(bains);
  
  // Batiments commerciaux
  SituationCommerciale tarifsOuest;
  tarifsOuest.setPrixRessource(left, 1);
  Carte* comptoirOuest = new CarteCommerce("Comptoir Ouest", jaune, tarifsOuest);
  cartes.push_back(comptoirOuest);
  
  SituationCommerciale tarifsEst;
  tarifsEst.setPrixRessource(right, 1);
  Carte* comptoirEst = new CarteCommerce("Comptoir Est", jaune, tarifsEst);
  cartes.push_back(comptoirEst);

  SituationCommerciale tarifsMarche;
  tarifsMarche.setPrixProduit(left, 1);
  tarifsMarche.setPrixProduit(right, 1);
  Carte* marche = new CarteCommerce("Marché", jaune, tarifsMarche);
  cartes.push_back(marche);
  
  // Batiments militaires
  Carte* tourDeGarde = new Carte("Tour de Garde", rouge, Cout(0,0,0,1), false, 0, 1);
  Carte* caserne = new Carte("Caserne", rouge, Cout(0,1), false, 0, 1);
  Carte* palissade = new Carte("Palissade", rouge, Cout(1), false, 0, 1);
  cartes.push_back(tourDeGarde);
  cartes.push_back(caserne);
  cartes.push_back(palissade);

  // Batiments scientifiques
  Carte* atelier = new Carte("Atelier", vert, Cout(0,0,0,0,1));
  atelier->addSymbole(roue);
  cartes.push_back(atelier);
  Carte* officine = new Carte("Officine", vert, Cout(0,0,0,0,0,1));
  officine->addSymbole(compas);
  cartes.push_back(officine);
  Carte* scriptorium = new Carte("Scriptorium", vert, Cout(0,0,0,0,0,0,1));
  scriptorium->addSymbole(tablette);
  cartes.push_back(scriptorium);
  
  show();

}

void Deck::show() {
  for (std::list<Carte*>::iterator it = cartes.begin(); it != cartes.end(); it++) {
    std::cout << **it << " ";
    (*it)->talk();
  }
}


void Deck::shuffle() {
  std::list<Carte*> nouvellePile;
  while (cartes.size() > 0) {
    nouvellePile.push_back(takeRandomCarte(cartes));
  }
  cartes = nouvellePile;
}

void Deck::deal(std::vector<Joueur> & joueurs) {
  std::vector<Joueur>::iterator itJoueurs = joueurs.begin();
  std::list<Carte*>::iterator itCartes = cartes.begin();
  
  while (itCartes != cartes.end()) {
    for (itJoueurs = joueurs.begin(); itJoueurs != joueurs.end(); itJoueurs++) {
      itJoueurs->addCarte(*itCartes);
      itCartes++;
    }
  }
}

Carte* takeRandomCarte(std::list<Carte*> & cartes) {
  int random = rand() % cartes.size();
  std::list<Carte*>::iterator it = cartes.begin();
  for (int i = 0; i < random; i++) {
    it++;
  }
  Carte* carteChoisie = *it;
  cartes.erase(it);
  return carteChoisie;
}
  
