#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
#include <ctime>
using namespace std;

int main() {

    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;

    int compValue, userValue, nWin = 0, nLoss = 0, nTie = 0;

    play = true;
    srand(time(0));
    Deck game;
    Deck discardPile;
    game.populate();
    game.shuffle();
    cout << "create card objects" << endl;
    Card playerCard;
    Card computerCard;
    cout << "playerCard and computerCard" << endl;

    while(play) {

        cout<< "Im in the while loop" << endl;
         game.shuffle();
         playerCard = game.getCard();
        if(discardPile.addToDiscardPile()){ play = false;}
         computerCard = game.getCard();
        if(discardPile.addToDiscardPile()){ play = false;}
         cout << "Im here " << endl;

        // get user's bet
        cout << "Computer's value is " ;
        computerCard.showValueofCard();
        cout << endl;
        invalid = true;

        while(invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;

            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            }
            else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            }
            else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if((playerCard > computerCard && guessedHigher) || (!(playerCard > computerCard) && !guessedHigher)){
            cout << "Great! You're right:" << endl;
            nWin++;
        }

        else if((playerCard > computerCard && !guessedHigher) || (!(playerCard > computerCard) && guessedHigher)){
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        }

        else {
            cout << "It's a tie:" << endl;
            nTie++;
        }

        cout << "\tYour value is ";
        playerCard.showValueofCard();
        cout << endl;

        // ask user to play again
        invalid = true;

        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            }
            else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            }

            else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;

    return 0;
}