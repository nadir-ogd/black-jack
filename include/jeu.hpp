#ifndef JEU_HPP
#define JEU_HPP

#include "joueur.hpp"
#include "croupier.hpp"

class Jeu {
 private:
  vector<Joueur> listJoueurs;//un vecteur qui contiendra tous les joueurs de la partie
 public: 
  Jeu() = default;//constructeur par défaut de la classe
  int nbPlayers;//nombre de joueurs
  void debutJeu();//initialise les joueurs avant que le jeu commence
  void continueJeu();//contiendra toutes les étapes nécessaires de déroulement du Black Jack
};


#endif