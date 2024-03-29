#include "Gambler.hpp"

Gambler::Gambler(unsigned int money) : my_money(money)
{
}

unsigned int Gambler::get_money() const
{
	return my_money;
}

void Gambler::set_money(unsigned int new_money)
{
	my_money = new_money;
}

void Gambler::list_cards() const
{
	std::cout << "Your Cards:" << std::endl;
	Player::list_cards();
	std::cout << "Card Total: " << sum()  << "\n" << std::endl;
}