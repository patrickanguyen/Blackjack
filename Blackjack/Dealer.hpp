#ifndef DEALER_HPP
#define DEALER_HPP

#include "Player.hpp"

class Dealer : public Player
{
public:
	void play(CardDeck& cd);
	void initial_play(CardDeck& cd);
	void list_first_card() const;
	void list_cards() const;
};

#endif