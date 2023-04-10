
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "card.hpp"
#include "deck.hpp"

using namespace std;
using namespace ariel;

    Deck::Deck(){
        for (int i=2; i < 15; ++i) {
            for (int j=0; j<4; ++j) {
                this->cards.push_back(Card(static_cast<ariel::Cards_Num>(i), static_cast<ariel::Cards_Type>(j)));
            }
        }
    }
    
    void Deck::shuffle() {
        static std::mt19937 mt(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
        std::shuffle(this->cards.begin(),this->cards.end(), mt);
    }
    
    Card Deck::drawCard() {
        Card card = this->cards.back();
        this->cards.pop_back();
        return card;
    }
    
    bool Deck::isEmpty(){
        return this->cards.empty();
    }

    int Deck::get_size(){
        return this->cards.size();
    }

    string Deck::deck_to_string(){
    vector<Card> temp=this->cards;
    string answer="[";
    while(!(temp.empty())){
        answer=answer+to_string(temp.back().Get_Card_Val())+",";
        temp.pop_back();
    }
    answer=answer+"]";
    return answer;
}

    
