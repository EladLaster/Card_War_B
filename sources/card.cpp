#include <iostream>
#include "card.hpp"

using namespace std;
using namespace ariel;


Card::Card(Cards_Num cnum,Cards_Type ctype):cnum(cnum),ctype(ctype){}

int Card::Get_Card_Val(){
    Cards_Num cn = this->cnum;
    int val = static_cast<int>(cnum);
    return val;
}
string Card::Get_Cards_Num(){
    Cards_Num cn = this->cnum;
    int val = static_cast<int>(cnum);
    
    if(val==2) return "Two";
    if(val==3) return "Three";
    if(val==4) return "Four";
    if(val==5) return "Five";
    if(val==6) return "Six";
    if(val==7) return "Seven";
    if(val==8) return "Eight";
    if(val==9) return "Nine";
    if(val==10) return "Ten";
    if(val==11) return "Jack";
    if(val==12) return "Queen";
    if(val==13) return "King";
    if(val==14) return "Ace";
    return NULL;
}
string Card::Get_Cards_Type(){
    Cards_Type ct = this->ctype;
    int val = static_cast<int>(ctype);

    if(val==0) return "Hearts";
    if(val==1) return "Diamonds";
    if(val==2) return "Spades";
    if(val==3) return "Clubs";
    return NULL;
}
