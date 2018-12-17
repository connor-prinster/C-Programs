#include "printPi.hpp"

PrintPi::PrintPi() { }

PrintPi::PrintPi(std::string passFilename) {
	filename = passFilename;
}

PrintPi::~PrintPi() { }

void PrintPi::readFromFile() {
	std::fstream inFile;

	inFile.open("../piTemplate.txt");


	std::string temp;
	if (inFile.is_open()) {
		while (std::getline(inFile, temp)) {
			vec.push_back(temp + "\n");
		}
	}
	else {
		"\n\nIf no template is shown, you must run from ./src/build/ instead of where you're running it from now\n\n";
	}

	inFile.close();
}

void PrintPi::refactorImage() {
	for(unsigned int i = 0; i < vec.size(); i++) {
		std::replace(vec[i].begin(), vec[i].end(), '1', '2');
		std::replace(vec[i].begin(), vec[i].end(), '0', ' ');
		std::cout << vec[i];
	}
}

void PrintPi::print() {
	readFromFile();
	refactorImage();

	int piCtr = 0;
	for (unsigned int i = 0; i < vec.size(); i++) {
		for (unsigned int j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == '2') {
				vec[i][j] = 1;
			}

		}
	}
}
