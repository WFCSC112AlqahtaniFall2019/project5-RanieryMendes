#include "Deck.h"
#include <iostream>
#include <ctime>
using namespace std;

//constructor - initialize all private variables
Deck ::Deck() {

    arraySize = 52;
    cards = new Card [arraySize];
    cardsLeft = 0;

}
//destructor - deletes pointer of array
Deck::~Deck() {
    cout << "Deck Destructor Called" << endl;
    //delete [] this->cards;
    //this -> cards = nullptr;

}

// populate the deck with 52 cards - 4 suits with 13 cards each
void Deck ::populate() {

    int k = 0; // element of card array
    for (int j = 0; j < 4; j++){ // for loop that set the suits
    for (int i = 0; i < 13; i++) { // for loop that set the ranks
            cards[k].setCard(i,j);
            k++;
            cardsLeft++; // increments card left until it
        }
    }
    cardsLeft--;

}

// includes a member function that removes a card from the deck and returns its value, putting it into a Card object;
Card Deck ::getCard() {

    int card = cardsLeft; // store the card taken from the deck
    this-> cardsLeft--; //updates the amount of card

    return this->cards[card]; // return the card taken from the deck ; it will be inserted in the Card object which is in main
}

// shuffle the card that are in the deck
void Deck ::shuffle() {
    srand(time(0));

    //establish the number of swaps that will be carried out to shuffle the cards
    int numberOfSwaps = cardsLeft *cardsLeft;

    //swap the cards
    for (int i = 0; i < numberOfSwaps; i++){
        //securing that the cards that will be swapped are randomly selected
        int cardA = rand()%cardsLeft;
        int cardB = rand()%cardsLeft;
        //swap the two random cards selected
        swap(cards[cardA], cards[cardB]);
    }

}

//copy constructor for Deck class
Deck ::Deck(const Deck &origClass) {

    cards = new Card;
    *cards = *(origClass.cards);
}

// member function that adds a card to the deck (it returns false if there is no physical space in the deck)
bool Deck ::addToDiscardPile(Deck game) {

    if(this->cardsLeft == 51) {

        return false;
    }

    else{

        this->cardsLeft++;


        this->cards[cardsLeft] = game.cards[cardsLeft];



        return true;
    }

}


Deck Deck::operator=(Deck rhs){
    swap(*this, rhs);
    return *this;
}





