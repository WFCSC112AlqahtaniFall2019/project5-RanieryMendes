#include "Deck.h"

Deck::~Deck() {

    delete cards;
    cards = nullptr;

}


