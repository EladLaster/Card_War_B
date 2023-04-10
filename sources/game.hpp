#ifndef GAME
#define GAME

#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include "deck.hpp"
#include <vector>

using namespace std;
namespace ariel{

class Game{

public:
	

    Game (Player &pla1,Player &pla2);
    void playTurn();
	void printLastTurn();
	void playAll();
	void printWiner();
	void printLog();
	int compare();
	void split_cards(vector <Card>& temp);
	Deck get_deck();
	void printStats();
	

private:

	Player &pla1,&pla2;
	Deck deck;
	vector<Card> temp;
	int flag=0;
	int rounds;
    int draws;

};
}

#endif