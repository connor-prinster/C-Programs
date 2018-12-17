/*
 * WARNING!
 *
 * You do not need to edit this file
 */

#include <iostream>

#include "Loop.hpp"

/*
 * This file contains routines which use for loops to traverse arrays. They
 * don't know in advance how long the arrays are, but seek a Sentinel value
 * "END" to mark the end of the array */


// Find the number of Area objects in an array, not counting the Sentinel
void print_every_area(Area *array) {
	for (int i = 0; array[i].area_fips != "END"; ++i)
		std::cout << array[i] << std::endl;
}

// Print all Area objects in an array
int count_all_areas(Area *array) {
	int i = 0;
	for (; array[i].area_fips != "END"; ++i)
		;
	return i;
}

// Print all Employment objects in an array
void print_every_empl(Employment *array) {
	for (int i = 0; array[i].area_fips != "END"; ++i)
		std::cout << array[i] << std::endl;
}

// Find the number of Employment objects in an array, not counting the Sentinel
int count_all_empl(Employment *array) {
	int i = 0;
	for (; array[i].area_fips != "END"; ++i)
		;
	return i;
}
