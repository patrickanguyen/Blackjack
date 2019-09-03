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

	initial_menu(bet, p1);
	initial_select(cd, p1, p2, bet);

	initial_display(p1, p2);

	return 0;
}

