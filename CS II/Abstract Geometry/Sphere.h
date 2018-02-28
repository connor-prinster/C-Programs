#pragma once
#include "Geometry.h"

#include <string>

const float PI = 3.14159265;

class Sphere : public Geometry
{
public:
	//constructor
	Sphere(std::string m_name, float radius); 
	//methods
	float computeSurface() override;
	float computeVolume() override;
	
protected:
	//class specific variable
	float m_radius;
};

