#include "Player.hpp"
#include <iostream>

int Player::num_of_aces() const
{
	int sum = 0;
	for (Card c : drawn_cards)
	{
		if (c.get_ct() == ace)
			sum += 1;
	}
	return sum;
}


void Player::draw(CardDeck& cd)
{
	drawn_cards.push_back(cd.draw_card());
}

void Player::reset()
{
	drawn_cards.clear();
}

void Player::list_cards() const
{
	for (Card card : drawn_cards)
	{
		std::cout << card << " ";
	}
	std::cout << std::endl;
}

unsigned int Player::sum() const
{
	int sum = 0;
	// If there isn't an ace in the deck, count sum normally
	for (Card c : drawn_cards)
	{
		sum += c.get_value();
	}
	if (num_of_aces() == 0)
		return sum;
	// If changing one ace to 11, is better for the player, add 10
	// If changing ace to 11, goes over 21 OR already is over 21, return unaltered sum
	else
	{
		if (sum + 10 <= 21)
			return sum + 10;
		else
			return sum;
	}
}


Card Player::get_card(int index) const
{
	return drawn_cards[index];
}

int Player::num_cards() const
{
	return drawn_cards.size();
}

// DEBUG METHOD
void Player::ADD_CERTAIN_CARD(Card c)
{
	drawn_cards.push_back(c);
}