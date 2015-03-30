#include "jeu.h"

Jeu::Jeu(int nombreDeJoueurs) {
  for (int i = 0; i < nombreDeJoueurs; i++) {
    joueurs.push_back(Joueur(i == 0));
  }
}

void Jeu::deal(Deck deck) {
  deck.deal(joueurs);
}

bool Jeu::ageFini() const {
  return joueurs.front().ageFini();
}

Joueur & Jeu::getHumain() {
  return joueurs.front();
}

Joueur Jeu::getHumain() const {
  return joueurs.front();
}

void Jeu::show() const {
  clearScreen();
  std::cout << "Voisin de gauche\n";
  joueurs.back().showConstructions();
  std::cout << std::endl;
  std::cout << "Voisin de droite\n";
  joueurs[1].showConstructions();
  std::cout << std::endl;
  getHumain().show();
}

void Jeu::draft() {
  nouveauTour();
  bool loop = true;
  while (loop) {
    show();
    int numero;
    std::cin >> numero;
    if (numero == 0) {
      std::cout << "Quelle action voulez-vous faire ?\n";
      std::cout << "v pour vendre, g & d pour acheter à gauche ou à droite\n";
      char caractere;
      std::cin >> caractere;
      switch (caractere) {
      case 'v':
	std::cout << "Quelle carte voulez-vous vendre ?\n";
	std::cin >> numero;
	if (!getHumain().vendre(numero)) {
	  std::cout << "Le numéro n'est pas acceptable" << std::endl;
	} else {
	  loop = false;
	}
	break;
      case 'g':
	if (!buyTo(left)) {
	  std::cout << "Vous n'avez pas assez d'argent\n";
	}
	break;
      case 'd':
	if (!buyTo(right)) {
	  std::cout << "Vous n'avez pas assez d'argent\n";
	}
	break;
      default:
	std::cerr << "Ce n'est pas un caractère valide\n";
	exit(-1);
      }     
    } else {
      if (!getHumain().construire(numero)) {
	std::cout << "Le numéro n'est pas acceptable" << std::endl;
      } else {
	loop = false;
      }
    }
  }
  for (std::vector<Joueur>::iterator it = joueurs.begin(); it != joueurs.end(); it++) {
    if (it != joueurs.begin()) {
      int gardeFou = 0;
      while(!it->construire(rand() % it->sizeHand() + 1) and gardeFou < 100) {
	gardeFou++;
      }
      if (gardeFou == 100) {
      	it->vendre(rand() % it->sizeHand() + 1);
      }
    }
  }
  
  std::vector<Carte> tampon = getHumain().getHand();
  unsigned int i = 1;
  for (std::vector<Joueur>::iterator it = joueurs.begin(); it != joueurs.end(); it++) {
    if (i < joueurs.size()) {
      it->setHand((it+1)->getHand());
    }
    i++;
  }
  joueurs.back().setHand(tampon);
}

bool Jeu::buyTo(Side side) {
  std::list<Carte> ressources = getHumain().getRessourcesToBuy(side);
  std::list<Carte>::const_iterator it;
  int i = 1;
  for (it = ressources.begin(); it != ressources.end(); it++) {
    std::cout << i << " " << *it;
    i++;
  }
  std::cout << "De quelle carte voulez vous acheter une ressource ?\n";
  int numero;
  std::cin >> numero;
  return getHumain().buy(getHumain(), side, numero);
}

void Jeu::nouveauTour() {
  for (unsigned int i = 0; i < joueurs.size(); i++) {
    joueurs[i].nouveauTour(joueurs[((joueurs.size()+i-1) % joueurs.size())], joueurs[((i+1) % joueurs.size())]);
  }
}
