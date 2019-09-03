#include "Card.hpp"

Card::Card(card_type ct):myCT(ct)
{
	switch (ct)
	{
	case ace: value = 1; break;
	case two: value = 2; break;
	case three: value = 3; break;
	case four: value = 4; break;
	case five: value = 5; break;
	case six: value = 6; break;
	case seven: value = 7; break;
	case eight: value = 8; break;
	case nine: value = 9; break;
	// Face cards and 10
	default: value = 10; break;
	}
}

int Card::get_value() const
{
	// Returns value from Card
	return value;
}

std::ostream& operator<<(std::ostream& strm, const Card& a)
{
	/*
	Overloads << operator and outputs Card Type
	*/
	std::string card_str;
	switch (a.myCT)
	{
	case ace: card_str = "Ace"; break;
	case two: card_str = "Two"; break;
	case three: card_str = "Three"; break;
	case four: card_str = "Four"; break;
	case five: card_str = "Five"; break;
	case six: card_str = "Six"; break;
	case seven: card_str = "Seven"; break;
	case eight: card_str = "Eight"; break;
	case nine: card_str = "Nine"; break;
	case ten: card_str = "Ten"; break;
	case jack: card_str = "Jack"; break;
	case queen: card_str = "Queen"; break;
	case king: card_str = "King"; break;
	}
	strm << card_str;
	return strm;
}

card_type Card::get_ct() const
{
	return myCT;
}