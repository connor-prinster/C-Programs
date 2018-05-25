/*
 * WARNING!
 *
 * You do not need to edit this file
 */

#pragma once

#include <string>
#include <ostream>

const int TOP_N = 5;

struct AreaTitleWithStat {
    std::string area_title;
    unsigned long stat;

    AreaTitleWithStat() : area_title(""), stat(0UL) { }

    friend std::ostream& operator<<(std::ostream& os, const AreaTitleWithStat& atws);
};

struct EmploymentDataSet {
    unsigned long long total_wages;                  // Total wages paid out in 2016
    unsigned long      total_employment;             // Total employment in 2016
    double             per_capita_wage;              // Per capita wage (i.e. total wages / total employment)
    AreaTitleWithStat  top_annual_wages[TOP_N];      // Top FIPS areas by annual wages
    AreaTitleWithStat  bot_annual_wages[TOP_N];      // Bottom FIPS areas by annual wages
    AreaTitleWithStat  top_annual_avg_emplvl[TOP_N]; // Top FIPS areas by annual average number of employees
    AreaTitleWithStat  bot_annual_avg_emplvl[TOP_N]; // Bottom FIPS areas by annual average number of employees

    EmploymentDataSet() : total_wages(0ULL), total_employment(0UL), per_capita_wage(0.0) { }
};

class Report {
    public:
        EmploymentDataSet all;
        EmploymentDataSet soft;

        Report()  { };
        ~Report() { };

        friend std::ostream& operator<<(std::ostream& os, const Report& rpt);  
};
