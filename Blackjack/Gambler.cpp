#include "Gambler.hpp"

Gambler::Gambler(int money) : my_money(money)
{
}

int Gambler::get_money() const
{
	return my_money;
}

void Gambler::set_money(int new_money)
{
	my_money = new_money;
}
