#ifndef GAMBLER_HPP
#define GAMBLER_HPP

#include "Player.hpp"

class Gambler : public Player
{
private:
	int my_money;
public:
	Gambler(int money);
	int get_money() const;
	void set_money(int new_money);
};

#endif