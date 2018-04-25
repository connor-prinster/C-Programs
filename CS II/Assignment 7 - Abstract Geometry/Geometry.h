#pragma once
#include <string>

class Geometry
{
public:
	//constructors
	Geometry(); //The compiler didn't let me run the program without a default Geometry constructor
	Geometry(std::string type, std::string name);
	//methods
	std::string getName();
	std::string Geometry::getType();
	virtual float computeVolume() = 0;
	virtual float computeSurface() = 0;

protected:
	//the variables the Geometry class takes care of
	std::string m_name;
	std::string m_type;
};

