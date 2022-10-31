#include "../include/deck.hpp"

deckMap Deck::getShuff() {
  return shuffCard;
}

deckMap Deck::getDefausse() {
  return defausse;
}

void Deck::remplirDeck() { 
     int i; int cpt = 1;
     for(int j = 0; j < 6; j++) {
      //Les piques
      for(i= 0+j*NB_CARTES; i < 13+j*NB_CARTES; i++)
      {
       if (cpt > 9) 
        {cartes.insert({i, make_pair("\06",10)});} 
       else{
        cartes.insert({i, make_pair("\06",cpt)});
        cpt++;
       }
      }  
      cpt = 1;
      
      //Les carreaux
      for(i= 13+j*NB_CARTES; i < 26+j*NB_CARTES; i++)
      {
       if (cpt > 9) 
        {cartes.insert({i, make_pair("\04",10)});}
       else{
        cartes.insert({i, make_pair("\04",cpt)});
        cpt++;}
      }  
      cpt = 1;

      //Les coeurs
      for(i= 26+j*NB_CARTES; i < 39+j*NB_CARTES; i++)
      {
       if (cpt > 9)
        {cartes.insert({i, make_pair("\03",10)});}
       else{
        cartes.insert({i, make_pair("\03",cpt)});
        cpt++;
       }
      }  
      cpt = 1;

      //Les trèfles
      for(i= 39+j*NB_CARTES; i < 52+j*NB_CARTES; i++)
      {
       if (cpt > 9) 
        {cartes.insert({i, make_pair("\05",10)});}
       else{
        cartes.insert({i, make_pair("\05",cpt)});
        cpt++;
       }
      }  
    }
}

void Deck::printDeck() { 
     cout << "Les cartes avant les melanger :" << endl;
   for (auto it = cartes.begin() ; it != cartes.end() ; it++)
    {
    cout << "carte " << it->first << " : { " << it->second.first << " , " << it->second.second << " }" << endl;
    }
}

void Deck::printDeckshuff() { 
   cout << "Les cartes de deck sont :" << endl;
   for (auto it = shuffCard.begin() ; it != shuffCard.end() ; it++)
    {
    cout << "carte " << it->first << " : { " << it->second.first << " , " << it->second.second << " }" << endl;
    }
}

void Deck::printDefausse() { 
  cout << "Les cartes de la defausse sont :" << endl;
   for (auto it = defausse.begin() ; it != defausse.end() ; it++)
    {
    cout << "carte : " << it->first << " { " << it->second.first << " , " << it->second.second << " }" << endl;
    }
}

void Deck::shuffleDeck(deckMap& deckToShuff, deckMap& deckSource) {
  vector<int> vkeys(NB_DECK);//mettre les valeurs de map dans vkeys
  vector<int> vktmp(NB_DECK);//melanger les elem de vkeys et les mettre dans vktmp
  vector<string> vcolor(NB_DECK);//mettre les couleurs de map dans vcolor
  vector<string> vctmp(NB_DECK);//melanger les elem de vcolor et les mettre dans vctmp 
  int i = 0, j = 0, indice, taille = 312;
  for (auto it = deckSource.begin() ; it != deckSource.end() ; it++)
    {
    vcolor[i] = it->second.first;
    vkeys[i] = it->second.second;
    i++;
    }
    i = 0;
  while(i < 312)//utiliser l'algorithme "Mélanger les cartes"
    {
      srand(time(NULL));
      indice = rand() % taille;
      vktmp[j] = vkeys[indice];
      vctmp[j] = vcolor[indice];
      for(int k = indice ; k < taille -1; k++)
       {
        vkeys[k] = vkeys[k+1];
        vcolor[k] = vcolor[k+1];
       }
       vkeys[taille] = 0;
       --taille;
       j++;
       i++;
    }
    for (int i = 0; i < NB_DECK ; i++)
      {
        deckToShuff.insert({i,make_pair(vctmp[i], vktmp[i])}) ;//nouvelle map mélangée
      }
  defausse.clear();//vide la défausse
}

void Deck::videDeck() {
  if(shuffCard.size() == 0)
  {
   cout << "Impossible de tirer une carte, le deck est vide :( \n";
   this->shuffleDeck(shuffCard,defausse);//si le deck est vide elle mis les cartes de la défausse dans le deck et le mélange
   cout << "Les cartes de la defausse ont ete recuperees vous pouvez continuez a jouer !" << endl;
  }
}