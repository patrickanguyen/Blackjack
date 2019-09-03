#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

enum card_type {
	ace, two, three, four, five, six,
	seven, eight, nine, ten,
	jack, queen, king
};

class Card
{
private:
	card_type myCT;
	int value;
public:
	Card(card_type ct);
	int get_value() const;
	friend std::ostream& operator<<(std::ostream& strm, const Card& a);
	card_type get_ct() const;

};



#endif