#pragma once

#include <string>
#include <vector>

#include "SecondWordInfo.h"

class FirstWordInfo
{
public:
	FirstWordInfo();

	std::string word;
	int count;
public:
	std::vector<SecondWordInfo> secondWordList;
	std::string toString();
	FirstWordInfo(std::string s, int c);
	void updateSecondWord(std::string w);
	void updateCount();

	~FirstWordInfo();
};

