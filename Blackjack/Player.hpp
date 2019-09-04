#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Card.hpp"
#include "CardDeck.hpp"

class Player
{
private:
	std::vector<Card> drawn_cards;
	int num_of_aces();

public:
	void draw(CardDeck& cd);
	void reset();
	void list_cards();
	unsigned int sum();
	void ADD_CERTAIN_CARD(Card c);
	Card get_card(int index);
	int num_cards();
};

#endif