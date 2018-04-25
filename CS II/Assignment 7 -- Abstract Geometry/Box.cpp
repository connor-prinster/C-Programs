#include "Box.h"

Box::Box(std::string name, float height, float width, float length) : Geometry("Box", name)
{
	m_height = height;
	m_width = width;
	m_length = length;
}

float Box::computeSurface()
{
	float surfaceArea = 2 * this->m_length*this->m_height + 2 * this->m_length*this->m_width + 2 * this->m_width*this->m_height;
	return surfaceArea;
}

float Box::computeVolume()
{
	float area = this->m_length*this->m_height*this->m_width;
	return area;
}

Box::~Box(){}
