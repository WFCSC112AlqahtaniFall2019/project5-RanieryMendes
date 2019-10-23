#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {

public:
    ~Deck();
private:
    Card* cards;
    int arraySize = 50;
    int cardsLeft ;
};



#endif //BLINDMANSBLUFF_DECK_H
