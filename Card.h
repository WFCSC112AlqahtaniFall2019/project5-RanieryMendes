#ifndef BLINDMANSBLUFF_CARD_H
#define BLINDMANSBLUFF_CARD_H
#include <string>
#include <ctime>
#include <random>
using namespace std;


// ranks are ordered Ace-low and Queen-high
const string ranks[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","King","Queen"};
// suits are ordered alphabetically
const string suits[] = {"Clubs","Diamonds","Hearts","Spades"};

class Card {

public:
    Card ();
    Card (string rank, string suits);
    void formCard ();
    bool operator >(Card tmp);
    void setCard(int rank, int suits);
    void showValueOfCard ();

private:
    string fullSentence;
    string suitCard;
    string rankCard;
};


#endif //BLINDMANSBLUFF_CARD_H
