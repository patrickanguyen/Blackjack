#include <iostream>
#include <vector>

#include "CardDeck.hpp"
#include "Gambler.hpp"
#include "Rules.hpp"
#include "Dealer.hpp"

int main()
{
	// Initalize card deck, gambler, and dealer
	bool keep_playing = true;
	CardDeck cd;
	Gambler p1(1000);
	Dealer p2;
	unsigned int bet = 50;

	do
	{
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

		
		if (p1.get_money() > 0)
		{
			// Continue or end game
			end_menu();
			end_select(keep_playing);
		}
		else // If out of money, end game
		{
			std::cout << "You're all out of money" << std::endl;
		}

	} while (keep_playing && p1.get_money() > 0);

	// Print out money
	std::cout << "Your Money: " << p1.get_money() << std::endl;

	return 0;
}

