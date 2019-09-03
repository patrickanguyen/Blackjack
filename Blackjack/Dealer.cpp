#include "Dealer.hpp"

// After player has stopped hitting, dealer starts drawing
void Dealer::play(CardDeck& cd)
{
	while (sum() <= 17)
	{
		draw(cd);
	}
}

// Dealer starts round by drawing two cards
void Dealer::initial_play(CardDeck& cd)
{
	// Draw two cards
	draw(cd);
	draw(cd);
}

void Dealer::list_first_card()
{
	std::cout << get_card(0) << std::endl;
}
