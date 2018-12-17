#pragma once

#include <string>

class SecondWordInfo
{
public:
	SecondWordInfo();
	~SecondWordInfo();

	std::string word;
	int count;
	std::string toString();
	SecondWordInfo(std::string s, int c);
	void increment() { count++; }
};

