#pragma once

#include <string>

class Stat 
{
	private:
		std::string _time;
		float _precipitationQgag;  // Precipitation volume in 1/100th of (cubic?) inch
		float _precipitationQpcp;  // Precipitation amount in 1/100th of inch

	public:
	Stat(std::string time, std::string qgag, std::string cpcp);
	std::string getTime();
	float getPrecipitationQgag();
	float getPrecipitationQpcp();
};