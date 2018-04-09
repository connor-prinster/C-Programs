#include <iostream>
#include <ctime>

#include "UserInterface.hpp"
#include "Deck.hpp"
#include "Card.hpp"

int main()
{

	// Initialize the random number generator
	unsigned int seed = (unsigned int)time(NULL);
	srand(seed);

	UserInterface ui;
	ui.run();
}
