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
	p1.list_cards();
	p2.list_first_card();

}

void initial_select(CardDeck& cd, Gambler& p1, Dealer& p2, unsigned int& bet)
{
	int option;
	std::cin >> option;
	std::cout << std::endl;
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
		std::cout << std::endl;
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
	std::cout << "Menu:" << std::endl;
	std::cout << "1 - Hit " << std::endl;
	std::cout << "2 - Double down" << std::endl;
	std::cout << "3 - Stand" << std::endl;

}

// Hit, Double-Down, Stand
void first_select(unsigned int& bet, CardDeck& cd, Gambler& p1, bool& is_standing)
{
	int option;
	std::cin >> option;
	std::cout << std::endl;
	switch (option)
	{
	case 1: // Hit
	{
		p1.draw(cd);
		p1.list_cards();
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
			p1.list_cards();
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
	std::cout << "Menu:" << std::endl;
	std::cout << "1 - Hit " << std::endl;
	std::cout << "2 - Stand" << std::endl;

}

void select(CardDeck& cd, Gambler& p1, bool& is_standing)
{
	int option;
	std::cin >> option;
	std::cout << std::endl;
	switch (option)
	{
	case 1: // Hit
	{
		p1.draw(cd);
		p1.list_cards();
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


// Compare the hands of the dealer and gambler
// True = Gambler won / False = Dealer won
result compare(Gambler& p1, Dealer& p2, CardDeck& cd)
{
	// If gambler busted, automatic win for dealer
	if (p1.sum() > 21)
	{
		std::cout << "Bust!" << std::endl;
		return LOSE;
	}
	// If gambler got blackjack, automatic win for gambler
	else if (p1.sum() == 21)
	{
		std::cout << "Blackjack!" << std::endl;
		return WIN;
	}
	else
	{
		// Dealer must draw to at least 17
		p2.play(cd);
		p1.list_cards();
		p2.list_cards();

		// If dealer busted, gambler wins
		if (p2.sum() > 21)
			return WIN;
		// If same value, return tie
		else if (p1.sum() == p2.sum())
			return TIE;
		else
			return ( p1.sum() > p2.sum() ) ? WIN : LOSE;
	}
}

void results(unsigned int bet, CardDeck& cd, Gambler& p1, Dealer& p2)
{
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
		std::cout << "You lost!" << std::endl;
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
}