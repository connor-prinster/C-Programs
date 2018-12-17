/*
 * WARNING!
 *
 * You do not need to edit this file
 */

#include <iostream>

#include "Area.hpp"

Area::Area( std::string	_area_fips,
		std::string	_area_title
		) {
	this->area_fips  = _area_fips;
	this->area_title = _area_title;
}


std::ostream& operator<<(std::ostream& os, const Area& a) {
	os << "[" << a.area_fips << "]\t" << a.area_title << std::endl;
	return os;
}
