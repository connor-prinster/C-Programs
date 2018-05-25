/*
 * WARNING!
 *
 * You do not need to edit this file
 */

#include "Employment.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Employment& emp) {
	os << "[" << emp.area_fips << "]"
		<< "\tEmployment Level:   " << emp.annual_avg_emplvl  << std::endl
		<< "\tTotal Annual Wages: " << emp.total_annual_wages << std::endl;
	return os;  
}
