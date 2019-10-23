#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H
#include "Card.h"

class Deck {

public:
    void populate();
    Deck ();
    ~Deck();
    Deck (const Deck& origClass);
    Deck operator=(Deck rhs);
    void shuffle ();
    void setCard(); // set the card represented by an element in the array
    Card getCard ();
    bool addToDiscardPile ();
    int trackPile = 0;
    void remove ();

private:
    Card* cards;
    int arraySize;
    int cardsLeft;
};



#endif //BLINDMANSBLUFF_DECK_H
