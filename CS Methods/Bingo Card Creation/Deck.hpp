#ifndef BINGO_DECK_H
#define BINGO_DECK_H

#include "Card.h"

#include <ostream>
#include <vector>

class Deck {

public:
    Deck(int cardSize, int cardCount, int numberMax);	//constructor
    ~Deck();

    void print() const;	//prints out all cards in deck
    void print(int cardIndex) const;	//prints out a specific card
	std::vector<Card *> deckOfCards;	//vector of Card pointers
};

#endif //BINGO_DECK_H
