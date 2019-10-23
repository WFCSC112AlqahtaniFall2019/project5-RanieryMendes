#include "Deck.h"
#include <iostream>
#include <ctime>
using namespace std;

Deck ::Deck() {
    cout << "Constructor Called" << endl;
    arraySize = 52;
    cards = new Card [arraySize];
    cardsLeft = 0;

}


void Deck ::populate() {
    cout << "Populator Called" << endl;

    int k = 0;
    for (int j = 0; j < 4; j++){
    for (int i = 0; i < 13; i++) {
            cards[k].setCard(i,j);
            k++;
            cardsLeft++;
        }
    }

    cout << "Array initialization ended" << endl;

}


Deck::~Deck() {
    cout << "Deck Destructor Called" << endl;
    delete cards;
    cards = nullptr;
}

Card Deck ::getCard() {

    int card = cardsLeft;
    cardsLeft--;

    return this->cards[card];
}

void Deck ::shuffle() {

    int numberOfSwaps = cardsLeft *cardsLeft;
    cout << "The number of swaps is: " << numberOfSwaps;
    for (int i = 0; i < numberOfSwaps; i++){
        int cardA = rand()%cardsLeft;
        int cardB = rand()%cardsLeft;
        cout << " swaping" << endl;
        swap(cards[cardA], cards[cardB]);
    }
    cout << "Shuffling ended" << endl;
}

Deck ::Deck(const Deck &origClass) {
    cout << "copy Constructor called" << endl;
    cards = new Card;
    *cards = *(origClass.cards);
}


bool Deck ::addToDiscardPile() {
    cout << "addToDiscardPile called" << endl;

    if(cardsLeft == 52) {

        return false;
    }

    else{
        cardsLeft++;
        cout << "adding to discard pile" << endl;
        this->cards[cardsLeft];
        cout<< "Discard pile has: " << 52 - cardsLeft << endl;

        return true;
    }

}


Deck Deck::operator=(Deck rhs){
    cout << "copy assignment operator called" << endl;
    swap(*this, rhs);
    return *this;
}





