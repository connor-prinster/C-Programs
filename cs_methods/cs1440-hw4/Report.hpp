/*                                                                                                                                         
 * WARNING!
 *
 * You should not edit this file
 */

#pragma once

#include <ostream>

class Report {
	public:

		int           num_areas;

		unsigned long total_wages;
		unsigned long min_wages;
		unsigned long med_wages;
		unsigned long max_wages;

		unsigned      total_emplvl;
		unsigned      min_emplvl;
		unsigned      med_emplvl;
		unsigned      max_emplvl;

        Report() : num_areas(0),
            total_wages(0UL), min_wages(0UL), med_wages(0UL), max_wages(0UL),
            total_emplvl(0U), min_emplvl(0U), med_emplvl(0U), max_emplvl(0U)
            { };

        ~Report() { };

		friend std::ostream& operator<<(std::ostream& os, const Report& rpt);  
};
