#ifndef CARD
#define CARD

#include <iostream>

using namespace std;
namespace ariel {
enum class Cards_Num{
    Two=2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

enum class Cards_Type{
    Hearts,
    Diamonds,
    Spades,
    Clubs
};
}
class Card {

public:

    Card(ariel::Cards_Num cnum,ariel::Cards_Type ctype);
    int Get_Card_Val();
    string Get_Cards_Num();
    string Get_Cards_Type();

    private:

    ariel::Cards_Num cnum;
    ariel::Cards_Type ctype;
};


#endif