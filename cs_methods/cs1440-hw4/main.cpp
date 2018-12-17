#include <iostream>

#include "Report.hpp"
#include "DirToList.hpp"
#include "ListUtils.hpp"
#include "Stats.hpp"
#include "Sort.hpp"

// include other header files as needed

int main(void) {
	Report rpt;
	
	std::string dirName = "database";
	Employment * emp = DirToList(dirName);
	
	//print_every_empl(emp);
	
	rpt.num_areas = list_length(emp);
	
	emp = sort_empl_by_total_annual_wages(emp);
	rpt.total_wages = total_annual_wages(emp);
	rpt.min_wages = min_annual_wages(emp);
	rpt.med_wages = med_annual_wages(emp);
	rpt.max_wages = max_annual_wages(emp);
	
	emp = sort_empl_by_annual_avg_emplvl(emp);
	rpt.total_emplvl = total_annual_emplvl(emp);
	rpt.min_emplvl = min_annual_emplvl(emp);
	rpt.med_emplvl = med_annual_emplvl(emp);
	rpt.max_emplvl = max_annual_emplvl(emp);
	
	std::cout << rpt << std::endl; //final tab
	
	cleanup_list(emp);
}

