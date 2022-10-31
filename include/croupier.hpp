#ifndef CROUPIER_HPP
#define CROUPIER_HPP

#include "deck.hpp"

#define PT_OBJECTIF 21
#define COURPIER_REGLE 16
#define NB_CARTES 52


using namespace std;
typedef  map<int, pair<string,int>> deckMap;

class Croupier {
  private:
   int scoreC;//le score du Croupier
   int checkC;//stocke la premiere valeur du carte tirée pour le Croupier afin de vérifier le BJ avec la deuxieme carte

   
  public:
   deckMap croupierCartes;//map qui contiendra les cartes du Croupier (vidée une fois la partie est terminée)
   bool bjCroupier;//vérifie si le croupier a obtenu un black jack
   Croupier() : scoreC(0), checkC(0) {}//constructeur paramétré qui initialise le score et checkC du croupier à 0
   void distribuerC(Deck& Mydeck);//sert à distribuer la premiere carte du deck au croupier et l'insérer dans croupierCartes, l'enlever du deck et la mettre dans la défausse
   void hitCroupier(Deck& Mydeck);//sert à tirer une carte du deck tant que scoreC < 16 et vérifie le BJ
   void clearCartesC(Deck& Mydeck);//sert à vider la main des cartes du Croupier
   int getScore();//retourne le score actuel du croupier
   void printCartesC();//affiche les cartes actuelles du Croupier

};


#endif