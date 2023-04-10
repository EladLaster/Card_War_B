#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include "deck.hpp"
#include <vector>

using namespace std;
using namespace ariel;



Player::Player(string name){
    this->name=name;
}

void Player::add_card(Card card) {
    this->hand.push_back(card);
}

void Player::add_card_second_hand(Card card) {
    this->second_hand.push_back(card);
}

void Player::clear_hand(){
        hand.clear();
    }

string Player::get_name(){
        return name;
    }

vector<Card>& Player::get_hand(){
    return this->hand;
}

vector<Card>& Player::get_second_hand(){
    return this->second_hand;
}
  
    int Player::stacksize(){
        return this->hand.size();
    }

    int Player::cardesTaken(){
        return this->second_hand.size();
    }

    void Player::set_wins(){
        this->wins++;
    }

    int Player::get_wins(){
        return this->wins;
    }

    string Player::hand_to_string(){
    vector<Card> temp=this->hand;
    string answer="[";
    while(!(temp.empty())){
        answer=answer+to_string(temp.back().Get_Card_Val())+",";
        temp.pop_back();
    }
    answer=answer+"]";
    return answer;
}
string Player::second_hand_to_string(){
    vector<Card> temp=this->second_hand;
    string answer="[";
    while(!(temp.empty())){
        answer=answer+to_string(temp.back().Get_Card_Val())+",";
        temp.pop_back();
    }
    answer=answer+"]";
    return answer;
}
