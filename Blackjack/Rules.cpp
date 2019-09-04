#include "Rules.hpp"
#include <iostream>

void initial_menu(unsigned int& bet, Gambler& p1)
{
	std::cout << "Money: " << p1.get_money() << std::endl;
	std::cout << "Current bet: " << bet << std::endl;
	std::cout << "Menu:" << std::endl;
	std::cout << "1 - Deal" << std::endl;
	std::cout << "2 - Change bet" << std::endl;
}

void initialize_game(CardDeck& cd, Gambler& p1, Dealer& p2)
{
	p2.initial_play(cd);
	p1.draw(cd);
	p1.draw(cd);
}

void initial_display(Gambler& p1, Dealer& p2)
{
	std::cout << "Player's Cards:" << std::endl;
	p1.list_cards();
	std::cout << "Current total: " << p1.sum() << std::endl;
	std::cout << "\nDealer's Cards: " << std::endl;
	p2.list_first_card();

}

void initial_select(CardDeck& cd, Gambler& p1, Dealer& p2, unsigned int& bet)
{
	int option;
	std::cin >> option;
	switch (option)
	{
	case 1: // Start game
	{
		initialize_game(cd, p1, p2);
		break;
	}
	case 2: // Change bet value
	{
		bool validBet = false;
		// Check if bet is valid amount
		while (!validBet)
		{
			// Input bet amount
			std::cout << "Enter bet amount:" << std::endl;
			std::cin >> bet;

			// 50 <= bet <= money
			if (bet >= 50 && bet <= p1.get_money())
				validBet = true;
			else
				std::cout << "Invalid bet amount" << std::endl;
		}
		// Start menu again
		initial_menu(bet, p1);
		initial_select(cd, p1, p2, bet);
		break;
	}
	default: // Option is not 1 || 2
	{
		std::cout << "Invalid option" << std::endl;
		initial_menu(bet, p1);
		initial_select(cd, p1, p2, bet);
		break;
	}

	}
}

void first_menu()
{
	std::cout << "1 - Hit " << std::endl;
	std::cout << "2 - Double down" << std::endl;
	std::cout << "3 - Stand" << std::endl;

}

// Hit, Double-Down, Stand
void first_select(unsigned int& bet, CardDeck& cd, Gambler& p1, bool& is_standing)
{
	int option;
	std::cin >> option;
	switch (option)
	{
	case 1: // Hit
	{
		p1.draw(cd);
		break;
	}
	case 2: // Double Down
	{
		// Cannot bet more money than actually have
		if ( (2 * bet) <= p1.get_money() ) 
		{
			// Double bet amount and draw one card
			bet *= 2;
			p1.draw(cd);
			is_standing = true;
			break;
		}
		else 
		{
			std::cout << "Cannot double down" << std::endl;
			first_menu();
			first_select(bet, cd, p1, is_standing);
			break;
		}
	}
	case 3: // Stand
	{
		is_standing = true;
		break;
	}
	default: // Invalid option
	{
		std::cout << "Invalid option" << std::endl;
		first_menu();
		first_select(bet, cd, p1, is_standing);
		break;
	}

	}
}

// Hit or Stand
void menu()
{
	std::cout << "1 - Hit " << std::endl;
	std::cout << "2 - Stand" << std::endl;

}

void select(CardDeck& cd, Gambler& p1, bool& is_standing)
{
	int option;
	std::cin >> option;
	switch (option)
	{
	case 1: // Hit
	{
		p1.draw(cd);
		break;
	}
	case 2: // Stand
	{
		is_standing = true;
		break;
	}
	default: // Invalid option
	{
		std::cout << "Invalid option" << std::endl;
		menu();
		select(cd, p1, is_standing);
		break;
	}

	}
}

void compare(Gambler& p1, Dealer& p2, CardDeck& cd, unsigned int& bet)
{

}


