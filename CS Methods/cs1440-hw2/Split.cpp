#include <string>
#include <sstream>

#include "Split.h"

bool Split::split(const std::string& s, char delimiter, std::string elements[], int expectedNumberOfElements) {
	std::stringstream ss;
	ss.str(s);
	std::string item;

	int i=0;
	while (std::getline(ss, item, delimiter) && i<expectedNumberOfElements) {
		elements[i++] = item;
	}
	return (i==expectedNumberOfElements);
}