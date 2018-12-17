/*
 * WARNING!
 *
 * You do not need to edit this file
 */

#pragma once

#include "Employment.hpp"
#include "Area.hpp"

// This function has been written for you
void sort_area_by_fips_code(Area *array, size_t num);


// You must provide implementations for these functions
void sort_employment_by_area_fips(Employment *array, size_t num);
void sort_employment_by_annual_avg_estabs(Employment *array, size_t num);
void sort_employment_by_annual_avg_emplvl(Employment *array, size_t num);
void sort_employment_by_total_annual_wages(Employment *array, size_t num);
