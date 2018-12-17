//#pragma once

#include <string>
#include <cstdlib>

#include "Employment.hpp"
#include "Sort.hpp"


/*
 * An example comparator used when sorting Area objects.
 *
 * Use this code as a guide when writing your own comparators for Employment
 * objects.
 *
 * This comparator compares two Area objects on the basis of their FIPS code.
 * If the left-hand argument is "less than" the right-hand argument, it returns
 * -1. If the one on the left is greater, it returns 1. When they are equal 0
 *  is returned. qsort() uses this information to decide whether to swap these
 *  two objects.
 *
 * Notice that the type given for the left and right objects is `void *`. We
 * know that these objects are actually of type `Area *`. But this comparator
 * is called by qsort(), which we didn't write, and therefore it doesn't know
 * about the classes we have created in our code. Because qsort() has no way
 * of knowing about our Area object it can only treat our Area objects as a
 * bunch of bits & bytes.
 *
 * Since we are writing the comparator, we can use our knowledge of the Area
 * type to access the fields within. The static_cast operator converts the
 * bunch of bits & bytes back into `Area *` which allows us to access the
 * area_fips field.
 */
static int cmp_area_area_fips(const void *left, const void *right) {
    if ((static_cast<const Area*>(left))->area_fips < (static_cast<const Area*>(right))->area_fips)
        return -1;
    else if ((static_cast<const Area*>(left))->area_fips > (static_cast<const Area*>(right))->area_fips)
        return 1;
    else
        return 0;
}

/*
 * Example: using the standard quicksort function with an array of Area objects
 *
 * Note that qsort() takes four parameters, described below
 */
void sort_area_by_fips_code(Area *array, size_t count) {
    qsort(
            array,               // array to be sorted
            count,               // count of items in the array
            sizeof(Area),        // size in bytes of a single Area object
            cmp_area_area_fips); // name of comparator function
}



/*
 * Here is another example of a comparator. This comparator can order two
 * Employment objects based upon their FIPS area code. This might just come in
 * handy later.
 */
static int cmp_employment_area_fips(const void *left, const void *right) {
	if ((static_cast<const Employment*>(left))->area_fips < (static_cast<const Employment*>(right))->area_fips)
		return -1;
	else if ((static_cast<const Employment*>(left))->area_fips > (static_cast<const Employment*>(right))->area_fips)
		return 1;
	else if ((static_cast<const Employment*>(left))->area_fips == (static_cast<const Employment*>(right))->area_fips)
		return cmp_area_area_fips(left, right);
	else
		return 0;
}

/*
 * This sort routine will organize an array of Employment objects
 * alphabetically by FIPS area code.
 */
void sort_employment_by_area_fips(Employment *array, size_t num) 
{
	qsort(array, num, sizeof(Employment), cmp_employment_area_fips);
}

static int cmp_employment_annual_avg_emplvl(const void *left, const void *right) {
    if ((static_cast<const Employment*>(left))->annual_avg_emplvl < (static_cast<const Employment*>(right))->annual_avg_emplvl)
		return -1;
	else if ((static_cast<const Employment*>(left))->annual_avg_emplvl > (static_cast<const Employment*>(right))->annual_avg_emplvl)
		return 1;
	else if ((static_cast<const Employment*>(left))->annual_avg_emplvl > (static_cast<const Employment*>(right))->annual_avg_emplvl)
		return cmp_area_area_fips(left, right);
	else
		return 0;
}

/* Sort an array of Employment objects on the basis of the employment level */
void sort_employment_by_annual_avg_emplvl(Employment *array, size_t count) {
    qsort(array, count, sizeof(Employment), cmp_employment_annual_avg_emplvl);
}

static int cmp_employment_total_annual_wages(const void *left, const void *right) 
{
    if ((static_cast<const Employment*>(left))->total_annual_wages < (static_cast<const Employment*>(right))->total_annual_wages)
		return -1;
	else if ((static_cast<const Employment*>(left))->total_annual_wages > (static_cast<const Employment*>(right))->total_annual_wages)
		return 1;
	else if ((static_cast<const Employment*>(left))->total_annual_wages > (static_cast<const Employment*>(right))->total_annual_wages)
		return cmp_area_area_fips(left, right);
	else
		return 0;
}

/* Sort an array of Employment objects on the basis of total annual wages */
void sort_employment_by_total_annual_wages(Employment *array, size_t count) 
{
    qsort(array, count, sizeof(Employment), cmp_employment_total_annual_wages);
}
