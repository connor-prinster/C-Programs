/*
 * WARNING!
 *
 * You do not need to edit this file
 */

#pragma once

#include <string>
#include <iostream>

// This data came from the CSV file linked at
// https://data.bls.gov/cew/doc/titles/area/area_titles.htm

class Area {
	public:
		std::string	area_fips;   // Code
		std::string	area_title;  // Area Title

		Area(
			std::string	_area_fips,
			std::string	_area_title);

		friend std::ostream& operator<<(std::ostream& os, const Area& a);
};

