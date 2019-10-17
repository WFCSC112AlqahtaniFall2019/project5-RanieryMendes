#include "Card.h"
#include <string>
#include <ctime>



Card::Card() {
    srand(time(0));
    int suitElement = rand()%4;
    int rankElement = rand()%13;

    this->rankCard = suits[suitElement];

    this->suitCard = ranks[rankElement];

}

Card ::Card(string rank, string suits) {

    this->rankCard = rank;
    this ->suitCard = suits;

}

string Card ::showCard() {

    string fullSentence;
    fullSentence.append(this->suitCard);
    fullSentence.append(" of ");
    fullSentence.append(this->rankCard);


    return fullSentence;
}

bool Card ::operator>(Card tmp) {


    //Check if user's card  > computer's card
    if(this->rankCard > tmp.rankCard) {

        return true;
    } else{
        return false;
    }
}
