/*                                                                                                                                         
 * WARNING!
 *
 * You should not edit this file
 */

#include <iomanip>

#include "Report.hpp"

const int DISP_WIDTH = 35;

template<typename T>
void printLine(std::ostream& os, std::string label, T item) {
	os << std::left << std::setw(DISP_WIDTH) << label << item << std::endl;
}

template<typename T>
void printLine(std::ostream& os, std::string label, char prefix, T item) {
	os << std::left << std::setw(DISP_WIDTH) << label << prefix << item << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Report& rpt) {
	os  << "[============]\n"
		   "[Final Report]\n"
		   "[============]\n\n"
		   "Statistics over all industries in 2016:\n"
		   "=======================================\n"
		   << std::fixed << std::setprecision(12);

	printLine(os, "Number of FIPS areas in report",       rpt.num_areas);
	os << std::endl;

	printLine(os, "Total annual wages",  '$',             rpt.total_wages);
	printLine(os, "Minimum annual wage", '$',             rpt.min_wages);
	printLine(os, "Median annual wage",  '$',             rpt.med_wages);
	printLine(os, "Maximum annual wage", '$',             rpt.max_wages);
	os << std::endl;

	printLine(os, "Total annual employment level",        rpt.total_emplvl);
	printLine(os, "Median annual employment level",       rpt.med_emplvl);
	printLine(os, "Maximum annual employment level",      rpt.max_emplvl);
	printLine(os, "Minimum annual employment level",      rpt.min_emplvl);
	os << std::endl;

	return os;  
}
