/*                                                                                                                                         
 * WARNING!
 *
 * You should not edit this file
 */

#include "Employment.hpp"

Employment::Employment(
		std::string       _area_fips,
		unsigned      _annual_avg_emplvl,
		long unsigned _total_annual_wages,
		Employment*   _next
		) {
	this->area_fips          =  _area_fips;
	this->annual_avg_emplvl  =  _annual_avg_emplvl;
	this->total_annual_wages =  _total_annual_wages;
	this->next               = _next;
}

std::ostream& operator<<(std::ostream& os, const Employment& emp) {
	os << "[" << emp.area_fips << "]"
		<< "\tEmployment Level:   " << emp.annual_avg_emplvl  << std::endl
		<< "\tTotal Annual Wages: " << emp.total_annual_wages << std::endl;
	return os;  
}
