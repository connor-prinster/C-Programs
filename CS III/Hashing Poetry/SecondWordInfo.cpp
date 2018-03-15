#include "SecondWordInfo.h"



SecondWordInfo::SecondWordInfo()
{
}
SecondWordInfo::~SecondWordInfo()
{
}

SecondWordInfo::SecondWordInfo(std::string s, int c)
{
	word = s;
	count = c;
}

std::string SecondWordInfo::toString()
{
	return word + "(" + std::to_string(count) + ") "; //returns "word(freq) ";
}


