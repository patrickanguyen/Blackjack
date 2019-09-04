#ifndef RULES_HPP
#define RULES_HPP

#include "Gambler.hpp"
#include "CardDeck.hpp"
#include "Dealer.hpp"

void menu();
void initial_menu(unsigned int& bet, Gambler& p1);
void initialize_game(CardDeck&, Gambler&, Dealer&);
void initial_display(Gambler& p1, Dealer& p2);
void initial_select(CardDeck& cd, Gambler& p1, Dealer& p2, unsigned int& bet);
void select(CardDeck& cd, Gambler& p1, bool& is_standing);
void first_select(unsigned int& bet, CardDeck& cd, Gambler& p1, bool& is_standing);
void first_menu();

#endif