#include "Card.h"
#include <string>
#include <random>
#include <ctime>
#include <iostream>



Card::Card() {

    srand(time(NULL));
    int suitElement = random()%4;
    int rankElement = random()%13;
    this->rankCard = suits[suitElement];
    this->suitCard = ranks[rankElement];
    cout << "Card Constructor called" << endl;

}

Card ::Card(string rank, string suits) {

    this->rankCard = rank;
    this->suitCard = suits;

}


void Card ::setCard(int rank, int suit) {

    this->rankCard = ranks[rank];

    this->suitCard = suits[suit];

    formCard();

}

void Card :: formCard() {


    fullSentence.append(this->rankCard);
    fullSentence.append(" of ");
    fullSentence.append(this->suitCard);
    cout << fullSentence <<  " " << endl;

}

void Card ::showValueofCard (){

    cout << fullSentence;
}

bool Card ::operator>(Card tmp) {

    //Check if user's card  > computer's card
    if(this->rankCard > tmp.rankCard) {

        return true;
    }

    else{
        return false;
    }
}
