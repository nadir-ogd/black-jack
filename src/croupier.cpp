#include "../include/croupier.hpp"

void Croupier::hitCroupier(Deck& Mydeck)
{
    Mydeck.videDeck();
    int id, value; string color;
    bjCroupier = false;
    auto it =  Mydeck.shuffCard.begin();
      do
      {
        id = it->first; 
        color = it->second.first;
        value =it->second.second;
        this->scoreC += value;
        croupierCartes.insert({id,make_pair(color,value)});
        Mydeck.defausse.insert({it->first, make_pair(it->second.first,it->second.second)}) ;
        Mydeck.shuffCard.erase(it);       
        it++; id++;
        if (((checkC + value) == 11) && (croupierCartes.size() == 2))//vérifie si y a un BJ sauf pour la deuxieme carte tirée pour le croupier
        {cout <<  "Black Jack - Croupier !" << endl; bjCroupier=true; break;}       
      }while((scoreC < 16));    
}

void Croupier::distribuerC(Deck& Mydeck) 
{
    Mydeck.videDeck();
    int id, value; string color;
    auto it =  Mydeck.shuffCard.begin();
    id = it->first;
    color = it->second.first;
    value =it->second.second;
    if (value == 1) {checkC +=1;}
    if (value == 10) {checkC +=10;}
    croupierCartes.insert({id,make_pair(color,value)});
    cout << "La carte :" << " { "<< color<< " , " << value << " } tiree pour le croupier" << endl;
    scoreC += value;
     Mydeck.defausse.insert({it->first, make_pair(it->second.first,it->second.second)}) ;
     Mydeck.shuffCard.erase(it);
}

int Croupier::getScore() {return scoreC;}

void Croupier::printCartesC() 
{
   cout << "Les cartes actuelles de croupier sont :" << endl;
   for (auto it = croupierCartes.begin() ; it != croupierCartes.end() ; it++)
    {cout << "carte " << it->first << " : { " << it->second.first << " , " << it->second.second << " }" << endl;}
}

void Croupier::clearCartesC(Deck& Mydeck)
{
  checkC = 0, scoreC = 0;
   for(auto it = croupierCartes.begin(); it != croupierCartes.end(); it++){
    Mydeck.defausse.insert({it->first, make_pair(it->second.first,it->second.second)}) ;
    }
  this->croupierCartes.clear();
  cout << "Main de cartes du croupier a ete videe !" << endl;
}