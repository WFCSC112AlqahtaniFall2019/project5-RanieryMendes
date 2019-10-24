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

    int nWin = 0, nLoss = 0, nTie = 0;

    play = true;
    srand(time(0));
    Deck game;
    Deck discardPile;
    game.populate();
    game.shuffle();
    Card playerCard;
    Card computerCard;

    while(play) {

        playerCard = game.getCard();
        if (discardPile.addToDiscardPile(game) == false) { play = false; }
        computerCard = game.getCard();
        if (discardPile.addToDiscardPile(game) == false) { play = false; }


        // get user's bet
        cout << "Computer's value is ";
        computerCard.showValueOfCard();
        cout << endl;
        invalid = true;

        while (invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;

            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if ((playerCard > computerCard && guessedHigher) || (!(playerCard > computerCard) && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if ((playerCard > computerCard && !guessedHigher) || (!(playerCard > computerCard) && guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }

        cout << "\tYour value is ";
        playerCard.showValueOfCard();
        cout << endl;
        game.shuffle();


        // ask user to play again
        invalid = true;
        if (play == false) {
            // output stats
            cout << "Thanks for playing!" << endl;
            cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;
            invalid = false;
        }

        while (invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

    }
    if (play == false) {
        // output stats
        cout << "Thanks for playing!" << endl;
        cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;
        invalid = false;
    }

    return 0;
}