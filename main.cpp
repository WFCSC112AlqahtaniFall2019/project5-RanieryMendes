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

    Card computer;
    Card player;
    string test = player.getCard();
    cout << test << endl;
    string computerValue;
    string playerValue;
    srand(time(0));


    while(play) {

        //get random values for being elements of Player card's suit array and rank array
        int rankPlayer; int suitPlayer;
        rankPlayer = rand()%13;
        suitPlayer = rand()%4;
        //set the Player's card with the suit and rank obtained above
        player.setCard(rankPlayer, suitPlayer);
        //Put in a string the Player's card info (suit and rank)
        playerValue = player.getCard();

        int rankComp; int suitComp;
        rankComp = rand()%13;
        suitComp = rand()%4;
        computer.setCard(rankComp, suitComp);
        computerValue = computer.getCard();


        // get user's bet
        cout << "Computer's value is " << computerValue << endl;
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
        if((player > computer && guessedHigher) || (!(player > computer) && !guessedHigher)){
            cout << "Great! You're right:" << endl;
            nWin++;
        }

        else if((player > computer && !guessedHigher) || (!(player > computer) && guessedHigher)){
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        }

        else {
            cout << "It's a tie:" << endl;
            nTie++;
        }

        cout << "\tYour value is " << playerValue << endl;

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