#ifndef SORTING_ALGORITHM_HH
#define SORTING_ALGORITHM_HH

#include "sequence.hh"
#include <cmath>

bool isLess(Element a, Element b);                   /* Sprawdzenie wielkosci elementu*/
void mergeSort(Sequence &S);                         /* Sortowanie przez scalanie */
void merge(Sequence &S1, Sequence &S2, Sequence &S); /* Scalanie potrzebne do sortowania przez scalanie */
void QuickSort(Sequence &S);                         /* Sortowanie szybkie */
void bucketSort(Sequence &S);                        /* Sortowanie kubełkowe */

#endif