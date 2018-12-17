#include <iostream>

#include "Report.hpp"
#include "Loop.hpp"
#include <iostream>

#include "Report.hpp"
#include "Loop.hpp"
#include "Stats.hpp"
#include "Database.hpp"
#include "Sort.hpp"

// include header files as needed


int main(void) {
	Report rpt;
	int sizeOfAll = count_all_empl(all_industries);
	
	rpt.all.total_wages = total_annual_wages(all_industries);
	rpt.all.total_employment = total_employment_level(all_industries);
	rpt.all.per_capita_wage = per_capita_annual_wages(all_industries);

	sort_employment_by_total_annual_wages(all_industries, sizeOfAll);
	for (int i = 0; i < TOP_N; i++)
	{
		rpt.all.top_annual_wages[i].area_title = area_fips_To_area_title(fips_areas, all_industries[sizeOfAll - 1 - i].area_fips);
		rpt.all.top_annual_wages[i].stat = all_industries[sizeOfAll - 1 - i].total_annual_wages;
	}
	for (int i = 0; i < TOP_N; i++)
	{
		rpt.all.bot_annual_wages[i].area_title = area_fips_To_area_title(fips_areas, all_industries[i].area_fips);
		rpt.all.bot_annual_wages[i].stat = all_industries[i].total_annual_wages;
	}

	sort_employment_by_annual_avg_emplvl(all_industries, sizeOfAll);
	for (int i = 0; i < TOP_N; i++)
	{
		rpt.all.top_annual_avg_emplvl[i].area_title = area_fips_To_area_title(fips_areas, all_industries[sizeOfAll - 1 - i].area_fips);
		rpt.all.top_annual_avg_emplvl[i].stat = all_industries[sizeOfAll - 1 - i].annual_avg_emplvl;
	}
	for (int i = 0; i < TOP_N; i++)
	{
		rpt.all.bot_annual_avg_emplvl[i].area_title = area_fips_To_area_title(fips_areas, all_industries[i].area_fips);
		rpt.all.bot_annual_avg_emplvl[i].stat = all_industries[i].annual_avg_emplvl;
	}
	//=================================================================================================================================
	//												  vv Software Information vv
	//=================================================================================================================================
	int sizeOfSoft = count_all_empl(software_publishing);
	rpt.soft.total_wages = total_annual_wages(software_publishing);
	rpt.soft.total_employment = total_employment_level(software_publishing);
	rpt.soft.per_capita_wage = per_capita_annual_wages(software_publishing);

	sort_employment_by_total_annual_wages(software_publishing, sizeOfSoft);
	for (int i = 0; i < TOP_N; i++)
	{
		rpt.soft.top_annual_wages[i].area_title = area_fips_To_area_title(fips_areas, software_publishing[sizeOfSoft - 1 - i].area_fips);
		rpt.soft.top_annual_wages[i].stat = software_publishing[sizeOfSoft - 1 - i].total_annual_wages;
	}
	for (int i = 0; i < TOP_N; i++)
	{
		rpt.soft.bot_annual_wages[i].area_title = area_fips_To_area_title(fips_areas, software_publishing[i].area_fips);
		rpt.soft.bot_annual_wages[i].stat = software_publishing[i].total_annual_wages;
	}

	sort_employment_by_annual_avg_emplvl(software_publishing, sizeOfAll);
	for (int i = 0; i < TOP_N; i++)
	{
		rpt.soft.top_annual_avg_emplvl[i].area_title = area_fips_To_area_title(fips_areas, software_publishing[sizeOfSoft - i].area_fips);
		rpt.soft.top_annual_avg_emplvl[i].stat = software_publishing[sizeOfSoft - i].annual_avg_emplvl;
	}
	for (int i = 0; i < TOP_N; i++)
	{
		rpt.soft.bot_annual_avg_emplvl[i].area_title = area_fips_To_area_title(fips_areas, software_publishing[i].area_fips);
		rpt.soft.bot_annual_avg_emplvl[i].stat = software_publishing[i].annual_avg_emplvl;
	}

	std::cout << rpt << std::endl;
}
