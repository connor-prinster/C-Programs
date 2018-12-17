

#include "MergeSort.hpp"
#include "Employment.hpp"


/* You must implement comparators to use with listsort() which implement stable
 * sorts which fall-back to the FIPS area code as a secondary key to break ties.
 *
 * Hint: The signature of comparators used with listsort() are identical to the
 * comparators used with the standard qsort() function
 */



static int cmp_area_area_fips(const void *left, const void *right) {
    if ((static_cast<const Employment*>(left))->area_fips < (static_cast<const Employment*>(right))->area_fips)
        return -1;
    else if ((static_cast<const Employment*>(left))->area_fips > (static_cast<const Employment*>(right))->area_fips)
        return 1;
    else
        return 0;
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
void sort_empl_by_annual_avg_emplvl(Employment *list) {
    mergesort(list, cmp_employment_annual_avg_emplvl);
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

void sort_empl_by_total_annual_wages(Employment * list) 
{
    mergesort(list, cmp_employment_total_annual_wages);
}