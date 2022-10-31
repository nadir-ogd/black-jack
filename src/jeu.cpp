#include "../include/jeu.hpp"

void Jeu::debutJeu() {
  int id = 1, miseJ, creditJ;
  string nomJ;
  cout << "-----GAME START-----" << endl;
  cout << "<<<<< BLACK JACK >>>>>" << endl;
  cout << "Veuillez entrez le nombre de joueurs" << endl;
  cin >> nbPlayers;
  for(int i = 0; i < nbPlayers; i++)
  {
    cout << "Joueur "  << id << ", Veuillez entrez votre nom ?"<< endl;
    cin >> nomJ;
    cout << nomJ << ", Veuillez entrer votre credit ?" << endl;
    cin >> creditJ;
    while (creditJ < 10) {
     cout << "Credit insuffisant! entrez un credit sup a 10: " << endl;
     cin >> creditJ;
    }
    cout << nomJ << ", Veuillez entrer votre mise initiale ?" << endl;
    cin >> miseJ;
    while ((miseJ < 10) || (miseJ > creditJ)) {
     cout << "La mise doit etre sup >= 10 et inf a  <= votre credit, entrez de nouveau:" << endl;
     cin >> miseJ;
    }
    listJoueurs.push_back(Joueur(id,nomJ, creditJ, miseJ, 0));
    listJoueurs[i].getJoueur();
    id++;
  }
      cout << "Tout est en place le jeu commence !" << endl;
}

  void Jeu::continueJeu(){
    int nvPartie = 0;//si il est > 0 donc une deuxieme partie est lancée, les joueurs devont entrer du nouveau leurs mises
    Deck Mydeck;
    Croupier Crp;
    deckMap cards;
    Mydeck.remplirDeck();
    Mydeck.shuffleDeck(Mydeck.shuffCard, Mydeck.cartes);
    // Mydeck.printDeck();
    // Mydeck.printDeckshuff();
    while(listJoueurs.size() != 0) 
      {
          cout << "-----Nouvelle partie-----" << endl;
          if(nvPartie > 0) {
            for(unsigned int i = 0; i < listJoueurs.size(); i++) 
            {
              listJoueurs[i].setMise();
              listJoueurs[i].getJoueur();
              listJoueurs[i].printCartesJ();
            }
          }
          Crp.distribuerC(Mydeck);
          cout << "Score actuel du croupier : " << Crp.getScore() <<endl;
          cout << endl;
          for(unsigned int i = 0; i < listJoueurs.size(); i++) 
           {
            listJoueurs[i].distribuerJ(Mydeck);
           }
          for(unsigned int i = 0; i < listJoueurs.size(); i++) 
           {
            listJoueurs[i].distribuerJ(Mydeck);
           }
          for(unsigned int i = 0; i < listJoueurs.size(); i++) 
           {
            listJoueurs[i].getJoueur();
           }
          for(unsigned int i = 0; i < listJoueurs.size(); i++) 
           {
               listJoueurs[i].decisionPlayer(Mydeck);
               listJoueurs[i].printCartesJ();
           }
             Crp.hitCroupier(Mydeck);
             cout << "Score actuel du croupier : " << Crp.getScore() <<endl;
             Crp.printCartesC();
  
             for(unsigned int i = 0; i < listJoueurs.size(); i++) 
              {  
               listJoueurs[i].resultatsJ(Crp.bjCroupier, Crp.getScore());
               listJoueurs[i].getJoueur(); 
              }
             auto it = listJoueurs.begin();
             while(it != listJoueurs.end())
             (*it).quitter(listJoueurs,it);

             for(unsigned int i = 0; i < listJoueurs.size(); i++) 
              {
               listJoueurs[i].getJoueur(); 
              }
              Crp.clearCartesC(Mydeck);
              for(unsigned int i = 0; i < listJoueurs.size(); i++) 
              {
               listJoueurs[i].joueurCartes.clear();
               listJoueurs[i].clearCartesJ(Mydeck);
              }
            Mydeck.printDeckshuff();
            Mydeck.printDefausse();
            nvPartie++;
      }
  cout << "-----GAME OVER-----" << endl;
}