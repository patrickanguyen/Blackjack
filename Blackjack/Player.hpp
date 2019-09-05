#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Card.hpp"
#include "CardDeck.hpp"

class Player
{
private:
	std::vector<Card> drawn_cards;
	int num_of_aces() const;

public:
	void draw(CardDeck& cd);
	void reset();
	void list_cards() const;
	unsigned int sum() const;
	void ADD_CERTAIN_CARD(Card c);
	Card get_card(int index) const;
	int num_cards() const;
};

#endif