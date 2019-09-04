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

	// Look until stand or card total is greater than 21
	while (!is_standing && p1.sum() < 21)
	{
		// Hit or Stand
		menu();
		select(cd, p1, is_standing);
	}

	// Check to see who won hand
	results(bet, cd, p1, p2);

	return 0;
}

