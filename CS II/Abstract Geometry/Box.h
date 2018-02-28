#pragma once
#include "Geometry.h"

class Box : public Geometry
{
public:
	//constructor
	Box(std::string name, float height, float width, float length);
	//methods specific to Box
	float computeSurface() override;
	float computeVolume() override;
	~Box(); //won't let me run program without this destructor

protected:
	//variables specific to the Box class
	float m_height;
	float m_width;
	float m_length;
};

