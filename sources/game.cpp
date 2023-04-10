#include <iostream>
#include <vector>
#include "game.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "card.hpp"

using namespace std;
using namespace ariel;

Game::Game(Player &pla1, Player &pla2): pla1(pla1), pla2(pla2){
    this->deck=Deck();
    this->deck.shuffle();
    // cout<<this->deck.deck_to_string()<<endl;
    while (!(this->deck.isEmpty()))
    {
        this->pla1.add_card(this->deck.drawCard());
        this->pla2.add_card(this->deck.drawCard());
    }
}

void Game::playTurn(){

    if(&this->pla1==&this->pla2)
    throw "Need two diffrent players in order to play";
    if(this->pla1.stacksize() == 0 || this->pla2.stacksize() == 0)
    throw "Cant play! no more card left";
    
    // cout<<"size of temp is"<<this->temp.size()<<endl;

    if(this->pla1.stacksize()!=0&&this->pla2.stacksize()!=0){
        if(compare()==1){
            this->pla1.set_wins();
            while(!(this->temp.empty())){
                this->pla1.add_card_second_hand(temp.back());
                temp.pop_back();
            }
            this->pla1.add_card_second_hand(this->pla2.get_hand().back());
            this->pla1.add_card_second_hand(this->pla1.get_hand().back());           
            this->pla2.get_hand().pop_back();
            this->pla1.get_hand().pop_back();
            
            (this->pla1).set_wins();
            this->flag=1;
        }
        else if(compare()==-1){
            this->pla2.set_wins();
            while(!(this->temp.empty())){
                this->pla2.add_card_second_hand(temp.back());
                temp.pop_back();
            }
            this->pla2.add_card_second_hand(this->pla1.get_hand().back());
            this->pla2.add_card_second_hand(this->pla2.get_hand().back());\
            this->pla1.get_hand().pop_back();
            this->pla2.get_hand().pop_back();

            (this->pla2).set_wins();
            this->flag=-1;
        }
        else{
                this->draws++;
                this->temp.push_back(this->pla1.get_hand().back());
                this->temp.push_back(this->pla2.get_hand().back());
                this->pla1.get_hand().pop_back();
                this->pla2.get_hand().pop_back();

                this->flag=0;

                if(this->pla1.stacksize()<1&&this->pla2.stacksize()<1){
                    split_cards(this->temp);
                    return;
                }
                playTurn();
                
        }
    }
    else return;
}

int Game:: compare(){
    if(this->pla1.get_hand().back().Get_Card_Val()==2&&this->pla1.get_hand().back().Get_Card_Val()==14) return 1;
    if(this->pla1.get_hand().back().Get_Card_Val()==14&this->pla1.get_hand().back().Get_Card_Val()==2) return -1;
    if(this->pla1.get_hand().back().Get_Card_Val()==this->pla2.get_hand().back().Get_Card_Val()) return 0;
    else if (this->pla1.get_hand().back().Get_Card_Val()>this->pla2.get_hand().back().Get_Card_Val()) return 1;
    else return -1;
    }

void Game:: split_cards(vector <Card>& temp){
    while(!(temp.empty())){
        this->pla1.add_card_second_hand(temp.back());
        temp.pop_back();
        this->pla2.add_card_second_hand(temp.back());
        temp.pop_back();
    }
}
void Game::playAll(){
    while(this->pla1.stacksize()!=0&&this->pla2.stacksize()!=0){
        playTurn();
        this->rounds++;
        // printLastTurn();
    }
}

Deck Game:: get_deck(){
    return this->deck;
}


void Game::printLastTurn(){
    vector<Card> temp1=this->pla1.get_second_hand();
    vector<Card> temp2=this->pla2.get_second_hand();

    if(this->flag==1){
    cout<<this->pla1.get_name()<<" played "<<temp1.back().Get_Card_Val()<<" of "<<temp1.back().Get_Cards_Type()<< " ";
    temp1.pop_back();
    cout<<this->pla2.get_name()<<" played "<<temp1.back().Get_Card_Val()<<" of "<<temp1.back().Get_Cards_Type()<<" . "<<this->pla1.get_name()<< " wins."<<endl;
    return;
    }
    if(this->flag==-1){
    cout<<this->pla2.get_name()<<" played "<<temp2.back().Get_Card_Val()<<" of "<<temp2.back().Get_Cards_Type()<< " ";
    temp2.pop_back();
    cout<<this->pla1.get_name()<<" played "<<temp2.back().Get_Card_Val()<<" of "<<temp2.back().Get_Cards_Type()<<" . "<<this->pla2.get_name()<< " wins."<<endl;
    return;
    }
}
void Game::printWiner(){
    if(this->pla1.get_second_hand().size()>this->pla2.get_second_hand().size())
        cout<<"the winner is: "<< this->pla1.get_name()<<" !!!"<<endl;
    else if(this->pla1.get_second_hand().size()<this->pla2.get_second_hand().size())
        cout<<"the winner is: "<< this->pla2.get_name()<<" !!!"<< endl;
    else
        cout<<"its a draw !!!"<<endl;
}

void Game::printLog(){}

void Game::printStats(){
        cout<< "~~~~~~~~~~~~~~~~~~~~" << "\n";
        cout << this->pla1.get_name()<< " statistics:" << "\n";
        cout << "Number of cards taken: "<< this->pla1.cardesTaken() << "\n";
        cout << "Number of rounds win: "<< this->pla1.get_wins()/2 << "\n";
        cout << "Number of rounds played :"<< this->rounds << "\n";
        double winRate = this->pla1.get_wins()/2;
        winRate /= this->rounds;
        winRate *=100;
        cout<< "Win rate: " << winRate << "%\n";
        cout << "Cards won: " <<this->pla1.cardesTaken()<<"\n";
        cout<< "~~~~~~~~~~~~~~~~~~~~" << "\n";

        cout<< "~~~~~~~~~~~~~~~~~~~~" << "\n";
        cout << this->pla2.get_name()<< " statistics:" << "\n";
        cout << "Number of cards taken: "<< this->pla2.cardesTaken() << "\n";
        cout << "Number of rounds win: "<< this->pla2.get_wins()/2 << "\n";
        cout << "Number of rounds played :"<< this->rounds << "\n";
        double winRate2 = this->pla2.get_wins()/2;
        winRate2 /= this->rounds;
        winRate2 *=100;
        cout<< "Win rate: " << winRate2 << "%\n";
        cout << "Cards won: " <<this->pla2.cardesTaken()<<"\n";
        cout<< "~~~~~~~~~~~~~~~~~~~~" << "\n";

        double drawRate = draws;
        drawRate /= rounds;
        drawRate *=100;
        cout << "game stats:" << "\n";
        cout << "draw rate:" << drawRate<<"%\n";
        cout << "draws amount:" << this->draws << "\n";
    }


