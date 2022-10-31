#include "../include/joueur.hpp"
void Joueur::hitJoueur(Deck& Mydeck)
{
        Mydeck.videDeck();
        auto it = Mydeck.shuffCard.begin();
        int id = it->first;
        string color = it->second.first;
        int value =it->second.second;
        if (value == 1) //vérifier si un AS
        {
            if ((scoreJ + 11) <= PT_OBJECTIF)
            value = 11;//le considérer un 21 s'il dépasse pas 21
        }
        joueurCartes.insert({id,make_pair(color,value)});
        cout << "La carte : " << "{ "<< color<< " , " << value << " } tiree pour " << nom << endl;
        this->scoreJ += value;
        Mydeck.defausse.insert({it->first, make_pair(it->second.first,it->second.second)}) ;
        Mydeck.shuffCard.erase(it);
}

void Joueur::distribuerJ(Deck& Mydeck) 
{
    Mydeck.videDeck();
    int id, value;
    string color;
    auto it = Mydeck.shuffCard.begin();
    id = it->first;
    color = it->second.first;
    value =it->second.second;
    if (value == 1) {checkJ +=1;}
    if (value == 10) {checkJ +=10;}
    joueurCartes.insert({id,make_pair(color,value)});
    cout << "La carte " << id << " : { "<< color<< " , " << value << " } tiree pour " << nom << endl;
    Mydeck.defausse.insert({it->first, make_pair(it->second.first,it->second.second)}) ;
    Mydeck.shuffCard.erase(it);
    scoreJ+= value;
    id++; it++;
    bjJoueur = false;
    if ((checkJ) == 11) 
    {bjJoueur=true;}
}

void Joueur::doubleMise(Deck& Mydeck)
{
    Mydeck.videDeck();
    credit -= mise;
    mise = mise * 2;
    auto it =  Mydeck.shuffCard.begin();
    int id = it->first;
    string color = it->second.first;
    int value =it->second.second;
    if (value == 1) //vérifier si un AS
      {
        if ((scoreJ + 11) <= PT_OBJECTIF)
        value = 11;//le considérer un 21 s'il dépasse pas 21
      }
    joueurCartes.insert({id,make_pair(color,value)});
    cout << "La carte tiree est :" << "{ "<< color<< " , " << value << " }" << endl; 
    this->scoreJ += value;
     Mydeck.defausse.insert({it->first, make_pair(it->second.first,it->second.second)}) ;
     Mydeck.shuffCard.erase(it);
}
void Joueur::getJoueur()
{
    cout << "Joueur " << this->idJoueur << endl;
    cout << "Nom : " << nom << endl;
    cout << "Credit : " << credit << endl;
    cout << "Mise : " << mise << endl;
    if(bjJoueur == true){cout << "Score : BLACK JACK" << endl;}
    else{cout << "Score : " << scoreJ << endl;}
    cout << "--------" << endl;
}

int Joueur::getMise()
{
    return mise;
}
string Joueur::getNom()
{
    return nom;
}
void Joueur::setMise()
{
  int miseJ;
  cout << "Joueur "<< this->nom << ", Veuillez entrez votre mise initiale : " << endl;
  cin >> miseJ;
    while (miseJ < 10 || miseJ > credit) {
     cout << "La mise doit etre sup >= 10 et in <= a votre credit, entrez de nouveau:" << endl;
     cin >> miseJ;
    }
  this->mise = miseJ;
  this->credit -= miseJ;
}
int Joueur::getCredit()
{
    return credit;
}

void Joueur::setCredit(int creditJ)
{
    this->credit = creditJ;
}

void Joueur::quitter(vector<Joueur>& listJoueurs, vector<Joueur>::iterator& it)
{
  int choix;
  cout << this->nom << endl;
  cout << "Tappez 0 pour quitter le jeu" << endl;
  cout << "Tappez 1 pour continuer a jouer" << endl;
  cin >> choix;
 switch(choix) {
      case 0:
       cout << "Vous avez choisis le premier choix \n";
       cout << "Le joueur " << nom << " est retire du jeu !" << endl;
       it = listJoueurs.erase(it);//ce joueur sera supprimé du vecteur des joueurs
      break;
      case 1:
       cout << "Vous avez choisis le premier choix \n";
       if (credit > 10)//si le crédit du joueur est suffisant ou non pour continuer à jouer
         {
          cout << nom <<", vous pouvez continuer à jouer \n";
          it++;
         }
        else
         {
          cout << "Credit insuffisant, vous ne pouvez pas jouer\n";
          cout << "Le joueur " << nom << " est exclu du jeu !" << endl;
          it = listJoueurs.erase(it);
         }
      break;
}
}

