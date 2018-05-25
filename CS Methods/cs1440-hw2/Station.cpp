#include "Station.h"
#include "Split.h"


#include <string>
#include <sstream>

//================================================================================================================
Station::Station(std::string& id, std::string& name) {
	_id = id;
	_name = name;
}
//================================================================================================================
void Station::load(std::string& datetime, std::string& qgag, std::string& qpcp) {
	Split splitter;
	std::string dateParts[2];
	if (splitter.split(datetime, ' ', dateParts, 2)) {
		Day* day = findDay(dateParts[0]);
		if (day== nullptr)
			day = addDay(dateParts[0]);

		if (day != nullptr) {
			Stat* stat = new Stat(dateParts[1], qgag, qpcp);
			day->addStat(stat);
		}
	}
	else {
		std::cerr << "Invalid date/time << " << datetime << std::endl;
	}
}
//================================================================================================================
void Station::resetDayIteration() {
	_currentDay = 0;
}
//================================================================================================================
Day* Station::getDayNext() {
	Day* day = nullptr;
	if (_currentDay < _dayCount)
		day = _days[_currentDay++];
	return day;
}
//================================================================================================================
//bool Station::split(const std::string& s, char delimiter, std::string elements[], int expectedNumberOfElements) {
//	std::stringstream ss;
//	ss.str(s);
//	std::string item;
//
//	int i=0;
//	while (std::getline(ss, item, delimiter) && i<expectedNumberOfElements) {
//		elements[i++] = item;
//	}
//	return (i==expectedNumberOfElements);
//}
//================================================================================================================
std::string Station::getId() { 
	return _id; 
}
//================================================================================================================
std::string Station::getName() { 
	return _name;
}
//================================================================================================================
Day* Station::findDay(std::string& date) {
	Day* day = nullptr;

	for (int i=0; i<_dayCount && day==nullptr; i++) {
		if (_days[i]->getDate().compare(date)==0)
			day = _days[i];
	}

	return day;
}
//================================================================================================================
Day* Station::addDay(std::string& date) {
	Day* day = nullptr;
	if (_dayCount<MAX_DAYS) {
		day = new Day(date);
		_days[_dayCount++] = day;
	}
	else
		std::cerr << "Too many days for station " << getName() << std::endl;

	return day;
}
//================================================================================================================











