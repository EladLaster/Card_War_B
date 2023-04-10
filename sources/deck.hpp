#ifndef DECK
#define DECK

#include <iostream>
#include <vector>
#include "card.hpp"


using namespace std;
namespace ariel {

class Deck {

public:

    Deck();
    void shuffle();
    Card drawCard();
    bool isEmpty();
    int get_size();
    string deck_to_string();

private:

    vector<Card> cards;

};
}
#endif