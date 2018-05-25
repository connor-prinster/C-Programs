#pragma once

#include <fstream>
#include "Analyzer.h"
#include "Station.h"

#define MAX_STATION_COUNT 20

class Region {
	private:
		Station*        _stations[MAX_STATION_COUNT];
		int             _stationCount=0;
		int             _currentStation;

	public:
		Region();
		void load(std::ifstream &input);
		void resetStationIteration();
		Station* getNextStation();
		Station* findStation(std::string& id);
		bool split(const std::string& s, char delimiter, std::string elements[], int expectedNumberOfElements);

	private:
		Station* addStation(std::string& id, std::string& name);
};

