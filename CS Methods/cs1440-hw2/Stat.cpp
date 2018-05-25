#include "Stat.h"

#include <sstream>
#include <string>

//===================================================================
Stat::Stat(std::string time, std::string qgag, std::string qpcp) {
	_time = time;
	_precipitationQgag = stof(qgag);
	if (_precipitationQgag<= -9999 || _precipitationQgag >= 999)
		_precipitationQgag = 0;

	_precipitationQpcp = stof(qpcp);
	if (_precipitationQpcp<= -9999 || _precipitationQpcp >= 999)
		_precipitationQpcp = 0;
}
float Stat::getPrecipitationQgag() { 
	return _precipitationQgag; 
}
	
float Stat::getPrecipitationQpcp() { 
	return _precipitationQpcp; 
}
std::string Stat::getTime() { 
	return _time; 
}
//===================================================================		