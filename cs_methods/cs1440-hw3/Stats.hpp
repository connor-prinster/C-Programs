/*
 * WARNING!
 *
 * You do not need to edit this file
 */

#pragma once

#include <string>

#include "Employment.hpp"
#include "Area.hpp"

// This function has been written for you.
// Given an array of FIPS Areas and a FIPS area code, return the name
// of the corresponding area
std::string area_fips_To_area_title(Area *fips, std::string code);


// You must provide implementations for these functions
unsigned long long total_annual_wages(Employment *array);
unsigned long      total_employment_level(Employment *array);
double             per_capita_annual_wages(Employment *array);
