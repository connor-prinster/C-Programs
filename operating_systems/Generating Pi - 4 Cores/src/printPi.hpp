#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "map.hpp"

class PrintPi
{
public:
	PrintPi();
	PrintPi(std::string filename);
	~PrintPi();
	void print();

private:
	void readFromFile();
	void refactorImage();
	std::vector<std::string> vec; //stupid name but valid imho
	std::string filename;
};