void Joueur::decisionPlayer(Deck &Mydeck) 
{
  if( bjJoueur == false)
  {
      int choice;
    cout << nom << ", sélctionnez votre choix :" << endl;
    cout << "Tappez 1 pour tirer une autre carte" << endl;
    cout << "Tappez 2 pour s'arreter" << endl;
    cout << "Tappez 3 pour doubler votre mise" << endl;
    do{
    cin >> choice;
    switch(choice) {
      case 1:
         if(this->scoreJ < 21)//si son score dépasse 21 il peut pas tirer une carte
          {this->hitJoueur(Mydeck);}
         else
         {cout << "Joueur " << nom << " Impossible de tirer une carte vous avez depassez 21" << endl;}
      break;
      case 2://le joueur ne fais rien
            cout << "Joueur " << nom << " Vos cartes sont conservees !" << endl;
      break;
      case 3://le joueur double sa mise et une carte sera tirée pour lui
          this->doubleMise(Mydeck);
      break;      
      default://le joueur doit choisir l'un des choix proposés
            cout << "Joueur " << nom << " Veuillez choisir l'un des choix proposes :" << endl; 
      break;
        }       
        }while ((choice != 1) && (choice != 2) && (choice != 3));
    } 
  else {//si le joueur a obtenu deja un BJ il attend les résultat et fait rien
    if(bjJoueur == true){cout << "Joueur "<< nom << " vous avez obtenu un Black Jack !, attendez les resultats \n";}}
  }

void Joueur::printCartesJ()
{
   cout << "Les cartes actuelles de " << nom << " sont :" << endl;
   for (auto it = joueurCartes.begin() ; it != joueurCartes.end() ; it++)
    {
    cout << "carte " << it->first << " : { " << it->second.first << " , " << it->second.second << " }" << endl;
    }
}

void Joueur::resultatsJ(bool bjC, int scoreC) 
{
  if(scoreJ <= 21 && bjJoueur == false)//cas ou le joueur a un score <= 21 sans BJ
  {
    if(scoreC > 21)//si le croupier a dépassé 21
    {
      credit += (2*mise); mise = 0;
      cout << "Joueur "<< nom << " gagne une fois sa mise" << endl;
    }
    else
    {
      if(bjC == false)//si le croupier a un score <= 21 sans BJ
      {
       if(scoreJ < scoreC){credit -= mise; mise =0; cout << "Le croupier gagne et le joueur " << nom << " perd sa mise" << endl;}
       if(scoreJ == scoreC){credit += mise; mise=0; cout << "Le croupier et joueur " << nom << " ont le meme score, il gange une fois sa mise\n";}
       if(scoreJ > scoreC){credit += (2*mise); mise=0; cout << "Joueur "<< nom << " gagne une fois sa mise" << endl;}
      }
      else//si le croupier a un BJ
      {
        credit -= mise; mise =0;
        cout << "Le joueur " << nom << " perd sa mise" << endl; //ce cas (BJ pour croupier et le joueur a moins ou égal à 21pts mais sans BJ) pas cité dans l'énoncé du tp
      }
    }
  }
  else 
  {
    if (scoreJ > 21) {credit-=mise; mise =0;}//si le joueur dépasse 21
    else {//si le joueur a un BJ, les résultats dépends du croupier(a obtenu un BJ ou pas)
      if(bjC == true) {credit += mise; mise = 0; cout << "Le joueur "<< nom << " et le croupier ont obtenu un BLACK JACK " << endl;}
      else {credit += (1.5*mise); mise = 0; cout << "Le joueur "<< nom << " a obtenu un BLACK JACK " << endl;}
    }
  }
}

int Joueur::getScore() {return scoreJ;}

void Joueur::clearCartesJ(Deck& Mydeck) 
{
  checkJ = 0, scoreJ = 0;
  for(auto it = joueurCartes.begin(); it != joueurCartes.end(); it++){
    Mydeck.defausse.insert({it->first, make_pair(it->second.first,it->second.second)}) ;
  }
  this->joueurCartes.clear();
  cout << "Main de cartes du joueur " << nom << " a ete videe !" << endl;
}