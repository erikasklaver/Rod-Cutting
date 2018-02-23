#ifndef __quicksort_h
#define __quicksort_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include <limits.h>

int maxrev_recursive(int n, int * price_array);

int comp (const void * elem1, const void * elem2);

int maxrev_DP(int n, int * T, int * price_array);

#endif