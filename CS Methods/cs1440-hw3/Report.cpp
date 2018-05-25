/*
 * WARNING!
 *
 * You do not need to edit this file
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>

#include "Report.hpp"


static const int DISP_WIDTH = 35;

std::ostream& operator<<(std::ostream& os, const AreaTitleWithStat& atws) {
	os << std::left << std::setw(DISP_WIDTH)
        << atws.area_title
        << atws.stat << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Report& rpt) {
	os  << "[============]\n"
		   "[Final Report]\n"
		   "[============]\n\n"
		   "\nStatistics over all industries in 2016:\n"
		   "=======================================\n"
		<< std::fixed << std::setprecision(2) << std::left;

    os << std::setw(21) << "Total wages earned: $" << rpt.all.total_wages << std::endl;
    os << std::setw(21) << "Total employment: "    << rpt.all.total_employment << std::endl;
    os << std::setw(21) << "Per capita wage:    $" << rpt.all.per_capita_wage << std::endl << std::endl;

	os  << "Top " << TOP_N << " areas by Total Annual Wages" << std::endl
		<< "--------------------------------------------------" << std::endl;
	for (int i = 0; i < TOP_N; i++)
		os << '\t' <<  std::setw(2) << std::right << i+1 << ". " << rpt.all.top_annual_wages[i];
	os << std::endl;

	os  << "Bottom " << TOP_N << " areas by Total Annual Wages" << std::endl
		<< "--------------------------------------------------" << std::endl;
    for (int i = TOP_N - 1; i >= 0; i--)
		os << '\t' <<  std::setw(2) << std::right << i+1 << ". " << rpt.all.bot_annual_wages[i];
	os << std::endl;

	os  << "Top " << TOP_N << " areas by Annual Average Employment Level" << std::endl
		<< "--------------------------------------------------" << std::endl;
	for (int i = 0; i < TOP_N; i++)
		os << '\t' <<  std::setw(2) << std::right << i+1 << ". " << rpt.all.top_annual_avg_emplvl[i];
	os << std::endl;

	os  << "Bottom " << TOP_N << " areas by Annual Average Employment Level" << std::endl
		<< "--------------------------------------------------" << std::endl;
    for (int i = TOP_N - 1; i >= 0; i--)
		os << '\t' <<  std::setw(2) << std::right << i+1 << ". " << rpt.all.bot_annual_avg_emplvl[i];
	os << std::endl;


	os << "\nStatistics over the software publishing industry in 2016:\n"
		  "=========================================================\n";

    os << std::setw(21) << "Total wages earned: $" << rpt.soft.total_wages << std::endl;
    os << std::setw(21) << "Total employment: "    << rpt.soft.total_employment << std::endl;
    os << std::setw(21) << "Per capita wage:    $" << rpt.soft.per_capita_wage << std::endl << std::endl;

	os  << "Top " << TOP_N << " areas by Total Annual Wages" << std::endl
		<< "--------------------------------------------------" << std::endl;
	for (int i = 0; i < TOP_N; i++)
		os << '\t' <<  std::setw(2) << std::right << i+1 << ". " << rpt.soft.top_annual_wages[i];
	os << std::endl;

	os  << "Bottom " << TOP_N << " areas by Total Annual Wages" << std::endl
		<< "--------------------------------------------------" << std::endl;
	for (int i = TOP_N - 1; i >= 0; i--)
		os << '\t' <<  std::setw(2) << std::right << i+1 << ". " << rpt.soft.bot_annual_wages[i];
	os << std::endl;

	os  << "Top " << TOP_N << " areas by Annual Average Employment Level" << std::endl
		<< "--------------------------------------------------" << std::endl;
	for (int i = 0; i < TOP_N; i++)
		os << '\t' <<  std::setw(2) << std::right << i+1 << ". " << rpt.soft.top_annual_avg_emplvl[i];
	os << std::endl;

	os  << "Bottom " << TOP_N << " areas by Annual Average Employment Level" << std::endl
		<< "--------------------------------------------------" << std::endl;
    for (int i = TOP_N - 1; i >= 0; i--)
		os << '\t' <<  std::setw(2) << std::right << i+1 << ". " << rpt.soft.bot_annual_avg_emplvl[i];
	os << std::endl;


	return os;  
}
