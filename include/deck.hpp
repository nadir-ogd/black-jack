#ifndef DECK_HPP
#define DECK_HPP

#include <iomanip>
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <time.h>
#include <random>
#include <string>
#include <utility>
#include <cstdlib>


#define PT_OBJECTIF 21
#define COURPIER_REGLE 16
#define NB_CARTES 52
#define NB_DECK 312



using namespace std;
typedef  map<int, pair<string,int>> deckMap;//type de map qui sera utilisé dans tout le code du TP

class Deck {
 private:

 public:
  deckMap cartes;//cartes initiales avant de les mélanger
  deckMap shuffCard;//cartes mélangées
  deckMap defausse;//carte de la defausse
  deckMap getShuff();//renvoie la map des cartes mélangées
  deckMap getDefausse();//renvoie la map des cartes de la défausse
  void remplirDeck();//remplie le deck avec les N*6 cartes
  void shuffleDeck(deckMap& decktoToShuff, deckMap& deckSource);//sert à mélanger les cartes de deckSource et les mettre dans deckToShuff et vide la défausse (j'ai utilisé 2 param pour remplir le deck depuis la défausse une fois le deck est vide en plein jeu)
  void videDeck();//vérifie si le deck est vide, si oui elle le remplie de nouveau depuis la défausse et le mélange
  void printDeck();//affiche le deck avant le mélanger
  void printDeckshuff();//affiche les cartes mélangées
  void printDefausse();  //affiche la défausse

};

#endif