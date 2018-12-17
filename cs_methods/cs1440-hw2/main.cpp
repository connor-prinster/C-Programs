#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Analyzer.h"
#include "Region.h"

int main(int argc, char* argv[]) {
	if(argc == 1) {
		std::cout << "This file requires at least one argument to run correctly. Program will only run correctly with less than 2 arguments.\n";
		std::cout << "   -The first argument to be input is the file to be analyzed\n";
		std::cout << "     --e.g. inputting \'./main Data/*\' will read values for Logan, Ogden, Bountiful, and Experimental Farm\n";
		std::cout << "   -The second argument to be input is the specific area to be analyzed\n";
		std::cout << "     --e.g. inputting \'./main Data/* COOP:*\' will analyze all data points with \"STATION\" values of COOP:*\n";
		std::cout << "   -The program accepts more than 2 arguments, but any more than 2 will just be ignored by the program\n";
		std::cout << "     --e.g. inputting \'./main Data/* COOP:* COOP:**\' will analyze all data points with \"STATION\" values of COOP:* and simply ignore COOP:**\n";
		
	}
	else if (argc>1) {
		std::ifstream inputStream(argv[1], std::ios_base::in);

		Region region;
		region.load(inputStream);

		Analyzer analyzer;
		
		if (argc>2) {
			std::string stationId(argv[2]);
			Station* station = region.findStation(stationId);
			if (station!= nullptr)
				analyzer.analyze(station);
		}
		else {
			region.resetStationIteration();
			Station *station;
			while ((station = region.getNextStation()) != nullptr)
				analyzer.analyze(station);
		}
	}
	std::cout << std::endl;
	return 0;
}



