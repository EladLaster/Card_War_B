# ifndef PLAYER
# define PLAYER

#include <iostream>
#include <vector>
#include "card.hpp"

using namespace std;
namespace ariel {

class Player{

public:

    Player (string name);
    void add_card(Card card);
    void add_card_second_hand(Card card);
    void clear_hand();
    string get_name();
    vector<Card>& get_hand();
    vector<Card>& get_second_hand();
    int stacksize();
    int cardesTaken();
    string hand_to_string();
    string second_hand_to_string();
    void set_wins();
    int get_wins();


private:    

    string name;
    vector<Card> hand;
    vector<Card> second_hand;
    int cards_in_hands=0;
    int cards_taken=0;
    int wins=0;

};
}

#endif