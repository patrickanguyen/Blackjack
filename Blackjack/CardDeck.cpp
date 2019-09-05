#include "CardDeck.hpp"
#include "Card.hpp"
#include <ctime>

CardDeck::CardDeck(): cards(
	{Card(ace), Card(ace), Card(ace), Card(ace),
	Card(two), Card(two), Card(two), Card(two),
	Card(three), Card(three), Card(three), Card(three),
	Card(four), Card(four), Card(four), Card(four),
	Card(five), Card(five), Card(five), Card(five),
	Card(six), Card(six), Card(six), Card(six),
	Card(seven), Card(seven), Card(seven), Card(seven),
	Card(eight), Card(eight), Card(eight), Card(eight),
	Card(nine), Card(nine), Card(nine), Card(nine),
	Card(ten), Card(ten), Card(ten), Card(ten),
	Card(jack), Card(jack), Card(jack), Card(jack),
	Card(queen), Card(queen), Card(queen), Card(queen),
	Card(king), Card(king), Card(king), Card(king)})
{
	//Initalizes Card Deck to standard 52 deck
}


Card CardDeck::draw_card()
{
	/*
	Random selects card from deck and removes it from the deck
	Returns selected card
	*/
	// Select random card
	srand(time(NULL));
	int index = rand() % cards.size();
	Card drawn_card = cards.at(index);
	// Remove card from deck
	cards.erase(cards.begin() + index);
	// Return drawn card
	return drawn_card;
}


int CardDeck::num_of_cards() const
{
	// Returns number of cards in deck
	return cards.size();
}

void CardDeck::reset()
{
	cards = { Card(ace), Card(ace), Card(ace), Card(ace),
	Card(two), Card(two), Card(two), Card(two),
	Card(three), Card(three), Card(three), Card(three),
	Card(four), Card(four), Card(four), Card(four),
	Card(five), Card(five), Card(five), Card(five),
	Card(six), Card(six), Card(six), Card(six),
	Card(seven), Card(seven), Card(seven), Card(seven),
	Card(eight), Card(eight), Card(eight), Card(eight),
	Card(nine), Card(nine), Card(nine), Card(nine),
	Card(ten), Card(ten), Card(ten), Card(ten),
	Card(jack), Card(jack), Card(jack), Card(jack),
	Card(queen), Card(queen), Card(queen), Card(queen),
	Card(king), Card(king), Card(king), Card(king) };
}