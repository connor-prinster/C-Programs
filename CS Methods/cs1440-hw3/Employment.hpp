/*
 * WARNING!
 *
 * You do not need to edit this file
 */

#pragma once
#include <string> 
#include <ostream>

// This data came from https://data.bls.gov/cew/data/files/2016/csv/2016_annual_singlefile.zip
//
// The fields I took from the above dataset are described in
// https://data.bls.gov/cew/doc/layouts/csv_annual_layout.htm

class Employment {
    public:
        std::string   area_fips;          // 5-character FIPS code
        unsigned      annual_avg_emplvl;  // Annual average of monthly employment levels for a given year
        unsigned long total_annual_wages; // Sum of the four quarterly total wage levels for a given year

        Employment(
                std::string   _area_fips,
                unsigned      _annual_avg_emplvl,
                unsigned long _total_annual_wages)
            : area_fips(_area_fips),
              annual_avg_emplvl(_annual_avg_emplvl),
              total_annual_wages(_total_annual_wages) { }


        Employment()
            : area_fips(""),
              annual_avg_emplvl(0U),
              total_annual_wages(0UL) { }

        friend std::ostream& operator<<(std::ostream& os, const Employment& emp);  
};
