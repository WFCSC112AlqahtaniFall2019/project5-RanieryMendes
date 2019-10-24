#include "Card.h"
#include <string>
#include <random>

#include <iostream>


//default constructor for Card object --> initialize varibales, setting a rank and suit for each
Card::Card() {

    int suitElement = random()%4;
    int rankElement = random()%13;
    this->rankCard = suits[suitElement];
    this->suitCard = ranks[rankElement];


}

//general constructor --> assigns the paremeters inserted into the rank and

Card ::Card(string rank, string suits) {

    this->rankCard = rank;
    this->suitCard = suits;

}

// It assigns the rank and the suit variables for Card objects. It also stores the index of the const arrays for suits and rank
// --> they will be used later for comparation
// it is called by the populate function from Deck class
void Card ::setCard(int rank, int suit) {

    this->storeRank = rank;
    this->rankCard = ranks[rank];

    this->storeSuit = suit;
    this->suitCard = suits[suit];

    formCard();

}

void Card :: formCard() {

//form the string that name the card by appending the card's rank and suit
    fullSentence.append(this->rankCard);
    fullSentence.append(" of ");
    fullSentence.append(this->suitCard);

}

//return the string that exhbits the suit and rank of the card.
void Card ::showValueOfCard (){

    cout << fullSentence;
}

//overloading operator to compare the cards
//it compares first the rank then the suit if rank of both cards are equal

bool Card ::operator>(Card tmp) {

    //Check if user's card rank  > computer's card rank
    if (this->storeRank > tmp.storeRank) {

        return true;
    }

    //Check if user's card suit  > computer's card suit if the ranks are equal
    else if (this->storeRank == tmp.storeRank){

       //comparing suits
        if(this->storeSuit > tmp.storeSuit){
            return true;
        } else{
            return false;
        }
    }

    else{
        return false;
    }
}
