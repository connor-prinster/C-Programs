#include "Stats.hpp"
#include "Loop.hpp"
#include "Database.hpp"
// Given an array of FIPS Areas and a FIPS area code, return the name
// of the corresponding area
std::string area_fips_To_area_title(Area *fips, std::string code) {
	int i = 0;
	for (; fips[i].area_fips != "END"
			&& fips[i].area_fips != code; ++i)
		;
	return fips[i].area_title;
}

// total wages paid across all FIPS areas in this dataset
unsigned long long total_annual_wages(Employment *array) 
{
	unsigned long long totWage = 0;
	for (int i = 0; array[i].area_fips != "END"; i++)
	{
		totWage += array[i].total_annual_wages;
	}
	return totWage;
}


// total employment level across all FIPS areas in this dataset
unsigned long total_employment_level(Employment *array) {
	unsigned long emp = 0;
	for (int i = 0; array[i].area_fips != "END"; i++)
	{
		emp += array[i].annual_avg_emplvl;
	}
	return emp;
}

// average wage per employee represented in this dataset
double per_capita_annual_wages(Employment *array) 
{
    double percap = total_annual_wages(array) / total_employment_level(array);
	
	return percap;
}