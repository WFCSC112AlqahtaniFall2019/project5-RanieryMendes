#include "Deck.h"
#include <iostream>
#include <time.h>
using namespace std;

//constructor - initialize all private variables
Deck ::Deck() {

    arraySize = 52; //the array size is the amount of cards in the deck
    cards = new Card [arraySize];  //dynamically allocate array
    cardsLeft = 0; // variable that will store the number of cards left in the deck

}
//destructor - deletes pointer of array
Deck::~Deck() {
    cout << "Deck Destructor Called" << endl;
     delete [] cards;
   //  cards = nullptr;

}

// populate the deck with 52 cards - 4 suits with 13 cards each
void Deck ::populate() {

    int k = 0; // index of cards din array
    for (int j = 0; j < 4; j++){ // for loop that set the suits
    for (int i = 0; i < 13; i++) { // for loop that set the ranks
            cards[k].setCard(i,j);
            k++; //update index of cards dynamic array
            cardsLeft++; // increments card left until it
        }
    }
    cardsLeft--;// decrement once in order to avoid unreachable memory location in later function calls involving the array

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

        int cardA = rand()%52;
        int cardB = rand()%52;
        //swap the two random cards selected
        swap(cards[cardA], cards[cardB]);
    }

}

//copy constructor for Deck class
Deck ::Deck(const Deck &origClass) {
    cout<<"copy constructor called"<<endl;
   arraySize=origClass.arraySize;
   cardsLeft=origClass.cardsLeft;
    cards = new Card[arraySize];
    for (int i = 0; i < arraySize ; ++i) {

        cards[i] = origClass.cards[i];

    }
}

// member function that adds a card to the discard deck (it returns false if there is no physical space in the deck)
bool Deck ::addToDiscardPile(Deck game) {

    //if condition to return false when all cards were taken from the deck( 0 -51 = 52 cards)
    if(this->cardsLeft == 51) {

        return false;
    }

    //while there are cards to be drown from the deck
    else{
        //cardsLeft in this function represents the number of cards in the discard deck
        this->cardsLeft++; // increment the number of cards in the discard pile
        this->cards[cardsLeft] = game.cards[cardsLeft]; //store in the discard pile the card that was taken from the
        return true;
    }

}

// copy and swap idiom
Deck Deck::operator=(Deck rhs){
    cout<<"assignment called"<<endl;
    swap(this->cards, rhs.cards);
    return *this;
}





