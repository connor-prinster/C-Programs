#pragma once

#define MAX_DAYS          365

#include <string>

#include "Day.h"

class Station {
	private:
		std::string         _id;
		std::string         _name;
		Day*               _days[MAX_DAYS];
		int                 _dayCount = 0;
		int                 _currentDay = -1;

	public:
		Station(std::string& id, std::string& name);
		void load(std::string& datetime, std::string& qgag, std::string& qpcp);
		void resetDayIteration();
		Day* getDayNext();
		bool split(const std::string& s, char delimiter, std::string elements[], int expectedNumberOfElements);
		std::string getId();
		std::string getName();

	private:
		Day* findDay(std::string& date);
		Day* addDay(std::string& date);
};

