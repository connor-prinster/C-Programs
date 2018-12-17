#include "Geometry.h"
#include <string>

Geometry::Geometry(){}

Geometry::Geometry(std::string type, std::string name) :
	m_type(type), m_name(name){}

std::string Geometry::getName()
{
	return this->m_name;
}

std::string Geometry::getType()
{
	return this->m_type;
}
