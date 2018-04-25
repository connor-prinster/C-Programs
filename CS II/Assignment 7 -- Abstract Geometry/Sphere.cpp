#include "Sphere.h"
#include <string>
#include <math.h>

Sphere::Sphere(std::string name, float radius)
{
	m_type = "Sphere";
	m_name = name;
	m_radius = radius;
}

float Sphere::computeSurface()
{
	float surfaceArea = 4 * PI* pow(this->m_radius, 2);
	return surfaceArea;
}

float Sphere::computeVolume()
{
	float volume = (4 * PI*pow(this->m_radius, 3)) / 3;
	return volume;
}
