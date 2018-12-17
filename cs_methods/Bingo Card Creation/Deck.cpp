#include "Deck.hpp"

Deck::Deck(int cardSize, int cardCount, int numberMax)
{
	for (int i = 0; i < cardCount; i++)	//a for-loop will add "cardCount" cards to the decOfCards vector of cards
	{
		//int randNum = rand() % numberMax + 1;
		deckOfCards.push_back(new Card(cardSize, numberMax, i));	//inserts a card of with size = cardSize and the randomly-generated number with the card numberd "i"
	}
}

Deck::~Deck()
{
	for (unsigned int i = 0; i < deckOfCards.size(); i++)
	{
		delete deckOfCards[i];
		deckOfCards[i] = NULL;
	}
	deckOfCards.clear();
}

void Deck::print() const
{
	for (unsigned int i = 0; i < deckOfCards.size(); i++)
	{
		deckOfCards[i]->toString();
		std::cout << "\n";
	}
}

void Deck::print(int cardIndex) const
{
	deckOfCards[cardIndex]->toString();
	std::cout << "\n";
}