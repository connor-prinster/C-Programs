/*                                                                                                                                         
 * WARNING!
 *
 * You should not edit this file
 */


#include "MergeSort.hpp"

Employment *mergesort(Employment *list, int (*compar)(const void*, const void*)) {
    Employment *p, *q, *e, *tail;
    int insize, nmerges, psize, qsize, i;

    /*
     * Silly special case: if `list' was passed in as nullptr, return
     * nullptr immediately.
     */
    if (!list)
	return nullptr;

    insize = 1;

    while (1) {
	p = list;
	list = nullptr;
	tail = nullptr;

	nmerges = 0;  /* count number of merges we do in this pass */

	while (p) {
	    nmerges++;  /* there exists a merge to be done */
	    /* step `insize' places along from p */
	    q = p;
	    psize = 0;
	    for (i = 0; i < insize; i++) {
		psize++;
		q = q->next;
		if (!q) break;
	    }

	    /* if q hasn't fallen off end, we have two lists to merge */
	    qsize = insize;

	    /* now we have two lists; merge them */
	    while (psize > 0 || (qsize > 0 && q)) {

		/* decide whether next element of merge comes from p or q */
		if (psize == 0) {
		    /* p is empty; e must come from q. */
		    e = q; q = q->next; qsize--;
		} else if (qsize == 0 || !q) {
		    /* q is empty; e must come from p. */
		    e = p; p = p->next; psize--;
		} else if (compar(p,q) <= 0) {
		    /* First element of p is lower (or same);
		     * e must come from p. */
		    e = p; p = p->next; psize--;
		} else {
		    /* First element of q is lower; e must come from q. */
		    e = q; q = q->next; qsize--;
		}

		/* add the next element to the merged list */
		if (tail) {
		    tail->next = e;
		} else {
		    list = e;
		}
		tail = e;
	    }

	    /* now p has stepped `insize' places along, and q has too */
	    p = q;
	}
	tail->next = nullptr;

	/* If we have done only one merge, we're finished. */
	if (nmerges <= 1)   /* allow for nmerges==0, the empty list case */
	    return list;

	/* Otherwise repeat, merging lists twice the size */
	insize *= 2;
    }
}
