#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H
#include "Card.h"

class Deck {

public:

    //constructor
    Deck ();
    //populate the deck
    void populate();
    //destructor
    ~Deck();
    //copy constructor
    Deck (const Deck& origClass);
    // copy assignment operator
    Deck operator=(Deck rhs);
    //shuffle the cards
    void shuffle ();
    // set the card represented by an element in the array
    void setCard();
    // member function that removes a card from the deck and returns its value, putting it into a Card object;
    Card getCard ();
    // member function that adds a card to the deck (it returns false if there is no physical space in the deck).
    bool addToDiscardPile (Deck game);


private:
    Card* cards;
    int arraySize;
    int cardsLeft;
};



#endif //BLINDMANSBLUFF_DECK_H
