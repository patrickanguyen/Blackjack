#ifndef GAMBLER_HPP
#define GAMBLER_HPP

#include "Player.hpp"

class Gambler : public Player
{
private:
	unsigned int my_money;
public:
	Gambler(unsigned int money);
	unsigned int get_money() const;
	void set_money(unsigned int new_money);
	void list_cards();
};

#endif