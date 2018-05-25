/*                                                                                                                                         
 * WARNING!
 *
 * You should not edit this file
 */

#pragma once

#include "Employment.hpp"

// Code adapted by Erik Falor 2017 from
// https://www.chiark.greenend.org.uk/~sgtatham/algorithms/listsort.c

/*
 * This file is copyright 2001 Simon Tatham.
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL SIMON TATHAM BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * This is the actual sort function. Notice that it returns the new
 * head of the list. (It has to, because the head will not
 * generally be the same element after the sort.) So unlike sorting
 * an array with qsort() where you would ignore the return value:
 * 
 *     qsort(myarray, ...);
 * 
 * you now must do this:
 * 
 *     list = mergesort(mylist);
 *
 * Notice that the signature of comparator function used by mergesort() is
 * identical to those used by qsort()...
 */

Employment *mergesort(Employment *list, int (*compar)(const void*, const void*));
