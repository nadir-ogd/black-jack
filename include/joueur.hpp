#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "deck.hpp"

class Joueur {
  private:
   int idJoueur;//id pour numéroter les joueurs
   string nom;//nom du joueur
   int credit;//le cr&édit du joueur
   int mise;//la mise du joueur qui sera toujours >= 10 et <= credit
   int scoreJ;//score du joueur
   int checkJ;//stocke la valeur du premiere carte tirer pour vérifier le BJ avec la deuxieme valeur

  public:
   deckMap joueurCartes;//map qui contiendra les cartes du Joueur (vidée une fois la partie est terminée)
   bool bjJoueur;//veérifie si le croupier a obtenu un black jack
   Joueur() = default;//constructeur par défaut du joueur
   Joueur(int idJ, string name, int c, int m, int s) : idJoueur(idJ), nom(name) , credit(c), mise(m) , scoreJ(0), checkJ(0), bjJoueur(false) {credit -= mise;}//constructeur du joueur paramétré et mis le crédit à jour
   void distribuerJ(Deck& Mydeck);//sert à distribuer une carte du deck au joueur et l'insérer dans joueurCartes, l'enlever du deck et la mettre dans la défausse
   void hitJoueur(Deck& Mydeck);//sert à tirer une carte du deck tant que scoreC < 16 et vérifie le BJ
   void doubleMise(Deck& Mydeck);//double la mise du joueur et tire une carte (dernière carte tirée)
   void getJoueur();//affiche le joueur avec ses attributs
   string getNom();//retourne le nom du joueur
   int getMise();//retourne la mise du joueur
   void setMise();//mis a jour la mise (utilisée pour les prochaine partie du jeu)
   int getCredit();//renvoie le credit du joueur
   void setCredit(int creditJ);//mis le credit du joueur a creditJ
   int getScore();//renvoie le score du joueur
   void quitter(vector<Joueur>& listJoueurs,  vector<Joueur>::iterator& it);//demande au joueur s'il veut quitter ou non, si oui il sera retiré du vecteur des joueurs
   void decisionPlayer(Deck& Mydeck);//demande au joueur ce qu'il veut faire tant que il a pas un BJ
   void printCartesJ();//affiche la main des cartes du joueur
   void resultatsJ(bool bjC, int score);//calcule et affiche toutes les résultats des joueurs (en fonction du score du Croupier aussi)
   void clearCartesJ(Deck& Mydeck);//sert à vider la main des cartes du joueur
};

#endif