#ifndef CARDDECK_HPP
#define CARDDECK_HPP

#include <vector>
#include "Card.hpp"

class CardDeck
{
	private:
		std::vector<Card> cards;
	public:
		CardDeck();
		Card draw_card();
		int num_of_cards() const;
		void reset();

};



#endif