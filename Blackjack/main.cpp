#include <iostream>
#include <vector>

#include "CardDeck.hpp"
#include "Gambler.hpp"
#include "Rules.hpp"
#include "Dealer.hpp"

int main()
{
	// Initalize card deck, gambler, and dealer
	CardDeck cd;
	Gambler p1(1000);
	Dealer p2;
	unsigned int bet = 50;
	bool is_standing = false;

	// Change bet, Deal
	initial_menu(bet, p1);
	initial_select(cd, p1, p2, bet);

	initial_display(p1, p2);

	// Hit, Double Down, Stand
	first_menu();
	first_select(bet, cd, p1, is_standing);

	// Hit or Stand
	while (!is_standing && p1.sum() < 21)
	{
		menu();
		select(cd, p1, is_standing);
	}

	// Check to see who won hand
	switch (compare(p1, p2, cd))
	{
	case WIN:
	{
		p1.set_money(p1.get_money() + bet);
		std::cout << "You won!" << std::endl;
		std::cout << "Money: " << p1.get_money() << std::endl;
		break;
	}
	case LOSE: 
	{
		p1.set_money(p1.get_money() - bet);
		std::cout << "You won!" << std::endl;
		std::cout << "Money: " << p1.get_money() << std::endl;
		break;
	}
	case TIE:
	{
		std::cout << "It's a tie!" << std::endl;
		std::cout << "Money: " << p1.get_money() << std::endl;
		break;
	}
	}

	return 0;
}

